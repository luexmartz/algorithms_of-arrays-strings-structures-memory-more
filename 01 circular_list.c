/*  Lista circular: una especie de lista enlazada 
    simple o doblemente enlazada, pero que posee una 
    característica adicional para el desplazamiento dentro 
    de la lista, “ésta no tiene fin”. Para que la lista sea sin fin, 
    el puntero siguiente del último elemento apuntará hacia el 1er elemento 
    de la lista en lugar de apuntar al valor NULL */

#include <stdlib.h>
#include <stdio.h>

struct nodo 
{
   int valor;
   struct nodo *siguiente;
};

typedef struct nodo NODO;
typedef NODO *NODOSIG;

// FUNCIONES
NODOSIG * IngrezarValor(NODOSIG *);

void Borrar(NODOSIG *);

void printfLista(NODOSIG);

int main()
{
   NODOSIG lista = NULL;
   int op,error;
   do{
       system("cls");
       do
       {
            error=0;
            while(error==0)
            {
                fflush(stdin);
                printf("\n\t***********************");
                printf("\n\tMENU\n\t1.-"
                "Insertar elemento\n\t2.-"
                "Borrar elemento\n\t3.-"
                "imprimir elementos\n\t4.-Salir");
                printf("\n\t***********************\n\tOpcion:");
                error=scanf("%d",&op);
                if(error==0)
                {
                    system("cls");
                    printf("Error!! Introduzca un numero entero");            
                }
            }//while
            
            if(op<1||op>4)
            {
                  system("cls");
                  printf("Error!! Numero no valido");
            }   
       }while(op<1||op>4);
   
       switch(op)
       {
             case 1:
                  lista = *IngrezarValor(&lista);
                  printf("\n\n");
                  system("PAUSE");
                  break;
             case 2:
                  if(lista != NULL)
                       Borrar(&lista);
                  else
                      printf("\n\tlista vacia!");
                  printf("\n\n");
                  system("PAUSE");
                  break;
             case 3:
                  printfLista(lista);
                  printf("\n\n");
                  system("PAUSE");
                  break;
           } 

    }while(op!=4);
   printf("\n\n");
   system("PAUSE");
   return 0;
}

void printfLista(NODOSIG actual)
{
   if(actual != NULL)
   {
       NODOSIG w;
       w = actual;
       printf("\n\tLISTA\n\n");
       do 
       {
            printf("%d -> ", actual->valor);
            actual = actual->siguiente;
      
       }while(actual != w);
    }
    else
        printf("\n\n\tlista vacia !");
}

NODOSIG * IngrezarValor(NODOSIG *lista)
{
   NODOSIG nuevo;
   int num,error;
   do
   {
       error = 0;
   
       while(error==0)
       {
           fflush(stdin);
           printf("\n\n\tNumero:");
           error = scanf("%d",&num);
           if(error==0)
                 printf("Error!! Introduzca un numero entero");
       }
   }while(error < 1);
        
   // nuevo nodo
   nuevo = (NODO*)malloc(sizeof(NODO));
   nuevo->valor = num;

   //verificamos si es el primer nodo de la lista vacia
   if(*lista == NULL)
   { 
       *lista = nuevo;
   }
   //no lo es
   else 
   { 
        nuevo->siguiente = (*lista)->siguiente;
   }
   
   // se apunta al inicio del nodo y toma un aspecto circular 
   (*lista)->siguiente = nuevo;
   return lista;
}

void Borrar(NODOSIG *lista)
{
   NODOSIG nodo;
   int valor;

   nodo = *lista;
   
   printf("\n\n\tElemento a eliminar : ");
   scanf("%d",&valor);

   do 
   {
      if((*lista)->siguiente->valor != valor) 
      {
          *lista = (*lista)->siguiente;
      }
      
   } while(*lista != nodo && (*lista)->siguiente->valor != valor );
   
   if((*lista)->siguiente->valor == valor) 
   {
      if(*lista == (*lista)->siguiente) 
      {
                
         free(*lista);
         *lista = NULL;
      }
      else 
      {
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
             free(nodo);
      }
   }
}

