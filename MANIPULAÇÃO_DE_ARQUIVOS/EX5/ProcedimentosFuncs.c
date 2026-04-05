#include <stdio.h>
#include <string.h>

#include "ProcedimentosFuncs.h"



void printandoLinhas(char * * linhas, int N){

    for (int i=0; i<N; i++){
        printf("%s", linhas[i]);//Printa string
    }
}

void criandoVetorLinhas(char matrizLinhas[][1000], FILE * arquivo, int * N){
    char conteudoArquivo[1000];
    int i=0;

    while (fgets(conteudoArquivo, sizeof(conteudoArquivo), arquivo) != NULL){//Pega string

        strncpy(matrizLinhas[i], conteudoArquivo, sizeof(matrizLinhas[i]));
        i++;
    }
    *N=i;
}
