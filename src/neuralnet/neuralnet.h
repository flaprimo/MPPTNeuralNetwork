//
// NeuralNet
//

#ifndef MPPTNEURALNETWORK_NEURALNET_H
#define MPPTNEURALNETWORK_NEURALNET_H

#include "../helper/list.h"
#include "layer.h"

typedef struct neuralNet_t {
    int inputLength;
    double *minInput;
    double *maxInput;

    int outputLength;
    double *minOutput;
    double *maxOutput;

    int layerLength;
    Layer *layerArray;

    List *layerList;
} NeuralNet;

NeuralNet *neuralnet_get(int inputLength, double *minInput, double *maxInput, int outputLength, double *minOutput,
                         double *maxOutput, int layerLength, Layer *layerArray);
NeuralNet *neuralnet_importFile(char *neuralnetFilePath);
double *neuralnet_compute(double *input, NeuralNet *neuralNet);
void neuralnet_free(NeuralNet *neuralnet);

#endif //MPPTNEURALNETWORK_NEURALNET_H
