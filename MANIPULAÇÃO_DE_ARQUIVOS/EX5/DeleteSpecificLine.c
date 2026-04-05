#include <stdio.h>
#include "ProcedimentosFuncs.h"

int main(void){
    char nomeArquivo[100], linhas[1000][1000], novaLinha[1000];
    int Tlinhas, removeLinha;
    FILE * arquivo;
    
    printf("Nome do arquivo: "); scanf("%s", nomeArquivo);
    printf("Linha a ser alterada: "); scanf("%d", &removeLinha);
    printf("Linha nova: "); fscanf(stdin, "%s", novaLinha);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL){
        printf("ERRO - Arquivo não aberto\n");
        return 1;
    }

    criandoVetorLinhas(linhas, arquivo, &Tlinhas);
    fclose(arquivo);

    arquivo = fopen(nomeArquivo, "w");
    for(int i=0; i<Tlinhas; i++){
        if (i != removeLinha-1){        //caso linha nova
            fputs(linhas[i], arquivo);
        }else{
            fputs(novaLinha, arquivo);
            fputc('\n', arquivo);
        }
    }
    return 0;

}