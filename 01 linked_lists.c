/*	Este programa realiza las operaciones de inserción,
	eliminación e impresión en listas enlazadas	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo{
	char dato;/*Dato a almacenar en el nodo de la lista*/
	struct nodo *siguiente;/*enlace al siguiente nodo de la lista*/
};

typedef struct nodo NODO;/*definici¢n de la estructura como tipo de dato*/
typedef NODO *NODOSIG;/*Tipo de dato para generar los nodo de la lista*/

/*funciones de inserci¢n en la lista*/
void insertar_frente(NODOSIG *, char);
void insertar_final(NODOSIG *, char);
void insertar_medio(NODOSIG *, char);

/*funciones de eliminacion en la lista*/
char borrar_frente(NODOSIG *);
char borrar_final(NODOSIG *);
char borrar_medio(NODOSIG *, char);

/*funci¢n de impresion de la lista*/
void printlista(NODOSIG);

/*funci¢n del menu de opciones*/
void instrucciones(void);

main()
{
 NODOSIG lista = NULL;
 int op;
 char ele;

	do{
		clrscr();
		instrucciones();
		printf("? ");
		scanf("%d", &op);
		switch (op) {
			/*Los caso del 1 al 3 son de inserci¢n*/
			case 1:
				printf("Introduzca el elemento: ");
				scanf("\n %c", &ele);/*lectura del elemento a almacenar*/
				insertar_frente(&lista, ele);/*se envia el inicio de la lista y el valor a insertar*/
				printlista(lista);/*se imprime la lista con el valor insertado*/
				getch();
				break;
			case 2:
				printf("Introduzca el elemento: ");
				scanf("\n %c", &ele);
				insertar_final(&lista, ele);
				printlista(lista);
				getch();
				break;
			case 3:
				printf("Introduzca el elemento: ");
				scanf("\n %c", &ele);
				insertar_medio(&lista, ele);
				printlista(lista);
				getch();
				break;
			/*casos de borrar elemento de la lista del 4-6*/
			case 4:
				if (!isempty(lista))/*antes de eliminar el dato se pregunta si hay elementos en la lista*/
					if (borrar_frente(&lista)=='a')/* se envia la lista y se regresa el valor a para indicar que si se elimino un elemento de la lista*/
						printlista(lista);/*Se imprime la lista actualizada*/
					else{	/*regresa un valor diferente de a que indica que era el ultimo valor*/
						printf("Lista esta vacia\n\n");
						free(lista);/*se libera completamente el espacio que ocupaba la lista*/
						lista=NULL;/*se inicia nuevamente la lista*/
					}
				getch();
				break;
			case 5:
				if (!isempty(lista))
					if (borrar_final(&lista)=='a')
						printlista(lista);
					else{
						printf("Lista esta vacia\n\n");
						free(lista);
						lista=NULL;
					}
				getch();
				break;
			case 6:
				if (!isempty(lista)) {/*se pregunta si hay elementos en la lista*/
					printf("Elemento a borrar: ");/*Se solicita el numero que se desea borrar*/
					scanf("\n%c", &ele);/*se lee el elemento a borrar*/
					if (borrar_medio(&lista, ele)) {/*se envia la lista y el elemento a borrar*/
						printf("%c borrado", ele);/*se regresa un valor 1 si este elemento se borro*/
						printlista(lista);/*y se indica que el elemento fue borrado y se imprime la lista actualizada*/
					}
					else/*se regreso un valor diferente de 1, lo que indica que no se encontro el elemento a borrar*/
						printf("%c no existe \n\n",ele);
				}
				else{/*cuando la lista esta vacia se imprime el mesaje*/
					printf("Lista esta vacia\n\n");
					free(lista);/*se libera el espacio ocupado por la lista*/
					lista=NULL;/*se inicia la lista nuevamente*/
				}
				getch();
				break;
			}
	}while (op != 7);/*mientras no se presione la opcion de salir*/
	getch();
 return 0;
}

/*menu de opciones, para trabajar con la lista*/
void instrucciones(void)
{
 printf("Elija una opcion :\n"
	"   1 insertar frente\n"
	"   2 insertar final\n"
	"   3 insertat en medio\n"
	"   4 eliminar frente\n"
	"   5 eliminar final\n"
	"   6 eliminar en medio\n"
	"   7 salir\n");
}

