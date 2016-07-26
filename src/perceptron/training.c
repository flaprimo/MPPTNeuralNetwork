#include "training.h"
#include "perceptron.h"

/**
 * Given a perceptron and a training data, it returns the trained perceptron.
 * @param p perceptron that has to be trained
 * @param trainingData train data to train the perceptron
 */
void training_trainPerceptron(struct perceptron *p, training *trainingData)
{
    // ERROR = DESIRED OUTPUT - OUTPUT
    double error = trainingData->desiredOutput - perceptron_feedForward(p, trainingData->desiredInputs);

    for (int i = 0; i < p->weightsLength; i++) {
        // NEW WEIGHT = WEIGHT + ERROR * INPUT * LEARNING CONSTANT
        p->weights[i] = p->weights[i] + error * trainingData->desiredInputs[i] * trainingData->learningConstant;
    }
}

/**
 * Given a perceptron and a training data, it returns the perceptron trained to recognise the training data ("beware of overtraining").
 * @param p
 * @param trainingData
 */
void training_trainPerceptronForced(struct perceptron *p, training *trainingData)
{
    double error = trainingData->desiredOutput - perceptron_feedForward(p, trainingData->desiredInputs);

    if (error != 0) {
        training_trainPerceptron(p, trainingData);
        training_trainPerceptronForced(p, trainingData);
    }
}

/**
 * Given a perceptron and a training data set, it returs the trained perceptron.
 * @param p
 * @param trainingSet
 */
void training_trainPerceptronSet(struct perceptron *p, list *trainingSet)
{
    if (trainingSet) {
        training_trainPerceptron(p, trainingSet->info);
        training_trainPerceptronSet(p, trainingSet->next);
    }
}