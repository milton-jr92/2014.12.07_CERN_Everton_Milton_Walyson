#include "binaria.h"

int buscaArvBin(NoArvBinaria *r, unsigned long int k)
{
	int compara = 0;
    	compara = compara + 1;
   	while(r != NULL && (r)->chave != k)
	{
       		if((r)->chave > k)
          		r = (r)->esq;
       		else
          		r = (r)->dir;
          	compara = compara + 1;
    	}
    	return compara;
}

NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, unsigned long int k)
{
	if(*raiz == NULL)
    	{
		*raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
		if(*raiz == NULL) 
			return 0;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->chave = k;
		return *raiz;
    	}
	else
	{
        	if((*raiz)->chave > k)
            		insereArvBinRec(&(*raiz)->esq, k);
        	else
            		insereArvBinRec(&(*raiz)->dir, k);
	}
}

int alturaArvBinaria(NoArvBinaria **raiz) 
{
	int alturaesq;
    	int alturadir;
   	if(*raiz == NULL)
      		return -1;	//altura de árvore vazia é -1
   	else
	{
		alturaesq = alturaArvBinaria(&(*raiz)->esq);
		alturadir = alturaArvBinaria(&(*raiz)->dir);
	      	if(alturaesq < alturadir) 
			return alturadir + 1;
      		else 
			return alturaesq + 1;
   	}
}

