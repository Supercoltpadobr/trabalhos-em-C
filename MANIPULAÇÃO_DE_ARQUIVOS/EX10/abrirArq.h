#ifndef LERARQ_H
#define LERARQ_H

typedef struct ARQUIVO{
	char * nome;
	char * text;
	char type[10];
	int Byte_size;
} ARQ;

void AbrirLer(char * nome_Arquivo, char * * texto, int * TamanhoBytes);

void AbrirEscrever(char * nome_Arquivo, char * texto);

void AbrirAdicionar(char * nome_Arquivo, char * texto);

void Fechar(ARQ * arquivo);

#endif