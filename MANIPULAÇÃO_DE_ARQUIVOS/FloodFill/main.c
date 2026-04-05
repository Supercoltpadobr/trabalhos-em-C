#include <stdio.h>
#include <stdlib.h>
#include "floodfill.h"

#define ALT 20
#define LAR 20

void printarMatriz(char * * Matriz);

void freeMatriz(char * * matriz);


int main(void){
	char * * matriz = malloc(ALT * sizeof(char *));
	char nomeArquivo[150];
	FILE * Arquivo;
	int floodX, floodY;
	
	scanf("%s", nomeArquivo);
	
	Arquivo = fopen(nomeArquivo, "r");
	if (Arquivo==NULL){
		printf("Erro arquivo inexistente\n");
		return 1;
	}
	
	for(int i=0; i<ALT+1; i++){
		matriz[i] = malloc(LAR * sizeof(char));
		fgets(matriz[i], LAR+1, Arquivo);
		fscanf(Arquivo, "\n");
	}	
	
	fscanf(Arquivo, "%d %d", &floodX, &floodY);

	FloodFill(matriz, floodX, floodY, ALT, LAR);
	
	printarMatriz(matriz);
	
	fclose(Arquivo);
	
	return 0;
}


void freeMatriz(char * * matriz){
	for (int i=0; i<ALT+1; i++){
		free(matriz[i]);
	}
	
	free(matriz);
}


void printarMatriz(char * * Matriz){
	for(int i=0; i<ALT+1; i++){
		printf("%s\n", Matriz[i]);
	}
}