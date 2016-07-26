#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "pvpanel.h"

double pvpanel_convertCelsiusToKelvin(double temperature_celsius)
{
    return temperature_celsius + 273.2 /* Kelvin constant */;
}

pvPanel *pvpanel_get()
{
    pvPanel *pvpanel = malloc(sizeof(pvpanel));

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

    pvpanel->g = pvpanel->gRef;
    pvpanel->t = pvpanel->tRef;

    pvpanel->nS = 60 * 41;
    pvpanel->nP = 45;

    pvpanel->n = pvpanel->nRef;
    pvpanel->rs = pvpanel->rsRef * pvpanel->nS / pvpanel->nS;
    pvpanel->rp = pvpanel->rpRef * pvpanel->g / pvpanel->gRef * pvpanel->nS / pvpanel-> nP;
    pvpanel->eg = (1.16 - 7.02E-4 * (pow(pvpanel->t, 2) / (pvpanel->t - 1108))) * 1.602E-19;
    pvpanel->io = pvpanel->ioRef * pow(pvpanel->t / pvpanel->tRef, 3) *
            exp(pvpanel->egRef / pvpanel->k / pvpanel->tRef - pvpanel->eg / pvpanel->k / pvpanel->t) * pvpanel->nP;
    pvpanel->irr = pvpanel->irRef * pvpanel->g / pvpanel->gRef * (1 + pvpanel->alpha * (pvpanel->t - pvpanel->tRef)) * pvpanel->nP;

    pvpanel->vCurr = 1100;
    //pvpanel->Pannello(S,Vcurr);

    return pvpanel;
}

void pvpanel_print(pvPanel *pvpanel)
{
    printf("pvPanel {\n");

    printf("  q: %Le\n", pvpanel->q);
    printf("  k: %Le\n", pvpanel->k);

    printf("  tRef: %f\n", pvpanel->tRef);
    printf("  gRef: %f\n", pvpanel->gRef);
    printf("  ioRef: %Le\n", pvpanel->ioRef);
    printf("  irRef: %f\n", pvpanel->irRef);
    printf("  rsRef: %f\n", pvpanel->rsRef);
    printf("  rRef: %f\n", pvpanel->rpRef);
    printf("  nRef: %f\n", pvpanel->nRef);
    printf("  egRef: %Le\n", pvpanel->egRef);
    printf("  alpha: %f\n", pvpanel->alpha);

    printf("  g: %f\n", pvpanel->g);
    printf("  t: %f\n", pvpanel->t);

    printf("  nS: %f\n", pvpanel->nS);
    printf("  nP: %f\n", pvpanel->nP);

    printf("  n: %f\n", pvpanel->n);
    printf("  rs: %f\n", pvpanel->rs);
    printf("  rp: %f\n", pvpanel->rp);
    printf("  eg: %f\n", pvpanel->eg);
    printf("  io: %Le\n", pvpanel->io);
    printf("  irr: %f\n", pvpanel->irr);

    printf("  iCurr: %f\n", pvpanel->iCurr);
    printf("  vCurr: %f\n", pvpanel->vCurr);

    printf("}\n\n");
}