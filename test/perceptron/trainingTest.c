#include <stdlib.h>
#include "../unity/unity_fixture.h"
#include "../../src/perceptron/training.h"
#include "../../src/perceptron/training.c"

TEST_GROUP(trainingTest);

/*
 * FIXTURES
 */
struct perceptron *p;
training *t1;
int inputLength;

// run before each test
TEST_SETUP(trainingTest)
{
    inputLength = 5;

    // create perceptron
    p = malloc(sizeof(struct perceptron));

    p->weights = malloc(sizeof(double) * inputLength);
    p->weights[0] = 1;
    p->weights[1] = 1;
    p->weights[2] = 1;
    p->weights[3] = 1;
    p->weights[4] = 1;

    p->weightsLength = inputLength;

    // create training
    t1 = malloc(sizeof(training));

    t1->desiredInputs = malloc(sizeof(double) * inputLength);
    t1->desiredInputs[0] = 1;
    t1->desiredInputs[1] = 1;
    t1->desiredInputs[2] = 1;
    t1->desiredInputs[3] = 1;
    t1->desiredInputs[4] = 1;

    t1->desiredOutput = 1;

    t1->learningConstant = 0.5;
}

// run after each test
TEST_TEAR_DOWN(trainingTest)
{
    free(p->weights);
    free(p);
    free(t1->desiredInputs);
    free(t1);
}

/*
 * UNIT TESTS
 */
TEST(trainingTest, training_trainPerceptron)
{
    // training with already optimal result
    training_trainPerceptron(p, t1);

    for (int i = 0; i < inputLength; i++)
        TEST_ASSERT_EQUAL(1, p->weights[i]);

    // training without optimal result
    t1->desiredOutput = -1;
    training_trainPerceptron(p, t1);

    for (int i = 0; i < inputLength; i++)
        TEST_ASSERT_EQUAL(0, p->weights[i]);
}

/*
 * TESTS RUNNER
 */
TEST_GROUP_RUNNER(trainingTest)
{
    RUN_TEST_CASE(trainingTest, training_trainPerceptron);
}
