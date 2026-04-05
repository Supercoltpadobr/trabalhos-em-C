#include <stdio.h>
#include <stdlib.h>
#include "procedimentos.h"


void lerPGM(char * nome, int * H, int * L, int * * matrizImagem){
    FILE * pgmFile = fopen(nome, "r");
    
    char linha[200]; int MAX;

    if (pgmFile == NULL){
        printf("ERRO - arquivo não aberto.");
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
        matrizImagem[i] = (int*) malloc(sizeof(int)*(*L));
        for(int j=0; j<*L; j++){
            fscanf(pgmFile, "%d", &(matrizImagem[i][j]));
            matrizImagem[i][j] = matrizImagem[i][j] % (MAX+1);
        }
    }

    fclose(pgmFile);

}

void printarMatriz(int * * matriz, int alt, int larg){
    printf("\n");
    for(int i=0; i<alt; i++){
        for(int j=0; j<larg; j++){
            printf("%-4d", matriz[i][j]);
        }
        printf("\n");
    }
}