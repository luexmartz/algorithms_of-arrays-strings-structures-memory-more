/*Programa que calcula si una frase ingresada es un palíndromo o no
  ignorando los espacios en blanco*/

#include<stdio.h>

char cadena[' '],normal[' '],inversa[' '];

int longitud,i,k,opc;

void main()
{

	printf("\n\n\tIngrese una Cadena:");
	flushall();
	gets(cadena);

	//calculo la longitud de la cadena

	for(i=0;cadena[i]!= '\0';i++)
	{
		longitud++;
		if(cadena[i] != ' ')
		{
			//guardo cadena normal sin espacios
			normal[k]= cadena[i];
			k++;
		}
	}
	k=0;

	//Imprimo la frase ingresada de atras hacia adelante

	printf("\n\n\tLa frase inversa es: ");

	for(i = longitud-1 ;i >= 0;i--)
	{
		  printf("%c",cadena[i]);

		  // guardo inversa pero cin espacios

		  if(cadena[i] != ' ')
		  {
				inversa[k] = cadena[i];
				k++;
		  }
	}

	//compara las cadenas
	for(i =0;i < longitud;i++)
		 {
				if(normal[i] == inversa[i])
					opc = opc +1 ;
				else
					opc = opc -1;
		 }

		 if(opc == longitud)
		 {
			printf("\n\n\tLa cadena es un palindromo !!!");

		 }

		 else
		 {
			printf("\n\n\tLa cadena no es un palindromo !!!");
		 }

}
