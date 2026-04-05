#include "normFuncs.h"
#include <math.h>

float mediaMat(float * * Mat, int M, int N){
	float somatorio = 0;
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			somatorio += Mat[i][j];
		}
	}
	return somatorio/(M*N);
}

float desvioPadraoMat(float * * Mat, int M, int N, float media){
	float somatorio = 0;
	
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			somatorio += pow((Mat[i][j]-media), 2);
		}
	}
	return sqrt(somatorio/((M*N)-1));
}


float normaPixel(float pixel, float media, float desvioPadrao){
	return (pixel - media)/desvioPadrao;
}

void normalizandoMat(float * * Mat, int M, int N){
	float media = mediaMat(Mat, M, N);
	float desvio = desvioPadraoMat(Mat, M, N, media);
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			Mat[i][j] = normaPixel(Mat[i][j], media, desvio);
		}
	}
}