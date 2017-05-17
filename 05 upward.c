/*Programa que ordena de forma ascendente un arreglo numérico*/

#include<stdio.h>
#include<conio.h>

int A[' '],i,j,aux,error,longitud;

void main()
{
	
		do
		{
			clrscr();
			if(longitud<1)
			{
				printf("\nDEBE INGRESAR UN NUMERO ENTERO");
			}
			error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\nDeme la longitud del arreglo: ");
				error=scanf("%d",&longitud);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}
		}while(longitud < 1);


	 for(i =0; i < longitud; i++)
	 {
    	
			error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\tA[%d]: ",i+1);
				error = scanf("%d",&A[i]);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}
	 }

	 printf("\n\n\tEl arreglo ordenado es: [");
	 for(i =0;i<longitud-1;i++)
	 {
			for(j = i+1; j <longitud;j++)
			{
				  if(A[i]>A[j])
				  {
						aux = A[i];
						A[i] = A[j];
						A[j] = aux;
				  }//if

			}//for

	 }//for
    
	 for(i=0;i<longitud;i++)
	 {
		printf(",%d",A[i]);
	 }//for
	 printf("]");

}//main