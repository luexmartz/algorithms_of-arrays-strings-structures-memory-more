/*  Método permite buscar un valor en un arreglo 
    que se está desordenado utilizando 
    el algoritmo de búsqueda lineal, secuencial y recursivo. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int busqueda_desordenado (int v[],int N, int x,int flag);
int busqueda_desordenado_recursivo (int v[],int N,int x, int i, int flag);
int leer (int v[],int n);

int main (){

   int v[' '];
              
   int valor; //reprecenta el Valor a buscar
   int op, op2,N;
   int j;


  do {
   system ("CLS");
   printf ("\n\n\t\t* * * BUSQUEDA SECUENCIAL DESORDENADA * * *\n\n"
           "\t\t1> desordenada\n"
           "\t\t2> desordenada recursiva\n"
           "\t\t3> Salir\n"
           "\n\t\tOpcion: ");
   scanf("%d", &op2);

   switch(op2) {
               case 1:     system ("CLS");
                           printf("\n\t Total de elementos a ingresar: ");
                           scanf("%d",&N);
           				   leer(v,N);
           				   printf("\n");
                           for(j=0; j<N; j++) printf("\n V[%d] = %d",j,v[j]);
                           printf ("\n\n\tvalor a buscar: ");
                           scanf ("%d", &valor);
                           busqueda_desordenado (v,N,valor,0);
                           break;

               case 2:     system ("CLS");
                           printf("\n\t Total de elementos a ingresar: ");
                           scanf("%d",&N);
           				   leer(v,N);
           				   printf("\n");
                           for(j=0; j<N; j++) printf("\n V[%d] = %d",j,v[j]);
                           printf ("\n\nvalor a buscar: ");
                           scanf ("%d", &valor);
                           busqueda_desordenado_recursivo (v,N,valor, 0, 0);
                           break;
   }
   getch();
  }while(op2!=3);
}


int busqueda_desordenado(int v[],int N, int x,int flag) {
     int i;
     i = 0;
     while((i <= N) && (v[i]!= x)){ /* i sea menor que el total de numeros, y el valor del arreglo sea diferente
                                       al buscado */
           i++;         
     }
     if(i > N)
          printf("\n\t\tLa informacion no se encontro en el arreglo");
     else
         printf("\n\t\tla informacion se encuentra en la posicion V[%d] ",i);           
}
// *********************************

int busqueda_desordenado_recursivo (int v[' '],int N, int x, int i, int flag){
       if (i >= N){
          if(flag == 0)
                  printf ("\nLa informacion no se encuentra en el arreglo");
                  }
     else
       if (v[i]== x){
            printf ("\n\n\n\tLa informacion se encuentra en la posicion v[%d]", i);
            flag++;
            busqueda_desordenado_recursivo(v,N,x,i+1, flag);
         }else
             busqueda_desordenado_recursivo(v,N,x,i+1, flag);
}

int leer(int v[],int n) {
  int k=0;
  for (k=0; k<n; k++){
  	  printf ("\n\t\tValor[%d]: ", k);
     scanf ("%d", &v[k]);
  }
  system ("CLS");
}
