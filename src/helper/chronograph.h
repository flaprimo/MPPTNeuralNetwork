#ifndef MPPTNEURALNETWORK_CHRONOGRAPH_H
#define MPPTNEURALNETWORK_CHRONOGRAPH_H

typedef struct chronograph_t {
    double startTime;
} Chronograph;

Chronograph *chronograph_get();
double chronograph_getDelta(Chronograph *chronograph);
void chronograph_free(Chronograph *chronograph);

#endif //MPPTNEURALNETWORK_CHRONOGRAPH_H
