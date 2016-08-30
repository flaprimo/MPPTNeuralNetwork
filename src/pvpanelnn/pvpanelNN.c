#include <stdlib.h>
#include "pvpanelNN.h"
#include "../helper/list.h"
#include "../neuralnet/layer.h"

const int INPUT_LENGTH = 3;
const int LAYER1_LENGTH = 25;
const int OUTPUT_LENGTH = 1;

List *pvpanelNN_getLayerList()
{
    List *layerList;

    // hidden layer
    Layer *layer1 = layer_get(INPUT_LENGTH, LAYER1_LENGTH, SIGMOID);

    layer1->weightArray[0][0] = -4.16238761863828;
    layer1->weightArray[0][1] = -4.89647405099715;
    layer1->weightArray[0][2] = 1.49119243225256;
    layer1->weightArray[0][3] = 0.861133885546860;
    layer1->weightArray[0][4] = 1.32949196863967;
    layer1->weightArray[0][5] = -0.987176395912550;
    layer1->weightArray[0][6] = -2.30519798083694;
    layer1->weightArray[0][7] = -0.0518597173408378;
    layer1->weightArray[0][8] = 5.26018188551779;
    layer1->weightArray[0][9] = -0.0552353102329317;
    layer1->weightArray[0][10] = 0.406702438373463;
    layer1->weightArray[0][11] = 1.48663377533200;
    layer1->weightArray[0][12] = -0.636496114506964;
    layer1->weightArray[0][13] = 3.08343857188784;
    layer1->weightArray[0][14] = 4.44718898864415;
    layer1->weightArray[0][15] = 3.15706517971864;
    layer1->weightArray[0][16] = 0.841558236976516;
    layer1->weightArray[0][17] = 0.585215764553797;
    layer1->weightArray[0][18] = 0.370213963634089;
    layer1->weightArray[0][19] = -2.14638138186450;
    layer1->weightArray[0][20] = -0.591177783035397;
    layer1->weightArray[0][21] = 0.0457232973802251;
    layer1->weightArray[0][22] = -0.735571684196250;
    layer1->weightArray[0][23] = -0.597163184438216;
    layer1->weightArray[0][24] = -1.24740441822822;

    layer1->weightArray[1][0] = 0.730793667082905;
    layer1->weightArray[1][1] = -0.328038070977096;
    layer1->weightArray[1][2] = -7.03167979328387;
    layer1->weightArray[1][3] = 0.387004333216744;
    layer1->weightArray[1][4] = -6.54406556656631;
    layer1->weightArray[1][5] = -0.418130961563425;
    layer1->weightArray[1][6] = 3.38910634219411;
    layer1->weightArray[1][7] = -6.30274779349584;
    layer1->weightArray[1][8] = 0.583163944151354;
    layer1->weightArray[1][9] = -6.26735353067407;
    layer1->weightArray[1][10] = 1.34103208561851;
    layer1->weightArray[1][11] = -3.84789005114262;
    layer1->weightArray[1][12] = 1.64490955405288;
    layer1->weightArray[1][13] = -1.12303077433637;
    layer1->weightArray[1][14] = -0.249649778776412;
    layer1->weightArray[1][15] = -1.15461919807047;
    layer1->weightArray[1][16] = 0.743842970712744;
    layer1->weightArray[1][17] = -1.51752544613478;
    layer1->weightArray[1][18] = -1.09869196150447;
    layer1->weightArray[1][19] = 3.42227742212089;
    layer1->weightArray[1][20] = -1.21572452877892;
    layer1->weightArray[1][21] = 0.0397297105641391;
    layer1->weightArray[1][22] = -0.0446025890610893;
    layer1->weightArray[1][23] = -1.14410437664091;
    layer1->weightArray[1][24] = -0.365306749107149;

    layer1->weightArray[2][0] = -2.43139231403074;
    layer1->weightArray[2][1] = -2.96781129127597;
    layer1->weightArray[2][2] = 0.601388808091535;
    layer1->weightArray[2][3] = 0.396747758847731;
    layer1->weightArray[2][4] = 0.597795286300967;
    layer1->weightArray[2][5] = -0.432929545983239;
    layer1->weightArray[2][6] = -1.55497533855293;
    layer1->weightArray[2][7] = -0.308037637517481;
    layer1->weightArray[2][8] = 3.26649873659907;
    layer1->weightArray[2][9] = -0.362831047999268;
    layer1->weightArray[2][10] = 0.324965997558987;
    layer1->weightArray[2][11] = 0.911255805768970;
    layer1->weightArray[2][12] = -0.392827315275561;
    layer1->weightArray[2][13] = 2.21788307062478;
    layer1->weightArray[2][14] = 2.63386852931660;
    layer1->weightArray[2][15] = 2.28350204407132;
    layer1->weightArray[2][16] = 0.328179660351446;
    layer1->weightArray[2][17] = 0.361929361550504;
    layer1->weightArray[2][18] = 0.235457702298123;
    layer1->weightArray[2][19] = -1.42981405363696;
    layer1->weightArray[2][20] = 0.192546290394281;
    layer1->weightArray[2][21] = -0.155519042410701;
    layer1->weightArray[2][22] = -0.297242738405084;
    layer1->weightArray[2][23] = 0.210976360825200;
    layer1->weightArray[2][24] = -0.533000589798058;

    layer1->bias[0] = 3.48245858348948;
    layer1->bias[1] = 3.46248947500684;
    layer1->bias[2] = -8.32063772765874;
    layer1->bias[3] = -0.311913987869281;
    layer1->bias[4] = -8.14710067566170;
    layer1->bias[5] = 0.0252429199645986;
    layer1->bias[6] = 4.46610760314085;
    layer1->bias[7] = -7.25811441392727;
    layer1->bias[8] = -3.62217456401517;
    layer1->bias[9] = -7.11132415894586;
    layer1->bias[10] = 1.61028914532249;
    layer1->bias[11] = -3.27810765818465;
    layer1->bias[12] = 0.959782192353291;
    layer1->bias[13] = -2.36579368786956;
    layer1->bias[14] = -3.42986798502727;
    layer1->bias[15] = -2.41506002711059;
    layer1->bias[16] = 0.899196690710682;
    layer1->bias[17] = -1.03844830528047;
    layer1->bias[18] = -1.63451280797039;
    layer1->bias[19] = 4.39827392240531;
    layer1->bias[20] = -1.71612235468471;
    layer1->bias[21] = -0.349987713438870;
    layer1->bias[22] = 0.736047522764860;
    layer1->bias[23] = -1.69093052994134;
    layer1->bias[24] = 0.868818957310083;

    list_addLast(&layerList, layer1);

    // output layer
    Layer *layer2 = layer_get(LAYER1_LENGTH, OUTPUT_LENGTH, LINEAR);

    layer2->weightArray[0][0] = 1.92609063320856;
    layer2->weightArray[1][0] = 7.35287569459599;
    layer2->weightArray[2][0] = -3.00610021436071;
    layer2->weightArray[3][0] = 4.03690407777157;
    layer2->weightArray[4][0] = 8.27429024851439;
    layer2->weightArray[5][0] = 3.10219741484676;
    layer2->weightArray[6][0] = 4.95495197090250;
    layer2->weightArray[7][0] = -7.80233324026980;
    layer2->weightArray[8][0] = 3.58324281615384;
    layer2->weightArray[9][0] = 5.22424617144915;
    layer2->weightArray[10][0] = -0.214346921559992;
    layer2->weightArray[11][0] = 0.176113598249144;
    layer2->weightArray[12][0] = 3.28257461495322;
    layer2->weightArray[13][0] = 1.81337827801646;
    layer2->weightArray[14][0] = 5.28253951508147;
    layer2->weightArray[15][0] = -1.64774977477614;
    layer2->weightArray[16][0] = -0.456200487033103;
    layer2->weightArray[17][0] = 6.35618996552840;
    layer2->weightArray[18][0] = -11.7862614392991;
    layer2->weightArray[19][0] = -6.19680999016685;
    layer2->weightArray[20][0] = 1.64984689677114;
    layer2->weightArray[21][0] = 5.41722444197573;
    layer2->weightArray[22][0] = -4.70208972281721;
    layer2->weightArray[23][0] = -1.64353294016823;
    layer2->weightArray[24][0] = 3.41439907787649;

    layer2->bias[0] = -0.404523437283139;

    list_addLast(&layerList, layer2);

    return layerList;
}

