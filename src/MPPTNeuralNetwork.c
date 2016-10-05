/*#include <stdlib.h>
#include <stdio.h>
#include "helper/chronograph.h"*/
#include "simulation/simulation.h"

int main()
{
    Simulation *simulation = simulation_importFile("../res/default.nnsimulation");

    simulation_simulate(simulation);

    simulation_free(&simulation);

    /*NeuralNet *neuralNet = neuralnet_importFile("../res/default.nnconf");

    double *input = malloc(sizeof(double) * 3);
    input[0] = 976.866035758628; // V
    input[1] = 392.167166311451; // I
    input[2] = 342.621019067798; // T

    Chronograph *chronograph = chronograph_get();
    double *output = neuralnet_compute(input, neuralNet);

    printf("\nTOTAL TIME: %f", chronograph_getDelta(chronograph));
    printf("\nFINAL OUTPUT: %f", output[0]);

    chronograph_free(&chronograph);*/
}