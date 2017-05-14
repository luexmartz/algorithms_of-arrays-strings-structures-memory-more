/*  programa que utilice dos pilas, las cuales tendrán 
	como entrada valores numéricos. Se mezclarán las dos 
	pilas en una tercer pila, donde la pila resultante se 
	obtiene apilando alternativamente los elementos de ambas 
	pilas de tal manera que si existe un valor numérico repetido 
	solamente entrará uno, además calculará el número de elementos 
	de la pila. Se imprimirán las tres pilas */

#include<conio.h>
#include <stdio.h>
#include<stdlib.h>

//Estructura
typedef struct  nodo
{
	/*variable a introducir valor*/
	int valor;

	/*enlace al siguiente nodo de la pila*/
	struct  nodo *siguiente;
};

typedef struct nodo NODO;  /*definici¢n de la estructura como tipo de dato*/
typedef NODO *NODOSIG;    /*Tipo de dato para generar los nodo de la lista*/


/* Funciones con pilas: */

//funcion de entrada a valores
NODOSIG *Push(NODOSIG *);

/*Funcion crear. crea  la tercera pila con los elementos intercalados de l primera y la segunda pila*/
void Crear(NODOSIG *,NODOSIG *,NODOSIG *);

/*funcion de impresion imprime las tres pilas */
void ImprimePila(NODOSIG *,NODOSIG *,NODOSIG *);

/*main*/
int main()
{
	/*Pilas*/
	NODOSIG pila1 = NULL;
	NODOSIG pila2 = NULL;
	NODOSIG pila3 = NULL;

	int op,error;

	do
	{
		clrscr();
		/*validacion de variable op*/
		do
		{
			error=0;

			/*validacion ante caracteres*/
			while(error==0)
			{
				clrscr();
				fflush(stdin);
				printf("\n\n\t\t\tPILA DINAMICA !"
					 "\n\t****************************************"
					 "\n\n\t\t1.-Ingrezar primera pila"
					 "\n\t\t2.-Ingrezar segunda pila"
					 "\n\t\t3.-Generar tercera pila"
					 "\n\t\t4.-Imprimir pilas"
					 "\n\t\t5.-Salir"
					 "\n\t******************************************"
					 "\n\tOpcion: ");
					 error = scanf("%d",&op);
					 if(op == 0)
					 {
						clrscr();
						printf("Error!! Introduzca un numero entero");
					 }
			}
			if(op < 1 || op > 4)
			{
				clrscr();
				printf("Error !!  opcion  no valida");
			}

		}while(op < 1 || op >4);

		switch(op)
		{
			/*caso 1 llamada a funcion Push con direccion de pila 1*/
			case 1:
			pila1 = *Push(&pila1);
			printf("\n\n\tPresione una tecla para continuar.............");
			getch();
			break;

			/*caso 2 llamada a funcion Push con direccion de pila 2*/
			case 2:
			pila2 = *Push(&pila2);
			printf("\n\n\tPresione una tecla para continuar..............");
			getch();
			break;

			/*caso 3 llamada a funcion crear , se manda la direccion de las tres pilas */
			case 3:
			Crear(&pila1,&pila2,&pila3);
			break;

			/*caso 4 llamada a funcion imprime, se manda la direccion de lastres pilas*/
			case 4:
			ImprimePila(&pila1,&pila2,&pila3);
			printf("\n\n\tPresione una tecla para continuar..............");
			getch();
			break;
		}

	}while(op != 5);  /*mientras op sea diferente de 5 volver a mostrar menu */
	printf("\n\n");
	system("PAUSE");
	
	return 0;
}

