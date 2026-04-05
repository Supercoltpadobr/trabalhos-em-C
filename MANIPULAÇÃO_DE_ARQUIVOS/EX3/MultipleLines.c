#include<stdio.h>

int main(void){
    int lines;
    char linha[1000];
    FILE * arquivo = fopen("Wfile.txt", "w");

    if (arquivo == NULL){

        printf("ERRO - arquivo não aberto");
        return 1;
    }
    printf("Linhas : ");
    scanf("%d\n", &lines);

    for(int i = 0; i < lines; i++){

        fgets(linha, sizeof(linha), stdin);//Ler string até \n

        fputs(linha, arquivo);//Imprime string até \n

    }

    fclose(arquivo);
    return 0;

}