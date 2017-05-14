/*
	Programa que genera un �rbol Binario de b�squeda.
	El usuario puede agregar y borrar N nodos.
	Es posible buscar un nodo dentro del �rbol binario.
	Funciones adicionales:
	* Impresi�n del �rbol (InOrden, PreOrden, PostOrden)
	* Contar n�mero de nodos
	* Calcular la altura del �rbol
	* Calcular altura de un nodo
*/

#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//ESTRUCTURA DEL ARBOL/
typedef struct nodo
{
	int dato;

	//enlace al nodo derecho del arbol
	struct nodo *derecho;

	//enlace al nodo izquierdo del arbol
	struct nodo *izquierdo;

};

typedef struct nodo tipoNodo;
typedef tipoNodo *NODOSIG;
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


// FUNCIONES CON ARBOL**************
/* Insertar en �rbol ordenado: */
void Insertar(NODOSIG *a, int dat);

/* Borrar un elemento: */
void Borrar(NODOSIG *a, int dat);
//***********************************


//FUNCIONES DE INFORMACION***********
/* Funci�n de b�squeda: */
int Buscar(NODOSIG a, int dat);

/* Contar n�mero de nodos: */
int NumeroNodos(NODOSIG a, int* c);

/* Calcular la altura de un �rbol: */
int AlturaArbol(NODOSIG a, int* altura);

/* Calcular altura de un dato: */
int Altura(NODOSIG a, int dat);
//***********************************


//FUNCIONES DE RECORRIDO*************
void InOrden(NODOSIG);
void PreOrden(NODOSIG);
void PostOrden(NODOSIG);
//***********************************

//FUNCIONES AUXILIARES***************
void auxContador(NODOSIG a, int*);
void auxAltura(NODOSIG a, int, int*);
//***********************************


/* Programa de ejemplo */
int main(void)
{
	//Arbol
	NODOSIG ArbolInt=NULL;
	int error=0,altura,nnodos,elemento;

	do
	{
		clrscr();
		error=0;
		while(error==0)
		{
			 flushall();
			 printf("\n\t\tARBOL BINARIO DE BUSQUEDA\n\t\t*******************************"
			 "\n\t\t\t1.-Insertar"
			 "\n\t\t\t2.-Eliminar "
			 "\n\t\t\t3.-Recoridos"
			 "\n\t\t\t4.-Informacion"
			 "\n\t\t\t5.-Salir"
			 "\n\t\t*******************************"
			 "\n\t\tOpcion: ");
			 error = scanf("%d",&elemento);
			 if(error==0)
			 {
					 clrscr();
					 printf("\tError!!  Introduzca un numero entero");
			 }
		}
		
		switch(elemento)
		{
			/* Inserci�n de nodos en �rbol: */
			case 1:
				
				error=0;
				while(error == 0)
				{
					flushall();
					printf("\n\n\tInsertar un elemento entero: "),
					error = scanf("%d",&elemento);
					if(error == 0)
					{
						clrscr();
						printf("\tError!! Introduzca un elemento entero");
					}
				}

				//llamada a la funcion Insertar
				//como parametros: la direccion del arbol, el elemento a insertar
				Insertar(&ArbolInt,elemento);


				printf("\n\n\tPresione una tecla para continuar............");
				getch();
				
				//regrezamos el valor con el que entro
				elemento = 1;
				break;

			/* Borraremos algunos elementos: */
			case 2:
				error=0;
				while(error == 0)
				{
					flushall();
					printf("\n\n\tElemento a borrar: "),
					error = scanf("%d",&elemento);
					if(error == 0)
					{
						clrscr();
						printf("\tError!! Introduzca un elemento entero");
					}
				}

				//llamada a la funcion Borrar
				//como parametros: la direccion del arbol, el elemento a ser eliminado
				Borrar(&ArbolInt, elemento);

				printf("\n\n\tPresione una tecla para continuar............");
				getch();
				
				//regrazamos el valor con el que entro
				elemento = 2;
				break;

			/* Mostrar el �rbol en tres ordenes distintos: */
			case 3:
				error=0;
				while(error==0)
				{
					flushall();
					printf("\n\n\t\t1.-InOrden"
					"\n\t\t2.-Preorden"
					"\n\t\t3.-PostOrden\n\t\tOpcion:");
					error = scanf("%d",&elemento);
					if(error==0)
					{
						clrscr();
						printf("\tError!! Introduzca un elemento entero");
					}
				}
				if(elemento == 1 && ArbolInt != NULL)
				{
					printf("\n\n\tInOrden: ");

				    //llamada a la funcion Inorden(direccion del arbol)
					InOrden(ArbolInt);
				}
				if(elemento == 2 && ArbolInt != NULL)
				{
					printf("\n\n\tPreOrden: ");


				    //llamada a la funcion Preorden(direccion del arbol)
					PreOrden(ArbolInt);
				}
				if(elemento == 3 && ArbolInt != NULL)
				{
					printf("\n\n\tPostOrden: ");


				    //llamada a la funcion Postorden(direccion del arbol)
					PostOrden(ArbolInt);
				}
				if(ArbolInt == NULL)
					printf("\n\tError!! No hay elementos en el arbol......");

				printf("\n\n\tPresione una tecla para continuar............");
				getch();

				//regrazamos el valor con el que entro
				elemento = 3;
				break;

			/*Informacion extra del arbol*/
			case 4:
				error=0;
				while(error==0)
				{
					flushall();
					printf("\n\n\t1.-Numero de Nodos"
					"\n\t2.-Altura de Arbol"
					"\n\t3.-Altura de un nodo\n\tOpcion");
					error = scanf("%d",&elemento);
					if(error==0)
					{
						clrscr();
						printf("\tError!! Introduzca un elemento entero");
					}
				}
				if(elemento == 1)
					printf("Numero de nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
		
				if(elemento == 2)
					printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));

				if(elemento == 3)
				{
					error=0;
					while(error==0)
					{
						flushall();
						error = scanf("%d",&elemento);
						if(error==0)
						{
							clrscr();
							printf("\tError!! Introduzca un elemento entero");
						}
					}
					printf("Altura del Nodo %d un Nodo %d\n",elemento,AlturaArbol(ArbolInt, &altura));
				}
				printf("\n\n\tPresione una tecla para continuar............");
				getch();

				//regrazamos el valor con el que entro
				elemento = 4;
				break;

			}//SWITCH
			
			if(elemento < 1 || elemento > 5)
			{
				clrscr();
				printf("\tError!! opcion no valida");
			}

		}while(elemento!=5);
		
		clrscr();
		printf("\n\n\tGRACIAS !!");
	return 0;
}