/*Funci¢n para insertar un elemento al frente o al inicio de la lista
  recibe como parametro por referencia la lista y por valor
  el valor a insertar*/
void insertar_frente(NODOSIG *lista, char valor)
{
 NODOSIG nuevo;/*variables temporales para la insercion en la lista del nuevo nodo*/
	nuevo = malloc(sizeof(NODO));/*Esta operacion crea el nuevo nodo que sera insertado en la lista*/
	if (nuevo != NULL) {/*Se pregunta si se pudo crear el nuevo espacio de memoria para el nodo*/
		nuevo->dato = valor;/*se asigna el dato que se quiere insertar*/
		nuevo->siguiente = NULL;/*se asigna nulo a la posicisi¢n siguiente del nodo creado*/
		nuevo -> siguiente = *lista;/*el nuevo nodo en en su posicion siguiente toma el inicio de la lista y la lista completa*/
		*lista = nuevo;/*ahora el nuevo inicio de la lista lo tendra nuevo, por lo cual se le asigna
				la posici¢n de memoria a lista, que es en donde iniciara la lista ahora*/
	}
}

/*Funci¢n para insertar un elemento en medio de la lista
  recibe como parametro por referencia la lista y
  por valor el valor a insertar*/
void insertar_medio(NODOSIG *lista, char valor)
{
 NODOSIG nuevo, previo, actual;/*variables auxiliares para recorrer la lista e insertar el nodo*/
	nuevo = malloc(sizeof(NODO));/*crea el nuevo nodo*/
	if (nuevo != NULL) {/*pregunta si se pudo crear el nodo*/
		nuevo->dato = valor;/*se almacena el dato*/
		nuevo->siguiente = NULL;/*se pone en nulo el sigiente*/
		previo = NULL;/*se inicializa previo en nulo*/
		actual = *lista;/*se asigna la lista completa a actual*/
		while (actual != NULL && valor > actual -> dato) {/*se recorre la lista hasta encontrar el lugar adecuado para insertar el nodo*/
			previo = actual;/*el nodo se insertara en forma ordenada, se asigna la posicion de actual a previo y se*/
			actual = actual -> siguiente;/*avanza al siguiente nodo*/
		}/*cuando se llego al lugar indicado para insertar el nodo previo en su posicion siguiente toma la direccion del nuevo nodo*/
		previo -> siguiente = nuevo;/*el nuevo nodo en su posicion siguiente toma la posicion de actual, lo que quiere decir que se esta*/
		nuevo -> siguiente = actual;/*insertando el nuevo en la parte de enmedio de la lista*/
	}
}

/*Funci¢n para insertar un elemento en al final de la lista
  recibe como parametro por referencia la lista y por valor
  el valor a insertar, para ser insertado el elemento en la
  lista este debe recorrer toda la lista hasta llegar al final de ella*/
void insertar_final(NODOSIG *lista, char valor)
{
 NODOSIG nuevo, previo, actual;/*variables auxiliares para recorrer y crear el nodo en la lista*/
	nuevo = malloc(sizeof(NODO));/*se genera el espacio del nuevo nodo*/
	if (nuevo != NULL) {/*se se pudo crear el espacio de memoria para el nodo*/
		nuevo->dato = valor;/*se almacena el dato*/
		nuevo->siguiente = NULL;/*se pone en nulo el siguiente*/
		previo = NULL;/*se inicializa el previo que sera para verificar en donde se insertara el nodo*/
		actual = *lista;/*actual toma el inicio y la lista completa*/
		while (actual != NULL) {/*recorrera la lista hata llegar al final, pero la direccion del ultimo nodo */
			previo = actual;/*quedara almacenado en previo, el cual permitira el enlace entre la lista y el nuevo nodo*/
			actual = actual -> siguiente;/*se avanza actual al siguiente nodo para llegar al final de la lista*/
		}/*se llego al final de la lista y se asiga a previo en su posicion siguiente la posicion del nuevo nodo*/
		if (previo == NULL) {
			nuevo -> siguiente = *lista;
			*lista = nuevo;
		}
		else {
			previo -> siguiente = nuevo;
			nuevo -> siguiente = actual;
		}
	}
}

/*funcion para imprimir la lista completa, recibe como parametro por valor
  el inicio y la lista completa*/
