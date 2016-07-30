#include "../unity/unity_fixture.h"
#include "../../src/pvpanel/pvpanelSpec.h"
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
    PvPanel *pvpanel = pvpanel_get(1100, pvpanelSpec_get());

    TEST_ASSERT_EQUAL(pvpanel->iCurr, 368.190213257631);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(pvpanelTest)
{
    RUN_TEST_CASE(pvpanelTest, pvpanel_getTest);
}