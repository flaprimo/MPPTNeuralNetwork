#include "unity/unity_fixture.h"
#include "helper/listTest.c"
#include "neuralnet/weightTest.c"
#include "neuralnet/neuralnetTest.c"

static void RunAllTests(void)
{
    // helper
    RUN_TEST_GROUP(listTest);

    // neuralnet
    RUN_TEST_GROUP(weightTest);
    RUN_TEST_GROUP(neuralnetTest);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}