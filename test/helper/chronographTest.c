#include "../unity/unity_fixture.h"
#include "../../src/helper/chronograph.h"

TEST_GROUP(chronographTest);

/*
 * FIXTURES
 */

// run before each test
TEST_SETUP(chronographTest)
{
}

// run after each test
TEST_TEAR_DOWN(chronographTest)
{
}

/*
 * UNIT TESTS
 */
TEST(chronographTest, chronograph_getTest)
{
    Chronograph *chronograph = chronograph_get();

    chronograph_getDelta(chronograph);
    TEST_ASSERT_TRUE(chronograph_getDelta(chronograph) > 0);

    chronograph_free(&chronograph);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(chronographTest)
{
    RUN_TEST_CASE(chronographTest, chronograph_getTest);
}

