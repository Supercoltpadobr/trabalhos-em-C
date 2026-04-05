#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListaFuncionarios.h"

void destruirFuncionarios(funcionario * * ListaFuncionarios, int tam){
    for (int i=0; i<tam; i++){
        free(ListaFuncionarios[i]);
    }
}

void LerHorasTrabalhadas(funcionario * * ListaFuncionarios, int tam, char * Arquivo){
    FILE * ARQ;
    ARQ = fopen(Arquivo, "r");
    char linha[20];
    short horas;

    if (!ARQ){
        printf("Ops! Arquivo não aberto.");
        return;
    }

    for(int i=0; i<tam; i++){
        fgets(linha, 20, ARQ);
        linha[12]='\0';
        sscanf(linha+13, "%hd", &horas);
        
        for(int j=0; j<tam; j++){
            if (strncmp(linha, (*(ListaFuncionarios[j])).matricula,12) == 0){
                (*(ListaFuncionarios[j])).horasTrabalhadas = horas;
                (*(ListaFuncionarios[j])).salario = horas * (*(ListaFuncionarios[j])).valor_hora;
            }
        }
        
    }
    fclose(ARQ);
}

void escreverFuncionario(funcionario * F){
    printf("%s|", (*F).Nome);
    printf("%s|", (*F).CPF);
    printf("%s|", (*F).cod_banco);
    printf("%s|", (*F).agencia);
    printf("%s|", (*F).conta);
    printf("%.2f\n", (*F).salario);
}

void lerFuncionarios(funcionario * * ListaFuncionarios, int tam, char * Arquivo){
    FILE * ARQ;
    ARQ = fopen(Arquivo, "r");
    char linha[170];
    if (!ARQ){
        printf("Ops! Arquivo não aberto.");
        return;
    }
    for (int i=0; i<tam; i++){
        fgets(linha, 170, ARQ);
        ListaFuncionarios[i] = ConstroiFuncionario(linha);
    }
    if (ferror(ARQ)){
        printf("ERRO durante leitura.");
    }

    fclose(ARQ);
}

funcionario * ConstroiFuncionario(char * linha){
    
    char * p=linha;
    funcionario * f = malloc(sizeof(funcionario));
    char * q=(*f).Nome;

    for(int i=0; i<162; i++){
        *q = *p;
        p++;
        q++;
    }
    add0funcionario(f);
    sscanf(linha+160, "%f", &((*f).valor_hora));

    return f;
}

void add0funcionario(funcionario * funcionario){
    (*funcionario).Nome[50] = '\0';
    (*funcionario).matricula[12] = '\0';
    (*funcionario).endereco[65] = '\0';
    (*funcionario).CPF[11] = '\0';
    (*funcionario).cod_banco[3] = '\0';
    (*funcionario).agencia[5] = '\0';
    (*funcionario).conta[8] = '\0';
}

void OrdemAlfabetica(funcionario * * LFuncionarios, int tam){
    funcionario * troca;
    char * menor; int menori;
    for(int j=0; j<tam; j++){
        menor = "ZZZ";
        for(int i=j; i<tam; i++){
            if(ordenador((*LFuncionarios[i]).Nome, menor)){
                menori = i;
                menor = (*LFuncionarios[i]).Nome;
            }
        }
        troca = LFuncionarios[menori];
        LFuncionarios[menori] = LFuncionarios[j];
        LFuncionarios[j] = troca;
    }
}

int ordenador(char * s, char * t){
        char * p=s, * q=t;
        while (*p != '\0'){
            if (*p>*q){
                return 0;
            }else if(*p<*q){
                return 1;
            }
            p++;
            q++;
        }
        return 0;
}