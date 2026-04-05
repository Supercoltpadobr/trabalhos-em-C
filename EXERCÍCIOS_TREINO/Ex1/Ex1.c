#include <stdio.h>

#define MAIOR(x, y) (x>=y ? x : y)

#define MENOR(x,y) (x<=y ? x : y)

int main(){//soma de todos os números entre A e B (inclusive)
    int A, B, soma=0;


    scanf("%d", &A);
    scanf("%d", &B);

    if (A == B){
        printf("0\n");
        return 0; 
    }

    for(int i = MENOR(A, B); i <= MAIOR(A, B); i++){
        soma += i;
    }

    printf("%d\n", soma);

    return 0;

}