#include <stdlib.h>
#include <math.h>
#include "neuralnet.h"

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
 * Given the number of inputs and an ordered list containing weights.
 * Weights are defined as bidimensional arrays.
 * @return
 */
NeuralNet *neuralnet_get(int inputLength, List *weights)
{
    NeuralNet *neuralNet = malloc(sizeof(NeuralNet));

    neuralNet->inputLength = inputLength;
    neuralNet->weights = weights;

    return neuralNet;
}

/*double *neuralnet_compute(double *input, NeuralNet neuralNet)
{

}*/

/**
 * Frees NeuralNet struct.
 * @param neuralnet
 */
void neuralnet_free(NeuralNet *neuralnet)
{
    list_removeAll(&neuralnet->weights, weight_freeVoidPointer);
    free(neuralnet->weights);
    free(neuralnet);
}