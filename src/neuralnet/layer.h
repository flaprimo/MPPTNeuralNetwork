//
// Neural networks layer.
//
#include "transferFunc.h"

#ifndef MPPTNEURALNETWORK_LAYER_H
#define MPPTNEURALNETWORK_LAYER_H

typedef struct layer_t {
    int rowLength;
    int columnLength;
    double *weightArray;

    double *bias;

    double (*transferFunction)(double);
} Layer;

typedef struct layerWorkerArgs_t {
    int startWeight;
    int endWeight;

    Layer *layer;

    double *input;
    double *output;
} LayerWorkerArgs;

Layer *layer_get(int rowLength, int columnLength, double *weightArray, double *biasArray, TransferFunc_type transferFunction);
double *layer_compute(double *input, Layer *layer);
double *layer_computeMT(double *input, Layer *layer);
Layer *layer_importFile(char *layerFilePath);
void layer_free(Layer **layer);
void layer_print(Layer *layer);

#endif //MPPTNEURALNETWORK_LAYER_H
