#include <stdio.h>

int main(void){

    char nomeArquivo[100], conteudoArquivo[1000];

    FILE * arquivo;
    
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL){

        printf("ERRO - Arquivo não aberto");
        return 1;
    }else{

        fgets(conteudoArquivo, sizeof(conteudoArquivo), arquivo);
        printf("%s", conteudoArquivo);
    }

    if (ferror(arquivo)){

        printf("ERRO - Leitura do arquivo");
        return 2;
    }

    fclose(arquivo);

    return 0;

}