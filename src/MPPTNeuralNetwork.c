#include <stdio.h>
#include <stdlib.h>
#include "perceptron/training.h"
#include "perceptron/perceptron.h"
#include "pvpanel/pvpanelSpec.h"
#include "pvpanel/pvpanel.h"
#include "neuralnet/weight.h"

int main()
{
    /*
     * Create Perceptron
     */
    int inputLength = 5;

    // create perceptron
    struct perceptron *p = malloc(sizeof(struct perceptron));

    p->weights = malloc(sizeof(double) * inputLength);
    p->weights[0] = 1;
    p->weights[1] = 1;
    p->weights[2] = 1;
    p->weights[3] = 1;
    p->weights[4] = 1;

    p->weightsLength = inputLength;

    // print created perceptron
    printf("Without training:\n");
    perceptron_print(p);

    /*
     * Create inputs
     */
    // create inputs
    double *inputs = malloc(sizeof(double) * inputLength);
    inputs[0] = 0;
    inputs[1] = 0;
    inputs[2] = 0;
    inputs[3] = 0;
    inputs[4] = 0;

    /*
     * Get feed forward computation without training
     */
    printf("Feed forward result without training: %d\n\n", perceptron_feedForward(p, inputs));

    /*
     * Train perceptron
     */
    // create training set1
    training *trainData1 = malloc(sizeof(training));

    trainData1->desiredInputs = malloc(sizeof(double) * inputLength);
    trainData1->desiredInputs[0] = 1;
    trainData1->desiredInputs[1] = 3;
    trainData1->desiredInputs[2] = 20;
    trainData1->desiredInputs[3] = 5;
    trainData1->desiredInputs[4] = 7;

    trainData1->desiredOutput = -1;

    trainData1->learningConstant = 0.5;

    // create training set1
    training *trainData2 = malloc(sizeof(training));

    trainData2->desiredInputs = malloc(sizeof(double) * inputLength);
    trainData2->desiredInputs[0] = 2;
    trainData2->desiredInputs[1] = 5;
    trainData2->desiredInputs[2] = 4;
    trainData2->desiredInputs[3] = 9;
    trainData2->desiredInputs[4] = 0;

    trainData2->desiredOutput = 1;

    trainData2->learningConstant = 0.2;

    // create training data set
    List *trainingSet = NULL;
    list_addFirst(&trainingSet, trainData1);
    list_addFirst(&trainingSet, trainData2);

    // train perceptron's weights
    training_trainPerceptronSet(p, trainingSet);

    // print trained perceptron
    printf("With training:\n");
    perceptron_print(p);

    /*
     * Get feed forward computation with training
     */
    printf("Feed forward result with training: %d\n\n", perceptron_feedForward(p, inputs));

    /*
     * PORTING MATLAB ALGORITHM
     */

    /*
     * get pvpanelSpec and print it
     */
    PvPanelSpec *pvpanelSpec = pvpanelSpec_get();
    pvpanelSpec_print(pvpanelSpec);

    /*
     * Create weights and print them
     */

    // create weight1 Weight
    Weight *weight1 = weight_get(3, 5);

    // print weight1
    weight_print(weight1);

    // initialize weight1Matrix array
    for (int i = 0; i < weight1->rowLength; i++)
        for (int j = 0; j < weight1->columnLength; j++)
            weight1->matrix[i][j] = 1;

    // print weight1
    weight_print(weight1);

    // initialize matrix
    for (int i = 0; i < weight1->rowLength; i++)
        for (int j = 0; j < weight1->columnLength; j++)
            weight1->matrix[i][j] = 1;

    // create and initialize input matrix
    double *input = malloc(sizeof(double) * weight1->rowLength);
    input[0] = 1;
    input[1] = 2;
    input[2] = 3;

    // compute weighted sum
    double *output = weight_weightedSum(input, weight1);

    // check output
    for (int i = 0; i < weight1->columnLength; i++)
        printf("%f ", output[i]);

    // free resources
    free(input);
    free(output);
}