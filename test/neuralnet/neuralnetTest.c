#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/neuralnet.h"
#include "../../src/neuralnet/weight.h"

TEST_GROUP(neuralnetTest);

/*
 * FIXTURES
 */

// run before each test
TEST_SETUP(neuralnetTest)
{
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