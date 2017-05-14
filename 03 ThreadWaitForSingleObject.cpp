

#include <iostream>

#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

//PROCESO: Es un programa en ejecucion
//THREAD: es un hilo en ejecucion, el cual tiene un proceso padre.
//Pueden dividir su proceso en multiples threads usando la funcion CreateThread y una funcion thread de soporte.

DWORD MiThread (LPVOID threadParametros );

//DEFINICION DE LA FUNCION
DWORD MiThread (LPVOID threadParametros )
{

   int iNumeroDeThreadIn = (int)threadParametros;

    for(int i = 0; i < 10 ; i++)
    {
       cout<<"Mensaje desde el Thread "<<iNumeroDeThreadIn<<" :"<<i<<endl;
       Sleep(1000);  
    }

    return 0; 
} 

int main (void)
{

   DWORD dwThreadId;
   DWORD dwWaitResult;

   int iNumeroDeThreads = 0;

   HANDLE hThr[20];
     
   cout<<"Numero de threads?"<<endl;
   cin>>iNumeroDeThreads;
   int iContadorThreads = 0;

   for (int i = 0; i < iNumeroDeThreads; i++) 
   {

      hThr[i] = CreateThread
         (
            NULL, //DEJA ESTE VALOR SIEMPRE IGUAL
            0,    //DEJA ESTE VALOR SIEMPRE IGUAL
            (LPTHREAD_START_ROUTINE)&MiThread,  //Aqui le pasas el Nombre de tu funcion que fungira como Thread. Siempre ponle el (LPTHREAD_START_ROUTINE)& antepuesto al nombre de tu funcion
            (LPVOID) i,   //Aqui le pasas el parametro de entrada que recibira tu funcion, en este caso es la variable i la cual es int, a cada thread se le asignara un numero i. Siempre ponly (LPVOID) antepuesto del nombre de tu parametro.
            0, //DEJA ESTE VALOR SIEMPRE IGUAL
            &dwThreadId //PASALE LA VARIABLE dwThreadId que declaraste arriba en el main
            ) ;
      
      if (hThr[i]==NULL)
      {
         cout<<"Error creando threads"<<endl; 
         return(1);
      }
      else
      {
         cout<<"Conteo de Threads"<<i<<endl;
         iContadorThreads++;
      }
   }
   
   cout<<"Antes del wait"<<endl;
   
   //USEN LA FUNCION WaitForMultipleObjects cuando quieran esperar a que terminen los threads que crearon.
   //Recuerden que la ejecucion del main se pausara aqui en el WaitForMultipleObjects, hasta que todos los threads hayan terminado de ejecutar.
   dwWaitResult = WaitForMultipleObjects(iContadorThreads,hThr,FALSE,INFINITE);
   cout<<"Despues del wait"<<endl;
   
   //Getch para que no se cierre el programa y permita ver el resultado final
   getch();

   return 0;
}



