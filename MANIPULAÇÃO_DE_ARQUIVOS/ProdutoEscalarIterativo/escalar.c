#include <stdio.h>
#include "escalar.h"


float ProdutoEscalar(float * V1, float * V2, int N){
    if (N!=0){
        return ProdutoEscalar(V1, V2, N-1) + (V1[N-1]) * (V2[N-1]);
    }
    else{
        return 0;
    }
}