PvPanelNN *pvpanelNN_get()
{
    PvPanelNN *pvpanelNN = malloc(sizeof(PvPanelNN));

    // input
    pvpanelNN->inputLength = INPUT_LENGTH;

    pvpanelNN->minInput = malloc(sizeof(double) * INPUT_LENGTH);
    pvpanelNN->minInput[0] = 750.5;
    pvpanelNN->minInput[1] = 2.83892709347493;
    pvpanelNN->minInput[2] = 263;

    pvpanelNN->maxInput = malloc(sizeof(double) * INPUT_LENGTH);
    pvpanelNN->maxInput[0] = 1578.8;
    pvpanelNN->maxInput[1] = 569.413757050536;
    pvpanelNN->maxInput[2] = 363;

    // output
    pvpanelNN->outputLength = OUTPUT_LENGTH;

    pvpanelNN->minOutput = malloc(sizeof(double) * OUTPUT_LENGTH);
    pvpanelNN->minOutput[0] = 782.16;

    pvpanelNN->maxOutput = malloc(sizeof(double) * OUTPUT_LENGTH);
    pvpanelNN->maxOutput[0] = 1403.6;

    // neuralNet
    pvpanelNN->neuralNet = neuralnet_get(INPUT_LENGTH);
    pvpanelNN->neuralNet->layerList = pvpanelNN_getLayerList();

    // pvpanel
    pvpanelNN->pvpanel = pvpanel_get(1100, pvpanelSpec_get());

    return pvpanelNN;
}

