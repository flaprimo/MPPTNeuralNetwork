#include "../unity/unity_fixture.h"
#include "../../src/neuralnet/transferFunc.h"

TEST_GROUP(transferFuncTest);

/*
 * FIXTURES
 */

// run before each test
TEST_SETUP(transferFuncTest)
{
}

// run after each test
TEST_TEAR_DOWN(transferFuncTest)
{
}

/*
 * UNIT TESTS
 */
TEST(transferFuncTest, transferFunc_getTest)
{
    TransferFunction sigmoidFunc = transferFunc_get(SIGMOID);
    TEST_ASSERT_EQUAL(-1, sigmoidFunc(-90));

    TransferFunction linearFunc = transferFunc_get(LINEAR);
    TEST_ASSERT_EQUAL(-90, linearFunc(-90));
}

TEST(transferFuncTest, transferFunc_stringToEnumTypeTest)
{
    TEST_ASSERT_EQUAL(SIGMOID, transferFunc_stringToEnumType("SIGMOID"));
    TEST_ASSERT_EQUAL(LINEAR, transferFunc_stringToEnumType("LINEAR"));
    TEST_ASSERT_EQUAL(LINEAR, transferFunc_stringToEnumType("ASsdbw83"));
}

TEST(transferFuncTest, transferFunc_linearTest)
{
    TEST_ASSERT_EQUAL(0, transferFunc_linear(0));
    TEST_ASSERT_EQUAL(-90, transferFunc_linear(-90));
    TEST_ASSERT_EQUAL(5.4, transferFunc_linear(5.4));
}

TEST(transferFuncTest, transferFunc_sigmoidTest)
{
    TEST_ASSERT_EQUAL(0, transferFunc_sigmoid(0));
    TEST_ASSERT_EQUAL(-1, transferFunc_sigmoid(-90));
    TEST_ASSERT_EQUAL(1, transferFunc_sigmoid(100.7));
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(transferFuncTest)
{
    RUN_TEST_CASE(transferFuncTest, transferFunc_getTest);
    RUN_TEST_CASE(transferFuncTest, transferFunc_stringToEnumTypeTest);
    RUN_TEST_CASE(transferFuncTest, transferFunc_linearTest);
    RUN_TEST_CASE(transferFuncTest, transferFunc_sigmoidTest);
}