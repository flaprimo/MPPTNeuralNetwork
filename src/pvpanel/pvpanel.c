#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pvpanel.h"

const int NEWTON_RAPHSON_ITERATIONS = 50;

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel current.
 * @param pvpanelSpec
 * @param vCurr
 * @return
 */
double pvpanel_newtonRaphson(PvPanelSpec *pvpanelSpec, double vCurr)
{
    double iCurr = 0;

    for (int i = 0; i < NEWTON_RAPHSON_ITERATIONS; i++) {

        long double f = iCurr - (pvpanelSpec->irr - pvpanelSpec->io *
                (expl(pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS * (vCurr + iCurr * pvpanelSpec->rs)) - 1) -
                (vCurr + iCurr * pvpanelSpec->rs) / pvpanelSpec->rp);
        long double dF = 1 - (-pvpanelSpec->io * pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS *
                expl(pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS * (vCurr + iCurr * pvpanelSpec->rs)) -
                pvpanelSpec->rs / pvpanelSpec->rp);

        iCurr = (double) (iCurr - f / dF);
    }

    return iCurr;
}

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel with the current calculated.
 * @param vCurr
 * @param pvpanelSpec
 * @return
 */
PvPanel *pvpanel_get(double vCurr, PvPanelSpec *pvpanelSpec)
{
    PvPanel *pvpanel = malloc(sizeof(PvPanel));

    pvpanel->pvpanelSpec = pvpanelSpec;
    pvpanel->vCurr = vCurr;
    pvpanel->iCurr = pvpanel_newtonRaphson(pvpanelSpec, pvpanel->vCurr);

    return pvpanel;
}

/**
 * Prints the photovoltaic panel.
 * @param pvpanel
 */
void pvpanel_print(PvPanel *pvpanel)
{
    printf("PvPanel {\n");

    printf("  pvpanelSpec: [...]\n");
    printf("  vCurr: %f\n", pvpanel->vCurr);
    printf("  iCurr: %f\n", pvpanel->iCurr);

    printf("}\n\n");
}