/**
 * Given a pvpanelNN object and an input array, it computes the neural networks normalizing inputs and outputs.
 * @param pvpanelNN
 * @param input
 * @return
 */
double *pvpanelNN_compute(PvPanelNN *pvpanelNN, double *input)
{
    double *normalizedInput = pvpanelNN_normalizeInput(pvpanelNN, input);
    double *output = neuralnet_compute(normalizedInput, pvpanelNN->neuralNet);

    return pvpanelNN_normalizeOutput(pvpanelNN, output);
}

/**
 * Given an input and a PvPanelNN, it normalizes the input.
 * inputN = (1+1) * (Input' - MinInput) ./ (MaxInput - MinInput) - [1 1 1];
 * @param pvpanelNN
 * @param input
 * @return
 */
double *pvpanelNN_normalizeInput(PvPanelNN *pvpanelNN, double *input)
{
    double *normalizedInput = malloc(sizeof(double) * pvpanelNN->inputLength);

    for (int i = 0; i < pvpanelNN->inputLength; i++)
        normalizedInput[i] = 2 * (input[i] - pvpanelNN->minInput[i]) / (pvpanelNN->maxInput[i] - pvpanelNN->minInput[i]) - 1;

    return normalizedInput;
}

/**
 * Given an output and a PvPanelNN, it normalizes the output.
 * outputN = (MaxOutput - MinOutput) * (NN_output + 1) / (1+1) + MinOutput;
 * @param pvpanelNN
 * @param output
 * @return
 */
double *pvpanelNN_normalizeOutput(PvPanelNN *pvpanelNN, double *output)
{
    double *normalizedOutput = malloc(sizeof(double) * pvpanelNN->outputLength);

    for (int i = 0; i < pvpanelNN->outputLength; i++)
        normalizedOutput[i] = (pvpanelNN->maxOutput[i] - pvpanelNN->minOutput[i]) * (output[i] + 1) / 2 + pvpanelNN->minOutput[i];

    return normalizedOutput;
}

/**
 * Frees pvpanelNN struct.
 * @param pvpanelNN
 */
void pvpanelNN_free(PvPanelNN *pvpanelNN)
{
    free(pvpanelNN->minInput);
    free(pvpanelNN->maxInput);

    free(pvpanelNN->minOutput);
    free(pvpanelNN->maxOutput);
}