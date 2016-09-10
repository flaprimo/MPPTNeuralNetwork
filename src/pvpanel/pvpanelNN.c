#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pvpanelNN.h"

/**
 * It returns a configured environment for mppt simulation with neural networks.
 * @param simulationLength
 * @param irradianceArray
 * @param temperatureArray
 * @param mppVoltageArray
 * @param mppCurrentArray
 * @return
 */
PvPanelNN *pvpanelNN_get(int simulationLength, double *irradianceArray, double *temperatureArray,
                         double *mppVoltageArray, double *mppCurrentArray)
{
    PvPanelNN *pvpanelNN = malloc(sizeof(PvPanelNN));

    pvpanelNN->pvpanel = pvpanel_get(1100);
    pvpanelNN->neuralNet = neuralnet_importFile("../res/default.nnconf");

    pvpanelNN->simulationLength = simulationLength;
    pvpanelNN->irradianceArray = irradianceArray;
    pvpanelNN->temperatureArray = temperatureArray;

    pvpanelNN->mppVoltageArray = mppVoltageArray;
    pvpanelNN->mppCurrentArray = mppCurrentArray;

    return pvpanelNN;
}

/**
 * Given the path to a file containing a PvPanelNN simulation configuration, it returns a PvPanelNN.
 * @param pvpanelNNFilePath
 * @return
 */
PvPanelNN *pvpanelNN_importFile(char *pvpanelNNFilePath)
{
    int simulationLength = 0;
    double *irradianceArray = NULL;
    double *temperatureArray = NULL;

    double *mppVoltageArray = NULL;
    double *mppCurrentArray = NULL;

    char temp[21];

    FILE *file = fopen(pvpanelNNFilePath, "r");

    // read simulation length
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#SIMULATION_LENGTH") == 0)
        fscanf(file, "%d", &simulationLength);

    // read irradiance
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#IRRADIANCE") == 0) {
        irradianceArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &irradianceArray[i]);
    }

    // read temperature
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#TEMPERATURE") == 0) {
        temperatureArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &temperatureArray[i]);
    }

    // read voltage
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MPP_VOLTAGE") == 0) {
        mppVoltageArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &mppVoltageArray[i]);
    }

    // read current
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MPP_CURRENT") == 0) {
        mppCurrentArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &mppCurrentArray[i]);
    }

    fclose(file);

    return pvpanelNN_get(simulationLength, irradianceArray, temperatureArray, mppVoltageArray, mppCurrentArray);
}

/**
 * Given a PvPanelNN it runs a simulation.
 * Beware, simulation can be run only once, to run again free this simulation and create another one.
 * @param pvPanelNN
 */
void pvpanelNN_simulate(PvPanelNN *pvPanelNN)
{
    double *input = malloc(sizeof(double) * pvPanelNN->neuralNet->inputLength);

    double voltage[pvPanelNN->simulationLength];
    double current[pvPanelNN->simulationLength];

    voltage[0] = pvPanelNN->pvpanel->vCurr;
    current[0] = pvPanelNN->pvpanel->iCurr;

    pvpanel_print(pvPanelNN->pvpanel);
    pvpanelNN_print(pvPanelNN);

    for (int i = 1; i < pvPanelNN->simulationLength; i++) {
        pvpanel_update(pvPanelNN->temperatureArray[i], pvPanelNN->irradianceArray[i], pvPanelNN->pvpanel);

        input[0] = voltage[i-1]; // V
        input[1] = current[i-1]; // I
        input[2] = pvPanelNN->temperatureArray[i]; // T

        voltage[i] = neuralnet_compute(input, pvPanelNN->neuralNet)[0];
        current[i] = pvpanel_newtonRaphson(pvPanelNN->pvpanel, voltage[i]);

    }

    // Print results
    printf("SIMULATION:\n");
    printf("Neuralnet values:\n");
    printf("  voltage: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", voltage[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", current[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", voltage[i] * current[i]);
    printf("\n\n");

    printf("Optimal values:\n");
    printf("  voltage: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", pvPanelNN->mppVoltageArray[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", pvPanelNN->mppCurrentArray[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", pvPanelNN->mppVoltageArray[i] * pvPanelNN->mppCurrentArray[i]);
    printf("\n\n");

    printf("DELTA:\n");
    printf("  voltage: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", pvPanelNN->mppVoltageArray[i] - voltage[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", pvPanelNN->mppCurrentArray[i] - current[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < pvPanelNN->simulationLength; i++)
        printf("%14f ", (pvPanelNN->mppVoltageArray[i] * pvPanelNN->mppCurrentArray[i]) - (voltage[i] * current[i]));
    printf("\n\n");
}

/**
 * Frees PvPanelNN struct.
 * @param pvpanelNN
 */
void pvpanelNN_free(PvPanelNN *pvpanelNN)
{
    free(pvpanelNN->irradianceArray);
    free(pvpanelNN->temperatureArray);

    free(pvpanelNN->mppVoltageArray);
    free(pvpanelNN->mppCurrentArray);

    pvpanel_free(pvpanelNN->pvpanel);
    neuralnet_free(pvpanelNN->neuralNet);
    free(pvpanelNN);
}

/**
 * Prints the PvPanelNN.
 * @param pvpanelNN
 */
void pvpanelNN_print(PvPanelNN *pvpanelNN)
{
    printf("PvPanelNN {\n");

    printf("  PvPanel *pvpanel\n");
    printf("  NeuralNet *neuralNet\n\n");

    printf("  simulationLength: %d\n", pvpanelNN->simulationLength);

    printf("  irradianceArray: {\n    ");
    for (int i = 0; i < pvpanelNN->simulationLength; i++)
        printf("%f ", pvpanelNN->irradianceArray[i]);
    printf("\n  }\n");

    printf("  temperatureArray: {\n    ");
    for (int i = 0; i < pvpanelNN->simulationLength; i++)
        printf("%f ", pvpanelNN->temperatureArray[i]);
    printf("\n  }\n");

    printf("}\n\n");
}