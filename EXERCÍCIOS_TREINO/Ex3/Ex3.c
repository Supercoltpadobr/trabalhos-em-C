#include <stdio.h>


int main(){
    int N, j=0; // j auxilia a contar quantos 0 colocar ao final

    scanf("%d", &N);

    int vetor[N];

    for(int i=0; i<N; i++){

        scanf("%d", &vetor[j]);

        if(vetor[j] == 0)
            j--;

        j++;
    }
    
    while (j<N)
    {
        vetor[j] = 0;
        j++;
    }
    
    for(int i=0; i<N; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}