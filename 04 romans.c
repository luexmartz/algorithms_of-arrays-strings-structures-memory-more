	/* ingresar un número entero y mostrar su equivalente romano */

	#include<stdio.h>

	int numero,C,D,U;

	void main()
	{
		  printf("\n\n\tingrese un numero entero: ");
		  scanf("%d",&numero);

		  if(numero > 0 && numero < 1001)
		  {
				C = numero / 100;
				if(numero >= 100)
				{
					D = (numero / 10)- (C * 10);
				}
				else
				{
					D = (numero / 10);
				}

				U = numero % 10;


				printf("\n\tDecimal = %d \t Romano: ",numero);

				switch(C)
				{
					case 1: printf("C"); break;
					case 2: printf("CC"); break;
					case 3: printf("CCC"); break;
					case 4: printf("CD"); break;
					case 5: printf("D"); break;
					case 6: printf("DC"); break;
					case 7: printf("DCC"); break;
					case 8: printf("DCCC"); break;
					case 9: printf("CM"); break;
					case 10: printf("M"); break;
				}

				switch(D)
				{
					case 1: printf("X"); break;
					case 2: printf("XX"); break;
					case 3: printf("XXX"); break;
					case 4: printf("XL"); break;
					case 5: printf("L"); break;
					case 6: printf("LX"); break;
					case 7: printf("LXX"); break;
					case 8: printf("LXXX"); break;
					case 9: printf("XC");break;
				}

				switch(U)
				{
					case 1: printf("I"); break;
					case 2: printf("II"); break;
					case 3: printf("III"); break;
					case 4: printf("IV"); break;
					case 5: printf("V"); break;
					case 6: printf("VI"); break;
					case 7: printf("VII"); break;
					case 8: printf("VIII"); break;
					case 9: printf("IX"); break;
				}
		  } // if
	}  // main
