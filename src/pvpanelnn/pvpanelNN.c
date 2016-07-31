#include <stdlib.h>
#include <stdio.h>
#include "pvpanelNN.h"

const int INPUT_LENGTH = 3;
const int OUTPUT_LENGTH = 1;

PvPanelNN *pvpanelNN_get()
{
    PvPanelNN *pvpanelNN = malloc(sizeof(PvPanelNN));

    // input
    pvpanelNN->inputLength = INPUT_LENGTH;

    pvpanelNN->minInput = malloc(sizeof(double) * INPUT_LENGTH);
    pvpanelNN->minInput[0] = 750.5;
    pvpanelNN->minInput[1] = 2.83892709347493;
    pvpanelNN->minInput[2] = 263;

    pvpanelNN->maxInput = malloc(sizeof(double) * INPUT_LENGTH);
    pvpanelNN->maxInput[0] = 1578.8;
    pvpanelNN->maxInput[1] = 569.413757050536;
    pvpanelNN->maxInput[2] = 363;

    // output
    pvpanelNN->outputLength = OUTPUT_LENGTH;

    pvpanelNN->minOutput = malloc(sizeof(double) * OUTPUT_LENGTH);
    pvpanelNN->minOutput[0] = 782.16;

    pvpanelNN->maxOutput = malloc(sizeof(double) * OUTPUT_LENGTH);
    pvpanelNN->maxOutput[0] = 1403.6;

    return pvpanelNN;
}

/**
 * Given an input and a PvPanelNN, it normalizes the input.
 * inputN = (1+1) * (Input' - MinInput) ./ (MaxInput - MinInput) - [1 1 1];
 * @param pvpanelNN
 * @param input
 * @return
 */
double *pvpanelNN_normalizeInput(PvPanelNN *pvpanelNN, double *input)
{
    double *normalizedInput = malloc(sizeof(double) * pvpanelNN->inputLength);

    for (int i = 0; i < pvpanelNN->inputLength; i++)
        normalizedInput[i] = 2 * (input[i] - pvpanelNN->minInput[i]) / (pvpanelNN->maxInput[i] - pvpanelNN->minInput[i]) - 1;

    return normalizedInput;
}

/**
 * Given an output and a PvPanelNN, it normalizes the output.
 * outputN = (MaxOutput - MinOutput) * (NN_output + 1) / (1+1) + MinOutput;
 * @param pvpanelNN
 * @param output
 * @return
 */
double *pvpanelNN_normalizeOutput(PvPanelNN *pvpanelNN, double *output)
{
    double *normalizedOutput = malloc(sizeof(double) * pvpanelNN->outputLength);

    for (int i = 0; i < pvpanelNN->outputLength; i++) {
        normalizedOutput[i] = (pvpanelNN->maxOutput[i] - pvpanelNN->minOutput[i]) * (output[i] + 1) / 2 + pvpanelNN->minOutput[i];
        //printf("- %f\n", (pvpanelNN->maxOutput[i] - pvpanelNN->minOutput[i]));
    }

    return normalizedOutput;
}

void pvpanelNN_free(PvPanelNN *pvpanelNN)
{
    free(pvpanelNN->minInput);
    free(pvpanelNN->maxInput);

    free(pvpanelNN->minOutput);
    free(pvpanelNN->maxOutput);
}