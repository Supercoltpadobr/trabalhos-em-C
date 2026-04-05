#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortingAlgs.h"
#define TAM 10000000

void printarVetor(int * Vetor, int N);

void randomizarVetor(int * Vetor, int N);

int main(void){
	int * VET = malloc(TAM*sizeof(int));
	double duracao;
	clock_t inicio_t, fim_t; 
	
	randomizarVetor(VET, TAM);
	inicio_t = clock();
	
	MergeSort(VET, TAM);			//coloque aqui
	
	fim_t = clock();
	printarVetor(VET, TAM);
	
	
	duracao = ((double)(fim_t-inicio_t))/CLOCKS_PER_SEC;
	
	printf("\n %f segundos\n", duracao);
	
	free(VET);
	return 0;
}

void printarVetor(int * Vetor, int N){
	printf("Vetor :\n");
	for(int i=0; i<N; i++){
		printf("%d ", Vetor[i]);
	}
	printf("\n");
}

void randomizarVetor(int * Vetor, int N){
	srand(time(0));
	
	for(int i=0; i<N; i++){
		Vetor[i] = (rand() % 10000000);
	}
	
}