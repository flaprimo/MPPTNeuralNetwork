#include <stdlib.h>
#include "../unity/unity_fixture.h"
#include "../../src/helper/list.h"

TEST_GROUP(listTest);

/*
 * HELPER FUNCTIONS
 */
void freeIntPointer(void *integerVoidPointer)
{
    if (integerVoidPointer != NULL)
        free((int *)integerVoidPointer);
}

/*
 * FIXTURES
 */
List *l1;

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
    list_removeAll(&l1, freeIntPointer);
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

TEST(listTest, list_removeTest)
{
    list_remove(&l1, 2, freeIntPointer);
    TEST_ASSERT_EQUAL(11, *(int *)list_get(l1, 0));

    list_remove(&l1, 1, freeIntPointer);
    TEST_ASSERT_EQUAL(11, *(int *)list_get(l1, 0));

    list_remove(&l1, 0, freeIntPointer);
    TEST_ASSERT_NULL(list_get(l1, 0));
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(listTest)
{
    RUN_TEST_CASE(listTest, list_getTest);
    RUN_TEST_CASE(listTest, list_removeTest);
}