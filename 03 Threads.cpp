#include <iostream>

#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

//PROCESO: Es un programa en ejecucion
//THREAD: es un hilo en ejecucion, el cual tiene un proceso padre.
//Pueden dividir su proceso en multiples threads usando la funcion CreateThread y una funcion thread de soporte.

//Para que puede servir un thread?
//Para agilizar procesos que requieren gran cantidad de tiempo de espera para el usuario
//Para evitar dejar la consola congelada mientras se ejecuta algun proceso grande,
//Se puede dejar el thread principal MAIN,  actualizando un mensaje de espera para el usuario, mientras que un Thread aparte ejecuta el proceso grande.
//Para imprimir se debe de crear un thread aparte, para que no se le congele la pantalla al usuario mientras se imprime el documento
//Para leer archivos grandes, se puede crear un thread aparte que lea el archivo mientras se le muestra un mensaje de ESPERE al usuario, 
//O bien se le puede permitir al usuario seguir trabajando con el programa, y accesando opciones de menu, o navegando por el programa,
//mientras un thread aparte este ejecutando una tarea que pueda ser muy tardada.

//Declaracion de la funcion THREAD de soporte
//Las palabras DWORD y LPVOID siempre deben de ir tal cual estan aqui. 
//La funcion siempre SIEMPRE debe regresar un DWORD, y siempre SIEMPRE debe recibir un LPVOID como parametro de entrada.
//El nombre de la funcion, y el nombre del parametro de entrada, si lo puedes cambiar a como tu escojas, solo ten cuidado que 
//cuando crees el thread usando la funcion CreateThread en el main, le pases el nombre de la funcion tal y como la hayas llamado aqui.

//LA FUNCION THREAD se puede poner en el .h y .cpp de una clase, PERO FUERA DE LA CLASE,
//y despues se puede mandar llamar la funcion CreateThread desde dentro de alguna de las funciones de la clase,
//igual cuando invoques la funcion CreateThread solo pasale el nombre de la funcion thread que definiste en el .cpp
//Con esto te quiero decir que puedes crear un thread desde donde quieras, siempre y cuando la 
//funcion thread este accesible,  si quieres crear un thread desde dentro del constructor de una clase,
//o desde una funcion virtual, o desde una funcion normal dentro de una clase, se puede hacer.



DWORD MiThread (LPVOID threadParametros );

//DEFINICION DE LA FUNCION
DWORD MiThread (LPVOID threadParametros )
{

   //En este ejemplo el parametro de entrada, viene siendo el numero de thread que se le asigno a este THREAD.
   //pero en realidad el parametro de entrada puede ser lo que ustedes quieran,  y como ustedes lo quieran usar, es decicion de ustedes,
   //en este ejemplo dicho parametro se esta usando para ponerle un numero al este thread, que sera mas bien como el nombre del thread.
   //cada thread que se cree recibira un numero como nombre, Ejemplo: Thread 1, Thread 2, Thread 3, etc. Y el numero de thread se recibe desde el MAIN,
   //al momento en que se crea el thread, el main le pasa este numero a esta funcion que fungira como Thread.

   //El parametro de entrada threadParametros  es de tipo LPVOID
   //LPVOID en realidad es un puntero a void, es como si tuvieras un  void * miVariable;
   //pero en vez de void *, se le pone LPVOID el cual es un tipo de dato de la libreria de Windows.
   
   
   //convertimos el LPVOID usando cast, al tipo de dato que sea tu parametro.
   //Si tu parametro es un int hay que convertir el LPVOID a int usando el cast (int)
   int iNumeroDeThreadIn = (int)threadParametros;

   //Recuerda la analogia que de poner un int dentro de una caja de tipo LPVOID, tomas el int y lo metes a la caja,
   //despues pasas la caja de tipo LPVOID a esta funcion que lo recibe como parametro, y dentro de esta funcion
   //sacas el int que esta dentro de la caja LPVOID, y la forma de sacarlo es haciendo un cast  (int) como se ve en el codigo de arriba.


   //Ya que convertiste el parametro de entrada, usando el cast de arriba,  ahora puedes codificar la logica de tu thread,
   //lo que tu hayas definido que el thread debe hacer, aqui lo codificas.


   //AQUI SOLO POR MOSTRAR UN EJEMPLO el thread solamente hara un ciclo de 10,  y en cada ciclo va a desplegar un mensaje, en cuyo 
   //mensaje se desplegara el numero de thread, asi como la variable i del ciclo.

   //OJO: dado que la variable iNumeroDeThreadIn se declara dentro del cuerpo de esta funcion,  CADA THREAD declarara su propia variable
   //por lo que dicha variable sera independiente de los demas threads,  cada thread tendra su propia variable, ya que cada thread corre aparte.
   //es por eso que cada thread mantiene su NUMERO (o nombre del thread).

    for(int i = 0; i < 10 ; i++)
    {
       cout<<"Mensaje desde el Thread "<<iNumeroDeThreadIn<<" :"<<i<<endl;
       Sleep(1000);  
       //OJO no quiere decir que siempre le tengan que poner un Sleep a sus threads, yo se lo puse solo para mostrar un ejemplo!!
    }

    return 0; 
} 


