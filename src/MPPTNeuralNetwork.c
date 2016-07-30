#include <stdio.h>
#include <stdlib.h>
#include "pvpanel/pvpanelSpec.h"
#include "pvpanel/pvpanel.h"
#include "neuralnet/weight.h"

int main()
{
    /*
     * get pvpanelSpec and print it
     */
    PvPanelSpec *pvpanelSpec = pvpanelSpec_get();
    pvpanelSpec_print(pvpanelSpec);

    /*
     * Create weights and print them
     */

    // create weight1 Weight
    Weight *weight1 = weight_get(3, 5);

    // print weight1
    weight_print(weight1);

    // initialize weight1Matrix array
    for (int i = 0; i < weight1->rowLength; i++)
        for (int j = 0; j < weight1->columnLength; j++)
            weight1->matrix[i][j] = 1;

    // print weight1
    weight_print(weight1);

    // initialize matrix
    for (int i = 0; i < weight1->rowLength; i++)
        for (int j = 0; j < weight1->columnLength; j++)
            weight1->matrix[i][j] = 1;

    // create and initialize input matrix
    double *input = malloc(sizeof(double) * weight1->rowLength);
    input[0] = 1;
    input[1] = 2;
    input[2] = 3;

    // compute weighted sum
    double *output = weight_weightedSum(input, weight1);

    // check output
    for (int i = 0; i < weight1->columnLength; i++)
        printf("%f ", output[i]);

    // free resources
    free(input);
    free(output);
}