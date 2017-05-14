/*  programa en lenguaje C con estructura dinámica 
	para generar una cola de caracteres alfabéticos 
	de tal forma que una vez que genera la cola dinámica, 
	se accesa la cola generada y se van sacando los elementos 
	de la cola (caracteres alfabéticos) y se van a insertar en 
	una segunda cola dinámica de tal manera que si vienen dos caracteres 
	repetidos solamente se insertara un carácter. Se imprimirá la cola con 
	los caracteres insertados y la segunda cola sin los caracteres repetidos */

#include <stdio.h>
#include<stdlib.h>

//Estructura
typedef struct  nodo
{
	/*variable a introducir caracter*/
	char caracter;

	/*enlace al siguiente nodo de la pila*/
	struct  nodo *siguiente;
};

typedef struct nodo NODO;  /*definicion de la estructura como tipo de dato*/
typedef NODO *NODOSIG;    /*Tipo de dato para generar los nodo de la lista*/


/* Funciones con pilas: */

//funcion de entrada a valores
NODOSIG *Push(NODOSIG *);

//Funcion que crea la segunda Cola
NODOSIG *Crear(NODOSIG *,NODOSIG *);

//funcion que imprime la primera y segunda Cola
void Imprime(NODOSIG *,NODOSIG *);


/*main*/
int main(void)
{
	/*Pilas*/
	NODOSIG Cola = NULL;                                
	NODOSIG Cola2 = NULL;

    /*Variables*/
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
				printf("\n\n\t\t\tCOLA DINAMICA !"
					 "\n\t****************************************"
					 "\n\n\t\t1.-Ingrezar elemento a primera cola"
					 "\n\t\t2.-Generar segunda Cola"
					 "\n\t\t3.-Salir"
					 "\n\t******************************************"
					 "\n\tOpcion: ");
					 
					 error = scanf("%d",&op);
					 if(error == 0)
					 {
						system("cls");
						printf("\tError!! Introduzca un numero entero");
					 }
			}
			if(op < 1 || op > 3)
			{
				system("cls");
				printf("\tError !!  opcion  no valida");
			}

		}while(op < 1 || op >3);
		
		//switch op
		switch(op)
		{
			/*caso 1 llamada a funcion Push, como parametro la Cola 1*/
			case 1:
			Cola = *Push(&Cola);
			
			//llamada a funcion Imprime, como parametros la direccion de las dos Colas
			Imprime(&Cola,&Cola2);
			printf("\n\n\t");
			system("PAUSE");
			break;

			/*caso 2 llamada a funcion Crear, como parametros la direccion de las dos Colas*/
			case 2:
			Cola = *Crear(&Cola,&Cola2);
			
			//llamada a funcion Imprime, como parametros la direccion de las dos Colas
			Imprime(&Cola,&Cola2);
			printf("\n\n\t");
			system("PAUSE");
			break;
		}
	}while(op!=3);

	printf("\n\n");
	system("PAUSE");
	return 0;
}

/*funcion Push recibe direccion de pila1 o pila2*/
NODOSIG * Push(NODOSIG *Cola)
{
	NODOSIG nuevo,aux;  /*variable auxiliar para crear nuevo nodo */

	/* Crear un nodo nuevo */
	nuevo = malloc(sizeof(NODO));

    if(nuevo != NULL)
    {
	   fflush(stdin);
	   printf("\n\n\tIntroduzca un caracter: ");
	   scanf("%c",&nuevo->caracter);

	   /*varificamos si es el primer nodo a ingrezar en la Cola*/
	   if(*Cola == NULL)
	   {
		   nuevo->siguiente = NULL;
		   *Cola = nuevo;
		   
		   //Retorno de la nueva direccion de Cola
		   return Cola;
	   }

	   //No es el primer nodo de la Cola
	   else
	   {
		   /*conectamos el nodo al Final de la Cola*/
		   nuevo->siguiente = NULL;
		   aux = *Cola;

		   while(aux->siguiente != NULL)
			   aux = aux->siguiente;

		   aux->siguiente = nuevo;

		   /*retorno de la nueva direccion de Cola */
		   return Cola;
	   }
   }
}

//Funcion Imprime, Recibe como parametros la direccion de cola y Cola2
void Imprime(NODOSIG *Cola,NODOSIG *Cola2)
{
	NODOSIG aux,aux2; /* variables auxiliares para manipular nodo */

    // Imprecion de solamente la Cola Ingrezada
	if(*Cola != NULL) 
    {     
         aux = *Cola; // variable axiliar para el manejo de la Cola
         system("cls");
         printf("\n\n\tCola \n\t");

		    /*se recorrera Cola1 hasta llegar a NULL*/
		    while(aux  != NULL)
		    {
		        printf("%c-->",aux->caracter);
	            aux = aux->siguiente;
		    }
		    printf("NULL");
     }

    //Impreciones de las dos Colas
	else
	{	 
        aux2 = *Cola2;
		printf("\n\n\tSegunda Cola\n\t");
        
        /*se recorrera Cola2 hasta llegar a NULL*/
		while(aux2  != NULL)
		{
		  printf("%c-->",aux2->caracter);
		  aux2 = aux2->siguiente;
		}
		printf("NULL");
	}
}

//Funcion Crear, Recibe como parametros la direccion de la primera y segunda Cola
NODOSIG * Crear(NODOSIG *Cola,NODOSIG *Cola2)
{
	if(*Cola != NULL)
	{
		NODOSIG aux; /*variable auxiliar para la manipulacion de la Cola */
		NODOSIG nuevo; /* variable auxiliar para crear nuevo nodo */
		NODOSIG aux2; /*variable auxiliar para la manipulacion de la Cola */
		NODOSIG previo;/*variable auxiliar para la manipulacion de la Cola */
		
		//variables
		int bandera;
		aux = *Cola;

		/*Se recorre Cola1 hasta llegar a NULL*/
		while(aux != NULL)
		{
            //Yah hay elementos introducidos en la segunda Cola       
			if(*Cola2 != NULL)
			{
				aux2 = *Cola2;
				bandera = 0;
				
				//se Recorre Cola 2 hasta llegar a NULL
				while(aux2!= NULL)
				{
                    //Pregunta si ya existe el caracter a ingrezar en Cola2
					if(aux->caracter == aux2->caracter)
						bandera = 1;
					
					previo = aux2;
					aux2 = aux2->siguiente;
				}
     
                //No se encontro un nodo con mismo caracter
				if(bandera == 0)
				{
                      //se crea el nuevo NODO
					 nuevo = malloc(sizeof(NODO));
					 
					 //se creo espacio en memoria
					 if(nuevo != NULL)
					 {
					     nuevo->caracter = aux->caracter;
					     nuevo->siguiente = NULL;
					     previo->siguiente = nuevo;
                     }
				}
			}
			
			//Es el primer Nodo a Introducir en segunda Cola
			else
			{
					nuevo = malloc(sizeof(NODO));
					if(nuevo != NULL)
					{
                         nuevo->caracter = aux->caracter;
					     nuevo->siguiente = NULL;
					     /* Ahora, el comienzo de nuestra Cola es en nuevo nodo */
					     *Cola2 = nuevo;
                    }
			}
			if(aux->siguiente == NULL)
			{
                  free(*Cola); 
                  aux = NULL; 
                  *Cola = aux;                
            }
			else
			{
               *Cola = aux->siguiente;
               free(aux);
               aux = *Cola;    
            }
		}
	}
	else
	{
		 printf("\n\n\tNo se han introducido elementos en la Cola uno!");
	}
	return Cola;
}
