#ifndef MPPTNEURALNETWORK_PERCEPTRON_H
#define MPPTNEURALNETWORK_PERCEPTRON_H

struct perceptron {
    double *weights;
    int weightsLength;
};

void perceptron_print(struct perceptron *p);
int perceptron_feedForward(struct perceptron *p, double *inputs);
struct perceptron *perceptron_get(int inputLength);

#endif //MPPTNEURALNETWORK_PERCEPTRON_H
