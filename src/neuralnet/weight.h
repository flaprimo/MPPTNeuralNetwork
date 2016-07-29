//
// Neural networks weight.
//

#ifndef MPPTNEURALNETWORK_WEIGHT_H
#define MPPTNEURALNETWORK_WEIGHT_H

typedef struct weight_t {
    int rowLength;
    int columnLength;

    double **matrix;
} Weight;

Weight *weight_get(int rowLength, int columnLength);
double *weight_weightedSum(double *input, Weight* weight);
void weight_free(Weight *weight);
void weight_freeVoidPointer(void *weightVoidPointer);
void weight_print(Weight *weight);

#endif //MPPTNEURALNETWORK_WEIGHT_H
