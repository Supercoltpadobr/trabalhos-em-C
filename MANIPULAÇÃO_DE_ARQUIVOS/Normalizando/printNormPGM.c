#include "procedimentosPGM.h"
#include "normFuncs.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int altura, largura;
    float * * imagem;
	
    lerPGM(&altura, &largura, imagem);
	
	normalizandoMat(imagem, altura, largura);
	
    printarMatriz(imagem, altura, largura);
		
	for(int i=0; i<altura; i++){
		free(imagem[i]);
	}
    return 0;
}
