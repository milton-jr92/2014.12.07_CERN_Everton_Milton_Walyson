#include "hashLinear.h"

long int hashlinear(unsigned long int **v, unsigned long int ID, long int hashcode)
{
	int colisao = 0;
       	static int count=0;
        for(;;)
        {
		if(*(*v+hashcode) == 0)
         	{
			*(*v + hashcode) = ID;
            		return colisao;
         	}
		if(hashcode == 99999)
        		hashcode = 0;
        	else
             		++hashcode;
        	colisao = colisao + 1;
        }
}

int buscahashline(long int *v, unsigned long int k, long int hashcode)
{
	static int compara = 0;
    	int i = 0;
    	while(*(v+hashcode) != k && i < 100000)
    	{
    		if(hashcode == 99999)
            		hashcode = 0;
        	else
            		hashcode = hashcode + 1;
        	compara = compara + 1;
     		i++;
     	}
    	return compara;
}
