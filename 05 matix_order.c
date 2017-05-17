/* Dada una matriz de m x n elementos desarrollar un programa en C el cual, ordene los
elementos de la matriz por fila y los dejes ordenados en la misma fila. Imprimir la matriz
ordenada por filas. */

#include<stdio.h>
#include<conio.h>

int A[' '][' '],B[' '][' '],i,j,error,aux,m,n,k;

void main()
{
	do{
		error=0;
		while(error==0)
		{
			flushall();
			printf("\n\n\tN° de dilas: ");
			error= scanf("%d",&m);
			if(error ==0)
			{
				clrscr();
				printf("\n\n\tDebe Ingrezar un numero\n\n");
			}
		}
	}while(m<1);

	do
	{
		error=0;
		while(error==0)
		{
			flushall();
			printf("\n\n\tN° de columnas: ");
			error= scanf("%d",&n);
			if(error ==0)
			{
				clrscr();
				printf("\n\n\tDebe Ingrezar un numero\n\n");
			}
		}
	}while(n<1);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			error=0;
			while(error==0)
			{
				flushall();
				printf("\nA[%d][%d]: ",i+1,j+1);
				error= scanf("%d",&A[i][j]);
				if(error ==0)
				{
					clrscr();
					printf("\n\n\tDebe Ingrezar un numero");
				}

			}
			B[i][j]= A[i][j];

		}

		for(i=0;i<m;i++)
			for(j=0;j<n-1;j++)
				for(k=j+1;k<n;k++)
				{
					if(B[i][j]>B[i][k])
					{
						aux=B[i][j];
						B[i][j]= B[i][k];
						B[i][k]=aux;
					}
				}

	clrscr();
	printf("\n\n\tMatriz de entrada\n");
	 for(i=0;i<m;i++)
		{
		printf("\n\t");
		for(j=0;j<n;j++)
			printf("%d ",A[i][j]);
		}

		printf("\n\n\tMatriz ordenada!\n");
	 for(i=0;i<m;i++)
	{
		printf("\n\t");
		  for(j=0;j<n;j++)
		  {
				printf("%d ",B[i][j]);

			}
	}
}