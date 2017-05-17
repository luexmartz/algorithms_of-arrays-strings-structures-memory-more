/*Programa que intercala los elementos de dos arreglos en un tercer arreglo
	primero los elementos de A y después los elementos de B*/

	#include<stdio.h>
	#include<conio.h>

	int error,A1[' '],A2[' '],A3[' '],i,longitud,k,doble;
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
				printf("\n\nDeme la longitud de los arreglos: ");
				error=scanf("%d",&longitud);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}
		}while(longitud < 1);

		printf("\n\tArreglo 1");
		for(i=0;i<longitud;i++)
		{
			error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\tA[%d]: ",i+1);
				error = scanf("%d",&A1[i]);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}//while
		}//for

		clrscr();
		printf("\n\tArreglo 2");
		for(i=0;i<longitud;i++)
		{
      	error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\tA[%d]: ",i+1);
				error = scanf("%d",&A2[i]);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}//while
		}//for

		for(i=0;i<longitud;i++)
		{
			A3[k] = A1[i];
			k++;
		}
		for(i=0;i<longitud;i++)
		{

			A3[k] = A2[i];
			k++;
		}

		clrscr();
		printf("\n\tEl primer arreglo ingrezado es:   [");

		for(i = 0;i<longitud;i++)
		{
			 printf(",%d",A1[i]);
		}
		printf("]\n\tEl segundo arreglo ingrezado es : [");

		for(i = 0;i<longitud;i++)
		{
			 printf(",%d",A2[i]);
		}

		printf("]\n\tEl arreglo intercalado primero A[] despues B[] es: [");

		doble = longitud *2;
		for(i = 0;i<doble;i++)
		{
			 printf(",%d",A3[i]);
		}
		printf("]");
	}