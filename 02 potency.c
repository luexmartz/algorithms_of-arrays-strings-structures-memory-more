// Programa que dado dos números obtiene la potencia de número uno elevado la número dos

#include <stdio.h>

int main(){
	int exp, numero;
	printf("Enter the number:");
    scanf("%d", &numero);
    printf("Enter the power:");
    scanf("%d", &exp);
    printf("The number %d to the power %d is: %d",numero,exp,calcular(numero, exp));
}

int calcular(int numero, int exp){
	if(exp == 1)
        return numero;
    else if(exp == 0)
        return 1;
    else {
        return numero * calcular(numero, exp - 1);
    }
}
