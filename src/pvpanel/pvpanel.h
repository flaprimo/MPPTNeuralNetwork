#ifndef MPPTNEURALNETWORK_PVPANEL_H
#define MPPTNEURALNETWORK_PVPANEL_H

typedef struct pvPanel {
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
    double eg;
    long double io;
    double irr;

    double vCurr;
    double iCurr;
} pvPanel;

pvPanel *pvpanel_get();
void pvpanel_print(pvPanel *pvpanel);

#endif //MPPTNEURALNETWORK_PVPANEL_H