/*Se tiene un texto formado por un máximo de 10 líneas, del cual se
quiere saber el número de apariciones de la palabra CLAVE. Desarrollar
un programa en C, el cual lea el texto y la palabra CLAVE, determine el
número de apariciones de la palabra CLAVE en el texto. Se imprimirá el
texto y el número de veces que aparece la palabra CLAVE.*/


#include <stdio.h>
#include <string.h>

	 char cadena[10][' '],palabra[' '];
	 char *elemento;
	 int longitud,i,contador,compara;

void main()
{
	
		printf("\n\n\tPalabra clave: ");
		scanf("%s",&palabra);
		printf("\n\n\tIngrese un texto de dies lineas!\n\n");
	 for(i=0;i<10;i++)
	 {
		flushall();
		gets(cadena[i]);
		elemento = strtok(cadena[i], " ");
		while(elemento != NULL)
		{
		  longitud = strlen(elemento);
		  compara = strcmpi(elemento,palabra);
		  if(compara == 0 )
		  {
				contador++;
		  }
		  elemento = strtok(NULL, " ");

		 }
		}//fin de for

	 printf("\n\n\tLa cantidad de palabras clave es: %d",contador);
}