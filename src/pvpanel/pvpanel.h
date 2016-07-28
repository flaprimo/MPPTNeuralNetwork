//
// Defines Photovoltaic Panel
//

#ifndef MPPTNEURALNETWORK_PVPANEL_H
#define MPPTNEURALNETWORK_PVPANEL_H

#include "pvpanelSpec.h"

typedef struct pvPanel_t {
    PvPanelSpec *pvpanelSpec;

    double vCurr;
    double iCurr;
} PvPanel;

PvPanel *pvpanel_get(double vCurr, PvPanelSpec *pvpanelSpec);
void pvpanel_print(PvPanel *pvpanel);

#endif //MPPTNEURALNETWORK_PVPANEL_H