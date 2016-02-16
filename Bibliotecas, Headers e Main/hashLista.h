#ifndef LISTAHASH_H
#define LISTAHASH_H
#include <stdlib.h>
#include <stdio.h>

struct TipoListaSimples
{
  unsigned long int ID;
 int nmr;
 struct TipoListaSimples *prox;
};
typedef struct TipoListaSimples TipoListaSimples;

int hashlista(TipoListaSimples *v[], unsigned long int k, long int hashcode);
int buscahashlista(TipoListaSimples *v[], unsigned long int k,long int hashcode);

#endif
