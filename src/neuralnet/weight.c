#include <stdlib.h>
#include <stdio.h>
#include "weight.h"

/**
 * Given rowNumber, columnNumber, it returns a weight object.
 * @param rowLength
 * @param columnLength
 * @param matrix
 * @return
 */
Weight *weight_get(int rowLength, int columnLength)
{
    Weight *weight = malloc(sizeof(Weight));

    weight->rowLength = rowLength;
    weight->columnLength = columnLength;
    weight->matrix = malloc(sizeof(double *) * rowLength);
    for (int i = 0; i < rowLength; i++)
        weight->matrix[i] = calloc((unsigned int) columnLength, sizeof(double)); // unsigned

    return weight;
}

/**
 * Given an input array and a Weight struct, it returns the weighted sum beetween input and weights.
 * @param input array length is equal to rowLength of the Weight struct.
 * @param weight array with the length equal to columnLength of the Weight struct.
 * @return
 */
double *weight_weightedSum(double *input, Weight* weight)
{
    double *output = calloc((unsigned int) weight->columnLength, sizeof(double));

    for (int i = 0; i < weight->rowLength; i++)
        for (int j = 0; j < weight->columnLength; j++)
            output[j] += input[i] * weight->matrix[i][j];

    return output;
}

/**
 * Frees Weight struct.
 * @param weight
 */
void weight_free(Weight *weight)
{
    for (int i = 0; i < weight->rowLength; i++)
        free(weight->matrix[i]);

    free(weight->matrix);
    free(weight);
}

/**
 * Frees Weight struct passed as a void pointer. Use if weight are used in a list.
 * @param weightVoidPointer
 */
void weight_freeVoidPointer(void *weightVoidPointer)
{
    if (weightVoidPointer != NULL)
        weight_free((Weight *) weightVoidPointer);
}

/**
 * Prints the weight.
 * @param weight
 */
void weight_print(Weight *weight)
{
    printf("Weight {\n");

    printf("  rowLength: %d\n", weight->rowLength);
    printf("  columnLength: %d\n", weight->columnLength);

    printf("  matrix: {\n");
    for (int i = 0; i < weight->rowLength; i++) {
        printf("    | ");
        for (int j = 0; j < weight->columnLength; j++)
            printf("%f ", weight->matrix[i][j]);
        printf("|\n");
    }
    printf("  }\n");

    printf("}\n\n");
}