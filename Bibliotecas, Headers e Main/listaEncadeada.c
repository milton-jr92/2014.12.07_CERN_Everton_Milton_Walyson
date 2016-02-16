#include "listaEncadeada.h"

TipoLista *inserelista(TipoLista **cabeca, unsigned long int k)
{
	TipoLista *a = (TipoLista*)malloc(sizeof(TipoLista));
	if(a != NULL)
	{
		a->prox = *cabeca;
		a->ID = k;
	}
    	else
    	{
        	printf("Nao inseriu");
        	return NULL;
    	}
    	*cabeca = a;
	return NULL;
}

int buscalist(TipoLista *cabeca, unsigned long int k)
{
    	int compara = 0;
	while(cabeca != NULL)
	{
		if(cabeca->ID == k)
        	{
            		++compara;
            		return compara;
		}
		++compara;
		cabeca = cabeca->prox;
	}
	return compara;
}


