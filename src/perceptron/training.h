#ifndef MPPTNEURALNETWORK_TRAINING_H
#define MPPTNEURALNETWORK_TRAINING_H

#include "../helper/list.h"
#include "perceptron.h"

typedef struct training {
    double *desiredInputs;
    double desiredOutput;
    double learningConstant;
} training;


void training_trainPerceptron(struct perceptron *p, training *trainingData);
void training_trainPerceptronSet(struct perceptron *p, list *trainingSet);

#endif //MPPTNEURALNETWORK_TRAINING_H
