#include <stdio.h>
#include "ProcedimentosFuncs.h"

int main(void){
    char nomeArquivo[100], * vetorLinhas[1000];
    int linhas=0, caracteres=0;
    FILE * arquivo;
    
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL){
        printf("ERRO - Arquivo não aberto\n");
        return 1;
    }else{
        criandoVetorLinhas(vetorLinhas, arquivo, &linhas);

        printandoLinhas(vetorLinhas, linhas); 
    }
    printf("\nForam lidas %d linha(s).\n", linhas);
    if (ferror(arquivo)){

        printf("ERRO - Leitura do arquivo\n");
        return 2;
    }

    fclose(arquivo);

    return 0;
}

