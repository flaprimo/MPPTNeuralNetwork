#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simulation.h"
#include "../helper/chronograph.h"

/**
 * It returns a configured environment for mppt simulation with neural networks.
 * @param pvPanel
 * @param neuralNet
 * @param simulationLength
 * @param irradianceArray
 * @param temperatureArray
 * @param mppVoltageArray
 * @param mppCurrentArray
 * @return
 */
Simulation *simulation_get(PvPanel *pvPanel, NeuralNet *neuralNet, int simulationLength, double *irradianceArray,
                           double *temperatureArray, double *mppVoltageArray, double *mppCurrentArray)
{
    Simulation *pvpanelNN = malloc(sizeof(Simulation));

    pvpanelNN->pvpanel = pvPanel;
    pvpanelNN->neuralNet = neuralNet;

    pvpanelNN->simulationLength = simulationLength;
    pvpanelNN->irradianceArray = irradianceArray;
    pvpanelNN->temperatureArray = temperatureArray;

    pvpanelNN->mppVoltageArray = mppVoltageArray;
    pvpanelNN->mppCurrentArray = mppCurrentArray;

    return pvpanelNN;
}

/**
 * Given the path to a file containing a PvPanelNN simulation configuration, it returns a PvPanelNN.
 * @param simulationFilePath
 * @return
 */
Simulation *simulation_importFile(char *simulationFilePath)
{
    PvPanel *pvPanel = NULL;
    NeuralNet *neuralNet = NULL;

    int simulationLength = 0;
    double *irradianceArray = NULL;
    double *temperatureArray = NULL;

    double *mppVoltageArray = NULL;
    double *mppCurrentArray = NULL;

    char temp[21];

    FILE *file = fopen(simulationFilePath, "r");

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

    // read mpp voltage
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MPP_VOLTAGE") == 0) {
        mppVoltageArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &mppVoltageArray[i]);
    }

    // read mpp current
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MPP_CURRENT") == 0) {
        mppCurrentArray = malloc(sizeof(double) * simulationLength);

        for (int i = 0; i < simulationLength; i++)
            fscanf(file, "%lf", &mppCurrentArray[i]);
    }

    // read pvpanel voltage
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#PVPANEL_VOLTAGE") == 0) {
        double pvpanelVoltage = 0;
        fscanf(file, "%lf", &pvpanelVoltage);

        pvPanel = pvpanel_get(pvpanelVoltage);
    }

    // read neuralnet settings
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#NEURALNETWORK") == 0) {
        fscanf(file, "%20s", temp);
        char layerPath[20] = "../res/";
        strcat(layerPath, temp);

        neuralNet = neuralnet_importFile(layerPath);
    }

    fclose(file);

    return simulation_get(pvPanel, neuralNet, simulationLength, irradianceArray, temperatureArray, mppVoltageArray, mppCurrentArray);
}

/**
 * Given a PvPanelNN it runs a simulation.
 * Beware, simulation can be run only once, to run again free this simulation and create another one.
 * @param simulation
 */
void simulation_simulate(Simulation *simulation)
{
    double *input = malloc(sizeof(double) * simulation->neuralNet->inputLength);

    double voltage[simulation->simulationLength];
    double current[simulation->simulationLength];

    voltage[0] = simulation->pvpanel->vCurr;
    current[0] = simulation->pvpanel->iCurr;

    pvpanel_print(simulation->pvpanel);
    simulation_print(simulation);

    Chronograph *chronograph = chronograph_get();
    for (int i = 1; i < simulation->simulationLength; i++) {
        pvpanel_update(simulation->temperatureArray[i], simulation->irradianceArray[i], simulation->pvpanel);

        input[0] = voltage[i-1]; // V
        input[1] = current[i-1]; // I
        input[2] = simulation->temperatureArray[i]; // T

        voltage[i] = neuralnet_compute(input, simulation->neuralNet)[0];
        current[i] = pvpanel_newtonRaphson(simulation->pvpanel, voltage[i]);

    }
    printf("\nSIMULATION TIME: %f\n\n", chronograph_getDelta(chronograph));
    chronograph_free(&chronograph);

    // Print results
    printf("SIMULATION:\n");
    printf("Neuralnet values:\n");
    printf("  voltage: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", voltage[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", current[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", voltage[i] * current[i]);
    printf("\n\n");

    printf("Optimal values:\n");
    printf("  voltage: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", simulation->mppVoltageArray[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", simulation->mppCurrentArray[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", simulation->mppVoltageArray[i] * simulation->mppCurrentArray[i]);
    printf("\n\n");

    printf("DELTA:\n");
    printf("  voltage: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", simulation->mppVoltageArray[i] - voltage[i]);
    printf("\n");
    printf("  current: ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", simulation->mppCurrentArray[i] - current[i]);
    printf("\n");
    printf("  power:   ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%14f ", (simulation->mppVoltageArray[i] * simulation->mppCurrentArray[i]) - (voltage[i] * current[i]));
    printf("\n\n");
}

/**
 * Frees Simulation struct.
 * @param simulation
 */
void simulation_free(Simulation **simulation)
{
    if (*simulation) {
        free((*simulation)->irradianceArray);
        (*simulation)->irradianceArray = NULL;

        free((*simulation)->temperatureArray);
        (*simulation)->temperatureArray = NULL;

        free((*simulation)->mppVoltageArray);
        (*simulation)->mppVoltageArray = NULL;

        free((*simulation)->mppCurrentArray);
        (*simulation)->mppCurrentArray = NULL;

        pvpanel_free(&(*simulation)->pvpanel);

        neuralnet_free(&(*simulation)->neuralNet);

        free(*simulation);
        *simulation = NULL;
    }
}

/**
 * Prints the PvPanelNN.
 * @param simulation
 */
void simulation_print(Simulation *simulation)
{
    printf("Simulation {\n");

    printf("  PvPanel *pvpanel\n");
    printf("  NeuralNet *neuralNet\n\n");

    printf("  simulationLength: %d\n", simulation->simulationLength);

    printf("  irradianceArray: {\n    ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%f ", simulation->irradianceArray[i]);
    printf("\n  }\n");

    printf("  temperatureArray: {\n    ");
    for (int i = 0; i < simulation->simulationLength; i++)
        printf("%f ", simulation->temperatureArray[i]);
    printf("\n  }\n");

    printf("}\n\n");
}