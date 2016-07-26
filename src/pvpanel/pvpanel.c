#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pvpanel.h"

const int NEWTON_RAPHSON_ITERATIONS = 1;
/* Matlab implementation of the function
function [Ipl] = Pannello(S,V)

% Newton-Raphson
I = 0;
for ct = 1:50

    F = I - (S.Irr - S.I0 .* (exp(S.q ./ S.k ./ S.T ./ S.n ./ S.Ns .* (V + I .* S.Rs)) - 1) - (V + I .* S.Rs) ./ S.Rp);
    dF = 1 - ( -S.I0 * S.q ./ S.k ./ S.T ./ S.n ./ S.Ns .* S.Rs .* exp(S.q ./ S.k ./ S.T ./ S.n ./ S.Ns .* (V + I .* S.Rs)) - S.Rs ./ S.Rp);

    I = I - F ./ dF;
end

Ipl = I;
*/

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel current.
 * @param pvpanelSpec
 * @param vCurr
 * @return
 */
long double pvpanel_newtonRaphson(pvPanelSpec *pvpanelSpec, long double vCurr)
{
    long double iCurr = 0;

    for (int i = 0; i < NEWTON_RAPHSON_ITERATIONS; i++) {

        printf("\n%Le\n", pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS * (vCurr + iCurr * pvpanelSpec->rs));
        long double f = iCurr - (pvpanelSpec->irr - pvpanelSpec->io *
                (expl(pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS * (vCurr + iCurr * pvpanelSpec->rs)) - 1) -
                (vCurr + iCurr * pvpanelSpec->rs) / pvpanelSpec->rp);
        printf("\nf: %Le\n", f);
        long double dF = 1 - (-pvpanelSpec->io * pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS *
                expl(pvpanelSpec->q / pvpanelSpec->k / pvpanelSpec->t / pvpanelSpec->n / pvpanelSpec->nS * (vCurr + iCurr * pvpanelSpec->rs)) -
                pvpanelSpec->rs / pvpanelSpec->rp);
        printf("\ndF: %Le\n", dF);

        iCurr = iCurr - f / dF;
    }

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
    printf("  vCurr: %Le\n", pvpanel->vCurr);
    printf("  iCurr: %Le\n", pvpanel->iCurr);

    printf("}\n\n");
}