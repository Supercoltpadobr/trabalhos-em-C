#include <stdio.h>
#include <string.h>

#include "ProcedimentosFuncs.h"



void printandoLinhas(char linhas[1000][1000], int N){

    for (int i=0; i<N; i++){
        printf("%s", linhas[i]);//Printa string
    }
}

void criandoVetorLinhas(char * * matrizLinhas, FILE * arquivo, int * N){
    char conteudoArquivo[1000];
    int i=0;

    while (fgets(conteudoArquivo, sizeof(conteudoArquivo), arquivo) != NULL){//Pega string
        strcpy(matrizLinhas[i], conteudoArquivo);
        i++;
    }
    *N=i;
}
