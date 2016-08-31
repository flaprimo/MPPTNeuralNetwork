#include <stdlib.h>
#include "neuralnet.h"

/**
 * Given the number of inputs, it returns a NeuralNet struct.
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
    List *layerList = neuralNet->layerList;

    while (layerList) {
        Layer *currentLayer = (Layer *) layerList->info;

        // compute the weighted sum
        input = layer_weightedSum(input, currentLayer); // the new input is the output

        // apply the activation function
        layer_activationFunction(input, currentLayer);

        layerList = layerList->next;
    }

    return input;
}

/**
 * Frees NeuralNet struct.
 * @param neuralnet
 */
void neuralnet_free(NeuralNet *neuralnet)
{
    list_removeAll(&neuralnet->layerList, layer_freeVoidPointer);
    free(neuralnet->layerList);
    free(neuralnet);
}