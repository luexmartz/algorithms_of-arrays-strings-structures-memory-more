/*Programa en c que compara dos strings*/

#include<stdio.h>

char opc,string1[' '],string2[' '];
int i,longitud1,longitud2;
void main()
{
	 printf("\n\n\tIngrese una cadena: ");
	 gets(string1);
	 printf("\n\n\tIngrese una segunda cadena:");
	 gets(string2);
    
	for(i=0;string1[i]!= '\0';i++)
	{
		longitud1++;

	}
   
	for(i=0;string2[i]!= '\0';i++)
	{
		longitud2++;
	}

	if(longitud1 == longitud2)
	{
		 for(i =0;i < longitud1;i++);
		 {
			if(string1[i] == string2[i])
				opc = 1;
			else
				printf("\n\n\tLas cadenas no son iguales !!");
		 }
		 if(opc == 1)
				printf("\n\n\tLas cadenas son iguales!!");
	 }
	 else
		printf("\n\n\tLas cadenas no son iguales!!");
}