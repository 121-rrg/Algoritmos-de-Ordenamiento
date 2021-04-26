
#include <iostream>
using namespace std;

void insercion(int lista[],int tam); // prototipo de funcion

int main(){
    int lista[]={67,-8,15,44,27,12,35}; //declaramos nuestra lista
    cout <<"Lista Original" <<endl;
    for(int i =0; i<7; i++) // imprimimos nuestra lista original
        cout << lista[i] <<" ";
    cout<<endl;
    insercion(lista,7); //llamamos a la funcion para el ordenamiento
    cout<<"Lista Ordenada ascendente " <<endl;
    for(int i =0; i<7; i++) // imprimimos nuestra lista ordenada ascendente
        cout<<lista[i]<<" ";
    cout << endl;
    cout<<"Lista Ordenada descendente " <<endl;
    for(int i =6; i>=0; i--) // imprimimos nuestra lista ordenada desscendente
        cout<<lista[i]<<" ";
    return 0;
}
void insercion(int lista[],int tam){ //implementacion de la funcion
    int i,aux,posicion; //declaramos las variables
    for(i=1;i<7;i++){
        aux=lista[i]; //asignamos el numero de la lista a un aux
        posicion=i; // asignamos la posicion en el arreglo

        while(posicion>0 && lista[posicion-1]>aux){ // condiciones 
            lista[posicion] = lista[posicion -1]; // intercambiamos el valor si es mayor
            posicion--; // seguira intercambiando hasta llegar a la posicion 1
        }
        lista[posicion]=aux; //actualiza el valor 
    }
}