#include <stdlib.h>
#include "../unity/unity_fixture.h"
#include "../../src/perceptron/perceptron.h"
#include "../../src/perceptron/perceptron.c"

TEST_GROUP(perceptronTest);

/*
 * FIXTURES
 */
// run before each test
TEST_SETUP(perceptronTest)
{
}

// run after each test
TEST_TEAR_DOWN(perceptronTest)
{
}

/*
 * UNIT TESTS
 */
TEST(perceptronTest, perceptron_getRandomWeight)
{
    int attemptsNumber = 10;

    for (int i = 0; i < attemptsNumber; i++) {
        int attempt = perceptron_getRandomWeight();

        if(attempt == 1 || attempt == -1)
            TEST_ASSERT_EQUAL(0, 0); // pass test
        else
            TEST_ASSERT_EQUAL(0, 1); // fail test
    }
}

TEST(perceptronTest, perceptron_getWeights)
{
    int inputLength = 10;
    double *weights = perceptron_getWeights(inputLength);

    for (int i = 0; i < inputLength; i++) {
        if (weights[i] == 1 || weights[i] == -1)
            TEST_ASSERT_EQUAL(0, 0); // pass test
        else
            TEST_ASSERT_EQUAL(0, 1); // fail test
    }

    free(weights);
}

TEST(perceptronTest, perceptron_activate)
{
    TEST_ASSERT_EQUAL(1, perceptron_activate(1));
    TEST_ASSERT_EQUAL(1, perceptron_activate(10));

    TEST_ASSERT_EQUAL(-1, perceptron_activate(0));
    TEST_ASSERT_EQUAL(-1, perceptron_activate(-1));
    TEST_ASSERT_EQUAL(-1, perceptron_activate(-10));
}

TEST(perceptronTest, perceptron_get)
{
    int inputLength = 10;
    struct perceptron *p = perceptron_get(inputLength);

    TEST_ASSERT_EQUAL(inputLength, p->weightsLength);
    TEST_ASSERT_NOT_NULL(p->weights);

    for (int i = 0; i < inputLength; i++) {
        if (p->weights[i] == 1 || p->weights[i] == -1)
            TEST_ASSERT_EQUAL(0, 0); // pass test
        else
            TEST_ASSERT_EQUAL(0, 1); // fail test
    }

    free(p->weights);
    free(p);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(perceptronTest)
{
    RUN_TEST_CASE(perceptronTest, perceptron_getRandomWeight);
    RUN_TEST_CASE(perceptronTest, perceptron_getWeights);
    RUN_TEST_CASE(perceptronTest, perceptron_activate);
    RUN_TEST_CASE(perceptronTest, perceptron_get);
}
