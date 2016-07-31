#include "unity/unity_fixture.h"

static void RunAllTests(void)
{
    // helper
    RUN_TEST_GROUP(listTest);

    // neuralnet
    RUN_TEST_GROUP(weightTest);
    RUN_TEST_GROUP(neuralnetTest);

    // pvpanel
    RUN_TEST_GROUP(pvpanelSpecTest);
    RUN_TEST_GROUP(pvpanelTest);

    // pvpanelnn
    RUN_TEST_GROUP(pvpanelNNTest);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}