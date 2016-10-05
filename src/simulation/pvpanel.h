//
// Defines Photovoltaic Panel
//

#ifndef MPPTNEURALNETWORK_PVPANEL_H
#define MPPTNEURALNETWORK_PVPANEL_H

typedef struct pvPanel_t {
    double q;
    double k;

    double tRef;
    double gRef;
    double ioRef;
    double irRef;
    double rsRef;
    double rpRef;
    double nRef;
    double egRef;
    double alpha;

    double g;
    double t;

    double nS;
    double nP;

    double n;
    double rs;
    double rp;
    double eg;
    double io;
    double irr;

    double vCurr;
    double iCurr;
} PvPanel;

PvPanel *pvpanel_get(double vCurr);
double pvpanel_newtonRaphson(PvPanel *pvpanel, double vCurr);
void pvpanel_update(double temperature, double irradiance, PvPanel *pvpanel);
void pvpanel_free(PvPanel **pvpanel);
void pvpanel_print(PvPanel *pvpanel);

#endif //MPPTNEURALNETWORK_PVPANEL_H