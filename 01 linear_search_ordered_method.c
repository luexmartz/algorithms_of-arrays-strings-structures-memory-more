/*  Método permite buscar un valor en un arreglo 
    que se está ordenado utilizando 
    el algoritmo de búsqueda lineal, secuencial y recursivo. */

#include <stdio.h>
#include <windows.h>


void busqueda_ordenado (int v[],int N, int x);
void busqueda_ordenado_recursivo (int v[],int N, int x, int i, int flag);
void leer_Ordenar(int v[],int N);

int main (){

   int v[' '];  
   int valor;
   int op;
   int j,N;

  do {
   system ("CLS");
   printf ("\n\n\t\t****BUSQUEDA SECUENCIAL ORDENADA ****\n\n"
           "\t\t1.ordenada\n"
           "\t\t2.ordenada recursiva\n"
           "\t\t3.Salir"
           "\n\n\t\tIngrese una opcion: ");
           scanf("%d", &op);

   switch(op) {
   	case 1:
			system ("CLS");
         printf("\n\n\t\tTotal de elementos: ");
         scanf("%d",&N);
         leer_Ordenar(v,N);

  			for(j=0; j<N; j++)
         	 printf("\n\nV[%d]= %d",j,v[j]);

      	printf ("\n\n\tIngrese el valor a buscar: ");
  			scanf ("%d", &valor);
         busqueda_ordenado (v,N, valor);
         getch();
      break;

      case 2:
         system ("CLS");
         printf("\n\n\t\tTotal de elementos: ");
         scanf("%d",&N);
         leer_Ordenar(v,N);

         for(j=0; j<N; j++)
             printf("\n\nV[%d]= %d",j,v[j]);

      	printf ("\n\n\tIngrese el valor a buscar: ");
  			scanf ("%d", &valor);
         busqueda_ordenado_recursivo (v,N, valor, 0, 0);
         getch();
      break;
   }
  }while(op!=3);
}


void leer_Ordenar(int v[],int N){
     int i,j,aux;
     for(i = 0; i < N; i++){
                  printf("Valor [%d]: ",i);
                  scanf("%d",&v[i]);
     }
     //Ordenar los datos pedidos ****
     for(i=0;i<N-1;i++){
         for(j=i+1; j<N; j++){
                 if(v[j] < v[i]){
                         aux = v[j];
                         v[j] = v[i];
                         v[i] = aux;
                 }
         }
     }
     system("CLS");
}

void busqueda_ordenado(int v[],int N, int x) {
     int i;
     i = 0;
     while( (i<= N) && (x > v[i]) )
        i++;
     if( i > N || x < v[i])
           printf("La informacion no se encuentra en el arreglo");
     else
         printf("\nLa informacion se encuentra en la posicion V[%d]",i);
}


void busqueda_ordenado_recursivo (int v[],int N, int x, int i, int flag){

       if ( (i < 10) && (x == v[i]) ){
            printf ("\n\n\n\t\tLa informacion se encuentra en la posicion v[%d]", i);
            flag++;
            busqueda_ordenado_recursivo(v,N,x,i+1,flag);
       }
     else
       if (i > 10){
       	  if (flag == 0)
               printf ("\n\nLa informacion no se encuentra en el arreglo");
       }else
            busqueda_ordenado_recursivo(v,N,x,i+1, flag);
}
