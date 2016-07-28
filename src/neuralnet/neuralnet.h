//
// NeuralNet
//

#ifndef MPPTNEURALNETWORK_NEURALNET_H
#define MPPTNEURALNETWORK_NEURALNET_H

#include "../helper/list.h"

typedef struct neuralNet_t {
    int inputNumber;
    List *weights;
} NeuralNet;

NeuralNet *neuralnet_get(int inputNumber, List *weights);

#endif //MPPTNEURALNETWORK_NEURALNET_H
