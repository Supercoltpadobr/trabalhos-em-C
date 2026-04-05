#include <stdio.h>
#include <stdlib.h>
#include "vetinput.h"


float * LerVetor(char * N_Arq, int * N){
    FILE * Arquivo = fopen(N_Arq, "r");
    if (Arquivo == NULL){
        printf("Erro: arquivo %s não foi encontrado.\n", N_Arq);
        return NULL;
    }
    float * vetor;

    fscanf(Arquivo, "%d\n", N);
    vetor = malloc((*N)*sizeof(int));

    for(int i=0; i<(*N); i++){
        if(fscanf(Arquivo, "%f\n", vetor+i)<1){
            printf("Erro: arquivo %s está corrompido.\n", N_Arq);
            free(vetor);
            return NULL;
        }
    }


    if(fclose(Arquivo)){
        printf("Erro: arquivo %s não pôde ser fechado.\n", N_Arq);
        free(vetor);
        return NULL;
    }

    return vetor;
}
