#ifndef NORMFUNCS_H
#define NORMFUNCS_H

float mediaMat(float * * Mat, int M, int N);

float desvioPadraoMat(float * * Mat, int M, int N, float media);

float normaPixel(float pixel, float media, float desvioPadrao);

void normalizandoMat(float * * Mat, int M, int N);

#endif