// Programa que dado un número obtiene su valor en binario

#include<stdio.h>
#include<conio.h>

void binario(int);

main() {
	int a;
	printf("Enter an integer to convert to binary:");
	scanf("%d",&a);
	printf("The number %d in binary is: ",a);
	binario(a);
	getch();
}

void binario(int b) {
	int guard;
	if(b>0) {
		guard=b%2;
		binario(b/2);
		printf("%d",guard);
	}
}
