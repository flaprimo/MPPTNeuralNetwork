//
// Neural networks weight.
//
#include "transferFunc.h"

#ifndef MPPTNEURALNETWORK_WEIGHT_H
#define MPPTNEURALNETWORK_WEIGHT_H

typedef struct weight_t {
    int rowLength;
    int columnLength;
    double **weightArray;

    double *bias;

    double (*transferFunction)(double);
} Weight;

Weight *weight_get(int rowLength, int columnLength, TransferFunc_type transferFunction);
double *weight_weightedSum(double *input, Weight* weight);
void weight_free(Weight *weight);
void weight_freeVoidPointer(void *weightVoidPointer);
void weight_print(Weight *weight);

#endif //MPPTNEURALNETWORK_WEIGHT_H
