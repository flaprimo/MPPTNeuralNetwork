#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/layer.h"

TEST_GROUP(layerTest);

/*
 * FIXTURES
 */
Layer *layer1;

// run before each test
TEST_SETUP(layerTest)
{
    int rowLength = 2;
    int columnLength = 6;

    double *weightArray = malloc(sizeof(double) * rowLength * columnLength);
    for (int i = 0; i < rowLength * columnLength; i++)
        weightArray[i] = i;

    double *biasArray = malloc(sizeof(double) * columnLength);
    for (int i = 0; i < columnLength; i++)
        biasArray[i] = i + 20;

    TransferFunc_type transferFuncType = SIGMOID;

    // create layer1
    layer1 = layer_get(rowLength, columnLength, weightArray, biasArray, transferFuncType);
}

// run after each test
TEST_TEAR_DOWN(layerTest)
{
    free(layer1->weightArray);
    free(layer1->bias);
    //layer_free(layer1);
}

/*
 * UNIT TESTS
 */
TEST(layerTest, layer_getTest)
{
    TEST_ASSERT_EQUAL(2, layer1->rowLength);
    TEST_ASSERT_EQUAL(6, layer1->columnLength);

    for (int i = 0; i < layer1->rowLength * layer1->columnLength; i++)
        TEST_ASSERT_EQUAL(i, layer1->weightArray[i]);

    for (int i = 0; i < layer1->columnLength; i++)
        TEST_ASSERT_EQUAL(i + 20, layer1->bias[i]);

    TEST_ASSERT_EQUAL(transferFunc_get(SIGMOID), layer1->transferFunction);
}

TEST(layerTest, layer_computeTest)
{
    double *input = malloc(sizeof(double) * layer1->rowLength);
    input[0] = -1000;
    input[1] = 1;

    double *output = layer_compute(input, layer1);

    TEST_ASSERT_EQUAL(1, output[0]);
    for (int i = 1; i < layer1->columnLength; i++)
        TEST_ASSERT_EQUAL(-1, output[i]);

    free(input);
}

TEST(layerTest, layer_computeMTTest)
{
    double *input = malloc(sizeof(double) * layer1->rowLength);
    input[0] = -1000;
    input[1] = 1;

    double *output = layer_computeMT(input, layer1);

    TEST_ASSERT_EQUAL(1, output[0]);
    for (int i = 1; i < layer1->columnLength; i++)
        TEST_ASSERT_EQUAL(-1, output[i]);

    free(input);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(layerTest)
{
    RUN_TEST_CASE(layerTest, layer_getTest);
    RUN_TEST_CASE(layerTest, layer_computeTest);
    RUN_TEST_CASE(layerTest, layer_computeMTTest);
}