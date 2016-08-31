//
// Defines Photovoltaic Panel Build Specifications
//

#ifndef MPPTNEURALNETWORK_PVPANELSPEC_H
#define MPPTNEURALNETWORK_PVPANELSPEC_H

typedef struct pvPanelSpec_t {
    long double q;
    long double k;

    double tRef;
    double gRef;
    long double ioRef;
    double irRef;
    double rsRef;
    double rpRef;
    double nRef;
    long double egRef;
    double alpha;

    double g;
    double t;

    double nS;
    double nP;

    double n;
    double rs;
    double rp;
    long double eg;
    long double io;
    double irr;
} PvPanelSpec;

PvPanelSpec *pvpanelSpec_get();
void pvpanelSpec_free(PvPanelSpec *pvpanelSpec);
void pvpanelSpec_print(PvPanelSpec *pvpanelSpec);

#endif //MPPTNEURALNETWORK_PVPANELSPEC_H