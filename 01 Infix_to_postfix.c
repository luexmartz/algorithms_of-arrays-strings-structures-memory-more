/*	Programa en lenguaje C el cual de cómo entrada una expresión 
	en notación Infija y la transforme a notación Postfija 
	apoyándose con el uso de pilas.	*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura
typedef struct  nodo
{
	/*variable a introducir un caracter*/
	char caracter;

	/*variable que indica la prioridad del caracter dentro de la pila*/
	int prioridad;

	/*enlace al siguiente nodo de la pila*/
	struct  nodo *siguiente;
};

typedef struct nodo NODO;  /*definición de la estructura como tipo de dato*/
typedef NODO *NODOSIG;    /*Tipo de dato para generar los nodo de la lista*/


/* Funciones con pilas: */

//Funcion Conviert: convierte la cadena ingrezada en expresion Infija a su correspondiente Expresion Postfija
//tipo de retorno int
int Convierte(NODOSIG *);

//funcion Apila: esta funcion apila el caracter recibido como parametro
//tipo de retorno NODOSIG*(retorna la nueva direccion de la pila)
NODOSIG *Apila(NODOSIG *,char);

//funcion Pioridad: funcion que retorna el numero de prioridad del caracter recibido como parametro
//tipo de retorno int
int Prioridad(char caracter);

/*funcion de impresion*/
//void ImprimePostfija(NODOSIG *);

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
				printf("\n\n\t\tConvertidor de Expresiones\n\n\t\tInfijo ---> Postfijo"
					 "\n\t****************************************"
					 "\n\n\t\t1.-Expresion Infija"
					 "\n\t\t2.-Salir"
					 "\n\t******************************************"
					 "\n\tOpcion: ");
					 error = scanf("%d",&op);
					 if(op == 0)
					 {
						system("cls");;
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
			//llamada a funcion Convierte. Se Recibe un retorno entero de la funcion 
			if(Convierte(&pila)==1)
				printf("\n\tExpresion Infija no valida");
			printf("\n\n\t");
			system("PAUSE");
			break;
		}

	}while(op != 2);  /*mientras op sea diferente de 2 volver a mostrar menu */
	printf("\n\n\t");
	system("PAUSE");;
	return 0;//finalizo con exito el programa
}

/*Funcion Convierte
 recibe como parametro la direccion de la pila*/
