  /*Dado un arreglo de mxn elementos, crear un programa en C el cual, tome los
elementos de la matriz que pertenecen al centro y los almacene en un vector. Se
imprimirá la matriz de entrada y el vector.*/

#include<stdio.h>
#include<conio.h>

void mxn();
void salida(int m,int n, int A[' '][' ']);
entrada(int m,int n);

void main()
{
	mxn();
}

 void mxn()
 {
	int error,m,n;
	 do
	 {
		 clrscr();
			if(m<1)
			{
				printf("\nDEBE INGRESAR UN NUMERO ENTERO");
			}
			error=0;
			while(error==0)
			{
				flushall();
				printf("\n\nIngrese el numero de filas deseadas: ");
				error=scanf("%d",&m);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}//if
			}//while

		}while(m % 2 == 0);

		do
		{
			clrscr();
			if(n<1)
			{
				printf("\nDEBE INGRESAR UN NUMERO ENTERO");
			}
			error=0;
			while(error==0)
			{
				flushall();
				printf("\n\nIngrese el numero de columnas deseadas: ");
				error=scanf("%d",&n);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}
		}while(n % 2 == 0);


		clrscr();
		entrada(m,n);

	 }// fin de funcion

 //--------------------------------------------------------------------
	entrada(int m,int n)
	{
		int i,j,error,num,A[' '][' '];

		for(i=0;i<m;i++)
		{

			  for(j=0;j<n;j++)
			  {

				error=0;
				while(error==0)
				{
					flushall();
					printf("\n\n\tIngrese A[%d][%d] :  ",i+1,j+1);
					error = scanf("%d",&num);
					A[i][j]=num;
					if(error==0)
					{
						clrscr();
						printf("\nDEBE INGRESAR UN NUMERO ENTERO");

					} //if
				} // while

			  } //for

		 } //for

		clrscr();
		 salida(m,n,A);
		} // fin de funcion
 //----------------------------------------------------------------------


 void salida(int m,int n, int A[' '][' '])
 {
	int j,i;
		printf("\n\n\t\tMATRIZ");
		for(i=0;i<m;i++)
		{

			printf("\n");
			for(j=0;j<n;j++)
			printf("\t %d ",A[i][j]);
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if((i == (m/2)) && (j == (n/2)))
					printf("\n\n\tCentral[%d] ",A[i][j]);
			}
		}

	} // fin funcion