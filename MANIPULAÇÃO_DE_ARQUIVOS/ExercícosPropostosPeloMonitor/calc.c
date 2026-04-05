#include <stdio.h>
#include <stdlib.h>

#include "complexo.h"

void calcLoop();

int main(void){
	short mode;

	scanf("%hd", &mode);
	
	switch(mode){
		case 0:	
            printf("Saindo...\n");
			break;
		case 1:
			calcLoop();
			break;
		default:
            printf("Opcao invalida!\n");
            break;
        }	
    
    return 0;
}


void calcLoop(){

    short op;
    struct complexo * resultado, * A, * B;

    A = lerComplexo(); B = lerComplexo();

    scanf("%hd", &op);

    if(op == 0){
        printf("Saindo...\n");
        return;
    }else if(op == 1){
        resultado = Soma(A, B);
        imprComplexo(resultado);
    }else if(op == 2){
        resultado = Multiplicacao(A, B);
        imprComplexo(resultado);    
    }else if(op == 3){
        printf("%.2lf", Modulo(A));
    }else if(op == 4){
        resultado = Subtracao(A, B);
        imprComplexo(resultado);   
    }else if(op == 5){
        resultado = Conjugado(A);
        imprComplexo(resultado);
    }else{
        printf("Opcao invalida!\n");
    }

}
