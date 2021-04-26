//metodo quicksort
# include <iostream>
using namespace std;

int Partition(int arr[], int s, int e); //Prototipos de funcion
void QuickSort(int arr[], int s, int e);

int main(){
    int size=0;          
    int arreglo[size];
    cout<<"Ingrese el tamanio del arreglo "<<endl;
    cin>>size;
    
    for(int i=0;i<size;i++)
        cin>>arreglo[i];
    
    cout<<"El arreglo es "<<endl;
    for(int i=0;i<size;i++)
        cout<<arreglo[i]<<" ";
    
    cout<<endl;
    
    QuickSort(arreglo,0,(size-1));  //llamamos a nuestra funcion QuickSort
    
    cout<<"El arreglo ordenado es "<<endl;
    for(int i=0;i<size;i++)
        cout<<arreglo[i]<<" ";
    
    return 0;
}

int Partition(int arr[], int s, int e){  //implementacion de la funcion

    int pivot = arr[e];                     //tomamos como pivote al ultimo elemento de la lista
    int pIndex = s;                         // pIndex como mi primer elemento
 
    for(int i = s;i<e;i++){                 //Recorremos las posiciones del arreglo segun su tamaño

        if(arr[i]<=pivot){                   //condicion si mi primer numero es menor que ni pivote
            int temp = arr[i];              //mi variable auxiliar temp almacenara ese numero
            arr[i] = arr[pIndex];           //La intercambiara el valor actual con mi primer numero
            arr[pIndex] = temp;             //se le asigna la primer numero el valor almacenado de mi auxiliar
            pIndex++;                       //incrementamos pIndex para el siguiente cambio
        }
    }
 
    int temp = arr[e];                      //mi variable auxiliar almacenara el ultimo valor o pivote
    arr[e] = arr[pIndex];                   //lo intercambiara por la el numero donde se quedo pIndex en su posicion
    arr[pIndex] = temp;                     // se efectua el cambio asigandole el valor

    return pIndex;                          //retorna la posicion en donde se efectuo la particion
}
 
void QuickSort(int arr[], int s, int e){ //implementacion de la funcion
    if(s<e){
        int p = Partition(arr,s, e);
        QuickSort(arr, s, (p-1));  // llamada recursiva, segun el pIndex que arrojo la funcion particion 
        QuickSort(arr, (p+1), e);  
    }
}
 