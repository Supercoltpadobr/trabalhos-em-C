#include <stdio.h>
#include <stdlib.h>
#include "procedimentosPGM.h"


void lerPGM(int * H, int * L, float * * matrizImagem){
	char NomeArquivo[200];
	
	scanf("%s", NomeArquivo);
    
    FILE * pgmFile = fopen(NomeArquivo, "r");
    
    char linha[200]; int MAX;

    if (pgmFile == NULL){
        printf("Erro: arquivo inexistente");
        return;
    }

    fgets(linha, sizeof(linha), pgmFile);

    if(linha[0]!='P' || linha[1]!='2'){
        printf("Formato incorreto.");
        return;
    }

    while(fgets(linha, sizeof(linha), pgmFile)[0]=='#'){}

    sscanf(linha, "%d %d\n", L, H);
    fscanf(pgmFile, "%d", &MAX);
	
	
    for(int i=0; i<*H; i++){
        matrizImagem[i] = (float*) malloc(sizeof(float)*(*L));
        for(int j=0; j<*L; j++){
            fscanf(pgmFile, "%f", &(matrizImagem[i][j]));
        }
    }

    fclose(pgmFile);

}

void printarMatriz(float * * matriz, int alt, int larg){
    for(int i=0; i<alt; i++){
        for(int j=0; j<larg; j++){
            
			if (j == larg-1){
				printf("%.4f", matriz[i][j]);
				break;
			}
			printf("%.4f ", matriz[i][j]);
        }
		if (i == alt-1){
			break;
		}
		printf("\n");
    }
}