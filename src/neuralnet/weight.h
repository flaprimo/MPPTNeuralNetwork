//
// Neural networks weight.
//

#ifndef MPPTNEURALNETWORK_WEIGHT_H
#define MPPTNEURALNETWORK_WEIGHT_H

typedef struct weight_t {
    int rowNumber;
    int columnNumber;

    double **matrix;
} Weight;

Weight *weight_get(int rowNumber, int columnNumber);
void weight_free(Weight *weight);
void weight_freeVoidPointer(void *weightVoidPointer);
void weight_print(Weight *weight);

#endif //MPPTNEURALNETWORK_WEIGHT_H
