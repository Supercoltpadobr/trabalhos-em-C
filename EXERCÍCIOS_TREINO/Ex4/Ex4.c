#include <stdio.h>
#include <math.h>

int main(){// calculo número primo
    long long int numero;

    scanf("%lld", &numero);

    if (numero < 2){
            printf("%lld nao primo", numero);
            return 0;
    }

    int limite = (int) sqrt((double)numero);

    for(int i=2; i<=limite; i++){
        if(numero%i == 0){
            printf("%lld nao primo", numero);
            return 0;
        }
    }
    
    printf("%lld primo", numero);

    return 0;
}