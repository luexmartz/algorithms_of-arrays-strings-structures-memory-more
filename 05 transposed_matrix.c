/*programa en C el cual lee una matriz A de M x N elementos y forma una matriz traspuesta de A.*/

#include<stdio.h>
#include<conio.h>
int m,n,i,j,c,k,A[' '][' '],B[' '],error,aux;

void main()
{


	error=0;
	while(error==0)
	{
		flushall();
		printf("\n\n\tN° de filas:");
		error=scanf("%d",&m);
		if(error==0)
		{
			clrscr();
			printf("\n\n\tDebe de Introducir un numero");
		}
	}//while

	error=0;
	while(error==0)
	{
		flushall();
		printf("\n\n\tN° de Columnas:");
		error=scanf("%d",&n);
		if(error==0)
		{
			clrscr();
			printf("\n\n\tDebe de Introducir un numero");
		}
	}//while



	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			error=0;
			while(error==0)
			{
				flushall();
				printf("\n\tA[%d][%d]:",i+1,j+1);
				error=scanf("%d",&A[i][j]);
				if(error==0)
					printf("\n\tDebe de Introducir un numero");
			}//while
		}//for
	}//for

	clrscr();
	printf("\n\tMatriz de Entrada");
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("\t%d",A[i][j]);
		}
	}

	printf("\n\n\tMatriz Transpuesta");
	for(i=0;i<n;i++)
	{
			printf("\n");
			for(j=0;j<m;j++)
			{
				printf("\t%d",A[j][i]);
			}//for
	}//for
}//main
