#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abrirArq.h"
#include "gui.h"

ARQ * loadFile(char * nome){
	
	ARQ * newArq = malloc(sizeof(ARQ));
	
	AbrirLer(nome, &(newArq->text), &(newArq->Byte_size));
	if (newArq->Byte_size == 0){
		free(newArq);
		return NULL;
	}
	
	strcpy(newArq->nome, nome);
	
	while(*nome != '.') // até o .txt
		nome++;
	
	
	strcpy(newArq->type, nome+1);
	
	return newArq;
}


void unLoadFile(ARQ * * arquivo){
	Fechar(*arquivo);
	*arquivo = NULL;
}


void mostrarTexto(ARQ * arq){
	printf("%s", arq->text);
}


void lerTexto(char * * texto){
	char c;
	int i=0;
	
	*texto = malloc(10 * sizeof(char));
	while ((c = getchar()) != EOF){
		(*texto)[i] = c;
		i++;
		
		if (!(i%10)){
			*texto = realloc(*texto, i+10);
		}
	}
	
}


void MainLoop(){
	int op=1; 
	ARQ * ArquivoPrincipal = NULL;
	while (op){
		printf("MANIPULAR ARQUIVO\n");
		printf("1 - Carregar Arquivo\n");
		printf("2 - Adicionar Conteúdo\n");
		printf("3 - Sobrescrever Conteúdo\n");
		printf("0 - Sair\n");
		
		scanf("%d", &op);
		
		switch (op){
			case 1:
				ArquivoPrincipal = CarregarArquivo();
				break;
			case 2:
				AdicionarConteudo(ArquivoPrincipal);
				break;
			case 3:
				
				break;
			case 0:
				printf("bye bye");
				break;
			default:
				printf("\nOpção indisponível\n");
				break;
		}
		
		printf("\n");
	}
	
	
}


ARQ * CarregarArquivo(){
	char nomeArq[150];
	ARQ * arquivoCarregado;
	printf("\nNome do arquivo : ");
	scanf("%s", nomeArq);
	if ((arquivoCarregado = loadFile(nomeArq)) == NULL){
		return NULL;
	}
	printf("Arquivo %s aberto com sucesso!", nomeArq);
	
	return arquivoCarregado;
}

void AdicionarConteudo(ARQ * Arquivo){
	if (Arquivo != NULL){
		printf("%s", Arquivo->text);
		lerTexto(&(Arquivo->text));
		AbrirAdicionar(Arquivo->nome, Arquivo->text);
	}else{
		printf("Arquivo não carregado.\n");
	}
}