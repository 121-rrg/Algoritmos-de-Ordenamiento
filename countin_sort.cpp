# include <iostream>
using namespace std;

void CountingSort(int array[],int s, int r);

int main()
{
	int size=0;			//declaro mis variables
	int range = 10;    // va de 0-9
	int arreglo[size];	//declaro mi arreglo
	cout<<"Ingrese el numero de su arreglo "<<endl;
	cin>>size;			//almaceno los numeros en mi arreglo

	for(int i=0;i<size;i++)
		cin>>arreglo[i];

	cout<<"El arreglo es "<<endl;
	for(int i=0;i<size;i++)
		cout<<arreglo[i]<<" ";
	cout<<endl;
	CountingSort(arreglo,size,range);  // Llamamos a la funcion CountingSort

	cout<<"El arreglo ordenado es"<<endl;
	for(int i=0;i<size;i++)
		cout<<arreglo[i]<<" ";
	return 0;
}

void CountingSort(int array[],int s, int r){

	int salida[s];  //declaramos un array que sera de salida
	int count_array[r];	//declaramos un array count_array que sera de rango de 0-9
	
	for(int i=0;i<r;i++)		//asignamos un valor de 0 a cada posicion del arreglo  count_array
		count_array[i]=0;
		
	for(int i=0;i<s;i++)			//sumara 1 a cada elemento que se repita en la posicion del arreglo count_array
		++count_array[array[i]];
	
	for(int i=1;i<r;i++)				// el bucle ira desde la posicion 1 hasta 9
		count_array[i]=count_array[i]+count_array[i-1];		// sumara el elemento actual que se haya repetido de count_array, con uno anterior
	//va de 0- al tamaño del arreglo
	for(int i=0;i<s;i++)							//ordenara los numeros del array , pero segun la posicion de mi matriz de salida
		salida[--count_array[array[i]]] = array[i];		// y la posicion que le corresponda sera la posicion de count_array disminuido en 1
	
	for(int i=0;i<s;i++)								//Transferimos los valores de mi arreglo de salida a la principal array
		array[i]=salida[i];
}

