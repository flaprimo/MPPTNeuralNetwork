#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/neuralnet.h"
#include "../../src/neuralnet/layer.h"

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