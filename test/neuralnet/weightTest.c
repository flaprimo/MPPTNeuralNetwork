#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/weight.h"
#include "../../src/neuralnet/weight.c"

TEST_GROUP(weightTest);

/*
 * FIXTURES
 */
Weight *weight1;

// run before each test
TEST_SETUP(weightTest)
{
    //create weight
    weight1 = weight_get(3, 5);
}

// run after each test
TEST_TEAR_DOWN(weightTest)
{
    weight_delete(weight1);
}

/*
 * UNIT TESTS
 */
TEST(weightTest, weight_getTest)
{
    // check array default initialization
    for (int i = 0; i < weight1->rowNumber; i++)
        for (int j = 0; j < weight1->columnNumber; j++)
            TEST_ASSERT_EQUAL(weight1->matrix[i][j], 0);

    // check array initialization
    for (int i = 0; i < weight1->rowNumber; i++)
        for (int j = 0; j < weight1->columnNumber; j++) {
            weight1->matrix[i][j] = 1;
            TEST_ASSERT_EQUAL(weight1->matrix[i][j], 1);
        }

    // check array single
    weight1->matrix[2][3] = 2.4;
    weight1->matrix[0][1] = 5.01;

    for (int i = 0; i < weight1->rowNumber; i++)
        for (int j = 0; j < weight1->columnNumber; j++) {
            if (i == 2 && j == 3)
                TEST_ASSERT_EQUAL(weight1->matrix[i][j], 2.4);
            else if (i == 0 && j == 1)
                TEST_ASSERT_EQUAL(weight1->matrix[i][j], 5.01);
            else
                TEST_ASSERT_EQUAL(weight1->matrix[i][j], 1);
        }
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(weightTest)
{
    RUN_TEST_CASE(weightTest, weight_getTest);
}