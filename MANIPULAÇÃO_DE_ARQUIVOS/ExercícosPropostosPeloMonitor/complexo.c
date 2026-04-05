#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

void imprComplexo(struct complexo * C){
    if ((*C).I >= 0)
	    printf("%.2lf + %.2lfi\n", (*C).R, (*C).I);
    else
        printf("%.2lf + (%.2lf)i\n", (*C).R, (*C).I);
    }

struct complexo * lerComplexo(){
	struct complexo * C;
	C = (struct complexo *) malloc(sizeof(C));
	
	scanf("%lf %lf", &((*C).R), &((*C).I));
	
	return C;

}

struct complexo * Soma(struct complexo * A, struct complexo * B){
	struct complexo * soma;
	soma = (struct complexo *) malloc(sizeof(soma));
	
	(*soma).R = (*A).R + (*B).R;
	
	(*soma).I = (*A).I + (*B).I;
	
	return soma;
	
}

struct complexo * Subtracao (struct complexo * A, struct complexo * B){
	struct complexo * subtracao;
	subtracao = (struct complexo *) malloc(sizeof(subtracao));
	
	(*subtracao).R = (*A).R - (*B).R;
	
	(*subtracao).I = (*A).I - (*B).I;
	
	return subtracao;
	
}

struct complexo * Multiplicacao (struct complexo * A, struct complexo * B){
	struct complexo * produto;
	produto = (struct complexo *) malloc(sizeof(produto));

    (*produto).R = ( (*A).R * (*B).R ) + ( (*A).I * (*B).I );
    (*produto).I = ( (*A).R * (*B).I ) + ( (*A).I * (*B).R );

    return produto;
}

double raizQuadrada(double X){
    
    return raizR(X, X, 0, X/2);

}

double raizR(double X, double max, double min, double mid){
    
    if(max-min < 0.0005){
        return mid;
    }else{
        if (mid*mid == X){
            return mid;
        }else if (mid*mid > X){
            return raizR(X, mid, min, (min+mid)/2);
        }else{
            return raizR(X, max, mid, (max+mid)/2);
        }
    }

}

double Modulo (struct complexo * C){

    return raizQuadrada(( (*C).R * (*C).R ) + ( (*C).I * (*C).I ));

}

struct complexo * Conjugado (struct complexo * C){
	struct complexo * conj;
	conj = (struct complexo *) malloc(sizeof(conj));

    (*conj).R = (*C).R;
    (*conj).I = -(*C).I;

    return conj;
}