/*funcion Push recibe direccion de pila1 o pila2*/
NODOSIG * Push(NODOSIG *pila)
{
	NODOSIG nuevo;  /*variable auxiliar para crear nuevo nodo */
	int error,valor;

	clrscr();

	/*validacion de la variable valor en caso de ser menor a 1 */
	do
	{
		error =0;

		/*validacion ante caracteres*/
		while(error==0)
		{
			fflush(stdin);
			printf("\n\n\tIntroduzca el elemento entero: ");
			error = scanf("%d",&valor);
			if(error==0)
			{
				clrscr();
				printf("\tError!! Introduzca un elemento entero");
			}
		}
		if(error < 1)
		{
			clrscr();
			printf("\tError!! Valor no admitido");
		}
	}while(error < 1);

	/* Crear un nodo nuevo */
	nuevo = new NODO;

	/* variable valor del nuevo nodo = a la variable valor*/
	nuevo->valor= valor;

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

/*funcion ImprimePila, recibe como parametros las 3 direcciones de las pilas*/
void ImprimePila(NODOSIG *pila1,NODOSIG *pila2 ,NODOSIG *pila3)
{
	NODOSIG aux1,aux2,aux3; /* variables auxiliares para manipular nodo */

	if(pila1 != NULL && pila2 != NULL)
	{
		/*las variables auxiliares toman las pilas correcpondientes*/
		aux1 = *pila1;
		aux2 = *pila2;
		aux3=*pila3;
		clrscr();
		printf("\n\n\tPila1 \n\t");

		/*se recorrera pila1 hasta llegar a NULL*/
		while(aux1 != NULL)
		{
		  printf("%d-->",aux1->valor);
		  aux1= aux1->siguiente;
		}

		printf("NULL\n\n\tPila2 \n\t");

		/*se recorrera pila2 hasta llegar a NULL */
		while(aux2 != NULL)
		{
			printf("%d-->",aux2->valor);
			aux2 = aux2->siguiente;
		}

		printf("NULL\n\n\tPila3 \n\t");

		/*se recorrera pila 3 hasta llegar a NULL */
		while(aux3 != NULL)
		{
			printf("%d-->",aux3->valor);
			aux3 = aux3->siguiente;
		}
		printf("NULL");
	}
}



/*funcion Crea, recibe como parametros la direccion de pila1
  pila2 y pila3 por medio de punteros*/
void Crear(NODOSIG *pila1,NODOSIG *pila2,NODOSIG *pila3)
{
	/*nos haceguramos de que las pilas o estan vacias*/
	if(*pila1 != NULL && pila2 != NULL)
	{
		NODOSIG aux1,aux2,aux3; /*variables auxiliares para la manipulacion de las pilas */
		NODOSIG nuevo; /* variable auxiliar para crear nuevo nodo */

		/*toman las pilas correspondientes*/
		aux1 = *pila1;
		aux2 = *pila2;

		/*se recorre pila1 y pila2 hasta llegar a NULL*/
		while(aux1 != NULL && aux2 != NULL)
		{
			/*aux toma la pila correspondiente */
			aux3 = *pila3;

			/*Proceso de busqueda de valores  identicos*/
			while(aux3 != NULL)
			{
				if(aux1->valor == aux3->valor)
					break;
				aux3 =aux3->siguiente;
			}

			/*en caso de no encontrar coinsidencias en el proceso anterior
			  aux3 tendra el valor de NULL*/
			/*en caso de ser el primer nodo a ingrezar a la pila3*/
			if(aux3 == NULL)
			{
				/*se crea el nuevo nodo*/
				nuevo = new NODO;

				/*variables valor del nuevo nodo = a variable valor */
				nuevo->valor = aux1->valor;

				/*verificamos si es el primer nodo a ingrezar a la pila3  */
				if(*pila3 == NULL)
				{
					/*nuevo->siguiente toma el valor de null */
					 nuevo->siguiente = NULL;

					 /*se conecta la pila3 a nuevo */
					 *pila3 = nuevo;
				}

				/*en caso de no ser el primer nodo a ingrezar a la pila3 */
				else
				{
					/*se conecta el nuevo nodo al inicio de la pila3  */
					 nuevo->siguiente = *pila3;

					 /*se actualiza pila3 tomando nuevamnete el inicnio de la pila3  */
					 *pila3 = nuevo;
				}
			}

			/*aux tres toma nuevamente pila3 para hacer al mismo proceso anterior con pila2 */
			aux3 = *pila3;

			while(aux3 != NULL)
			{
				if(aux2->valor == aux3->valor)
					break;
				aux3 = aux3->siguiente;
			}

			if(aux3 == NULL)
			{
				nuevo = new NODO;
				nuevo->valor = aux2->valor;

				if(*pila3 == NULL)
				{
					 nuevo->siguiente = NULL;
					 *pila3 = nuevo;
				}
				else
				{
					 nuevo->siguiente = *pila3;
					 *pila3 = nuevo;
				}
			}

			/*si aux1 aun no es NULL se avanza al siguiente nodo*/
			if(aux1 != NULL)
				aux1 = aux1->siguiente;

			/*si aux2 aun no es NULL se avanza al siguiente nodo*/
			if(aux2 != NULL)
				aux2 = aux2->siguiente;

		}//while

	}//if

	/*pila1 y pila2 estan vacias !*/

	else
	{
		clrscr();
		printf("\n\n\tError no se han ingrezado las pilas 1 y 2");
	}
}
