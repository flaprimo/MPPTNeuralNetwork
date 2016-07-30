#include "../unity/unity_fixture.h"
#include "../../src/pvpanel/pvpanelSpec.h"

TEST_GROUP(pvpanelSpecTest);

/*
 * FIXTURES
 */

// run before each test
TEST_SETUP(pvpanelSpecTest)
{
}

// run after each test
TEST_TEAR_DOWN(pvpanelSpecTest)
{
}

/*
 * UNIT TESTS
 */
TEST(pvpanelSpecTest, pvpanelSpec_getTest)
{
    PvPanelSpec *pvpanelSpec = pvpanelSpec_get();

    TEST_ASSERT_EQUAL(pvpanelSpec->q, 1.602E-19);
    TEST_ASSERT_EQUAL(pvpanelSpec->k, 1.3806503E-23);

    TEST_ASSERT_EQUAL(pvpanelSpec->tRef, 298.2);
    TEST_ASSERT_EQUAL(pvpanelSpec->gRef, 1000);
    TEST_ASSERT_EQUAL(pvpanelSpec->ioRef, 3.797E-9);
    TEST_ASSERT_EQUAL(pvpanelSpec->irRef, 8.312);
    TEST_ASSERT_EQUAL(pvpanelSpec->rsRef, 0.005);
    TEST_ASSERT_EQUAL(pvpanelSpec->rpRef, 39.487);
    TEST_ASSERT_EQUAL(pvpanelSpec->nRef, 1.101);
    TEST_ASSERT_EQUAL(pvpanelSpec->egRef, 1.9818e-19);
    TEST_ASSERT_EQUAL(pvpanelSpec->alpha, 0.00559);

    TEST_ASSERT_EQUAL(pvpanelSpec->gRef, 1000);
    TEST_ASSERT_EQUAL(pvpanelSpec->tRef, 298.2);

    TEST_ASSERT_EQUAL(pvpanelSpec->nS, 2460);
    TEST_ASSERT_EQUAL(pvpanelSpec->nP, 45);

    TEST_ASSERT_EQUAL(pvpanelSpec->n, 1.101);
    TEST_ASSERT_EQUAL(pvpanelSpec->rs, 0.273333333333333);
    TEST_ASSERT_EQUAL(pvpanelSpec->rp, 2.158622666666667e+03);
    TEST_ASSERT_EQUAL(pvpanelSpec->eg, 1.981811518148876e-19);
    TEST_ASSERT_EQUAL(pvpanelSpec->io, 1.708650000000000e-07);
    TEST_ASSERT_EQUAL(pvpanelSpec->irr, 3.740400000000000e+02);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(pvpanelSpecTest)
{
    RUN_TEST_CASE(pvpanelSpecTest, pvpanelSpec_getTest);
}