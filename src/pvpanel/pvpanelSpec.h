//
// Defines Photovoltaic Panel Build Specifications
//

#ifndef MPPTNEURALNETWORK_PVPANELSPEC_H
#define MPPTNEURALNETWORK_PVPANELSPEC_H

typedef struct pvPanelSpec {
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
} pvPanelSpec;

pvPanelSpec *pvpanelSpec_get();
void pvpanelSpec_print(pvPanelSpec *pvpanelSpec);

#endif //MPPTNEURALNETWORK_PVPANELSPEC_H