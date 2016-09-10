#ifndef MPPTNEURALNETWORK_PVPANELNN_H
#define MPPTNEURALNETWORK_PVPANELNN_H

#include "pvpanel.h"
#include "../neuralnet/neuralnet.h"

typedef struct pvPanelNN_t {
    PvPanel *pvpanel;
    NeuralNet *neuralNet;

    int simulationLength; // taken from Matlab file "AG1.txt" length
    double *irradianceArray; // taken from Matlab file "AG1.txt"
    double *temperatureArray; // taken from Matlab variable "T_test" after a complete simulation

    double *mppVoltageArray; // taken from Matlab variable "Vmp" after a complete simulation
    double *mppCurrentArray; // taken from Matlab variable "Imp" after a complete simulation
} PvPanelNN;

PvPanelNN *pvpanelNN_get(int simulationLength, double *irradianceArray, double *temperatureArray,
                         double *mppVoltageArray, double *mppCurrentArray);
PvPanelNN *pvpanelNN_importFile(char *pvpanelNNFilePath);
void pvpanelNN_simulate(PvPanelNN *pvPanelNN);
void pvpanelNN_free(PvPanelNN *pvpanelNN);
void pvpanelNN_print(PvPanelNN *pvpanelNN);

#endif //MPPTNEURALNETWORK_PVPANELNN_H
