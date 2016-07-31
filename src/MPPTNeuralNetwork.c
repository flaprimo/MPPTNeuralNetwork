#include <stdio.h>
#include <stdlib.h>
#include "pvpanel/pvpanelSpec.h"
#include "pvpanel/pvpanel.h"
#include "neuralnet/weight.h"
#include "pvpanelnn/pvpanelNN.h"

const double VCURR = 1100;

const int HIDDENLAYER_WEIGHT_LENGTH = 25;

int main()
{
    /*
     * Get PvPanel
     */
    // Get pvpanel specification
    PvPanelSpec *pvpanelSpec = pvpanelSpec_get();

    // Get pvpanel
    PvPanel *pvpanel = pvpanel_get(VCURR, pvpanelSpec_get());

    /*
     * Create and initialize weights for the Neural network
     */
    Weight *hiddenLayer = weight_get(3, HIDDENLAYER_WEIGHT_LENGTH);

    hiddenLayer->matrix[0][0] = -4.16238761863828;
    hiddenLayer->matrix[0][1] = -4.89647405099715;
    hiddenLayer->matrix[0][2] = 1.49119243225256;
    hiddenLayer->matrix[0][3] = 0.861133885546860;
    hiddenLayer->matrix[0][4] = 1.32949196863967;
    hiddenLayer->matrix[0][5] = -0.987176395912550;
    hiddenLayer->matrix[0][6] = -2.30519798083694;
    hiddenLayer->matrix[0][7] = -0.0518597173408378;
    hiddenLayer->matrix[0][8] = 5.26018188551779;
    hiddenLayer->matrix[0][9] = -0.0552353102329317;
    hiddenLayer->matrix[0][10] = 0.406702438373463;
    hiddenLayer->matrix[0][11] = 1.48663377533200;
    hiddenLayer->matrix[0][12] = -0.636496114506964;
    hiddenLayer->matrix[0][13] = 3.08343857188784;
    hiddenLayer->matrix[0][14] = 4.44718898864415;
    hiddenLayer->matrix[0][15] = 3.15706517971864;
    hiddenLayer->matrix[0][16] = 0.841558236976516;
    hiddenLayer->matrix[0][17] = 0.585215764553797;
    hiddenLayer->matrix[0][18] = 0.370213963634089;
    hiddenLayer->matrix[0][19] = -2.14638138186450;
    hiddenLayer->matrix[0][20] = -0.591177783035397;
    hiddenLayer->matrix[0][21] = 0.0457232973802251;
    hiddenLayer->matrix[0][22] = -0.735571684196250;
    hiddenLayer->matrix[0][23] = -0.597163184438216;
    hiddenLayer->matrix[0][24] = -1.24740441822822;

    hiddenLayer->matrix[1][0] = 0.730793667082905;
    hiddenLayer->matrix[1][1] = -0.328038070977096;
    hiddenLayer->matrix[1][2] = -7.03167979328387;
    hiddenLayer->matrix[1][3] = 0.387004333216744;
    hiddenLayer->matrix[1][4] = -6.54406556656631;
    hiddenLayer->matrix[1][5] = -0.418130961563425;
    hiddenLayer->matrix[1][6] = 3.38910634219411;
    hiddenLayer->matrix[1][7] = -6.30274779349584;
    hiddenLayer->matrix[1][8] = 0.583163944151354;
    hiddenLayer->matrix[1][9] = -6.26735353067407;
    hiddenLayer->matrix[1][10] = 1.34103208561851;
    hiddenLayer->matrix[1][11] = -3.84789005114262;
    hiddenLayer->matrix[1][12] = 1.64490955405288;
    hiddenLayer->matrix[1][13] = -1.12303077433637;
    hiddenLayer->matrix[1][14] = -0.249649778776412;
    hiddenLayer->matrix[1][15] = -1.15461919807047;
    hiddenLayer->matrix[1][16] = 0.743842970712744;
    hiddenLayer->matrix[1][17] = -1.51752544613478;
    hiddenLayer->matrix[1][18] = -1.09869196150447;
    hiddenLayer->matrix[1][19] = 3.42227742212089;
    hiddenLayer->matrix[1][20] = -1.21572452877892;
    hiddenLayer->matrix[1][21] = 0.0397297105641391;
    hiddenLayer->matrix[1][22] = -0.0446025890610893;
    hiddenLayer->matrix[1][23] = -1.14410437664091;
    hiddenLayer->matrix[1][24] = -0.365306749107149;

    hiddenLayer->matrix[2][0] = -2.43139231403074;
    hiddenLayer->matrix[2][1] = -2.96781129127597;
    hiddenLayer->matrix[2][2] = 0.601388808091535;
    hiddenLayer->matrix[2][3] = 0.396747758847731;
    hiddenLayer->matrix[2][4] = 0.597795286300967;
    hiddenLayer->matrix[2][5] = -0.432929545983239;
    hiddenLayer->matrix[2][6] = -1.55497533855293;
    hiddenLayer->matrix[2][7] = -0.308037637517481;
    hiddenLayer->matrix[2][8] = 3.26649873659907;
    hiddenLayer->matrix[2][9] = -0.362831047999268;
    hiddenLayer->matrix[2][10] = 0.324965997558987;
    hiddenLayer->matrix[2][11] = 0.911255805768970;
    hiddenLayer->matrix[2][12] = -0.392827315275561;
    hiddenLayer->matrix[2][13] = 2.21788307062478;
    hiddenLayer->matrix[2][14] = 2.63386852931660;
    hiddenLayer->matrix[2][15] = 2.28350204407132;
    hiddenLayer->matrix[2][16] = 0.328179660351446;
    hiddenLayer->matrix[2][17] = 0.361929361550504;
    hiddenLayer->matrix[2][18] = 0.235457702298123;
    hiddenLayer->matrix[2][19] = -1.42981405363696;
    hiddenLayer->matrix[2][20] = 0.192546290394281;
    hiddenLayer->matrix[2][21] = -0.155519042410701;
    hiddenLayer->matrix[2][22] = -0.297242738405084;
    hiddenLayer->matrix[2][23] = 0.210976360825200;
    hiddenLayer->matrix[2][24] = -0.533000589798058;

    /*
     * Get pvpanelNN
     */

    /*
     * Create input
     */
    PvPanelNN *pvpanelNN = pvpanelNN_get();

    double *input = malloc(sizeof(double) * pvpanelNN->inputLength);
    input[0] = 977.581807425645;
    input[1] = 391.935856999970;
    input[2] = 342.475382369526;

    double *inputN = pvpanelNN_normalizeInput(pvpanelNN, input);
    printf("%f\n", inputN[0]);

    free(input);

    /*
     * Create Output
     */
    double *output = malloc(sizeof(double) * pvpanelNN->outputLength);
    output[0] = -0.3734;

    double *outputN = pvpanelNN_normalizeOutput(pvpanelNN, input);

    free(output);
}