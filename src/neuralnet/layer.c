#include <stdlib.h>
#include <stdio.h>
#include "layer.h"

/**
 * Given rowNumber, columnNumber, it returns a Layer object.
 * @param rowLength
 * @param columnLength
 * @param matrix
 * @return
 */
Layer *layer_get(int rowLength, int columnLength, TransferFunc_type transferFunction)
{
    Layer *weight = malloc(sizeof(Layer));

    weight->rowLength = rowLength;
    weight->columnLength = columnLength;
    weight->weightArray = malloc(sizeof(double *) * rowLength);
    for (int i = 0; i < rowLength; i++)
        weight->weightArray[i] = calloc((unsigned int) columnLength, sizeof(double)); // unsigned


    weight->bias = calloc((unsigned int) columnLength, sizeof(double));
    weight->transferFunction = transferFunc_get(transferFunction);

    return weight;
}

/**
 * Given an input array and a Layer struct, it returns the weighted sum beetween input and weights.
 * @param input array length is equal to rowLength of the Layer struct.
 * @param layer array with the length equal to columnLength of the Layer struct.
 * @return
 */
double *layer_weightedSum(double *input, Layer *layer)
{
    double *output = calloc((unsigned int) layer->columnLength, sizeof(double));

    for (int i = 0; i < layer->rowLength; i++)
        for (int j = 0; j < layer->columnLength; j++)
            output[j] += input[i] * layer->weightArray[i][j];

    return output;
}

/**
 * Given the result of a weighted sum and a Layer struct, it apply the activation function to the current result.
 * @param output
 * @param layer
 */
void layer_activationFunction(double *output, Layer *layer)
{
    for (int i = 0; i < layer->columnLength; i++)
        output[i] = layer->transferFunction(output[i] + layer->bias[i]);
}

/**
 * Computes a layer with the weighted sum and activation function.
 * @param input
 * @param layer
 * @return
 */
double *layer_compute(double *input, Layer *layer)
{
    // compute the weighted sum
    double *output = layer_weightedSum(input, layer); // the new input is the output

    // apply the activation function
    layer_activationFunction(output, layer);

    return output;
}

/**
 * Frees Layer struct.
 * @param layer
 */
void layer_free(Layer *layer)
{
    for (int i = 0; i < layer->rowLength; i++)
        free(layer->weightArray[i]);

    free(layer->weightArray);
    free(layer->bias);
    free(layer);
}

/**
 * Frees Layer struct passed as a void pointer. Use if layer are used in a list.
 * @param layerVoidPointer
 */
void layer_freeVoidPointer(void *layerVoidPointer)
{
    if (layerVoidPointer != NULL)
        layer_free((Layer *) layerVoidPointer);
}

/**
 * Prints the layer.
 * @param layer
 */
void layer_print(Layer *layer)
{
    printf("Layer {\n");

    printf("  rowLength: %d\n", layer->rowLength);
    printf("  columnLength: %d\n", layer->columnLength);

    printf("  weightArray: {\n");
    for (int i = 0; i < layer->rowLength; i++) {
        printf("    | ");
        for (int j = 0; j < layer->columnLength; j++)
            printf("%f ", layer->weightArray[i][j]);
        printf("|\n");
    }
    printf("  }\n");

    printf("  bias: {\n    | ");
    for (int i = 0; i < layer->columnLength; i++)
        printf("%f ", layer->bias[i]);
    printf("|\n  }\n");

    printf("}\n\n");
}