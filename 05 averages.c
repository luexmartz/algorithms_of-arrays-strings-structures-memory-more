/*Programa en C, el cual Calcula el promedio de n valores almacenados
en un vector. Determina además cuantos son mayores que el promedio, e imprime el
promedio, el número de datos mayores que el promedio y una lista de valores mayores
que el promedio, así como el vector original.*/

#include<stdio.h>
#include<conio.h>

void leer();
void llenar(int n);
void proceso(int n,int suma,int A[' ']);
void imprime(int n,int k,int x,int prom,int sumar,int A[' '],int B[' ']);

void main()
{
	leer();
}

void leer()
{
	int error,n;
	error=0;

	while(error==0)
	{
		fflush(stdin);
		printf("\n\n\tTotal de elementos del arreglo A:");
		error=scanf("%d",&n);
		if(error==0)
	{
		printf("\n\n\tDebe de introducir un numero");}
	}
	llenar(n);
}// fin funcion


void llenar(int n)
{
	int i,error,A[' '],suma=0;
	for(i=0;i<n;i++)
	{
		error=0;
		while(error==0)
		{
			fflush(stdin);
			printf("\n\n\tIngrese A[%d]: ",i+1);
			error=scanf("%d",&A[i]);
			if(error==0)
			{
				printf("\n\n\tDebe de introducir un numero");
			}
		}

		suma = suma+A[i];

	}
	proceso(n,suma,A);
}// funcion

 void proceso(int n,int suma,int A[' '])
 {
		int prom;
		int i,x=0,k=0,B[' '],sumar = 0;

		prom = suma/n;
		for(i=0;i<n;i++)
		{
			if(A[i]>prom)
			{
				x++;
			}
		}

		for(i=0;i<n;i++)
		{
			if(A[i]>prom)
			{
				B[k]=A[i];
				sumar=sumar+A[i];
				k++;
			}
		}
		imprime(n,k,x,prom,sumar,A,B);

	}// funcion


	void imprime(int n,int k,int x,int prom,int sumar,int A[' '],int B[' '])
	{
		printf("\n");
		int i;
		printf("\n\n\tArreglo de entrada: [");
		for(i=0;i<n;i++)
		{
			printf(" %d",A[i]);
		}

		printf("]\n\n\tArreglo con elementos mayores al promedio: [");
		for(i=0;i<k;i++)
		{
			printf(" %d",B[i]);
		}

			printf("]\n\n\tPromedio de los elementos del Arreglo es: %d",prom);
			printf("\n\n\tSuma de los elementos mayores al promedio es: %d",sumar);
			printf("\n\n\tCantidad de elementos mayores que el promedio es: %d",x);

	}// funcion
