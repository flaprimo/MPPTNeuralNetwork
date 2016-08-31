#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "neuralnet.h"

/**
 * Given the number of inputs, it returns a NeuralNet struct.
 * @param inputLength
 * @return
 */
NeuralNet *neuralnet_get(int inputLength, double *minInput, double *maxInput, int outputLength, double *minOutput,
                         double *maxOutput, List *layerList)
{
    NeuralNet *neuralNet = malloc(sizeof(NeuralNet));

    neuralNet->inputLength = inputLength;
    neuralNet->minInput = minInput;
    neuralNet->maxInput = maxInput;

    neuralNet->outputLength = outputLength;
    neuralNet->minOutput = minOutput;
    neuralNet->maxOutput = maxOutput;

    neuralNet->layerList = layerList;

    return neuralNet;
}

/**
 * Given the path to a file containing a neural network configuration, it returns a neural network.
 * @param neuralnetFilePath
 * @return
 */
NeuralNet *neuralnet_importFile(char *neuralnetFilePath)
{
    // declare and initialize default values
    int inputLength = 0;
    double *minInput = NULL;
    double *maxInput = NULL;

    int outputLength = 0;
    double *minOutput = NULL;
    double *maxOutput = NULL;

    List *layerList = NULL;

    char temp[21];

    FILE *file = fopen(neuralnetFilePath, "r"); // ../res/default.nnconf

    // read input length
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#INPUT_LENGTH") == 0)
        fscanf(file, "%d", &inputLength);

    // read min input
        fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MIN_INPUT") == 0) {
        minInput = malloc(sizeof(double) * inputLength);

        for (int i = 0; i < inputLength; i++)
            fscanf(file, "%lf", &minInput[i]);
    }

    // read max input
        fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MAX_INPUT") == 0) {
        maxInput = malloc(sizeof(double) * inputLength);

        for (int i = 0; i < inputLength; i++)
            fscanf(file, "%lf", &maxInput[i]);
    }

    // read output length
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#OUTPUT_LENGTH") == 0)
        fscanf(file, "%d", &outputLength);

    // read min output
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MIN_OUTPUT") == 0) {
        minOutput = malloc(sizeof(double) * outputLength);

        for (int i = 0; i < outputLength; i++)
            fscanf(file, "%lf", &minOutput[i]);
    }

    // read max output
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#MAX_OUTPUT") == 0) {
        maxOutput = malloc(sizeof(double) * outputLength);

        for (int i = 0; i < outputLength; i++)
            fscanf(file, "%lf", &maxOutput[i]);
    }

    // read layers
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#LAYERS") == 0) {
        while(fscanf(file, "%20s", temp) != EOF) {
            char layerPath[20] = "../res/";
            strcat(layerPath, temp);

            Layer *layer = layer_importFile(layerPath);
            layer_print(layer);
            list_addLast(&layerList, layer);
        }
    }

    fclose(file);

    return neuralnet_get(inputLength, minInput, maxInput, outputLength, minOutput, maxOutput, layerList);
}

/**
 * Given an input and a PvPanelNN, it normalizes the input.
 * inputN = (1+1) * (Input' - MinInput) ./ (MaxInput - MinInput) - [1 1 1];
 * @param neuralNet
 * @param input
 * @return
 */
double *neuralnet_normalizeInput(NeuralNet *neuralNet, double *input)
{
    double *normalizedInput = malloc(sizeof(double) * neuralNet->inputLength);

    for (int i = 0; i < neuralNet->inputLength; i++)
        normalizedInput[i] = 2 * (input[i] - neuralNet->minInput[i]) / (neuralNet->maxInput[i] - neuralNet->minInput[i]) - 1;

    return normalizedInput;
}

/**
 * Given an output and a PvPanelNN, it normalizes the output.
 * outputN = (MaxOutput - MinOutput) * (NN_output + 1) / (1+1) + MinOutput;
 * @param neuralNet
 * @param output
 * @return
 */
double *neuralnet_normalizeOutput(NeuralNet *neuralNet, double *output)
{
    double *normalizedOutput = malloc(sizeof(double) * neuralNet->outputLength);

    for (int i = 0; i < neuralNet->outputLength; i++)
        normalizedOutput[i] = (neuralNet->maxOutput[i] - neuralNet->minOutput[i]) * (output[i] + 1) / 2 + neuralNet->minOutput[i];

    return normalizedOutput;
}

/**
 * Given a NeuralNet struct and an input, it returns the result of the neuralnet computation.
 * @param input
 * @param neuralNet
 * @return
 */
double *neuralnet_compute(double *input, NeuralNet *neuralNet)
{
    List *layerList = neuralNet->layerList;
    double *currentOutput = neuralnet_normalizeInput(neuralNet, input);

    while (layerList) {
        Layer *currentLayer = (Layer *) layerList->info;

        currentOutput = layer_compute(currentOutput, currentLayer);

        layerList = layerList->next;
    }

    return neuralnet_normalizeOutput(neuralNet, currentOutput);
}

/**
 * Frees NeuralNet struct.
 * @param neuralnet
 */
void neuralnet_free(NeuralNet *neuralnet)
{
    free(neuralnet->minInput);
    free(neuralnet->maxInput);
    free(neuralnet->minInput);
    free(neuralnet->maxInput);

    list_removeAll(&neuralnet->layerList, layer_freeVoidPointer);
    free(neuralnet->layerList);

    free(neuralnet);
}