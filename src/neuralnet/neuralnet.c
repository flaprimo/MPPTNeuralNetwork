#include <stdlib.h>
#include <math.h>
#include "neuralnet.h"

const int INPUT_NUMBER = 3;
const int PERCEPTRON_NUMBER = 25;

/**
 * Sigmoid function. Used as the activation function.
 * @param x
 * @return
 */
long double neuralnet_sigmoid(long double x)
{
    return 1 / (1 + expl(-x));
}

/**
 * Create a neural network.
 * @return
 */
neuralNet *neuralnet_get()
{
    neuralNet *neuralnet = malloc(sizeof(neuralNet));

    neuralnet->input = malloc(sizeof(double) * INPUT_NUMBER);
    neuralnet->firstWeights = malloc(sizeof(double) * PERCEPTRON_NUMBER * INPUT_NUMBER);
    neuralnet->secondWeights = malloc(sizeof(double) * PERCEPTRON_NUMBER);
    neuralnet->output = 0;

    return neuralnet;
}