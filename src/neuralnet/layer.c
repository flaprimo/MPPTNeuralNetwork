#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "layer.h"

/**
 * Given a the coordinates of a bidimensional array, it returns the corresponding coordinates of a bidimensional array
 * implemented as a vector.
 * @param rowLength
 * @param rowIndex
 * @param columnIndex
 * @return
 */
int arrayCoordinatesToIndex(int rowLength, int rowIndex, int columnIndex)
{
    return rowLength * rowIndex + columnIndex;
}

/**
 * Given rowNumber, columnNumber, it returns a Layer object.
 * @param rowLength
 * @param columnLength
 * @param matrix
 * @return
 */
Layer *layer_get(int rowLength, int columnLength, double *weightArray, double *biasArray, TransferFunc_type transferFunction)
{
    Layer *layer = malloc(sizeof(Layer));

    layer->rowLength = rowLength;
    layer->columnLength = columnLength;
    layer->weightArray = weightArray;
    layer->bias = biasArray;
    layer->transferFunction = transferFunc_get(transferFunction);

    return layer;
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

    for (int i = 0; i < layer->columnLength; i++)
        for (int j = 0; j < layer->rowLength; j++)
            output[i] += input[j] * layer->weightArray[arrayCoordinatesToIndex(layer->rowLength, i, j)];

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
 * Given the path to a file containing a layer configuration, it returns a layer.
 * @param layerFilePath
 * @return
 */
Layer *layer_importFile(char *layerFilePath)
{
    // declare and initialize default values
    int rowLength = 0;
    int columnLength = 0;
    double *weightArray = NULL;
    double *biasArray = NULL;
    TransferFunc_type transferFunction = LINEAR;

    char temp[21];

    FILE *file = fopen(layerFilePath, "r"); // ../res/layer1.nnlayer

    // read row length
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#ROW_LENGTH") == 0)
        fscanf(file, "%d", &rowLength);

    // read column length
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#COLUMN_LENGTH") == 0)
        fscanf(file, "%d", &columnLength);

    // read weight matrix
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#WEIGHT") == 0) {
        weightArray = malloc(sizeof(double) * rowLength * columnLength);

        for (int i = 0; i < rowLength * columnLength; i++)
            fscanf(file, "%lf", &weightArray[(i % columnLength) * rowLength + (i / columnLength)]);
    }

    // read bias matrix
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#BIAS") == 0) {
        biasArray = malloc(sizeof(double) * columnLength);

        for (int i = 0; i < columnLength; i++)
            fscanf(file, "%lf", &biasArray[i]);
    }

    // read transfer function
    fscanf(file, "%20s", temp);
    if (strcmp(temp, "#TRANSFER_FUNCTION") == 0) {
        fscanf(file, "%20s", temp);
        transferFunction = transferFunc_stringToEnumType(temp);
    }

    fclose(file);

    return layer_get(rowLength, columnLength, weightArray, biasArray, transferFunction);
}

/**
 * Frees Layer struct.
 * @param layer
 */
void layer_free(Layer *layer)
{
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

    printf("  weightArray: {\n    ");
    for (int i = 0; i < layer->rowLength * layer->columnLength; i++) {
        if (i % layer->rowLength == 0 && i != 0)
            printf("\n    ");
        printf("%f ", layer->weightArray[i]);
    }
    printf("\n  }\n");

    printf("  bias: {\n    ");
    for (int i = 0; i < layer->columnLength; i++)
        printf("%f ", layer->bias[i]);
    printf("\n  }\n");

    printf("}\n\n");
}