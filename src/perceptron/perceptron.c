#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "perceptron.h"
/**
 * Given a perceptron, it prints its informations.
 * @param p
 */
void perceptron_print(struct perceptron *p) {
    printf("Perceptron\n");
    printf("  - weightsLength: %d\n", p->weightsLength);
    printf("  - weights:       ");
    for (int i = 0; i < p->weightsLength; i++)
        printf("%f ", p->weights[i]);
    printf("\n\n");
}

/**
 * Randomize seed for rand() function.
 */
void perceptron_randomizeSeed()
{
    static int called = 0;

    if (!called) { // make sure it is called only once
        srand((unsigned) time(NULL));
        called = 1;
    }
}

/**
 * Returns random +1 and -1 weights.
 * @return
 */
int perceptron_getRandomWeight()
{
    perceptron_randomizeSeed();
    int randomNumber = rand() % 2;
    int weight;

    if (randomNumber > 0)
        weight = 1;
    else
        weight = -1;

    return weight;
}

/**
 * Given the number of inputs, creates a weight array randomly created.
 * @param inputLength number of inputs of the perceptron
 * @return
 */
double *perceptron_getWeights(int inputLength)
{
    double *weights = malloc(sizeof(double) * inputLength);

    for (int i = 0; i < inputLength; i++)
        weights[i] = perceptron_getRandomWeight();

    return weights;
}

/**
 * Given the sum of a feedForward operation, it returns if the NN was activated.
 * @param sum the result of a feedForward operation
 * @return
 */
int perceptron_activate(double sum)
{
    int activation;

    if (sum > 0)
        activation = 1;
    else
        activation = -1;

    return activation;
}

/**
 * Given the input length, it returns a new perceptron with random weights and a default learning constant.
 * @param inputLength number of input that the perceptron will be fed with
 * @return
 */
struct perceptron *perceptron_get(int inputLength)
{
    struct perceptron *newPerceptron = malloc(sizeof(struct perceptron));

    newPerceptron->weights = perceptron_getWeights(inputLength);
    newPerceptron->weightsLength = inputLength;

    return newPerceptron;
}

/**
 * Given an input array and its length it returns the result of a feedForward operation.
 * FeedForward operation multiplies every input with every weight and gives back the sum of such operations.
 * @param inputs an array of input to be computed by the perceptron
 * @param inputLength number of inputs of the perceptron
 * @return
 */
int perceptron_feedForward(struct perceptron *p, double *inputs)
{
    double sum = 0;

    for (int i = 0; i < p->weightsLength; i++)
        sum += inputs[i] * p->weights[i];

    return perceptron_activate(sum);
}