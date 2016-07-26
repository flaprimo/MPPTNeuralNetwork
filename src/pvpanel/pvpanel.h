//
// Defines Photovoltaic Panel
//

#ifndef MPPTNEURALNETWORK_PVPANEL_H
#define MPPTNEURALNETWORK_PVPANEL_H

#include "pvpanelSpec.h"

typedef struct pvPanel {
    struct pvPanelSpec *pvpanelSpec;

    long double vCurr;
    long double iCurr;
} pvPanel;

pvPanel *pvpanel_get(double vCurr, pvPanelSpec *pvpanelSpec);
void pvpanel_print(pvPanel *pvpanel);

#endif //MPPTNEURALNETWORK_PVPANEL_H