#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/neuralnet.h"

TEST_GROUP(neuralnetTest);

/*
 * FIXTURES
 */
NeuralNet *neuralNet1;

// run before each test
TEST_SETUP(neuralnetTest)
{
    neuralNet1 = neuralnet_importFile("../res/default.nnconf");
}

// run after each test
TEST_TEAR_DOWN(neuralnetTest)
{
}

/*
 * UNIT TESTS
 */
TEST(neuralnetTest, neuralnet_compute)
{
    double *input = malloc(sizeof(double) * 3);
    input[0] = 976.866035758628; // V
    input[1] = 392.167166311451; // I
    input[2] = 342.621019067798; // T

    double *output = neuralnet_compute(input, neuralNet1);

    TEST_ASSERT_EQUAL(976.164177, output[0]);

    free(input);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(neuralnetTest)
{
    RUN_TEST_CASE(neuralnetTest, neuralnet_compute);
}