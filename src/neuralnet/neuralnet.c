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

    neuralnet->input = malloc(sizeof(long double) * INPUT_NUMBER);
    neuralnet->firstWeights = malloc(sizeof(double) * PERCEPTRON_NUMBER * INPUT_NUMBER);
    neuralnet->secondWeights = malloc(sizeof(double) * PERCEPTRON_NUMBER);
    neuralnet->output = 0;

    return neuralnet;
}

long double *weightedSum(long double *array1, long double *array2, int array1Length, int array2Length)
{
    long double *result = malloc(sizeof(long double) * (array2Length / array1Length));

    for (int i = 0; i < array2Length; i++)
        for (int j = 0; j < array1Length; j++)
            result[i] += array1[j] * array2[i];

    return result;
}

/**
 * Compute the neural network.
 * @param neuralnet
 */
long double neuralnet_compute(neuralNet *neuralnet)
{
    long double output = 0;
    long double *firstWeightsResults = malloc(sizeof(long double) * PERCEPTRON_NUMBER);

    firstWeightsResults = weightedSum(neuralnet->input, neuralnet->firstWeights, INPUT_NUMBER, PERCEPTRON_NUMBER * INPUT_NUMBER);

    weightedSum(firstWeightsResults, neuralnet->secondWeights, PERCEPTRON_NUMBER, PERCEPTRON_NUMBER);


    free(firstWeightsResults);

    return neuralnet_sigmoid(output);
}