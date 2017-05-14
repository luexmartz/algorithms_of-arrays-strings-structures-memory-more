/*  Método permite buscar un valor en un arreglo 
    que se está desordenando utilizando 
    el algoritmo de búsqueda binaria. */

#include<stdio.h>
#include<conio.h>

int Binaria(int v[' '],int N,int X,int flag);
int binaria_Recursiva(int v[' '],int izq,int der,int x,int flag);
void mostrarArreglo(int v[' '],int N);

int main (){

    int vector[' '];
    int N,x,op;
    do{
        system("CLS");
        printf("\n\n\t\t***BUSQUEDA BINARIA***\n\n"
           "\t\t1.Busqeda sencilla\n"
           "\t\t2.Busqueda recursiva\n"
           "\t\t3.Salir \n"
           "\n\t\tOpcion: ");
        scanf("%d",&op);

        switch(op){
              case 1:       system("CLS");
                            printf("\n\n\t\tTotal de elementos: ");
                            scanf("%d",&N);
                            leer_Ordenar(vector, N);
                            mostrarArreglo(vector,N);
                            printf("Elemento a buscar: ");
                            scanf("%d",&x);
                            Binaria(vector,N,x,0);
                            getch();
                            break;

              case 2:       system("CLS");
                            printf("\n\n\t\tTotal de elementos: ");
                            scanf("%d",&N);
                            leer_Ordenar(vector, N);
                            mostrarArreglo(vector,N);
                            printf("\n\t\tElemento a buscar: ");
                            scanf("%d",&x);
                            binaria_Recursiva(vector,0,N,x,0);
                            getch();
                            break;
        }
    }while(op!=3);
return 0;
}


leer_Ordenar(int v[],int N)
{
     int i,j,aux;
     printf("\n\n");
     for(i = 0; i < N; i++){
                  printf("\t\tValor [%d]: ",i);
                  scanf("%d",&v[i]);
     }
     system("CLS");
     printf("\n__Datos ingresados__\n");
     for(i = 0; i < N; i++) printf("\n\tValor [%d]: %d",i,v[i]);
     printf("\n\n*__Datos Ordenados__*\n");
     //Ordenar los datos ****
     for(i=0;i<N-1;i++){
         for(j=i+1; j<N; j++){
                 if(v[j] < v[i]){
                         aux = v[j];
                         v[j] = v[i];
                         v[i] = aux;
                 }
         }
     }
}


int Binaria(int V[' '],int N,int X,int flag){
   int IZQ,CENTRO,DER;
   IZQ = 0;
   DER = N-1; 

  while( (IZQ < DER) ){

        CENTRO =(IZQ + DER)/2;
        if(V[CENTRO] == X){
           printf("\n\n\t\tLa informacion esta en la posicion V[%d]", CENTRO);
           flag++;
           if(V[CENTRO] > X)
                    DER = CENTRO -1;
               else
                     IZQ = CENTRO +1;
          } 
        else{   
            if(V[CENTRO]> X)
                     DER = CENTRO - 1;
                else
                     IZQ = CENTRO + 1;
        }
   }
      if(IZQ >= DER)
             if(flag == 0) 
                     printf("\n\n\t\tLa informacion no esta en el arreglo");
}


int binaria_Recursiva(int v[' '],int izq,int der,int x,int flag){
  int cen;
    if(izq > der){
          if(flag == 0)
                printf("\n\n\t\t%d No se encuentra en el vector",x);
    }           
    else{
           cen = ((izq + der)/2);
           if(x == v[cen]){
                printf("\n\t\tEl dato buscado se encuentra en la posicion V[%d]",cen);
                flag++;
                return binaria_Recursiva(v,izq,cen+1,x,flag);
           }
           else{
               if(x > v[cen])
                    return binaria_Recursiva(v,cen+1,der,x,flag);
               else
                   return binaria_Recursiva(v,izq,cen-1,x,flag);
           }
      }
}

void mostrarArreglo(int v[' '],int N)
{
 int i;
  for (i = 0; i < N; i++)
      printf("\n\tValor[%d] = %d",i,v[i]);
  printf("\n\n");
}
