#include "linear.h"
#include <stdio.h>
#include <stdlib.h>
// By Waly


long int hashlinear(unsigned long int **v, unsigned long int ID,long int hashcode){
         int colisao = 0;
       	 static int count=0;
         for(;;)
         {
         
         if(*(*v+hashcode)==0)
         {

            *(*v+hashcode)=ID;
            //printf("%10lu\n", *(*v+hashcode));
            return colisao;
         }
         if(hashcode==99999)
             hashcode=0;
         else
             ++hashcode;
         colisao=colisao+1;
         }
}


/*int buscahashline(long int *v, unsigned long int k,long int hashcode)
{
    int compara=1;
    int i =0;
    //printf("Entrou 1");
     while (*(v+hashcode)!=k&&i<100000)
     {
         //  printf("Entrou 2");
        if(hashcode==99999)
            hashcode=0;
        else
            hashcode=hashcode+1;
        compara=compara+1;
     i++;
     }
    //printf("Entrou 3");
    return compara;
}
*/
int buscahashline(long int *v, unsigned long int k,long int hashcode)
{
    static int compara=0;
    int i =0;
     while (*(v+hashcode)!=k&&i<100000)
     {

        if(hashcode==99999)
            hashcode=0;
        else
            hashcode=hashcode+1;
        compara=compara+1;
     i++;
     }
    return compara;
}
