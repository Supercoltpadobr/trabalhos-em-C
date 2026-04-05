#include <stdio.h>
#include "ListaFuncionarios.h"

#define QF 10 

int main(void){
    int ordem[QF];

    funcionario * LISTA_DE_FUNCIONARIOS[QF];

    lerFuncionarios(LISTA_DE_FUNCIONARIOS, QF, "Funcionarios.txt");

    OrdemAlfabetica(LISTA_DE_FUNCIONARIOS, QF);

    LerHorasTrabalhadas(LISTA_DE_FUNCIONARIOS, QF, "Novembro.txt");
    for(int i=0; i<QF; i++){
        escreverFuncionario(LISTA_DE_FUNCIONARIOS[i]);
    }
    destruirFuncionarios(LISTA_DE_FUNCIONARIOS, QF);

    return 0;
}

