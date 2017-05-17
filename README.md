# algorithms_of-arrays-strings-structures-memory-more
My solutions on C / C++ / Ruby of interesting challenges of arrays, strings, structures, memory and more..

----------

## 01 Structures

####	binary_search_method.c
Método permite buscar un valor en un arreglo que se está desordenando utilizando el algoritmo de búsqueda binaria.

####	binary_search_tree.c
Programa que genera un árbol Binario de búsqueda. 
El usuario puede agregar y borrar N nodos. 
Es posible buscar un nodo dentro del árbol binario.
Funciones adicionales:
* Impresión del árbol (InOrden, PreOrden, PostOrden).
* Contar número de nodos.
* Calcular la altura del árbol.
* Calcular altura de un nodo.

####	circular_list.c
Lista circular: una especie de lista enlazada simple o doblemente enlazada, pero que posee una característica adicional para el desplazamiento dentro de la lista, “ésta no tiene fin”. Para que la lista sea sin fin, el puntero siguiente del último elemento apuntará hacia el 1er elemento de la lista en lugar de apuntar al valor NULL.

####	double-linked_list.c
Las listas doblemente enlazadas no necesitan un nodo especial para acceder a ellas, pueden recorrerse en ambos sentidos a partir de cualquier nodo, esto es porque a partir de cualquier nodo, siempre es posible alcanzar cualquier nodo de la lista, hasta que se llega a uno de los extremos.

####	infix_to_postfix.c
Programa en lenguaje C el cual de cómo entrada una expresión en notación Infija y la transforme a notación Postfija apoyándose con el uso de pilas.

####	kruskal.c
Algoritmo de Kruskal 

####	linear_search_disordered_method.c
Método permite buscar un valor en un arreglo que se está desordenado utilizando el algoritmo de búsqueda lineal, secuencial y recursivo.

####	linear_search_disordered_method.c
Método permite buscar un valor en un arreglo que se está ordenado utilizando el algoritmo de búsqueda lineal, secuencial y recursivo.

####	linked_lists.c
Este programa realiza las operaciones de inserción, eliminación e impresión en listas enlazadas.

####	postfix_interpret.c
Programa en lenguaje C el cual evalúa una expresión transformada en notación postfija, la cual debe ser almacenada en un arreglo y ser evaluada, con el uso de pilas.

####	queue.c
Programa en lenguaje C con estructura dinámica para generar una cola de caracteres alfabéticos de tal forma que una vez que genera la cola dinámica, se accesa la cola generada y se van sacando los elementos de la cola (caracteres alfabéticos) y se van a insertar en una segunda cola dinámica de tal manera que si vienen dos caracteres repetidos solamente se insertara un carácter. Se imprimirá la cola con los caracteres insertados y la segunda cola sin los caracteres repetidos.

####	stacks.c
Programa que utilice dos pilas, las cuales tendrán como entrada valores numéricos. Se mezclarán las dos pilas en una tercer pila, donde la pila resultante se obtiene apilando alternativamente los elementos de ambas pilas de tal manera que si existe un valor numérico repetido solamente entrará uno, además calculará el número de elementos de la pila. Se imprimirán las tres pilas.

## 02 Recursiveness
	
####	int_to_binary.c
Programa que dado un número obtiene su valor en binario.

####	number_even.c
Programa que evalúa si un número es par o impar con recursividad indirecta.

####	potency.c
Programa que dado dos números obtiene la potencia de número uno elevado la número dos.

## 03 Threads

####	Threads.cpp
Hilo en ejecucion, el cual tiene un proceso padre.
Pueden dividir su proceso en multiples threads usando la funcion CreateThread y una funcion thread de soporte.
####	ThreadWaitForSingleObject.cpp
WaitForMultipleObjects cuando quieran esperar a que terminen los threads que crearon.
   Recuerden que la ejecucion del main se pausara en el WaitForMultipleObjects, hasta que todos los threads hayan terminado de ejecutar.

## 04 Strings
	
####	compare_strings.c
Programa en c que compara dos strings.

####	concatenate.c
Programa en c que concatena dos strings.

####	find_word.c
Se tiene un texto formado por un máximo de 10 líneas, del cual se quiere saber el número de apariciones de la palabra CLAVE. Desarrollar un programa en C, el cual lea el texto y la palabra CLAVE, determine el número de apariciones de la palabra CLAVE en el texto. Se imprimirá el texto y el número de veces que aparece la palabra CLAVE.

####	order_and_cont_chars.c
Programa en c, que dado una cadena toma las palabras de la dicha cadena y las imprime acomodadas en orden alfabetico además de mencionar el número de veces que la palabra se encuentra en la cadena.

####	palindrome.c
Programa que calcula si una frase ingresada es un palíndromo o no ignorando los espacios en blanco.

####	reverse_number.c
Dado un número entero inverte dicho número.

####	romans.c
Ingresar un número entero y mostrar su equivalente romano.

####	validate.c
Programa que convierte minúsculas a mayúsculas.

## 05 Arrays

####	averages.c
Programa en C, el cual calcula el promedio de n valores almacenados en un vector. Determina además cuantos son mayores que el promedio, e imprime el promedio, el número de datos mayores que el promedio y una lista de valores mayores que el promedio, así como el vector original.

####	counter_arrays.c
Dado dos arreglos de mxn elementos, programa en C el cual, suma los dos arreglos y los guarda en un tercer arreglo, únicamente los elementos que sean mayores a un valor dado por el teclado.

####	diagonal_counter.c
Programa que obtiene la suma de la diagonal principal de una matriz.

####	diagonals.c
Dado dos matrices de mxn elementos donde m=n, crear un programa en C el cual, intercambie los elementos de la diagonal principal con los elementos de la diagonal invertida. Se imprimirá, el arreglo de entrada, y el arreglo con las diagonales invertidas.

####	intercalate.c
Programa que intercala los elementos de dos arreglos en un tercer arreglo primero los elementos de A y después los elementos de B.

####	matrix_order.c
Dada una matriz de m x n elementos desarrollar un programa en C el cual, ordene los elementos de la matriz por fila y los dejes ordenados en la misma fila. Imprimir la matriz ordenada por filas.

####	matrix_center.c
Dado un arreglo de mxn elementos, crear un programa en C el cual, tome los elementos de la matriz que pertenecen al centro y los almacene en un vector. Se imprimirá la matriz de entrada y el vector.

####	square.c
Programa que genera un segundo arreglo con los elementos al cuadrado del primero.

####	trsnaposed_matrix.c
Programa en C el cual lee una matriz A de M x N elementos y forma una matriz traspuesta de A.

####	upward.c
Programa que ordena de forma ascendente un arreglo numérico.


