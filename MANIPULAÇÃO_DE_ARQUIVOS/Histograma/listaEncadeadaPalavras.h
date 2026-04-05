#ifndef LISTAENCADEADAPALAVRAS_H
#define LISTAENCADEADAPALAVRAS_H
typedef struct nopalavra{
	char * palavra;
	int quant;
	struct nopalavra * Prox;
}nopalavra; 

void inserePalavra(nopalavra * * L, char * palavra);

void destruirLista(nopalavra * L);

nopalavra * criarnoPalavra(char * palavra);



#endif