#include <stdio.h>

#define NumeroDeArquivos 2

int main(void){
    char nomeArquivoN[100], mArqNome[100], linha[1000];

    printf("Novo arquivo: "); scanf("%s", mArqNome);
    FILE * arquivoM = fopen(mArqNome, "w");

    for (int i=0; i<NumeroDeArquivos; i++){
        printf("Arquivo%d: ", i); scanf("%s", nomeArquivoN);

        FILE * arquivoN = fopen(nomeArquivoN, "r");
        
        if (arquivoN == NULL){
            printf("ERRO - Arquivo não aberto\n");
            continue;
        }
        while (fgets(linha, sizeof(linha), arquivoN) != NULL)
        {
            fputs(linha, arquivoM);
        }
        
        fclose(arquivoN);
    }

    fclose(arquivoM);
    
    return 0;
}