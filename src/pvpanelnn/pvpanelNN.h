#ifndef MPPTNEURALNETWORK_PVPANELNN_H
#define MPPTNEURALNETWORK_PVPANELNN_H

#include "../pvpanel/pvpanel.h"

typedef struct pvPanelNN_t {
    //PvPanel *pvpanel;

    int inputLength;
    double *minInput;
    double *maxInput;

    int outputLength;
    double *minOutput;
    double *maxOutput;
} PvPanelNN;

PvPanelNN *pvpanelNN_get();
double *pvpanelNN_normalizeInput(PvPanelNN *pvpanelNN, double *input);
double *pvpanelNN_normalizeOutput(PvPanelNN *pvpanelNN, double *output);
void pvpanelNN_free(PvPanelNN *pvpanelNN);

#endif //MPPTNEURALNETWORK_PVPANELNN_H
