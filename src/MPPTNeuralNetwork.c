#include <stdio.h>
#include <stdlib.h>
#include "pvpanelnn/pvpanelNN.h"
#include "helper/chronograph.h"

int main()
{
    Chronograph *chronograph = chronograph_get();

    PvPanelNN *pvpanelNN = pvpanelNN_get();

    double *input = malloc(sizeof(double) * pvpanelNN->inputLength);
    input[0] = 976.866035758628;
    input[1] = 392.167166311451;
    input[2] = 342.621019067798;

    double *output = pvpanelNN_compute(pvpanelNN, input);

    printf("\nFINAL OUTPUT: %f", output[0]);

    printf("\nTOTAL TIME: %f", chronograph_getDelta(chronograph));
    chronograph_free(chronograph);
}