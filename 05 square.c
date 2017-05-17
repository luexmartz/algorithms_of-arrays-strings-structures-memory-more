 /* Programa que genera un segundo arreglo con los elementos al cuadrado del primero. */

 #include<stdio.h>
 #include<conio.h>

 int error,suma,valor,i,longitud,A1[' '],A2[' '];

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

	for(i=0;i<longitud;i++)
	{


			error=0;
			while(error==0)
			{
				fflush(stdin);
				printf("\n\tA[%d]: ",i);
				error = scanf("%d",&A1[i]);

				if(error==0)
				{
					clrscr();
					printf("\nDEBE INGRESAR UN NUMERO ENTERO");

				}
			}

		A2[i] = A1[i]*A1[i];
		suma = suma + A2[i];

	}
	clrscr();

	printf("\n\tEl arreglo ingrezado es: ");

	for(i=0;i<longitud;i++)
	{
		printf(" %d ",A1[i]);
	}

	printf("\n\tEl arreglo con lo elemenos al cuadrado es: ");

	for(i=0;i<longitud;i++)
	{
		printf(" %d ",A2[i]);
	}
   
	printf("\n\tLa suma de los elementos al cuadrado es: %d ",suma);

 }