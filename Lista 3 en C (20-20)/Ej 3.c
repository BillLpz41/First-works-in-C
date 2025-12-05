#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int N);
void inicializarArreglo(int *arr, int N);
void desplegarArreglo(int *arr, int N);
void destruirArreglo(int *arr);

int main()
{
	int *arr10=NULL, *arr100=NULL, *arr1000=NULL;//arreglos para N=10, 100, 1000
	int N=10;
	
	arr10= crearArreglo(N);//crear un arreglo de 10 celdas
	inicializarArreglo(arr10, N);//llena de ceros el arreglo
	desplegarArreglo(arr10, N);//muestra el contenido del arreglo
	destruirArreglo(arr10);//libera la memoria del arreglo
	
	N=100;
	
	arr100= crearArreglo(N);//crea un arreglo de 100 celdas
	inicializarArreglo(arr100, N);
	desplegarArreglo(arr100, N);
	destruirArreglo(arr100);
	
	N= 1000;
	
	arr1000= crearArreglo(N);//crea un arreglo de 1000 celdas
	inicializarArreglo(arr1000, N);
	desplegarArreglo(arr1000, N);
	destruirArreglo(arr1000);
	
	return 0;
}

int *crearArreglo(int N)
{
	int *arr=NULL;
	
	arr= (int *) malloc(N*sizeof(int));//reserva memoria para N celdas
	
	return arr;//devuelve el arreglo
}

void inicializarArreglo(int *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0)//si arr es nulo o N es menor o igual a 0, se termina la funcion
		return;
		
	for(k=0; k<N; k++)
		arr[k]=0;//coloca un 0 en cada celda del arreglo
}

void desplegarArreglo(int *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
	
	printf("N= %d\n", N);//imprime el valor de N
	for(k=0; k<N; k++)
		printf("%d ", arr[k]);//imprime cada celda del arreglo
	printf("\n");
}

void destruirArreglo(int *arr)
{
	free(arr);
}
