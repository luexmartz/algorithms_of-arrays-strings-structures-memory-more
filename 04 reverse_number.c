/*dado un número entero inverte dicho número*/

#include<stdio.h>

	int num,D,C,U;

void main()
{
		printf("\n\n\tIngrese un numero entero: ");
		scanf("%d",&num);

		if(num < 100)
		{
			D =  num/10;
			U = num %10;
			printf("\n\n\tEl numero invertido es : %d%d",U,D);
		}
		if (num >= 100)
		{
			C = num / 100;
			D = (num /10)%10;
			U = num % 10;
			printf("\n\n\tEl numero invertido es: %d%d%d",U,D,C);
		}
}