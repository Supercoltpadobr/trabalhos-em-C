#include <stdio.h>
#include <stdlib.h>
#include "vetinput.h"
#include "escalar.h"

int main(void){
    char NomeDoArq[200];
    int N, M;

    scanf("%s", NomeDoArq);
    float * vetor1 = LerVetor(NomeDoArq, &N);
    
    scanf("%s", NomeDoArq);    
    float * vetor2 = LerVetor(NomeDoArq, &M);
    
    if(vetor1==NULL || vetor2==NULL){
        return 1;
    }

    if (N!=M){
        printf("Erro: os vetores possuem comprimentos distintos.\n");
        return 2;
    }
    
    printf("%.3f", ProdutoEscalar(vetor1, vetor2, N));

    free(vetor1);
    free(vetor2);

    return 0;
}