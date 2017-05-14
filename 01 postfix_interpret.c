/*	Programa en lenguaje C el cual evalúa una expresión 
	transformada en notación postfija, la cual debe ser 
	almacenada en un arreglo y ser evaluada, con el uso de pilas. */

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura
typedef struct  nodo
{
	/*variable a introducir valor*/
	float entero;

	/*enlace al siguiente nodo de la pila*/
	struct  nodo *siguiente;
};

typedef struct nodo NODO;  /*definición de la estructura como tipo de dato*/
typedef NODO *NODOSIG;    /*Tipo de dato para generar los nodo de la lista*/


/* FUNCIONES */

//Funcion Evalua: realiza la funcon de Evaluar la expresion Postfija dada de entrada
int Evalua(NODOSIG *);

//funcion Apila: esta funcion Apila el caracter recibido como parametro
NODOSIG *Apila(NODOSIG *,float);

/*main*/
int main()
{

	/*Pila*/
	NODOSIG pila = NULL;

	//variables
	int op,error;

	do
	{
		system("cls");
		/*validacion de variable op*/
		do
		{
			error=0;

			/*validacion ante caracteres*/
			while(error==0)
			{
				fflush(stdin);
				printf("\tEvaluador de Expresiones Postfijas"
					 "\n\t****************************************"
					 "\n\n\t\t1.-Expresion Postfija"
					 "\n\t\t2.-Salir"
					 "\n\t******************************************"
					 "\n\tOpcion: ");
					 error = scanf("%d",&op);
					 if(op == 0)
					 {
                        system("cls");
						printf("\tError!! Introduzca un numero entero");
					 }
			}
			if(op < 1 || op > 2)
			{
				system("cls");
				printf("Error !!  opcion  no valida");
			}

		}while(op < 1 || op >2);

		switch(op)
		{
			case 1:
			//llamada a funcion Evalua. Recibe de retorno un valor entero
			if(Evalua(&pila)==1)
				printf("\n\tExpresion Infija no valida");
			printf("\n\n\t");
			system("PAUSE");
			break;
		}

	}while(op != 2);  /*mientras op sea diferente de 5 volver a mostrar menu */
	printf("\n\n\t");
	system("PAUSE");
	return 0;
}

