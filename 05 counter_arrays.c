  /*Dado dos arreglos de mxn elementos, programa en C el cual, suma los dos
arreglos y los guarda en un tercer arreglo, únicamente los elementos que sean
mayores a un valor dado por el teclado*/

#include<stdio.h>
#include<conio.h>

int A[' '][' '], m, n, B[' '][' '], i, j,suma, C[' '][' '], error;

void main()
{
	error=0;
	while(error==0)
	{

		flushall();
		printf("\n\n\tN° de filas: ");
		error=scanf("%d",&m);
		if(error==0)
		{
			clrscr();
			printf("\n\n\tDebe de Introducir un numero");

		}
	}

	error=0;
	while(error==0)
	{
		clrscr();
      flushall();
		printf("\n\n\tN° de columnas: ");
		error=scanf("%d",&n);
		if(error==0)
			printf("\n\n\tDebe de Introducir un numero");
	}

	//entrada a matriz A

   clrscr();
	// Dar entrada a la matriz
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			error=0;
			while(error==0)
			{
				flushall();
				printf("\nA[%d][%d]:",i+1,j+1);
				error=scanf("%d",&A[i][j]);
				if(error==0)
				{
					clrscr();
					printf("\n\n\tDebe de Introducir un numero");
				}
			}//while
		}//for
	}// for

	flushall();
	clrscr();

   clrscr();
	// Dar entrada a la matriz
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			error=0;
			while(error==0)
			{
				flushall();
				clrscr();
				printf("\nB[%d][%d]:",i+1,j+1);
				error=scanf("%d",&B[i][j]);
				if(error==0)
					printf("\n\n\tDebe de Introducir un numero");
			}//while
		}//for
	}// for
	flushall();
   clrscr();

	//  suma de matrices

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			C[i][j]=A[i][j]+ B[i][j];
	
		}
	}


	printf("\n\n\tArreglo 1\n");

	//imprimir el arreglo 1
	for(i=0; i<m; i++)
	{
		printf("\n\t");
		for(j=0;j<n;j++)
			printf("%d ",A[i][j]);
	}

	printf("\n\n\tArreglo 2\n");

	//imprimir el arreglo 2

	for(i=0; i<m; i++)
	{
		printf("\n\t");
		for(j=0;j<n;j++)
			printf("%d ",B[i][j]);
	}

	printf("\n\n\tArreglo 1 + Arreglo 2 :\n");

	for(i=0;i<m;i++)
	{
		printf("\n\t");
		for(j=0;j<n;j++)
		printf("%d ",C[i][j]);
	
	}
}
