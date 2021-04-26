#include <iostream>
using namespace std;

void merge_mezcla(int *,int, int , int );               //prototipos de funcion
void merge_sort(int *, int , int );

int main(){
    int lista[30], num;                                             //Declaramos una arreglo y un valor
    cout<<"Escriba la cantidad de elementos que seran ordenados: ";
    cin>>num;                                                         //Tamaño de la arreglo
    cout<<"Escriba "<<num<<" elementos que seran ordenados: "<<endl;
    for (int i = 0; i < num; i++)                                   //Bucle
        cin>>lista[i];                                              //guardara nuestro num ingresado

    merge_sort(lista, 0, num-1);                                    //Ordenamiento por Mezcla
    cout<<"Arreglo ordenado\n";
    for (int i = 0; i < num; i++)
        cout<<lista[i]<<"\t";                                       //Imprime el arreglo ordenado
}

void merge_sort(int *arr, int inicio, int final){  //Funcion de Ordenamiento por Mezcla
    int mid;                                        //declaramos nuestra variable medio
    if (inicio<final){                           //Haremos una condicion en la que el inicio sera menor que el final
        mid=(inicio+final)/2;                        //Variable mid, sera la mitad del tamaño del arreglo
        merge_sort(arr,inicio,mid);               //Utilizaremos recursividad, esta linea sera para hacer el ordenamiento a la parte izq del arreglo
        merge_sort(arr,mid+1,final);             //Esta sera para la parte derecha de el arreglo
        merge_mezcla(arr,inicio,final,mid);              //Esta tomara como parametros todas las variables que estan dentro de la funcion
    }                                            //ya que hara que se mezclen la parte izquierda con la derecha, ordenandolas
}
void merge_mezcla(int *arr, int inicio, int final, int mid){ //Funcion mezcla

    int left, right, aux, c[50];                 //Declaramos nuestras variables
    left = inicio;                                  
    aux = inicio;                                   
    right = mid + 1;                       
    while (left <= mid && right <= final) {      //Bucle
        if (arr[left] < arr[right]) {           //Condicion si el num izq es menor que el de la derecha
            c[aux] = arr[left];                 //Pasa el menor a el arreglo auxiliar
            aux++;                              //se incrementa el arreglo auxiliar para comparar el siguiente elemento
            left++;                             //se incrementa, para almacenar el siguiente valor 
        }
        else  {                                 
            c[aux] = arr[right];               //Pasa el mayor a el arreglo auxiliar
            aux++;                             //se incrementa el arreglo auxiliar para comparar el siguiente elemento
            right++;                           //se incrementa, para almacenar el siguiente valor 
        }
    }
    while (left <= mid) {              //Bucle que tomara los valores que falta del arreglo izquierda
        c[aux] = arr[left];           // Mismo procedimiento
        aux++;
        left++;
    }
    while (right <= final) {             //Bucle que tomara los valores que falta del arreglo derecha     
        c[aux] = arr[right];            // Mismo procedimiento
        aux++;
        right++;
    }
    for (int i=0; i<aux; i++)          //Bucle para pasar los valores de la lista auxiliar a la original
        arr[i] = c[i];                //Se asigna el valor de la lista auxiliar a cada posicion en la lista original
    
}