#include <math.h>
#include <string.h>
#include "transferFunc.h"

/**
 * Given a transfer function type, it returns the corresponding function as a pointer.
 * @param type
 * @return
 */
TransferFunction transferFunc_get(TransferFunc_type type)
{
    switch (type) {
        case LINEAR: return transferFunc_linear;
        case SIGMOID: return transferFunc_sigmoid;
        default: return transferFunc_linear;
    }
}

/**
 * Given a string, it returns the corresponding transfer function type.
 * @param typeString
 * @return
 */
TransferFunc_type transferFunc_stringToEnumType(char *typeString)
{
    if (strcmp(typeString, "SIGMOID") == 0)
        return SIGMOID;
    else if (strcmp(typeString, "LINEAR") == 0)
        return LINEAR;
    else
        return LINEAR;
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