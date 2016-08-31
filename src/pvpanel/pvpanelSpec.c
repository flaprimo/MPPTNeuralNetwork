#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "pvpanelSpec.h"

/**
 * Given a temperature in Celsius it returns the temperature in Kelvin.
 * @param temperature_celsius
 * @return
 */
double pvpanelSpec_convertCelsiusToKelvin(double temperature_celsius)
{
    return temperature_celsius + 273.2 /* Kelvin constant */;
}

/**
 * Returns specifications for a default photovoltaic panel.
 * @return
 */
PvPanelSpec *pvpanelSpec_get()
{
    PvPanelSpec *pvpanelSpec = malloc(sizeof(PvPanelSpec));

    pvpanelSpec->q = 1.602E-19;
    pvpanelSpec->k = 1.3806503E-23;

    pvpanelSpec->tRef = pvpanelSpec_convertCelsiusToKelvin(25);
    pvpanelSpec->gRef = 1000;
    pvpanelSpec->ioRef = 3.797E-9;
    pvpanelSpec->irRef = 8.312;
    pvpanelSpec->rsRef = 0.005;
    pvpanelSpec->rpRef = 39.487;
    pvpanelSpec->nRef = 1.101;
    pvpanelSpec->egRef = (1.16 - 7.02E-4 * (pow(pvpanelSpec->tRef, 2) / (pvpanelSpec->tRef - 1108))) * 1.602E-19;
    pvpanelSpec->alpha = 0.00559;

    pvpanelSpec->g = pvpanelSpec->gRef;
    pvpanelSpec->t = pvpanelSpec->tRef;

    pvpanelSpec->nS = 60 * 41;
    pvpanelSpec->nP = 45;

    pvpanelSpec->n = pvpanelSpec->nRef;
    pvpanelSpec->rs = pvpanelSpec->rsRef * pvpanelSpec->nS / pvpanelSpec->nP;
    pvpanelSpec->rp = pvpanelSpec->rpRef * pvpanelSpec->g / pvpanelSpec->gRef * pvpanelSpec->nS / pvpanelSpec-> nP;
    pvpanelSpec->eg = (1.16 - 7.02E-4 * (pow(pvpanelSpec->t, 2) / (pvpanelSpec->t - 1108))) * 1.602E-19;
    pvpanelSpec->io = pvpanelSpec->ioRef * pow(pvpanelSpec->t / pvpanelSpec->tRef, 3) *
            expl(pvpanelSpec->egRef / pvpanelSpec->k / pvpanelSpec->tRef - pvpanelSpec->eg / pvpanelSpec->k / pvpanelSpec->t) * pvpanelSpec->nP;
    pvpanelSpec->irr = pvpanelSpec->irRef * pvpanelSpec->g / pvpanelSpec->gRef * (1 + pvpanelSpec->alpha * (pvpanelSpec->t - pvpanelSpec->tRef)) * pvpanelSpec->nP;

    return pvpanelSpec;
}

void pvpanelSpec_free(PvPanelSpec *pvpanelSpec)
{
    free(pvpanelSpec);
}

/**
 * Prints the photovoltaic panel specifications.
 * @param pvpanelSpec
 */
void pvpanelSpec_print(PvPanelSpec *pvpanelSpec)
{
    printf("PvPanelSpec {\n");

    printf("  q: %Le\n", pvpanelSpec->q);
    printf("  k: %Le\n\n", pvpanelSpec->k);

    printf("  tRef: %f\n", pvpanelSpec->tRef);
    printf("  gRef: %f\n", pvpanelSpec->gRef);
    printf("  ioRef: %Le\n", pvpanelSpec->ioRef);
    printf("  irRef: %f\n", pvpanelSpec->irRef);
    printf("  rsRef: %f\n", pvpanelSpec->rsRef);
    printf("  rRef: %f\n", pvpanelSpec->rpRef);
    printf("  nRef: %f\n", pvpanelSpec->nRef);
    printf("  egRef: %Le\n", pvpanelSpec->egRef);
    printf("  alpha: %f\n\n", pvpanelSpec->alpha);

    printf("  g: %f\n", pvpanelSpec->g);
    printf("  t: %f\n\n", pvpanelSpec->t);

    printf("  nS: %f\n", pvpanelSpec->nS);
    printf("  nP: %f\n\n", pvpanelSpec->nP);

    printf("  n: %f\n", pvpanelSpec->n);
    printf("  rs: %f\n", pvpanelSpec->rs);
    printf("  rp: %f\n", pvpanelSpec->rp);
    printf("  eg: %Le\n", pvpanelSpec->eg);
    printf("  io: %Le\n", pvpanelSpec->io);
    printf("  irr: %f\n", pvpanelSpec->irr);

    printf("}\n\n");
}