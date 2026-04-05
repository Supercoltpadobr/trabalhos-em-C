#include <stdio.h>
#include <stdlib.h>
#include "abrirArq.h"

void AbrirLer(char * nome_Arquivo, char * * texto, int * TamanhoBytes){
	FILE * ARQ; char c;
	ARQ = fopen(nome_Arquivo, "r");
	*TamanhoBytes = 0;
	
	if(ARQ == NULL){
		printf("Arquivo não aberto.");
		**texto = 0;
		return;
	}
	
	int i=0;
	(*texto) = malloc(10*sizeof(char));
	while ((c = fgetc(ARQ))!=EOF){
		
		if (i > 10){// allocando dinamicamente + 10 espaços 
			(*texto) = realloc((*texto), ((*TamanhoBytes)+10)*sizeof(char));
			i=0;
		}

		(*texto)[*TamanhoBytes] = c;
		(*TamanhoBytes)++;
		i++;
	}
	if (ferror(ARQ)){
		printf("Erro na leitura.");
		free((*texto));
		(*texto) = NULL;
		*TamanhoBytes = 0;
		return;
	}
	
	(*texto)[(*TamanhoBytes)] = '\0';	
	fclose(ARQ);
}


void AbrirEscrever(char * nome_Arquivo, char * texto){
	int i=0;
	FILE * ARQ = fopen(nome_Arquivo, "w");
	
	if(!ARQ){
		printf("Arquivo não aberto.");
		return;
	}
	
	while (texto[i]){
		fputc(texto[i], ARQ);
		i++;
	}
	
	if (ferror(ARQ)){
		printf("Erro na leitura.");
		return;
	}
	
	fclose(ARQ);
	
}


void AbrirAdicionar(char * nome_Arquivo, char * texto){
	int i=0;
	FILE * ARQ = fopen(nome_Arquivo, "a");
	
	if(!ARQ){
		printf("Arquivo não aberto.");
		return;
	}
	
	while (texto[i]){
		fputc(texto[i], ARQ);
		i++;
	}
	
	if (ferror(ARQ)){
		printf("Erro na leitura.");
		return;
	}
	
	fclose(ARQ);
	
}


void Fechar(ARQ * arquivo){
	free((*arquivo).text);
	free(arquivo);
}