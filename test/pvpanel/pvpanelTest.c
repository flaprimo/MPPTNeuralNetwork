#include "../unity/unity_fixture.h"
#include "../../src/pvpanel/pvpanel.h"

TEST_GROUP(pvpanelTest);

/*
 * FIXTURES
 */

// run before each test
TEST_SETUP(pvpanelTest)
{
}

// run after each test
TEST_TEAR_DOWN(pvpanelTest)
{
}

/*
 * UNIT TESTS
 */
TEST(pvpanelTest, pvpanel_getTest)
{
    PvPanel *pvpanel = pvpanel_get(1100);

    TEST_ASSERT_EQUAL(pvpanel->q, 1.602E-19);
    TEST_ASSERT_EQUAL(pvpanel->k, 1.3806503E-23);

    TEST_ASSERT_EQUAL(pvpanel->tRef, 298.2);
    TEST_ASSERT_EQUAL(pvpanel->gRef, 1000);
    TEST_ASSERT_EQUAL(pvpanel->ioRef, 3.797E-9);
    TEST_ASSERT_EQUAL(pvpanel->irRef, 8.312);
    TEST_ASSERT_EQUAL(pvpanel->rsRef, 0.005);
    TEST_ASSERT_EQUAL(pvpanel->rpRef, 39.487);
    TEST_ASSERT_EQUAL(pvpanel->nRef, 1.101);
    TEST_ASSERT_EQUAL(pvpanel->egRef, 1.9818e-19);
    TEST_ASSERT_EQUAL(pvpanel->alpha, 0.00559);

    TEST_ASSERT_EQUAL(pvpanel->gRef, 1000);
    TEST_ASSERT_EQUAL(pvpanel->tRef, 298.2);

    TEST_ASSERT_EQUAL(pvpanel->nS, 2460);
    TEST_ASSERT_EQUAL(pvpanel->nP, 45);

    TEST_ASSERT_EQUAL(pvpanel->n, 1.101);
    TEST_ASSERT_EQUAL(pvpanel->rs, 0.273333333333333);
    TEST_ASSERT_EQUAL(pvpanel->rp, 2.158622666666667e+03);
    TEST_ASSERT_EQUAL(pvpanel->eg, 1.981811518148876e-19);
    TEST_ASSERT_EQUAL(pvpanel->io, 1.708650000000000e-07);
    TEST_ASSERT_EQUAL(pvpanel->irr, 3.740400000000000e+02);

    TEST_ASSERT_EQUAL(pvpanel->vCurr, 1100);
    TEST_ASSERT_EQUAL(pvpanel->iCurr, 368.190213257631);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(pvpanelTest)
{
    RUN_TEST_CASE(pvpanelTest, pvpanel_getTest);
}