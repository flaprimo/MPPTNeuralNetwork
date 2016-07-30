#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/neuralnet.h"
#include "../../src/neuralnet/weight.h"

TEST_GROUP(neuralnetTest);

/*
 * FIXTURES
 */
NeuralNet *neuralNet1;
Weight *weight1;
Weight *weight2;

// run before each test
TEST_SETUP(neuralnetTest)
{
    int inputLength = 3;

    // create weight1 and weight2
    weight1 = weight_get(inputLength, 5);
    weight2 = weight_get(1, 1);

    // initialize weight1 and weight2
    for (int i = 0; i < weight1->rowLength; i++)
        for (int j = 0; j < weight1->columnLength; j++)
            weight1->matrix[i][j] = 1;

    for (int i = 0; i < weight2->rowLength; i++)
        for (int j = 0; j < weight2->columnLength; j++)
            weight2->matrix[i][j] = 1;

    // create and initialize neuralNet1
    neuralNet1 = neuralnet_get(inputLength);
    list_addLast(&neuralNet1->weights, weight1);
    list_addLast(&neuralNet1->weights, weight2);

    // create and initialize input
    double *input = malloc(sizeof(double) * inputLength);

    for (int i = 0; i < inputLength; i++)
        input[i] = 1;

    // compute the neural net
    double *output = neuralnet_compute(input, neuralNet1);

    TEST_ASSERT_EQUAL(output[0], 0.721633);

    free(input);
}

// run after each test
TEST_TEAR_DOWN(neuralnetTest)
{
    neuralnet_free(neuralNet1);
}

/*
 * UNIT TESTS
 */
TEST(neuralnetTest, neuralnet_getTest)
{
    TEST_ASSERT_EQUAL(0, 0);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(neuralnetTest)
{
    RUN_TEST_CASE(neuralnetTest, neuralnet_getTest);
}