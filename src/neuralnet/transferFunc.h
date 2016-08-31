//
// Transfer functions for neural networks
//

#ifndef MPPTNEURALNETWORK_TRANSFERFUNC_H
#define MPPTNEURALNETWORK_TRANSFERFUNC_H

typedef enum {LINEAR, SIGMOID} TransferFunc_type;

typedef double (*TransferFunction)(double);

TransferFunction transferFunc_get(TransferFunc_type type);
TransferFunc_type transferFunc_stringToEnumType(char *typeString);
double transferFunc_linear(double x);
double transferFunc_sigmoid(double x);

#endif //MPPTNEURALNETWORK_TRANSFERFUNC_H
