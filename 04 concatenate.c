/*Programa en c que concatena dos strings*/

#include<stdio.h>
#include<string.h>

char cadena1[' '],cadena2[' '];

int j,i,longitud1,longitud2,suma;


void main()
{

	printf("\n\n\tIntroduce la cadena 1:");
	gets(cadena1);
	// encontrar la longitud
	for(i=0;cadena1[i]!= '\0';i++)
	{
		longitud1++;
	}

	printf("\n\n\tIntroduce la cadena 1:");
	gets(cadena2);
	// encontrar la longitud
	for(i=0;cadena2[i]!= '\0';i++)
	{
		longitud2++;
	}


	//concatenar

	for(i=0;i < longitud2;i++)
	{
		cadena1[longitud1 + i] = cadena2[i];
	}

	printf("\n\n\tLa cadena uno concatenada con la cadena 2 es: %s",cadena1);
}