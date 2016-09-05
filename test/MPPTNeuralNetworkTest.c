#include "unity/unity_fixture.h"

static void RunAllTests(void)
{
    // helper
    RUN_TEST_GROUP(listTest);

    // neuralnet
    RUN_TEST_GROUP(layerTest);
    RUN_TEST_GROUP(transferFuncTest);
    RUN_TEST_GROUP(neuralnetTest);

    // pvpanel
    RUN_TEST_GROUP(pvpanelSpecTest);
    RUN_TEST_GROUP(pvpanelTest);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}