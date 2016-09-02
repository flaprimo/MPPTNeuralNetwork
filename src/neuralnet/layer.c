#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "layer.h"

const int THREAD_NUMBER = 3;

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
 * Computes a layer with the weighted sum and activation function.
 * @param input
 * @param layer
 * @return
 */
double *layer_compute(double *input, Layer *layer)
{
    double *output = calloc((unsigned int) layer->columnLength, sizeof(double));

    for (int i = 0; i < layer->columnLength; i++) {
        // compute weighted sum
        for (int j = 0; j < layer->rowLength; j++)
            output[i] += input[j] * layer->weightArray[arrayCoordinatesToIndex(layer->rowLength, i, j)];

        // add bias and apply the activation function
        output[i] = layer->transferFunction(output[i] + layer->bias[i]);
    }

    return output;
}

void *layer_compute_worker(void *voidWorkerArgs) {

    LayerWorker *workerArgs = (LayerWorker *) voidWorkerArgs;

    for (int i = workerArgs->startWeight; i < workerArgs->endWeight + 1; i++) {
        // compute weighted sum
        for (int j = 0; j < workerArgs->layer->rowLength; j++)
            workerArgs->output[i] += workerArgs->input[j] *
                    workerArgs->layer->weightArray[arrayCoordinatesToIndex(workerArgs->layer->rowLength, i, j)];

        // add bias and apply the activation function
        workerArgs->output[i] = workerArgs->layer->transferFunction(workerArgs->output[i] + workerArgs->layer->bias[i]);
    }

    return NULL;
}

double *layer_computeMT(double *input, Layer *layer)
{
    // get number of usable threads
    int threadNumber;

    if (layer->columnLength < THREAD_NUMBER)
        threadNumber = layer->columnLength;
    else
        threadNumber = THREAD_NUMBER;

    // create thread array
    pthread_t threadArray[threadNumber];

    // compute the number of weights a thread should handle
    int div = layer->columnLength / threadNumber;
    int rem = layer->columnLength % threadNumber;

    // initialize output
    double *output = calloc((unsigned int) layer->columnLength, sizeof(double));

    //initialize workerArgs
    LayerWorker *layerWorkerArray = malloc(sizeof(LayerWorker) * threadNumber);

    int counter = 0;

    for (int i = 0; i < threadNumber; i++) {
        // prepare worker args
        layerWorkerArray[i].startWeight = counter;
        layerWorkerArray[i].endWeight = layerWorkerArray[i].startWeight + div - 1;
        if (rem > 0) {
            layerWorkerArray[i].endWeight += 1;
            rem--;
        }
        layerWorkerArray[i].layer = layer;
        layerWorkerArray[i].input = input;
        layerWorkerArray[i].output = output;

        counter = layerWorkerArray[i].endWeight + 1;

        // create and start thread worker
        pthread_create(&threadArray[i], NULL, layer_compute_worker, &layerWorkerArray[i]);
    }

    // make worker finish
    for (int i = 0; i < threadNumber; i++)
        pthread_join(threadArray[i], NULL);

    free(layerWorkerArray);

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