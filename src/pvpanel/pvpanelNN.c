#include <stdlib.h>
#include "pvpanelNN.h"

PvPanelNN *pvpanelNN_get()
{
    PvPanelNN *pvpanelNN = malloc(sizeof(PvPanelNN));

    pvpanelNN->pvpanel = pvpanel_get(1100);
    pvpanelNN->neuralNet = neuralnet_importFile("../res/default.nnconf");

    return pvpanelNN;
}

/**
 * Frees pvpanelNN struct.
 * @param pvpanelNN
 */
void pvpanelNN_free(PvPanelNN *pvpanelNN)
{
    pvpanel_free(pvpanelNN->pvpanel);
    neuralnet_free(pvpanelNN->neuralNet);
    free(pvpanelNN);
}