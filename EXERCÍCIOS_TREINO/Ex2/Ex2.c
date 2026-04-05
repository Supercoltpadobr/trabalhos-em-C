#include <stdio.h>

void ordenacao_mequetrefe(int * vetor, int tam);

int main(){// Mediana de todos os valores positivos
    int N=0, nums[100], negativos=0;
    float mediana;

    while (N<100)
    {
        scanf("%d", &nums[N]);
        if(nums[N]==0)
            break;
        else if(nums[N]<0)
            negativos += 1;

        N+=1;
    }

    ordenacao_mequetrefe(nums, N);

    N = N-negativos;

    if(N%2 == 0){
        mediana = (float)(nums[(N/2)+negativos]+nums[(N/2)+negativos-1])/2;
    }else{
        mediana = nums[(N/2)+negativos];
    }

    if (N==0){
        printf("0");
    }else{
        printf("%f", mediana);
    }
    return 0;

}



void ordenacao_mequetrefe(int * vetor, int tam){
    int holder;
    for(int i=0; i<tam; i++){     //Ordenando o vetor nums
        for(int j=i; j<tam; j++){
            if (vetor[i] > vetor[j]){
                holder = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = holder;
            }       
        }
    } 
}