/* Insertar un dato en el �rbol ABB */
void Insertar(NODOSIG *a, int dat)
{
	NODOSIG padre = NULL;
	NODOSIG actual = *a;

	/* Busca el lugar donde colocar el nuevo nodo*/
	while(actual != NULL)
	{
		padre = actual;
		if(dat < actual->dato)
			actual = actual->izquierdo;

		else if(dat >= actual->dato)
				  actual = actual->derecho;
	}

	/* Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
		el nodo raiz */
	if(padre == NULL)
	{
		*a = (NODOSIG)malloc(sizeof(tipoNodo));
		(*a)->dato = dat;
		(*a)->izquierdo = (*a)->derecho = NULL;
	}


	/* Si el dato es menor que el que contiene el nodo padre, lo insertamos
		en la rama izquierda */
	else if(dat < padre->dato)
		  {
			actual = (NODOSIG)malloc(sizeof(tipoNodo));
			padre->izquierdo = actual;
			actual->dato = dat;
			actual->izquierdo = actual->derecho = NULL;
		  }

		  /* Si el dato es mayor o igual que el que contiene el nodo padre, lo insertamos
		  en la rama derecha */
		  else if(dat >= padre->dato) 
                  {
			actual = (NODOSIG)malloc(sizeof(tipoNodo));
			padre->derecho = actual;
			actual->dato = dat;
			actual->izquierdo = actual->derecho = NULL;
                  }
}

