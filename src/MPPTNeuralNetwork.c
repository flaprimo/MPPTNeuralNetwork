#include <stdlib.h>
#include "simulation/simulation.h"
#include "helper/chronograph.h"

int main()
{
    Simulation *simulation = simulation_importFile("../res/default.nnsimulation");

    simulation_simulate(simulation);

    simulation_free(&simulation);

    /*Simulation *pvpanelNN = simulation_get();

    double *input = malloc(sizeof(double) * 3);
    input[0] = 976.866035758628; // V
    input[1] = 392.167166311451; // I
    input[2] = 342.621019067798; // T

    Chronograph *chronograph = chronograph_get();
    double *output = neuralnet_compute(input, pvpanelNN->neuralNet);

    printf("\nFINAL OUTPUT: %f", output[0]);

    printf("\nTOTAL TIME: %f", chronograph_getDelta(chronograph));
    chronograph_free(chronograph);

    pvpanel_print(pvpanelNN->pvpanel);*/


    /*int rowLength = 2;
    int columnLength = 6;

    double *weightArray = malloc(sizeof(double) * rowLength * columnLength);
    for (int i = 0; i < rowLength * columnLength; i++)
        weightArray[i] = i;

    double *biasArray = malloc(sizeof(double) * columnLength);
    for (int i = 0; i < columnLength; i++)
        biasArray[i] = i + 20;

    TransferFunc_type transferFuncType = SIGMOID;

    // create layer1
    Layer *layer1 = layer_get(rowLength, columnLength, weightArray, biasArray, transferFuncType);
    layer_print(layer1);

    layer_free(&layer1);

    Layer *layer2 = layer_importFile("../res/default0.nnlayer");
    layer_print(layer2);

    layer_free(&layer2);*/
}