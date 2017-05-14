// Programa que dado un número obtiene el factorial aplicando recursividad 

#include<stdio.h>

int factorial(int);

main() {
	int n;
	system("cls");
	printf("\nEnter a number to evaluate its factorial :");
	scanf("%d",&n);
	printf("\nThe factorial of %d is: %d\n",n,factorial(n));
}

int factorial(int n) {
    if(n==0)
		return 1;
    else
		return n*factorial(n-1);    
}
