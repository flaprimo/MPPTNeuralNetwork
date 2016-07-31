#include "../unity/unity_fixture.h"
#include "../../src/pvpanelnn/pvpanelNN.h"

TEST_GROUP(pvpanelNNTest);

/*
 * FIXTURES
 */
PvPanelNN *pvpanelNN;

// run before each test
TEST_SETUP(pvpanelNNTest)
{
    pvpanelNN = pvpanelNN_get();
}

// run after each test
TEST_TEAR_DOWN(pvpanelNNTest)
{
    pvpanelNN_free(pvpanelNN);
}

/*
 * UNIT TESTS
 */
TEST(pvpanelNNTest, pvpanelNN_getTest)
{
    // input
    TEST_ASSERT_EQUAL(pvpanelNN->inputLength, 3);

    TEST_ASSERT_EQUAL(pvpanelNN->minInput[0], 750.5);
    TEST_ASSERT_EQUAL(pvpanelNN->minInput[1], 2.83892709347493);
    TEST_ASSERT_EQUAL(pvpanelNN->minInput[2], 263);

    TEST_ASSERT_EQUAL(pvpanelNN->maxInput[0], 1578.8);
    TEST_ASSERT_EQUAL(pvpanelNN->maxInput[1], 569.413757050536);
    TEST_ASSERT_EQUAL(pvpanelNN->maxInput[2], 363);

    // output
    TEST_ASSERT_EQUAL(pvpanelNN->outputLength, 1);

    TEST_ASSERT_EQUAL(pvpanelNN->minOutput[0], 782.16);

    TEST_ASSERT_EQUAL(pvpanelNN->maxOutput[0], 1403.6);
}

TEST(pvpanelNNTest, pvpanelNN_normalizeInputTest)
{
    double *input = malloc(sizeof(double) * pvpanelNN->inputLength);
    input[0] = 977.581807425645;
    input[1] = 391.935856999970;
    input[2] = 342.475382369526;

    double *inputN = pvpanelNN_normalizeInput(pvpanelNN, input);
    TEST_ASSERT_EQUAL(inputN[0], -0.450816101772092);
    TEST_ASSERT_EQUAL(inputN[1], 0.373505878953302);
    TEST_ASSERT_EQUAL(inputN[2], 0.589507647390516);

    free(input);
}

TEST(pvpanelNNTest, pvpanelNN_normalizeOutputTest)
{
    double *output = malloc(sizeof(double) * pvpanelNN->outputLength);
    output[0] = -0.3734;

    double *outputN = pvpanelNN_normalizeOutput(pvpanelNN, output);
    TEST_ASSERT_EQUAL(outputN[0], 976.8660);

    free(output);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(pvpanelNNTest)
{
    RUN_TEST_CASE(pvpanelNNTest, pvpanelNN_getTest);
    RUN_TEST_CASE(pvpanelNNTest, pvpanelNN_normalizeInputTest);
    RUN_TEST_CASE(pvpanelNNTest, pvpanelNN_normalizeOutputTest);
}