#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct TipoLista
{
  unsigned long int ID;
  struct TipoLista *prox;
};
typedef struct TipoLista TipoLista;

TipoLista *inserelista(TipoLista **cabeca, unsigned long int k);
int buscalist(TipoLista *cabeca, unsigned long int k);

#endif
