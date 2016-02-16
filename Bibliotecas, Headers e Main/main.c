#include "listaEncadeada.h"
#include "binaria.h"
#include "avl.h"
#include "hashLinear.h"
#include "hashLista.h"

int main(void)
{
/*--------------------------------------------------------------------------------------*/
/*Procedimentos para povoamento e busca da estrutura Lista Encadeada*/	
	TipoLista *lista = NULL;
	unsigned long int ID;	// Variavel para armazeandas os ID's
	FILE *pArquivo;
	FILE *pArqrequi;
	pArquivo = fopen("IDs-particulas.txt", "rt");
	if(pArquivo == NULL)
		return -1;
	/*Laço para armazenar os ID's nas estruturas de dados,
         *Arvore Bin Pesquisa, AVL, hash Linear, Hash Listas
         *e Lista Encadeada
	 */
	while(!feof(pArquivo))	//Lê até o final do arquivo
	{
		fscanf(pArquivo, "%10lu\n", &ID);	//Unsigned long int %10 lu
		inserelista(&lista, ID);	//Inserir em uma Lista encadeada
	}
	fclose(pArquivo);
    	pArqrequi = fopen("requisicoes-fisicos.txt", "rt");
    	if(pArqrequi == NULL)
		return -1;
    	int list = 0;
	while(!feof(pArqrequi))
	{
		fscanf(pArqrequi, "%10lu\n", &ID);
		list = list + buscalist(lista, ID);
	}
    	fclose(pArqrequi);
	list = list / 13;
    	printf("Lista Encadeada:\nMedia de comparacoes %d\n\n", list);
/*--------------------------------------------------------------------------------------*/
/*Procedimentos para povoamento e busca da estrutura Arvore Binária de Pesquisa*/	
	NoArvBinaria *raiz = NULL;	//Ponteiro para Arvore Binaria
	int alturaBin;	//variavel para receber o calculo da altura
	int mil = 0;	//variavel para contar a altura a cada mil ID's inseridos
	unsigned long int IDBin;	//Variavel para armazenar os ID's	
	FILE *pArquivo2; 
	FILE *arquivoBIN;
	FILE *pArqrequi2;
	pArquivo2 = fopen("IDs-particulas.txt", "rt");
	arquivoBIN = fopen("GraficoBin.txt", "w");
	if(pArquivo2 == NULL)
		return -1;		
	while(!feof(pArquivo2))	/*Le tudo até o final do arquivo*/
	{
		fscanf(pArquivo2, "%10lu\n", &IDBin);	/*Unsigned long int %10 lu*/
		insereArvBinRec(&raiz, IDBin);	//Colocar o ID na Arvore Binaria
		++mil;	//Somar 1 a cada ID inserida.
  		if(mil == 1000)	//Contar altura das arvores a cada 1000 elementos
         	{
                	alturaBin = alturaArvBinaria(&raiz);
                	fprintf(arquivoBIN, "%d\n", alturaBin);
                	mil = 0;
            	}
	}
	fclose(pArquivo2);	
	pArqrequi2 = fopen("requisicoes-fisicos.txt", "rt");
    	if(pArqrequi2 == NULL)
        	return -1;	
	int bin = 0;	//Variavel para armazenar o numero de comparações realizadas na busca.
	while(!feof(pArqrequi2))
	{
		fscanf(pArqrequi2, "%10lu\n", &IDBin);
		bin = bin + buscaArvBin(raiz, IDBin);
	}
	fclose(pArqrequi2);	
	bin = bin / 13;	//O numero de comparações deve ser divido por 13
	printf("Arvore Binaria:\nMedia de comparacoes %d\n", bin);
	alturaBin = alturaArvBinaria(&raiz);
	printf("Altura %d\n\n", alturaBin);
/*--------------------------------------------------------------------------------------*/
/*Procedimentos para povoamento e busca da estrutura Arvore AVL*/
	NoAVL *r = NULL;	//Ponteiro para AVL
	int alturaAvl;	//calcular a altura
	int mil2 = 0;	//Variavel para controlar quando 1000 nós forem inseridos.
	unsigned long int IDAVL;	//Variavel para armazeandas os ID's
	FILE *pArquivo3;
	FILE *arquivoAVL;
	FILE *pArqrequi3;
	pArquivo3 = fopen("IDs-particulas.txt", "rt");
	arquivoAVL = fopen("GraficoAVL.txt", "w");
	if (pArquivo3 == NULL)
		return -1;
	/*Laço para armazenar os ID's nas estruturas de dados,
         *Arvore Bin Pesquisa, AVL, hash Linear, Hash Listas
         *e Lista Encadeada
	 */
	while(!feof(pArquivo3))	/*Lê até o final do arquivo*/
	{
		fscanf(pArquivo3,"%10lu\n", &IDAVL);
		insereAVLRec(&r, IDAVL);	//Colocar o ID na AVL
		++mil2;
		if(mil2 == 1000)
		{
			alturaAvl = alturaAVL(&r);
            		fprintf(arquivoAVL, "%d\n", alturaAvl);     
            		mil2 = 0;
        	}
	}
	fclose(pArquivo3);
	pArqrequi3 = fopen("requisicoes-fisicos.txt", "rt");
    	if(pArqrequi3 == NULL)
    		return -1;
	int avl = 0;	//Variavel para receber as comparações
	while(!feof(pArqrequi3))
	{
		fscanf(pArqrequi3, "%10lu\n", &IDAVL);
		avl = avl + buscaAVL(r, IDAVL);
	}
    	fclose(pArqrequi3);
	avl = avl / 13;
	printf("Arvore AVL:\nMedia de Comparacoes %d\n", avl);
	alturaAvl = alturaAVL(&r);
	printf("Altura %d\n\n", alturaAvl);
/*--------------------------------------------------------------------------------------*/
/*Procedimentos para povoamento e busca da estrutura Hash Linear*/
	long int hashcode;
    	int i = 0;
    	unsigned long int IDLinear;
    	long int linear = 0;	//colisoes da linear
	unsigned long int *vlinear = (unsigned long int*)malloc(100000*sizeof(unsigned long int));	//vetor para o hash com linear probing
	while(i < 100000)
    	{
        	vlinear[i] = 0;
        	i++;
    	}    
   	FILE *pArquivo4;
   	FILE *arquivoCOL;
   	FILE *arquivoMIL;
    	pArquivo4 = fopen("IDs-particulas.txt", "rt");
    	arquivoCOL = fopen("colisoes.txt", "w");
    	arquivoMIL = fopen("colisoesMIL.txt", "w");
    	if(pArquivo4 == NULL)
		return -1;
    	int mil3 = 0;
    	int count = 0;
	int totalcolisao = 0;
    	while(!feof(pArquivo4))
	{
		fscanf(pArquivo4, "%10lu\n", &IDLinear);
		hashcode = IDLinear % 100000;
		linear = hashlinear(&vlinear, IDLinear, hashcode);
		totalcolisao = totalcolisao + linear;
        	fprintf(arquivoCOL, "ID: %10lu Colisoes: %li\n", IDLinear, linear);
        	++mil3;
        	++count;
        	if(count == 1000)
            	{
                	fprintf(arquivoMIL, "Insercoes: %d Colisoes: %d\n", mil3, totalcolisao);
                	count = 0;
            	}
    	}
    	fclose(pArquivo4);
    	FILE *pArqrequi4;
    	pArqrequi4 = fopen("requisicoes-fisicos.txt", "rt");
    	if(pArqrequi4 == NULL)
		return -1;
	int hashline = 0;	//Contar o numero de comparações durante a busca.
    	while(!feof(pArqrequi4))
	{
		fscanf(pArqrequi4, "%10lu\n", &IDLinear);
		hashcode = IDLinear % 100000;
		hashline = buscahashline(vlinear, IDLinear, hashcode);
    	}
    	fclose(pArqrequi4);
    	hashline = hashline / 13;
    	printf("Hash Linear:\nMedia de Comparacoes %d\n", hashline);
    	printf("Numero de Colisoes %d\n\n", totalcolisao);
/*--------------------------------------------------------------------------------------*/
/*Procedimentos para povoamento e busca da estrutura Hash com Lista Encadeada*/
	long int hashcode2;	//Calcular o hash
    	TipoListaSimples *vhashlista[100000];	
	unsigned long int IDLista;	//Variavel para armazeandas os ID's
	int i2 = 0;
	long int listas = 0;	//colisoes da hashlista encadeada
	while(i2 < 100000)
    	{
        	vhashlista[i2] = NULL;
        	i2++;
    	}
	FILE *pArquivo5;
	FILE *arquivoPOVO;
	FILE *arquivoVazia;
	pArquivo5 = fopen("IDs-particulas.txt", "rt");
    	arquivoPOVO = fopen("Colisao.txt", "w");
    	if(pArquivo5 == NULL)
		return -1;
	while(!feof(pArquivo5))
	{
		fscanf(pArquivo5, "%10lu\n", &IDLista);
		hashcode2 = IDLista % 100000;
		hashlista(vhashlista, IDLista, hashcode2);	//Criar o Hash com Lista, colocar ID's, contar colisao
	}
	fclose(pArquivo5);
	int cem = 0;
	while(cem < 100000)
	{                
         	if(vhashlista[cem] != NULL)
         		fprintf(arquivoPOVO, "Lista : %d Quantidade: %d\n", cem, vhashlista[cem]->nmr);
		else
         		fprintf(arquivoPOVO, "Lista : %d Quantidade: 0\n", cem);
         	++cem;
    	}
    	FILE *pArqrequi5;
    	pArqrequi5 = fopen("requisicoes-fisicos.txt", "rt");
    	if(pArqrequi5 == NULL)
		return -1;
	int hashlist = 0;	//Contar o numero de comparacoes durante a busca.
	while(!feof(pArqrequi5))
	{
		fscanf(pArqrequi5, "%10lu\n", &IDLista);
		hashcode2 = IDLista % 100000;
		hashlist = buscahashlista(vhashlista, IDLista, hashcode2);
	}
	fclose(pArqrequi5);
	printf("Hash com Lista Encadeada:\nMedia de Comparacoes %d\n", hashlist);
    	hashlist = hashlist / 13;
	printf("Numero de Colisoes %d\n", hashlist);
/*--------------------------------------------------------------------------------------*/

	return 0;
}
