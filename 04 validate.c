	/*	Programa que convierte minúsculas a mayúsculas*/

#include<stdio.h>
#include<string.h>
#include<conio.h>

 char cadena[' '];
 int i,longitud;

//convertir mayusculas a minusculas

void main()
{

  do
  {
		clrscr();
		if(i > longitud)
			printf("\n\n\tNo introdusca numeros!");
		printf("\n\n\tIntrodusca una cadena: ");
		flushall();
		gets(cadena);

		for(i=0;cadena[i]!= '\0';i++)
		{
			longitud++;

		}

		for(i=0;i<longitud;i++)
		{
			if(cadena[i] <= 64 || cadena[i] >= 121 || cadena[i] > 90 && cadena[i] < 97)
			{
				  i = longitud + 2;
			}
		}

	}while(i > longitud);

	for(i=0;i<longitud;i++)
	{
		printf("%c",cadena[i]);
	}

}