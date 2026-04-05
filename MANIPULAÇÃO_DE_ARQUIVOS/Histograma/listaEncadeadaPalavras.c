#include "listaEncadeadaPalavras.h"
#include "palavrasFuncs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inserePalavra(nopalavra * * L, char * palavra){	
	nopalavra * * I=L; char cmp;
	while(*I != NULL){
		cmp = strcmp(palavra, (*I)->palavra);
		if(cmp<0){
			nopalavra * novo = criarnoPalavra(palavra);
			novo->Prox = (*I);
			*I = novo;
			return;
		}
		if(cmp==0){
			(*I)->quant += 1;
			return;
		}
		I = &((*I)->Prox);
	}
	nopalavra * novo = criarnoPalavra(palavra);
	*I = novo;
}


nopalavra * criarnoPalavra(char * palavra){
	nopalavra * No = malloc(sizeof(nopalavra));
	(*No).Prox = NULL;
	(*No).quant = 1;
	(*No).palavra = malloc(sizeof(char) * strlen(palavra));
	strcpy((*No).palavra, palavra);
	return No;
}


void destruirLista(nopalavra * L){
	nopalavra * I=L, * prx;
	while(I!=NULL){
		free((*I).palavra);
		prx = (*I).Prox;
		free(I);
		I = prx;
	}
}