#include <stdio.h>

void printarHX(int n);

int main(void){
    int n;
    scanf("%d", &n);
    printarHX(n);
    return 0;
}

void printarHX(int n){
    if(n>15){
        printarHX(n/16);
        printarHX(n%16);
    }else if (n > 9){
        printf("%c", 'a'+(n-10));
    }else{
        printf("%d", n);
    }
}