//Funcion Evalua: Recibe como parametro la direccionde la pila
//Retorna un numero entero
int Evalua(NODOSIG *pila)
{
	NODOSIG aux; // variable auxiliar para el manejo de la pila
	aux = *pila;
	
	/*Variables*/
	int i=0,j=0,op;
	float sumas=0;
	float variable;

	/*Cadena de caracteres a guardar la expresion Postfija*/
	char Postfija[' '];
	system("cls");
	printf("\n\tEJEMPLO\n\tInfija: 5+5 = 10\n\tPOSTFIJA: 55+ = 10");
	printf("\n\t*********************************************");
	printf("\n\n\tIntroduzca la expresion Postfija a evaluar: ");
	fflush(stdin);
	//entrada a variable Postfija
	gets(Postfija);

	//Mientras cadana Postfija[''] en posicion i sea diferente de NULL
	while(Postfija[i] != NULL)
	{
		//Mientras el caracter Postfija[i] no se encuentre en los numeros o letras
		if(Postfija[i] < 65 && Postfija[i] > 57 || Postfija[i] < 48 && Postfija[i] != 32 && Postfija[i] != 35 || Postfija[i]> 90 && Postfija[i]< 97 || Postfija[i] >122)
		{			

			//Mientras el caracter Postfija[i] no se encuentre en '+'  ||  '-'  ||  '/'  ||  '*'  ||  '^'  ||  '='
			if(Postfija[i] != '+' && Postfija[i] != '-' && Postfija[i] != '/' && Postfija[i] != '*' && Postfija[i] != '^' && Postfija[i] != '(' && Postfija[i] != ')' && Postfija[i] != '=')
				return 1;
				
			//El caracter Postfija[i] si se encuentra en '+'  ||  '-'  ||  '/'  ||  '*'  ||  '^'  ||  '='
			else
			{
				//sitch de caracter Postfija[i]
				switch(Postfija[i])
				{
					case '+':
						//Mientras la pila no se encuentre vacia
						 if(*pila != NULL)
						 {
							//Mientras existan dos o mas nodos en la pila
							 if(aux->siguiente != NULL)
							 {
								//variable sumas = al ultimo valor flotante almacenado en la pila
								 sumas = aux->entero;
								 aux = aux->siguiente;
								 
								 //variable sumas = el penultimo valor flotante almanecado en la pila + sumas
								 sumas = aux->entero + sumas;
								 
								 /*se eliminan Los dos ultimos nodos de la pila*/
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 /*---------------------------------------------*/
								 
								 //Actualizamos aux
								 aux = *pila;
								 
								 //Mientras la pila tenga uno o mas nodos
								 //o mientras Postfija[i+1] contenga aún, otro caracter
								 if(*pila != NULL || Postfija[i+1] != NULL)
								 {
									//Llamada a funcion Apila se envia como parametros la pila vacia y el valor flotante a almacenar
									//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
									 aux = *Apila(&aux,sumas);
									 
									 //actualizamos pila
									 *pila = aux;
								 }
							 }
							 //no existen dos o mas nodos en la pila
							 else
								break;
						 }
						 //la pila esta Completamente vacia
						 else
							break;
					break;
					case '-':
						/*EXPLICACION SEMEJANTE A LA ANTERIOR*/
						 if(*pila != NULL)
						 {
							 if(aux->siguiente != NULL)
							 {
								//variable sumas = al ultimo valor flotante almacenado en la pila
								 sumas = aux->entero;
								 aux = aux->siguiente;
								 
								 //variable sumas = el penultimo valor flotante almanecado en la pila - sumas
								 sumas = aux->entero - sumas;
								 
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 
								 aux = *pila;
								 
								 if(*pila != NULL || Postfija[i+1] != NULL)
								 {
									 aux = *Apila(&aux,sumas);
									 *pila = aux;
								 }
							 }
							 else
								break;
						 }
						 else
							break;
					break;
					case '/':
							/*EXPLICACION SEMEJANTE A LA ANTERIOR*/
							if(*pila != NULL)
							{
							 if(aux->siguiente != NULL)
							 {
								//variable sumas = al ultimo valor flotante almacenado en la pila
								 sumas = aux->entero;
								 aux = aux->siguiente;
								 
								  //variable sumas = el penultimo valor flotante almanecado en la pila / sumas
								 sumas = aux->entero / sumas;
								 
								 aux = *pila;
								 *pila = (*pila)->siguiente;
								 free(aux);
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 
								 aux =*pila;
								 
								 if(*pila != NULL || Postfija[i+1]!=NULL)
								 {
									aux = *Apila(&aux,sumas);
									*pila = aux;
								 }
							 }
							 else
								break;
						 }
						 else
							break;
					break;
					case '*':
						/*EXPLICACION SEMEJANTE A LA ANTERIOR*/
						 if(*pila != NULL)
						 {
							 if(aux->siguiente != NULL)
							 {
								//variable sumas = al ultimo valor flotante almacenado en la pila
								 sumas = aux->entero;
								 aux = aux->siguiente;
								 
								//variable sumas = el penultimo valor flotante almanecado en la pila * sumas
								 sumas = aux->entero * sumas;
								 
								 aux = *pila;
								 *pila = (*pila)->siguiente;
								 free(aux);
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 
								 aux =*pila;
								 
								 if(*pila != NULL || Postfija[i+1]!=NULL)
								 {
									aux = *Apila(&aux,sumas);
									*pila = aux;
								 }
							 }
							 else
								break;
						 }
						 else
							break;
					break;
					case '^':
							if(*pila != NULL)
							{
							 if(aux->siguiente != NULL)
							 {
								//variable sumas = al ultimo valor flotante almacenado en la pila
								 sumas = aux->entero;
								 aux = aux->siguiente;

								 //PROCESO PARA OBTENER a^b
								 float suma;
								 suma = aux->entero;
								 for(int k = 1; k<sumas; k++)
								 {
									 suma = aux->entero * suma;
								 }
								 //sumas es igual al resultado obtenido
								 sumas = suma;

								 //se eliminan los ultimos dos nodos de la pila
								 aux = *pila;
								 *pila = (*pila)->siguiente;
								 free(aux);
								 aux =*pila;
								 *pila = aux->siguiente;
								 free(aux);
								 //*********************************************

								 aux =*pila;
								 if(*pila != NULL || Postfija[i+1]!=NULL)
								 {
									aux = *Apila(&aux,sumas);
									*pila = aux;
								 }
							 }
							 else
								break;
						 }
						 else
							break;
				}

			}//else
		}

		/*El caracter Postfija[i] se encuentra entre las letras y los numeros*/
		else
		{
			//Mientras el caracter Postfija[i] se encuentre en los numeros
			if(Postfija[i]>47 && Postfija[i]<58)
			{
				//switch Postfija[i]
				/*variable toma el valor correspondiente dependiendo del caracter a verificar*/
				switch(Postfija[i])
				{
					case '1':
						variable = 1;
						break;
					case '2':
						variable = 2;
						break;
					case '3':
						variable = 3;
						break;
					case '4':
						variable = 4;
						break;
					case '5':
						variable = 5;
						break;
					case '6':
						variable = 6;
						break;
					case '7':
						variable = 7;
						break;
					case '8':
						variable = 8;
						break;
					case '9':
						variable = 9;
						break;
				}
			}
			//El caracter Postfija[i] no esta entre los numeros
			else
			{
				printf("\n\tDeme el valor de %c: ",Postfija[i]);
				scanf("%f",&variable);
			}

			//Llamada a funcion Apila se envia como parametros la pila vacia y el valor flotante a almacenar
			//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
			aux = *Apila(&aux,variable);
			
			//Actualizamos pila
			*pila = aux;
		}

		i++;
	}


	system("cls");
	printf("\n\n\tExpresion Postfija: %s",Postfija);
	printf("\n\n\tResultado: %.2f",sumas);

	return 0; // el programa termino con exito!
}


//Funcion Apila: Recibe como parametro el caracter a apila y la direccion de pila
//retorna la nueva direccion de pila
NODOSIG * Apila(NODOSIG *pila,float Variable)
{
	NODOSIG nuevo;  /*variable auxiliar para crear nuevo nodo */

	/* Crear un nodo nuevo */
	nuevo = malloc(sizeof(NODO));

    if(nuevo != NULL)
    {
	 /* variable valor del nuevo nodo = a la variable valor*/
	nuevo->entero = Variable;

	/*varificamos si es el primer nodo a ingrezar en la pila */
	if(*pila == NULL)
        {
		/* Añadimos la pila a continuación del nuevo nodo */
		nuevo->siguiente = NULL;

		/* Ahora, el comienzo de nuestra pila es en nuevo nodo */
		*pila = nuevo;

		/*retorno de la direccion de pila */
		return pila;
	}

	//No es el primer nodo de la pila
	else
	{
		/*conectamos el nodo al inicio de la pila */
		nuevo->siguiente = *pila;

		/*actualizamos pila para que tenga el inicio nuevamente */
		*pila = nuevo;

		/*retorno de la direccion de pila */
		return pila;
	}
   }
   //no hay memoria 
   else
   {
       system("cls");
       printf("\n\n\tNO hay memoria suficiente");
       return pila;
   }
}