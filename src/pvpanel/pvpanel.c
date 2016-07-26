#include <stdlib.h>
#include <stdio.h>
#include "pvpanel.h"

/* Matlab implementation of the function
function [Ipl] = Pannello(S,V)

    % Newton-Raphson
    I = 0;

    for ct = 1:50
        F = I-( S.Irr - S.I0.*(exp(S.q./S.k./S.T./S.n./S.Ns.*(V+I.*S.Rs))-1)-(V+I.*S.Rs)./S.Rp );
        dF = 1 - ( -S.I0*S.q./S.k./S.T./S.n./S.Ns.*S.Rs.*exp(S.q./S.k./S.T./S.n./S.Ns.*(V+I.*S.Rs)) - S.Rs./S.Rp);

        I = I - F./dF;
    end

    Ipl = I;
*/

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel current.
 * @param pvpanel
 * @param vCurr
 * @return
 */
double pvpanel_newtonRaphson(pvPanelSpec *pvpanel, double vCurr)
{
    double iCurr = 0;
    /*int iterations = 50;

    for (int i = 0; i < iterations; i++) {
        f = iCurr - (pvpanel->irr - pvpanel->io);
    }*/

    return iCurr;
}

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel with the current calculated.
 * @param vCurr
 * @param pvpanelSpec
 * @return
 */
pvPanel *pvpanel_get(double vCurr, pvPanelSpec *pvpanelSpec)
{
    pvPanel *pvpanel = malloc(sizeof(pvpanel));

    pvpanel->pvpanelSpec = pvpanelSpec;
    pvpanel->vCurr = vCurr;
    pvpanel->iCurr = pvpanel_newtonRaphson(pvpanelSpec, pvpanel->vCurr);

    return pvpanel;
}

/**
 * Prints the photovoltaic panel.
 * @param pvpanel
 */
void pvpanel_print(pvPanel *pvpanel)
{
    printf("pvPanel {\n");

    printf("  pvpanelSpec: [...]\n");
    printf("  vCurr: %f\n", pvpanel->vCurr);
    printf("  iCurr: %f\n", pvpanel->iCurr);

    printf("}\n\n");
}