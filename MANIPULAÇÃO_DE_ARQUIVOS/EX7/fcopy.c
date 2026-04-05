#include <stdio.h>

int main(void){
    char nomeArquivo0[100], nomeArquivo1[100], linha[1000];

    printf("Arquivo a ser copiado: "); scanf("%s", nomeArquivo0);
    printf("Nome do novo: "); scanf("%s", nomeArquivo1);

    FILE * arquivo0 = fopen(nomeArquivo0, "r");
    FILE * arquivo1 = fopen(nomeArquivo1, "w");
    if (arquivo0 == NULL){
        printf("ERRO - Arquivo não aberto\n");
        return 1;
    }
    while (fgets(linha, sizeof(linha), arquivo0) != NULL)
    {
        fputs(linha, arquivo1);
    }
    
    fclose(arquivo0);
    fclose(arquivo1);
    
    return 0;
}