/* Eliminar un elemento de un �rbol ABB */
void Borrar(NODOSIG *a, int dat)
{
	NODOSIG padre = NULL;
	NODOSIG actual;
	NODOSIG nodo;

	int aux;

	actual = *a;

	/* Mientras sea posible que el valor est� en el �rbol */
	while(actual != NULL)
	{
		/* Si el valor est� en el nodo actual */
		if(dat == actual->dato)
		{
			/* Y si adem�s es un nodo hoja: lo borramos */
			if(actual->izquierdo == actual->derecho)
			{
				/* Si tiene padre (no es el nodo raiz) */
				if(padre != NULL)
					/* Anulamos el puntero que le hace referencia */
					if(padre->derecho == actual)
						padre->derecho = NULL;
					else
						if(padre->izquierdo == actual)
							padre->izquierdo = NULL;
				free(actual); /* Borrar el nodo */
				actual = NULL;
				return;
			}
			 /* Si el valor est� en el nodo actual, pero no es hoja */
			else
			{
				padre = actual;
				/* Buscar el nodo menor del subarbol derecho*/
				if(actual->derecho != NULL)
				{
					nodo = actual->derecho;
					while(nodo->izquierdo != NULL)
					{
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}

                //En caso de no tener subarbol derecho
				/* Buscar el nodo mayor del subarbol izquierdo*/
				else
				{
					nodo = actual->izquierdo;
					while(nodo->derecho != NULL)
					{
						padre = nodo;
						nodo = nodo->derecho;
					}
				}

				/*  El nodo encontrado no tiene
					por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
					de que s�lo se eliminan nodos hoja. */

				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}

		/* Todav�a no hemos encontrado el valor, seguir busc�ndolo */
		else
		{
			padre = actual;
			if(dat > actual->dato)
				actual = actual->derecho;
			else
				if(dat < actual->dato)
					actual = actual->izquierdo;
		}
	}
}

/* Recorrido de �rbol en inorden*/
void InOrden(NODOSIG a)
{
	if(a->izquierdo != NULL)
		InOrden(a->izquierdo);

	printf(",%d",a->dato);

	if(a->derecho != NULL)
		InOrden(a->derecho);
}

/* Recorrido de �rbol en preorden */
void PreOrden(NODOSIG a)
{
	printf(",%d",a->dato);

	if(a->izquierdo != NULL)
		PreOrden(a->izquierdo);

	if(a->derecho != NULL)
		PreOrden(a->derecho);
}

/* Recorrido de �rbol en postorden */
void PostOrden(NODOSIG a)
{
	if(a->izquierdo != NULL)
		PostOrden(a->izquierdo);

	if(a->derecho != NULL)
		PostOrden(a->derecho);

	printf(",%d",a->dato);
}


/* Buscar un valor en el �rbol */
int Buscar(NODOSIG a, int dat)
{
	NODOSIG actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
	while(actual != NULL)
	{
      if(dat == actual->dato) return TRUE; /* dato encontrado */
		else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
		else if(dat > actual->dato) actual = actual->derecho;
	}
   return FALSE; /* No est� en �rbol */
}

/* Calcular la altura del nodo que contiene el dato dat */
int Altura(NODOSIG a, int dat)
{
	int altura = 0;
	NODOSIG actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
	while(actual!= NULL)
	{
		if(dat == actual->dato)
			return altura; /* encontrado: devolver altura */
		else
		{
			altura++; /* Incrementamos la altura, seguimos buscando */
			if(dat < actual->dato)
				actual = actual->izquierdo;
			else if(dat > actual->dato)
					actual = actual->derecho;
		}
	}
	return -1; /* No est� en �rbol, devolver -1 */
}

/* Contar el n�mero de nodos */
int NumeroNodos(NODOSIG a, int *contador)
{
	*contador = 0;

	auxContador(a, contador); /* Funci�n auxiliar */
	return *contador;
}

/* Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
	preorden, el proceso es aumentar el contador */
void auxContador(NODOSIG nodo, int *c)
{
	(*c)++; /* Otro nodo */
	/* Continuar recorrido */
	if(nodo->izquierdo)
		auxContador(nodo->izquierdo, c);
	if(nodo->derecho)
		auxContador(nodo->derecho, c);
}

/* Calcular la altura del �rbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(NODOSIG a, int *altura)
{
	*altura = 0;

	auxAltura(a, 0, altura); /* Funci�n auxiliar */
	return *altura;
}

/* Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
	postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
	altura de la m�xima actual */
void auxAltura(NODOSIG nodo, int a, int *altura)
{
	/* Recorrido postorden */
	if(nodo->izquierdo)
		auxAltura(nodo->izquierdo, a+1, altura);
	if(nodo->derecho)
		auxAltura(nodo->derecho, a+1, altura);

	/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
		�rbol, actualizamos la altura actual del �rbol */
	if(nodo->derecho == nodo->izquierdo && a > *altura)
		*altura = a;
}


