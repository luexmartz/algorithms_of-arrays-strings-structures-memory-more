/* Dado dos matrices de mxn elementos donde m=n, crear un programa en C el cual,
intercambie los elementos de la diagonal principal con los elementos de la diagonal 
invertida. Se imprimirá, el arreglo de entrada, y el arreglo con las diagonales invertidas. */

#include<stdio.h>
#include<conio.h>


void escribe(int m,int n,int A[' '][' ']);
void proceso(int m,int n,int A[' '][' ']);
void imprime(int m,int n,int A[' '][' '],int B[' '][' ']);

void main()
{
  int A[' '][' '],error,m,n;

	do{
	error=0;
	while(error==0)
	{
		inicio:
		fflush(stdin);
		printf("\n\n\tN° de filas: ");
		error= scanf("%d",&m);

	}
	}while(m<2);
	do{
	error=0;
	while(error==0)
	{
		fflush(stdin);
		printf("\n\n\tN° columnas: ");
		error= scanf("%d",&n);

	}
	}while(n<2);

	if(m!=n)
		{printf("\n\nError!! Debe Ingresar una matriz cuadrada\n\n");
		goto inicio;  }
	escribe(m,n,A);
}

void escribe(int m,int n,int A[' '][' '])
{
	int i,j,error;

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\nA[%d][%d]: ",i+1,j+1);
				error= scanf("%d",&A[i][j]);


			}
		}
		proceso(m,n,A);
}

void proceso(int m,int n,int A[' '][' '])
{
	int i,j,B[' '][' '],l,aux,k=0;

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			B[i][j]= A[i][j];
		}


		l=n;
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
			  aux=B[i][j];
			  B[i][j]= B[k][l-1];
			  B[k][l-1]=aux;

			  k++;
			  l--;
			}
		}
		imprime(m,n,A,B);
}

void imprime(int m,int n,int A[' '][' '],int B[' '][' '])
{

		int i,j;
		clrscr();
		printf("\nMatriz de entrada\n");
		for(i=0;i<m;i++)
		{
			printf("\n");
			for(j=0;j<n;j++)
			printf("%5d ",A[i][j]);
		}

		printf("\n\n\tMatriz con diagonalez inversas");
		 for(i=0;i<m;i++)
		{
			printf("\n");
			for(j=0;j<n;j++)
			printf("%5d ",B[i][j]);
		}
}

