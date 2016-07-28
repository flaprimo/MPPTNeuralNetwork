//
// NeuralNet
//

#ifndef MPPTNEURALNETWORK_NEURALNET_H
#define MPPTNEURALNETWORK_NEURALNET_H

typedef struct neuralNet {
    double *input;

    double *firstWeights;
    double *secondWeights;

    double output;
} neuralNet;

neuralNet *neuralnet_get();

#endif //MPPTNEURALNETWORK_NEURALNET_H
