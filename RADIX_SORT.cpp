#include<iostream>
using namespace std;
 
 //Prototipos de funcion
 
int obtenerMaximo(const int *arreglo, int tamanio);
void cantidadOrden(int *arreglo, int tamanio, int div);
void RadixSort(int arr[], int size);

int main(){
    int arr[5] = {1,45,78,46,3};  // declaramos nuestro arreglo con 5 elementos
    RadixSort(arr, 5);             // llamamos a nuestra funcion RadixSort
    cout<<endl<<"Lista ordenada "<<endl;
    for(int i=0; i < 5; i++){           //imprimimos nuestros valores en pantalla
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Funcion para obtener maximo valor de un arreglo
int obtenerMaximo(const int *arreglo, int tamanio){  // implementacion de la funcion       
    int valorMax = arreglo[0];                       // inicializamos como valor maximo al primer elemento
    for (int i = 1; i < tamanio; i++)                //recorremos  el arreglo
        if (arreglo[i] > valorMax)                  // condicion para encontrar el elemento maximo
            valorMax = arreglo[i];                  //asignamos a valorMax el elemento mayor encontrado
    return valorMax;                                //retorna el numero mayor
}

void cantidadOrden(int *arreglo, int tamanio, int div){ // implementacion de la funcion  
    int salida[tamanio];                                //ARRAY DE LA RESPUESTA        
    int contador[10] = {0};                                 //ARRAY CONTADOR inicializados en ceros

    for (int i = 0; i < tamanio; i++)                   //recorre cada elemento del arreglo
        contador[(arreglo[i] / div) % 10 ]++;            //sumara uno por cada valor que se repita en la posicion

    for (int i = 1; i < 10; i++)                        //recorrera cada posicion de mi arreglo contador
        contador[i] += contador[i - 1];                 // se le sumara el elemento actual y el siguiente ya que empezamos en 1 y se ira actualizando su valor

    for (int i = tamanio - 1; i >= 0; i--){                //decreceremos en el bucle 
        salida[contador[(arreglo[i] / div) % 10 ] - 1] = arreglo[i];            // la posicion en el arreglo salida que tomara el numero del arreglo inicial
                                                                                //pero se le restara 1 al valor almacenado en mi contador
        contador[(arreglo[i] / div) % 10 ]--;                                   // disminuiremos el valor en 1 cada vez que asignemos ya una posicion
    }
//RESPUESTA FINAL:
    for (int i = 0; i < tamanio; i++)           //Con este for asignamos los valores de mi arrelgo de salida, como mi arreglo inicial
        arreglo[i] = salida[i];
}

void RadixSort(int arr[], int size){                    //implementacion de la funcion
    int numMayor = obtenerMaximo(arr, size);                // asignamos el mayor valor obtenido a la variable num mayor
    for (int i = 1; numMayor / i > 0; i *= 10)  // el mayor valor se dividira entre 10, 100, 1000 y asi sucesivamente
        cantidadOrden(arr, size, i);             // llamaremos a la funcion cantidadOrden i veces hasta que numMayor / i > 0  
}