#include "abrirArq.h"
#ifndef GUI_H
#define GUI_H

ARQ * loadFile(char * nome);

void unLoadFile(ARQ * * arquivo);

void mostrarTexto(ARQ * arq);

void lerTexto(char * * texto);

void MainLoop();

ARQ * CarregarArquivo();

void AdicionarConteudo(ARQ * Arquivo);

#endif