#include <stdlib.h>
#include <stdio.h>
#include "weight.h"

/**
 * Given rowNumber, columnNumber, it returns a weight object.
 * @param rowNumber
 * @param columnNumber
 * @param matrix
 * @return
 */
Weight *weight_get(int rowNumber, int columnNumber)
{
    Weight *weight = malloc(sizeof(Weight));

    weight->rowNumber = rowNumber;
    weight->columnNumber = columnNumber;
    weight->matrix = malloc(sizeof(double *) * rowNumber);
    for (int i = 0; i < rowNumber; i++)
        weight->matrix[i] = calloc((unsigned int) columnNumber, sizeof(double)); // unsigned

    return weight;
}

void weight_delete(Weight *weight)
{
    for (int i = 0; i < weight->rowNumber; i++)
        free(weight->matrix[i]);

    free(weight->matrix);
    free(weight);
}

/**
 * Prints the weight.
 * @param weight
 */
void weight_print(Weight *weight)
{
    printf("Weight {\n");

    printf("  rowNumber: %d\n", weight->rowNumber);
    printf("  columnNumber: %d\n", weight->columnNumber);

    printf("  matrix: {\n");
    for (int i = 0; i < weight->rowNumber; i++) {
        printf("    | ");
        for (int j = 0; j < weight->columnNumber; j++)
            printf("%f ", weight->matrix[i][j]);
        printf("|\n");
    }
    printf("  }\n");

    printf("}\n\n");
}