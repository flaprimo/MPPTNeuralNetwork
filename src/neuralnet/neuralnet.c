#include <stdlib.h>
#include <math.h>
#include "neuralnet.h"

/**
 * Sigmoid function. Used as the activation function.
 * @param x
 * @return
 */
double neuralnet_sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

/**
 * Given the number of inputs, it returns a NeuralNet struct.
 * Weights are defined as bidimensional arrays.
 * @param inputLength
 * @return
 */
NeuralNet *neuralnet_get(int inputLength)
{
    NeuralNet *neuralNet = malloc(sizeof(NeuralNet));

    neuralNet->inputLength = inputLength;

    return neuralNet;
}

/**
 * Given a NeuralNet struct and an input, it returns the result of the neuralnet computation.
 * @param input
 * @param neuralNet
 * @return
 */
double *neuralnet_compute(double *input, NeuralNet *neuralNet)
{
    List *currentWeightList = neuralNet->weights;

    while (currentWeightList) {
        // compute the weighted sum
        input = weight_weightedSum(input, (Weight *) currentWeightList->info); // the new input is the output

        // apply activation function
        for (int i = 0; i < ((Weight *) currentWeightList->info)->columnLength; i++)
            input[i] = neuralnet_sigmoid(input[i]);

        currentWeightList = currentWeightList->next;
    }

    return input;
}

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