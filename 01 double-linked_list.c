/*	Las listas doblemente enlazadas no necesitan un nodo 
	especial para acceder a ellas, pueden recorrerse en 
	ambos sentidos a partir de cualquier nodo, esto es 
	porque a partir de cualquier nodo, siempre es posible 
	alcanzar cualquier nodo de la lista, hasta que se llega a uno de los extremos.
*/

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct _nodo
{
	int valor;
	struct _nodo *siguiente;
	struct _nodo *anterior;

} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l);

void Borrar(Lista *);

void BorrarLista(Lista *);

void MostrarLista(Lista l, int orden);

int main() {
	Lista lista = NULL;
	int error,opc=1,op;

	do
	{
		clrscr();
		error=0;

		if(opc<1 || opc >4)
			printf("\tError !! opcion no valida");

		while(error==0)
		{
			flushall();
			printf("\n\t\t\tMENU\n"
			"\n\t\t1) Insertar elemento"
			"\n\t\t2) Borrar elemento"
			"\n\t\t3) Borrar lista"
			"\n\t\t4) Mostrar lista\n\t\t5) SALIR\n\t\tOPC: ");
			error=scanf("%d",&opc);
			if(error==0)
			{
				clrscr();
				printf("\tError !! Introduzca un numero entero");
			}
		 }
			switch(opc)
			{

			case 1:
				Insertar(&lista);
				break;
			case 2:
				Borrar(&lista);
				break;
			case 3:
				BorrarLista(&lista);
				break;
			case 4:
				clrscr();
				do
				{
					error=0;
					while(error==0)
					{
						flushall();
						printf("\n\n\t1)ASCENDENTE\n\t2)DESCENDENTE\n\tOPC: ");
						error = scanf("%d",&op);
						if(error==0)
						{
							clrscr();
							printf("\tError !!  Introduzca un numero entero");
						}
					}

					if(op <1 || op >2)
					{
						clrscr();
						printf("\tError!! opcion no valida");
					}

				}while(op <1 || op >2);

				if(op == 1)
					MostrarLista(lista, 1);
				if(op == 2)
					MostrarLista(lista, 0);

				break;
			}
		}while(opc!=5);
	getchar();
	return 0;
}

void Insertar(Lista *lista)
{
   pNodo nuevo, actual;
	int v;
	clrscr();
	printf("\n\n\tIntroduzca un elemento: ");
	scanf("%d",&v);
	/* Crear un nodo nuevo */
	nuevo = new tipoNodo;
	nuevo->valor = v;

	/* Colocamos actual en la primera posición de la lista */
	actual = *lista;
	if(actual)
		while(actual->anterior)
			actual = actual->anterior;

	/* Si la lista está vacía o el primer miembro es mayor que el nuevo */
	if(!actual || actual->valor > v) {
		/* Añadimos la lista a continuación del nuevo nodo */
		nuevo->siguiente = actual;
		nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
	else {
		/* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(actual->siguiente &&actual->siguiente->valor <= v) 
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
		nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}


void Borrar(Lista *lista)
{
	pNodo nodo;
	int v;

	clrscr();
	printf("\n\n\tIntroduzca el elementoa borrar : ");
	scanf("%d",&v);
  	nodo = *lista;
	if(nodo->siguiente == NULL && nodo->valor == v)
	 {	*lista = NULL; }
      
	/* Buscar el nodo de valor v */
	while(nodo && nodo->valor < v)
		nodo = nodo->siguiente;
	while(nodo && nodo->valor > v)
		nodo = nodo->anterior;

	/* El valor v no está en la lista */
	if(!nodo || nodo->valor != v) printf("\n\tEl valor no exiete!!");getch();return;
   
	/* Borrar el nodo */
	/* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
	  if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente;
   
   if(nodo->anterior) /* no es el primer elemento */
		nodo->anterior->siguiente = nodo->siguiente;
	if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
	free(nodo);
}

void BorrarLista(Lista *lista)
{
	if(lista != NULL)
	{
		printf("\n\tLista vacía");
		getch();
	}


	else
	{
		pNodo nodo, actual;
		actual = *lista;
		while(actual->anterior) actual = actual->anterior;

		while(actual)
		{
			nodo = actual;
			actual = actual->siguiente;
			free(nodo);
		}
		*lista = NULL;
	}
}

void MostrarLista(Lista lista, int orden)
{
   pNodo nodo = lista;

	if(!lista) printf("\n\tLista vacía");

	else
	{
		nodo = lista;
		if(orden == 1){
			while(nodo->anterior) nodo = nodo->anterior;
				printf("Orden ascendente: ");
			while(nodo)
			{
				 printf("%d -> ", nodo->valor);
				 nodo = nodo->siguiente;
			}
		}
		else
		{
			while(nodo->siguiente)
				nodo = nodo->siguiente;
			printf("Orden descendente: ");
			while(nodo)
			{
			 printf("%d -> ", nodo->valor);
				nodo = nodo->anterior;
			}
	}
}

	printf("\n");
	getch();
}
