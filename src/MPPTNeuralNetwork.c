#include <stdio.h>
#include <stdlib.h>
#include "pvpanelnn/pvpanelNN.h"
#include "helper/chronograph.h"

int main()
{
    PvPanelNN *pvpanelNN = pvpanelNN_get();

    double *input = malloc(sizeof(double) * 3);
    input[0] = 976.866035758628;
    input[1] = 392.167166311451;
    input[2] = 342.621019067798;

    Chronograph *chronograph = chronograph_get();
    double *output = neuralnet_compute(input, pvpanelNN->neuralNet);

    printf("\nFINAL OUTPUT: %f", output[0]);

    printf("\nTOTAL TIME: %f", chronograph_getDelta(chronograph));
    chronograph_free(chronograph);
}