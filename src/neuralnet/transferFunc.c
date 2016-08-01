#include <math.h>
#include "transferFunc.h"

TransferFunction transferFunc_get(TransferFunc_type type)
{
    switch (type) {
        case LINEAR: return transferFunc_linear;
        case SIGMOID: return transferFunc_sigmoid;
        default: return transferFunc_linear;
    }
}

/**
 * Linear transfer function.
 * @param x
 * @return
 */
double transferFunc_linear(double x)
{
    return x;
}

/**
 * Sigmoid transfer function.
 * @param x
 * @return
 */
double transferFunc_sigmoid(double x)
{
    return 2 / (1 + exp(-2 * x)) - 1;
}