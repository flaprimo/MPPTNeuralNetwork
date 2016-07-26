#include <stdlib.h>
#include "../unity/unity_fixture.h"
#include "../../src/helper/list.h"
#include "../../src/helper/list.c"

TEST_GROUP(listTest);

/*
 * FIXTURES
 */
list *l1;

// run before each test
TEST_SETUP(listTest)
{
    //create list
    l1 = NULL;

    // create and add 1st element
    int *i1 = malloc(sizeof(int));
    *i1 = 10;
    list_addFirst(&l1, i1);

    // create and add 2nd element
    int *i2 = malloc(sizeof(int));
    *i2 = 11;
    list_addFirst(&l1, i2);
}

// run after each test
TEST_TEAR_DOWN(listTest)
{
    list_removeFirst(&l1);
    list_removeFirst(&l1);
}

/*
 * UNIT TESTS
 */
TEST(listTest, list_getTest)
{
    TEST_ASSERT_EQUAL(11, *(int *)list_get(l1, 0));
    TEST_ASSERT_EQUAL(10, *(int *)list_get(l1, 1));
    TEST_ASSERT_NULL(list_get(l1, 2));
    TEST_ASSERT_NULL(list_get(l1, 3));
}

TEST(listTest, list_removeFirstTest)
{
    list_removeFirst(&l1);
    TEST_ASSERT_EQUAL(10, *(int *)list_get(l1, 0));

    list_removeFirst(&l1);
    TEST_ASSERT_NULL(list_get(l1, 0));
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(listTest)
{
    RUN_TEST_CASE(listTest, list_getTest);
    RUN_TEST_CASE(listTest, list_removeFirstTest);
}
