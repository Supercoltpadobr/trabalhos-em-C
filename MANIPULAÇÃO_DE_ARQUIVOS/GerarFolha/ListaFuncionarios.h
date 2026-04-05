#ifndef LISTAFUNCIONARIOS_H
#define LISTAFUNCIONARIOS_H
#endif

typedef struct funcionario{
    
    char Nome[51];
    char matricula[13];
    char endereco[66];
    char CPF[12];
    char cod_banco[4];
    char agencia[6];
    char conta[9];
    float valor_hora;
    short int horasTrabalhadas;
    float salario;

}funcionario;

void add0funcionario(funcionario * funcionario);

funcionario * ConstroiFuncionario(char * linha);

void lerFuncionarios(funcionario * * ListaFuncionarios, int tam, char * Arquivo);

void destruirFuncionarios(funcionario * * ListaFuncionarios, int tam);

void escreverFuncionario(funcionario * F);

void LerHorasTrabalhadas(funcionario * * ListaFuncionarios, int tam, char * Arquivo);

void OrdemAlfabetica(funcionario * * LFuncionarios, int tam);

int ordenador(char * s, char * t);