/*Programa que obtiene la suma de la diagonal principal de una matriz*/

#include<stdio.h>
#include<conio.h>

int error,i,j,num,m,n,matriz[' '][' '],suma;

void main()
{
	do
	{
		do
 		{
		    clrscr();

		    if(m != n)
			printf("\n\tIngrese una matriz cuadrada !!");

			if(m<1)
			{
				printf("\nDEBE INGRESAR UN NUMERO ENTERO");
			}
			error=0;

			while(error==0)
			{
				fflush(stdin);
				printf("\n\nIngrese las filas deseadas: ");
				error=scanf("%d",&m);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}

		}while(m<1);

		
		do
 		{
		    clrscr();
		    if(m != n)
			printf("\n\tIngrese una matriz cuadrada !!");

			if(n<1)
			{
				printf("\nDEBE INGRESAR UN NUMERO ENTERO");
			}
			error=0;

			while(error==0)
			{
				fflush(stdin);
				printf("\n\nIngrese las columnas deseadas: ");
				error=scanf("%d",&n);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}

		}while(n<1);


	}while(m != n);

	clrscr();

	for(i=0;i<m;i++)
	{

		for(j=0;j<n;j++)
		{
      	error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\n\tIngrese A[%d][%d] :  ",i+1,j+1);
				error = scanf("%d",&num);
				matriz[i][j]=num;

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}

		}
	}

	for(i=0;i<m;i++)
	{
		for(j =0;j<n;j++)
		{
			if(j == i)
			{
				suma = suma + matriz[i][j];
			}
		}
	}
   clrscr();
	printf("\n\n\t\tMATRIZ");
	for(i=0;i<m;i++)
	{
		printf("\n\t\t");
		for(j =0;j<n;j++)
		{
			printf(" %d ",matriz[i][j]);
		}
	}




	printf("\n\n\tLa suma de la diagonal pricipal es : %d",suma);
}