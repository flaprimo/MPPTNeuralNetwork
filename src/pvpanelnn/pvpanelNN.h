#ifndef MPPTNEURALNETWORK_PVPANELNN_H
#define MPPTNEURALNETWORK_PVPANELNN_H

#include "../pvpanel/pvpanel.h"
#include "../neuralnet/neuralnet.h"

typedef struct pvPanelNN_t {
    PvPanel *pvpanel;
    NeuralNet *neuralNet;
} PvPanelNN;

PvPanelNN *pvpanelNN_get();
void pvpanelNN_free(PvPanelNN *pvpanelNN);

#endif //MPPTNEURALNETWORK_PVPANELNN_H
