#include <stdio.h>

int main(void){
    int add; char nomeArquivo[100];

    printf("Nome do arquivo: "); scanf("%s", nomeArquivo);
    printf("Linhas a serem adicionadas: "); scanf("%d\n", &add);
    
    char linhasNovas[add][1000]; FILE * arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL){
        printf("ERRO - Arquivo não aberto\n");
        return 1;
    }

    for(int i=0; i<add; i++){
        fgets(linhasNovas[i], sizeof(linhasNovas[i]), stdin);
        fputs(linhasNovas[i], arquivo);
    }
    
    fclose(arquivo);

    return 0;
}