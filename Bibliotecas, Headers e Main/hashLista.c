#include "hashLista.h"

int hashlista(TipoListaSimples *v[], unsigned long int k, long int hashcode)
{
	if(v[hashcode] == NULL)
	{
		v[hashcode] = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
		v[hashcode]->ID = k;
		v[hashcode]->nmr = 1;
		v[hashcode]->prox = NULL;
		return 0;
	}   
	TipoListaSimples *a = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
    	if(a == NULL) 
		return 0;
	a->ID = k;    
	a->nmr = v[hashcode]->nmr + 1;
	a->prox = v[hashcode];
	v[hashcode] = a;
    	return 0;
}

int buscahashlista(TipoListaSimples *v[], unsigned long int k, long int hashcode)
{
	static int compara = 0;
    	if(v[hashcode] == NULL) 
		return compara + 1;
    	TipoListaSimples *a = v[hashcode];
    	while(a != NULL)
    	{
         	++compara;
         	if(a->ID == k) 
			return compara;
         	a = a->prox;
    	}
    	return compara;
}