void printlista(NODOSIG actual)
{
	if (actual == NULL)/*Si no hay elementos en la lista*/
		printf("Lista vacia \n\n");
	else {/*si hay elementos en la lista*/
		printf("La lista es: \n");
		while (actual != NULL) {/*se imprimira la lista hasta llegar al final*/
			printf("%c --> ",actual -> dato);/*se imprime el contenido del nodo*/
			actual = actual -> siguiente;/*se avanza la posicion de actual al siguiente nodo*/
		}
		printf("NULL \n\n");
	}
}

/*Funci¢n para borrar un elemento al principio de la lista
  recibe como parametro por referencia la lista*/
char borrar_frente(NODOSIG *lista)
{
 NODOSIG  temporal,/*temporal es la variable la cual contendra la direccion del nodo que se va a borrar*/
	  previo;/*se utiliza para determinar si es el ultimo nodo en la lista*/

	previo= (*lista)-> siguiente;/*toma la posicion del siguiente nodo en la lista*/
	if (previo != NULL) {/*si no es el ultimo nodo*/
		temporal = *lista;/*temporal toma la posicion del nodo que se borrara en la lista*/
		*lista = (*lista) -> siguiente;/*y la lista toma la direccion del siguiente nodo para que este sea el nuevo inicio de la lista*/
		free(temporal);/*se libera el espacio ocupado por el nodo*/
		return 'a';/*se retorna un valor para indicar que no era al ultimo nodo en la lista*/
	}
	return '\0';/*este valor de retorno indica que es el ultimo nodo en la lista*/
}

/*Funci¢n para borrar un elemento al final de la lista
  recibe como parametro por referencia la lista*/
char borrar_final(NODOSIG *lista)
{
 NODOSIG  previo, actual, temporal;/*variables auxiliares*/
	previo = NULL;/*se inicializa el en nulo el previo que es el que contendra la lista*/
	actual = *lista;/*se asigna a actual el inicio y la lista completa*/
	if (actual->siguiente != NULL) {/*pregunta si no es el ultimo nodo en la lista*/
		while (actual->siguiente != NULL ){/*se recorrera la lista sin llegar al ultimo elemento de la lista*/
			previo = actual;/*se asigna la posicion de actual a previo*/
			actual = actual -> siguiente;/*se avanza al siguiente nodo*/
		}/*se llego hasta un nodo antes del final y se asigna a temporal la lista*/
		temporal=actual;/*para que este sea borrado y asi liberar el espacio ocupado por el elemento*/
		previo->siguiente = NULL;/*se le asigna a previo en su posicion siguiente nulo, es decir, el fin de la lista*/
		free(temporal);/*se libera el espacio del nodo a borrar*/
		return 'a';/*se regresa un valor para indicar que no era el ultimo nodo*/
	}
	return '\0';/*se regresa este valor para indicar que es el ultimo nodo*/
}

/*Funci¢n para borrar un elemento elejido por el usuario
  recibe como parametro por referencia la lista y por
  valor el valor a eliminar de la lista*/
char borrar_medio(NODOSIG *lista, char valor)
{
 NODOSIG  previo, actual, temporal;/*variables auxiliares*/
	previo = *lista;/*previo toma el inicio de la lista*/
	actual = (*lista) -> siguiente;/*actual toma la posicion del siguiente nodo*/
	while (actual != NULL && actual -> dato != valor){/*mientras no se llege al final de la lista y no sea el numero que se quiere borrar*/
		previo = actual;/*previo toma la posicion de actual*/
		actual = actual -> siguiente;/*actual avanza al siguiente nodo*/
	}
	if (actual != NULL) {/*pregunta si no es el ultimo nodo en la lista*/
		temporal = actual;/*temporal toma la posicion de alctual que es el nodo a borrar*/
		previo -> siguiente = actual -> siguiente;/*previo en siguiente toma el enlace al siguiente nodo*/
		free(temporal);/*de actual y entonces se libera el espacio que ocupaba el nodo a borrar*/
		return(valor);/*regresa el elemento borrado*/
	}
	return '\0';/*regresa este valor para indicar que es el ultimo nodo en la lista*/
}

/*funcion para determinar si hay elementos en la lista, recibe como parametro
  por valor la el inicio de la lista*/
int isempty(NODOSIG lista)
{
 return lista == NULL;/*pregunta si hay elemento en la lista, regresa nulo si no hay*/
}		      /*de lo contrario regresa un valor diferente*/
