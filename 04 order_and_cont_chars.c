/*Programa en c, que dado una cadena toma las palabras de la 
 dicha cadena y las imprime acomodadas en orden alfabetico además 
 de mencionar el número de veces que la palabra se encuentra en la cadena*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

	 char cadena[' '],A[' '][' '],aux[' '];
	 char *elemento;
	 int k,i,j,cont;

void main()
{
	
		printf("\n\n\tIngrese una cadena: ");
		flushall();
		gets(cadena);
		elemento = strtok(cadena, " ");
		while(elemento != NULL)
		{

		  strcpy(A[k],elemento);
		  elemento = strtok(NULL, " ");
		  k++;

		 }
		 for(i=0;i<k;i++)
		 {
			for(j = i+1;j<k;j++)
			{
				if(strcmpi(A[i],A[j])>0)
				{
					strcpy(aux,A[i]);
					strcpy(A[i],A[j]);
					strcpy(A[j],aux);
				}
			}
		 }
		 printf("\n\n\tPALABRAS ORDENADAS\n\n");

		 for(i=0;i<k;i++)
			printf("\n\t %d): %s",i+1,A[i]);

		 for(i=0;i<k;i++)
		 {
			cont = 0;
			for(j=0;j<k;j++)
			{
				if(strcmpi(A[i],A[j]) == 0)
					cont++;
			}

			printf("\n\n\tPALBRA %s : %d palabra/s",A[i],cont);
		 }

}
