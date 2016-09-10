#ifndef MPPTNEURALNETWORK_SIMULATION_H
#define MPPTNEURALNETWORK_SIMULATION_H

#include "pvpanel.h"
#include "../neuralnet/neuralnet.h"

typedef struct simulation_t {
    PvPanel *pvpanel;
    NeuralNet *neuralNet;

    int simulationLength; // taken from Matlab file "AG1.txt" length
    double *irradianceArray; // taken from Matlab file "AG1.txt"
    double *temperatureArray; // taken from Matlab variable "T_test" after a complete simulation

    double *mppVoltageArray; // taken from Matlab variable "Vmp" after a complete simulation
    double *mppCurrentArray; // taken from Matlab variable "Imp" after a complete simulation
} Simulation;

Simulation *simulation_get(PvPanel *pvPanel, NeuralNet *neuralNet, int simulationLength, double *irradianceArray,
                           double *temperatureArray, double *mppVoltageArray, double *mppCurrentArray);
Simulation *simulation_importFile(char *simulationFilePath);
void simulation_simulate(Simulation *simulation);
void simulation_free(Simulation **simulation);
void simulation_print(Simulation *simulation);

#endif //MPPTNEURALNETWORK_SIMULATION_H