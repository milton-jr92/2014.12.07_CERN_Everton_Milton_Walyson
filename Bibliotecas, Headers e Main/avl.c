#include "avl.h"

int buscaAVL(NoAVL *r, unsigned long int k)
{
	int compara = 0;
   	while(r != NULL)
     	{
       		if(r->chave == k)
       		{
           		++compara;
           		return compara;
       		}
       		if (r->chave > k)
          		r = r->esq;
       		else
          		r = r->dir;
       		++compara;
    	}
    	return compara;
}
/*Rotações*/
void simplesE(NoAVL **r)
{
  	NoAVL *a = *r;
  	NoAVL *b = a->dir;
	a->dir = b->esq;
  	b->esq = a;
  	a->fb = 0;
  	b->fb = 0;
  	*r = b;
}
void simplesD(NoAVL **r)
{
	NoAVL *b = *r;
  	NoAVL *a = b->esq;
	b->esq = a->dir;
  	a->dir = b;
  	a->fb = 0;
  	b->fb = 0;
  	*r = a;
}
void duplaed(NoAVL **r)
{
	NoAVL *c = *r;
  	NoAVL *a = c->esq;
  	NoAVL *b = a->dir;
	c->esq = b->dir;
  	a->dir = b->esq;
  	b->esq = a;
  	b->dir = c;
  	switch(b->fb)
	{
		case -1:
			a->fb = 0;
			c->fb = 1;
			break;
	    	case 0:
			a->fb = 0;
			c->fb = 0;
			break;
	    	case +1:
			a->fb = -1;
			c->fb = 0;
			break;
  	}
	b->fb = 0;
  	*r = b;
}
void duplade(NoAVL **r)
{
  	NoAVL *a = *r;
  	NoAVL *c = a->dir;
  	NoAVL *b = c->esq;
	c->esq = b->dir;
  	a->dir = b->esq;
  	b->esq = a;
  	b->dir = c;
  	switch(b->fb)
	{
		case -1:
			a->fb = 0;
			c->fb = 1;
			break;
	  	case 0:
			a->fb = 0;
			c->fb = 0;
			break;
	  	case +1:
			a->fb = -1;
			c->fb = 0;
			break;
  	}
  	b->fb = 0;
  	*r = b;
}
// Fim das Rotações

/*
 * PROCEDIMENTOS DE INSERCAO
 * insere um no com chave igual a k numa arvore binaria
 * de pesquisa dada. O no raiz da arvore dada esta armazenado
 * no endereco *raiz. Assuma que a arvore pode estar vazia
 * nesse caso *raiz==NULL.
 * Devolve o endereco do no recem criado ou o endereco do no
 * que ja contenha chave igual a k.
 */
int insereAVLRec(NoAVL **raiz, unsigned long int k)
{
	static int flag = 0;
	if(*raiz == NULL)	//Cria um novo nó com FB == 0;
    	{
        	*raiz = (NoAVL*)malloc(sizeof(NoAVL));
        	if(*raiz == NULL) 
			return 0;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->chave = k;
		(*raiz)->fb = alturaAVL(&(*raiz)->dir)-alturaAVL(&(*raiz)->esq);
		flag = 1;
		return 1;
    	}
	else
	{
        	if((*raiz)->chave > k)
        	{
            		if(insereAVLRec(&(*raiz)->esq, k))
            		{
				if(flag)
				{
					if((*raiz)->fb == -1)
					{
						if((*raiz)->esq->fb == -1)
							simplesD(raiz);
						else
							duplaed(raiz);
						flag =0;
					}
					else if((*raiz)->fb == 0)
					{
						(*raiz)->fb = -1;
						flag = 1;
					}
					else if((*raiz)->fb == 1)
					{
						(*raiz)->fb = 0;
						flag = 0;
					}
				}
				return 1;
            		}
			else
				return 0;            
        	}
       		else
		{
			if(insereAVLRec(&(*raiz)->dir, k))
			{
				if(flag)
				{
					if((*raiz)->fb == -1)
					{
						(*raiz)->fb = 0;
						flag = 0;
					}
					else if((*raiz)->fb == 0)
					{
						(*raiz)->fb = 1;
						flag = 1;
					}
					else if((*raiz)->fb == 1)
					{
						if ((*raiz)->dir->fb == +1)
							simplesE(raiz);
						else
							duplade(raiz);
						flag =0;
					}
				}
				return 1;
			}
			else
				return 0;
		}
	}
}

int alturaAVL(NoAVL **raiz)
{
	if(*raiz == NULL)
      		return -1;	//altura de árvore vazia é -1
   	else
	{
		int alturaesq = alturaAVL(&(*raiz)->esq);
	      	int alturadir = alturaAVL(&(*raiz)->dir);
	      	if(alturaesq < alturadir) 
			return alturadir + 1;
	      	else 
			return alturaesq + 1;
   	}
}

