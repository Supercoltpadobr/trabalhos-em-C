#include "procedimentos.h"

int main(void){
    int altura, largura;
    int * * imagem;
    lerPGM("pgmP2_1.pgm", &altura, &largura, imagem);

    printarMatriz(imagem, altura, largura);
    
    return 0;
}
