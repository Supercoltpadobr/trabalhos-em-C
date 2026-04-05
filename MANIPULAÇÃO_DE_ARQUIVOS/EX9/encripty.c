#include <stdio.h>

#define embaralhador 100

void encripita(void);

void desencrepita(void);

void filtringArq(FILE * arq1, FILE * temp, short filter);

int main(void){

    while (1)
    {
        short op;
        printf("----ENCRIPITANDO----\n\n[1] Encripitar\n\n[2]Desencripitar\n\n[3] Cair fora\n\n>> "); 
        scanf("%hd", &op);

        if(op==3){break;}
        else if(op==1){encripita();}
        else if(op==2){desencrepita();}
    }
    return 0;
}


void encripita(void){
    char nome[100], caractere; 

    printf("Nome do arquivo: "); 
    scanf("%s", nome);
    
    FILE * arquivo = fopen(nome, "r");
    FILE * tempArq = fopen("tempArq.txt", "w");
    
    if (arquivo == NULL){
        printf("Erro de abertura do arquivo %s.", nome);
        return;
    }

    filtringArq(arquivo, tempArq, embaralhador);

    fclose(arquivo);
    fclose(tempArq);

    tempArq = fopen("tempArq.txt", "r");
    arquivo = fopen(nome, "w");

    if (tempArq == NULL){
        printf("Erro de abertura do arquivo %s.", nome);
        return;
    }

    filtringArq(tempArq, arquivo, 0);

    fclose(arquivo);
    fclose(tempArq);
}


void desencrepita(void){
    char nome[100];

    printf("Nome do arquivo: ");
    scanf("%s", nome);
    
    FILE * arquivo = fopen(nome, "r");
    FILE * tempArq = fopen("tempArq.txt", "w");
    
    if (arquivo == NULL){
        printf("Erro de abertura do arquivo %s.", nome);
        return;
    }

    filtringArq(arquivo, tempArq, -embaralhador);

    fclose(arquivo);
    fclose(tempArq);

    tempArq = fopen("tempArq.txt", "r");
    arquivo = fopen(nome, "w");
    
    if (tempArq == NULL){
        printf("Erro de abertura do arquivo %s.", nome);
        return;
    }

    filtringArq(tempArq, arquivo, 0);

    fclose(arquivo);
    fclose(tempArq);
}

void filtringArq(FILE * arq1, FILE * arq2, short filter){
    char ch;
    ch = fgetc(arq1);

    while (ch != EOF)
    {   
        ch += filter;
        fputc(ch, arq2);
        ch = fgetc(arq1);
    }
    
}