//OJO!!!!!!   Puedes tener cuantas funciones thread quieras, 
// Por ejemplo podrias tener otra funcion llamada MiThread1, y otra funcion llamada AccesarArchivo. 
// Cada una de estas funciones puede hacer cosas diferentes, lo que tu hayas dedicido que cada una haga, lo puede hacer, 
// no necesariamente tiene que ser el mismo codigo para todas tus funciones thread.
// Despues en el main puedes crear los threads para cada una usando la funcion CreateThread y nadamas cambiandole el nombre de la funcion cuando mandes llamar a CreateThread
// 

int main (void)
{

   //Declaras una variable DWORD para obtener el id del thread que se creo.
   //El ID es un numero unico que es asignado por el sistema operativo al thread que se creo.
   DWORD dwThreadId;

   int iNumeroDeThreads = 0;

   
   //Preguntamos al usuario cuantos threads quiere crear
   cout<<"Numero de threads?"<<endl;
   cin>>iNumeroDeThreads;


   //usamos un ciclo for para crear el numero de threads que el usuario quiere

   for (int i=1; i<= iNumeroDeThreads; i++) 
   {
      
      //SE UTILIZA LA FUNCION CreateThread para crear un thread, el cual correra en paralelo con el thread principal el cual es el MAIN de tu programa.
      //Desde tu MAIN  estas creando un thread que correra en paralelo, al mismo tiempo que el main.
      if (
            CreateThread
            (
            NULL, //DEJA ESTE VALOR SIEMPRE IGUAL
            0,    //DEJA ESTE VALOR SIEMPRE IGUAL
            (LPTHREAD_START_ROUTINE)&MiThread,  //Aqui le pasas el Nombre de tu funcion que fungira como Thread. Siempre ponle el (LPTHREAD_START_ROUTINE)& antepuesto al nombre de tu funcion
            (LPVOID) i,   //Aqui le pasas el parametro de entrada que recibira tu funcion, en este caso es la variable i la cual es int, a cada thread se le asignara un numero i. Siempre ponly (LPVOID) antepuesto del nombre de tu parametro.
            0, //DEJA ESTE VALOR SIEMPRE IGUAL
            &dwThreadId //PASALE LA VARIABLE dwThreadId que declaraste arriba en el main
            ) == NULL  //verifica que el thread se haya creado correctamente
         )
      {
         cout<<"Error creando threads"<<endl; //Si no se creo correctamente, despliega mensaje (OJO, si la especificacion o los requerimientos de usuario que te pasen, no te pide mostrar mensaje, entonces no muestres nada)
         return(1);
      }
      else
      {
         cout<<"Conteo de Threads"<<i<<endl;
      }
   }
   
   //Este mensaje se estara desplegando en pantalla, al mismo tiempo que se despliegan los mensajes de cada thread que se haya creado en el Create Thread.
   for (int i = 0; i < 20; i++)
   {
      cout<<"Mensaje desde el main"<<endl;
      Sleep(1000);
   }
   getch();
   return 0;
}



