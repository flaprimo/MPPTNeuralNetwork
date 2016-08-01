#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "neuralnet.h"

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
    List *weightList = neuralNet->weights;

    while (weightList) {
        Weight *currentWeight = (Weight *) weightList->info;

        // compute the weighted sum
        input = weight_weightedSum(input, currentWeight); // the new input is the output

        // apply activation function
        for (int i = 0; i < currentWeight->columnLength; i++)
            input[i] = currentWeight->transferFunction(input[i] + currentWeight->bias[i]);



        weightList = weightList->next;
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