int Convierte(NODOSIG *pila)
{
	NODOSIG aux,previo; // variables auxiliares para el manejo de la pila
	aux = *pila;
	
	/*Variables*/
	int i=0,j=0,prioridad;

	/*Cadena de caracteres a gusardar la expresion infija*/
	char Infija[' '];

	//entrada a variable Infija
	printf("\n\tIntroduzca la expresion Infija a convertir: ");
	fflush(stdin);
	gets(Infija);

	/*Cadena de caracteres a guardar la expresion postfija*/
	char Postfija[' '];

	/*Mientras no se llege al final de la cadena Infija[' ']*/
	while(Infija[i] != NULL)
	{
		//Mientras el caracter Infija[i] no se encuentre en los numeros o letras
		if(Infija[i] < 65 && Infija[i] > 57 || Infija[i] < 48 && Infija[i] != 32 && Infija[i] != 35 || Infija[i]> 90 && Infija[i]< 97 || Infija[i] >122)
		{
			//Miantras el caracter Infija[i] no se encuentre en '+'  ||  '-'  ||  '/'  ||  '*'  ||  '^'  ||  '='
			if(Infija[i] != '+' &&Infija[i] != '-' &&Infija[i] != '/' &&Infija[i] != '*' &&Infija[i] != '^' && Infija[i] != '(' && Infija[i] != ')' && Infija[i] != '=')
				return 1;

			//El caracter Infija[i] si se encuentra en '+'  ||  '-'  ||  '/'  ||  '*'  ||  '^'  ||  '='
			else
			{
				//Mientras la pila este vacia
				if(*pila == NULL)
				{
					//Llamada a funcion Apila se envia como parametros la pila vacia y el caracter a apilar
					//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
					aux = *Apila(&aux,Infija[i]);
					
					//Actualizamos pila
					*pila = aux;
				}
				//Mientras la pila no este vacia
				else
				{	
					//llamada a funcion Prioridad, se evian como parametro el caracter Infija[i]
					//y recibe de retorno el valor de la prioridad dentro de la pila por medio de la variable prioridad
					prioridad = Prioridad(Infija[i]);

					/*Mientras la prioridad del caracter Infija[i] es mayor a la prioridad del
					ultimo caracter apilado*/
					if(prioridad > aux->prioridad)
					{
						//Llamada a funcion Apila se envia como parametros la pila vacia y el caracter a apilar
						//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
						aux = *Apila(&aux,Infija[i]);
						
						//Actualizamos pila
						*pila = aux;
					}
					//Mientras no se cumpla la condicion If(prioridad > aux->prioridad)
					else
					{
						//Mientras el caracter Infija[i] sea igual a '('
						if(Infija[i] == '(')
						{
							//Llamada a funcion Apila se envia como parametros la pila vacia y el caracter a apilar
						    //y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
							aux = *Apila(&aux,Infija[i]);
							
							//Actualizamos pila
							*pila = aux;
						}
						//Mientras no se cumpla if(Infija[i] == '(')
						else
						{
							//Mientras el caracter Infija[i] sea igual a ')'
							if(Infija[i] == ')')
							{
								/*EL siguiente proceso pasa los elementos de la pila a la exprecion Postfija
								hasta toparse con un ')' prioridad 0*/
								while(aux->prioridad != 0)
								{
									//se copia a la expresion Postfija el ultimo caracter apilado
									Postfija[j] = aux->caracter;
									
									//Incremento de j
									j++;
									
									//se elimina el primer nodo de la pila anteriormente copiado
									previo = aux;
									aux = aux->siguiente;
									*pila = aux;
									free(previo);
								}
								
								//Actualizamos aux
								aux = *pila;
								
								//el caracter '(' aun eta apilado
								/*Mientras existan dos o mas nodos en la pila*/
								if(aux->siguiente != NULL)
								{
									//se elimina el nodo con el caracter '('
									*pila = aux->siguiente;
									free(aux);
									aux = *pila;
								}
								//solo esta apilado el caracter '('
								else
								{
									//se elimina Totalmente la pila
									*pila = NULL;
									aux = *pila;
								}
							}
							//No se cumple la condicion ifif(Infija[i] == ')')
							else
							{
								/*Mientras le prioridad del caracter Infija[i] sea menos o igual a la prioridad
								 del Ultimo caracter apilado. Pero tambien que el ultimo caracter Apilado
								 no sea '('*/
								while(prioridad<=aux->prioridad && aux->prioridad != 0)
								{
									//se copia a la expresion Postfija el ultimo caracter Apilado
									Postfija[j] = aux->caracter;
									
									//Incrementamos j
									j++;
									
									//Mientras existan dos o mas nodos en la pila
									if(aux->siguiente != NULL)
									{
										//se elimina el Ultimo nodo de la pila
										*pila = aux->siguiente;
										free(aux);
										aux = *pila;
									}
									//es el ultimo nodo de la pila
									else
									{
										//Se elimina Totalmente la pila
										*pila = NULL;
										aux = *pila;
										
										//Llamada a funcion Apila se envia como parametros la pila vacia y el caracter a apilar
										//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux

										aux = *Apila(&aux,Infija[i]);
										
										//actualizamos pila
										*pila = aux;
										
										break;
									}
								}
								//Mientras exista aun un nodo en la pila
								if(aux->siguiente != NULL)
								{
									//Llamada a funcion Apila se envia como parametros la pila vacia y el caracter a apilar
									//y recibe de retorno la nueva direccion de pila por medio de la variable auxiliar aux
									aux = *Apila(&aux,Infija[i]);
									
									//Actualizamos pila
									*pila = aux;
								}
							}
						}//else
					}//else
				}//else
			}//else
		}//if
		/*El caracter Infija[i] se encuentra entre las letras y los numeros*/
		else
		{
			Postfija[j] = Infija[i];
			j++;
		}
		
		//incrementacion de i 
		i++;
	}

	//PROCESO que recorre la pila hasta llegar al ultimo nodo
	//Mientras aux sea diferente de nulo
	while(aux!=NULL)
	{
		//se copian todos los caracteres Apilados en la expresion postfija
		 Postfija[j] = aux->caracter;
		 
		//Se incrementa j
		 j++;

		 //se elimina el nodo con el caracter anteriormente copiado a la expresion Postfija
		 previo = aux;
		 aux = aux->siguiente;
		 *pila = aux;
		 free(previo);
	}

	//hacemos NULL el ultimo caracter de la cadena Postfija
	Postfija[j]= '\0';

	system("cls");
	printf("\n\n\tExpresion Infija: %s",Infija);

	printf("\n\n\tExpresion Postfija: %s",Postfija);
	return 0;
}

//Funcion Apila: Recibe como parametro el caracter a apila y la direccion de pila
//retorna la nueva direccion de pila
NODOSIG * Apila(NODOSIG *pila,char Apilado)
{
	NODOSIG nuevo;  /*variable auxiliar para crear nuevo nodo */

	/*variable prioridad*/
	int prioridad;

	/* Crear un nodo nuevo */
	nuevo = malloc(sizeof(NODO));

    if(nuevo != NULL)
    {
	/* variable valor del nuevo nodo = a la variable valor*/
	nuevo->caracter = Apilado;

	/*llamada a funcio prioridad*/
	prioridad = Prioridad(Apilado);

	/*variable prioridad del nuevo nodo = a la variable prioridad*/
	nuevo->prioridad = prioridad;

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
    
    //no hay memoria disponible
    else
    {
        system("cls");
        printf("\n\n\tNo hay memoria disponible"); 
        return pila; 
    }
}

//Funcion Prioridad: Recibe como parametro el caracter a verificar su prioridad
//Retorna la prioridad correspondiente al caracter
int Prioridad(char caracter)
{
	switch(caracter)
	{
	  case '(':
	  return 0;

	  case ')':
	  return 0;

	  case '*':
	  return 2;

	  case '^':
	  return 3;

	  case '+':
	  return 1;

	  case '-':
	  return 1;

	  case '=':
	  return 1;

	  case '/':
	  return 2;

	}
}
