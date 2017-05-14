// Programa que evalúa si un número es par o impar con recursividad indirecta

#include<stdio.h>

int par(int n);

int impar(int n);

main() {
	int numero;
    int result;
	printf("Number: ");
    scanf("%d", &numero);
    result = par(numero);
    if(result == 1)
        printf("\nThe number is even");
    else
        printf("\nThe number is odd");	
}

int par(int n) {
  if (n == 0) return 1;
  return impar(n-1);
}

int impar(int n) {
  if (n == 0) return 0;
  return par(n-1);
}
