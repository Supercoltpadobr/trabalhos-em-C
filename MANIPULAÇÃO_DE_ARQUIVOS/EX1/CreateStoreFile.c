#include <stdio.h>


int main(void){
    
    char frase[1000];
    
    FILE * arquivo = fopen("file.txt", "w");

    if (arquivo == NULL){

        printf("ERRO - Arquivo não aberto.");
        return 1;
    }

    fgets(frase, sizeof(frase), stdin);

    fprintf(arquivo, "%s", frase);

    printf("%s", frase);

    fclose(arquivo);

    return 0;
}