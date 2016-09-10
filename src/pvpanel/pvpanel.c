#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pvpanel.h"

const int NEWTON_RAPHSON_ITERATIONS = 50;

/**
 * Given a temperature in Celsius it returns the temperature in Kelvin.
 * @param temperature_celsius
 * @return
 */
double pvpanel_convertCelsiusToKelvin(double temperature_celsius)
{
    return temperature_celsius + 273.2 /* Kelvin constant */;
}

/**
 * Given a tension and a photovoltaic panel specification it returns the photovoltaic panel current.
 * @param pvpanel
 * @param vCurr
 * @return
 */
double pvpanel_newtonRaphson(PvPanel *pvpanel, double vCurr)
{
    double iCurr = 0;

    for (int i = 0; i < NEWTON_RAPHSON_ITERATIONS; i++) {

        long double f = iCurr - (pvpanel->irr - pvpanel->io *
                (expl(pvpanel->q / pvpanel->k / pvpanel->t / pvpanel->n / pvpanel->nS * (vCurr + iCurr * pvpanel->rs)) - 1) -
                (vCurr + iCurr * pvpanel->rs) / pvpanel->rp);
        long double dF = 1 - (-pvpanel->io * pvpanel->q / pvpanel->k / pvpanel->t / pvpanel->n / pvpanel->nS *
                expl(pvpanel->q / pvpanel->k / pvpanel->t / pvpanel->n / pvpanel->nS * (vCurr + iCurr * pvpanel->rs)) -
                pvpanel->rs / pvpanel->rp);

        iCurr = (double) (iCurr - f / dF);
    }

    return iCurr;
}

/**
 * Given a voltage it returns a photovoltaic panel with the current calculated.
 * @param vCurr
 * @return
 */
PvPanel *pvpanel_get(double vCurr)
{
    PvPanel *pvpanel = malloc(sizeof(PvPanel));

    pvpanel->q = 1.602E-19;
    pvpanel->k = 1.3806503E-23;

    pvpanel->tRef = pvpanel_convertCelsiusToKelvin(25);
    pvpanel->gRef = 1000;
    pvpanel->ioRef = 3.797E-9;
    pvpanel->irRef = 8.312;
    pvpanel->rsRef = 0.005;
    pvpanel->rpRef = 39.487;
    pvpanel->nRef = 1.101;
    pvpanel->egRef = (1.16 - 7.02E-4 * (pow(pvpanel->tRef, 2) / (pvpanel->tRef - 1108))) * 1.602E-19;
    pvpanel->alpha = 0.00559;

    pvpanel->nS = 60 * 41;
    pvpanel->nP = 45;

    pvpanel_update(pvpanel->tRef, pvpanel->gRef, pvpanel);

    pvpanel->vCurr = vCurr;
    pvpanel->iCurr = pvpanel_newtonRaphson(pvpanel, pvpanel->vCurr);

    return pvpanel;
}

void pvpanel_update(double temperature, double irradiance, PvPanel *pvpanel)
{
    pvpanel->g = irradiance;
    pvpanel->t = temperature;

    pvpanel->n = pvpanel->nRef;
    pvpanel->rs = pvpanel->rsRef * pvpanel->nS / pvpanel->nP;
    pvpanel->rp = pvpanel->rpRef * pvpanel->g / pvpanel->gRef * pvpanel->nS / pvpanel-> nP;
    pvpanel->eg = (1.16 - 7.02E-4 * (pow(pvpanel->t, 2) / (pvpanel->t - 1108))) * 1.602E-19;
    pvpanel->io = pvpanel->ioRef * pow(pvpanel->t / pvpanel->tRef, 3) *
            expl(pvpanel->egRef / pvpanel->k / pvpanel->tRef - pvpanel->eg / pvpanel->k / pvpanel->t) * pvpanel->nP;
    pvpanel->irr = pvpanel->irRef * pvpanel->g / pvpanel->gRef * (1 + pvpanel->alpha * (pvpanel->t - pvpanel->tRef)) * pvpanel->nP;
}

void pvpanel_free(PvPanel *pvpanel)
{
    free(pvpanel);
}

/**
 * Prints the photovoltaic panel.
 * @param pvpanel
 */
void pvpanel_print(PvPanel *pvpanel)
{
    printf("PvPanel {\n");

    printf("  q: %Le\n", pvpanel->q);
    printf("  k: %Le\n\n", pvpanel->k);

    printf("  tRef: %f\n", pvpanel->tRef);
    printf("  gRef: %f\n", pvpanel->gRef);
    printf("  ioRef: %Le\n", pvpanel->ioRef);
    printf("  irRef: %f\n", pvpanel->irRef);
    printf("  rsRef: %f\n", pvpanel->rsRef);
    printf("  rpRef: %f\n", pvpanel->rpRef);
    printf("  nRef: %f\n", pvpanel->nRef);
    printf("  egRef: %Le\n", pvpanel->egRef);
    printf("  alpha: %f\n\n", pvpanel->alpha);

    printf("  g: %f\n", pvpanel->g);
    printf("  t: %f\n\n", pvpanel->t);

    printf("  nS: %f\n", pvpanel->nS);
    printf("  nP: %f\n\n", pvpanel->nP);

    printf("  n: %f\n", pvpanel->n);
    printf("  rs: %f\n", pvpanel->rs);
    printf("  rp: %f\n", pvpanel->rp);
    printf("  eg: %Le\n", pvpanel->eg);
    printf("  io: %Le\n", pvpanel->io);
    printf("  irr: %f\n\n", pvpanel->irr);

    printf("  vCurr: %f\n", pvpanel->vCurr);
    printf("  iCurr: %f\n\n", pvpanel->iCurr);
    printf("}\n\n");
}