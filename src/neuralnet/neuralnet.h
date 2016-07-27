//
// NeuralNet
//

#ifndef MPPTNEURALNETWORK_NEURALNET_H
#define MPPTNEURALNETWORK_NEURALNET_H

typedef struct neuralNet {
    long double *input;

    long double *firstWeights;
    long double *secondWeights;

    long double output;
} neuralNet;

neuralNet *neuralnet_get();
long double neuralnet_compute(neuralNet *neuralnet);

#endif //MPPTNEURALNETWORK_NEURALNET_H
