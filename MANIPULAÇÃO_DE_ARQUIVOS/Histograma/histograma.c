#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaPalavras.h"
#include "palavrasFuncs.h"

#define MAX_SIZE 100000


int main(void){
	char * palavra = malloc(MAX_SIZE * sizeof(char));
	int t;
	nopalavra * Lista=NULL, * I;
	
	while((t = scanearPalavra(palavra))!=-1){
		if (t==1){
			inserePalavra(&Lista, palavra);
		}
	}
	
	I = Lista;
	while(I!= NULL){
		printf("%s\t\t%d\n", (*I).palavra, (*I).quant);
		I = (*I).Prox;
	}

	destruirLista(Lista);
	free(palavra);
    return 0;
}
