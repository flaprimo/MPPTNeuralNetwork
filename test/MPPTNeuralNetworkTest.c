#include "unity/unity_fixture.h"
#include "helper/listTest.c"
#include "perceptron/perceptronTest.c"
#include "perceptron/trainingTest.c"
#include "neuralnet/weightTest.c"
#include "neuralnet/neuralnetTest.c"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(listTest);
    RUN_TEST_GROUP(perceptronTest);
    RUN_TEST_GROUP(trainingTest);
    RUN_TEST_GROUP(weightTest);
    RUN_TEST_GROUP(neuralnetTest);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}