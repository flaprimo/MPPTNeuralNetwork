//
// NeuralNet
//

#ifndef MPPTNEURALNETWORK_NEURALNET_H
#define MPPTNEURALNETWORK_NEURALNET_H

#include "../helper/list.h"
#include "weight.h"

typedef struct neuralNet_t {
    int inputLength;
    List *weights;
} NeuralNet;

NeuralNet *neuralnet_get(int inputLength);
double *neuralnet_compute(double *input, NeuralNet *neuralNet);
void neuralnet_free(NeuralNet *neuralnet);

#endif //MPPTNEURALNETWORK_NEURALNET_H
