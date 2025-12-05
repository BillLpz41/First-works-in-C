#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *crearArreglo(int N);
void inicializarArreglo(double *arr, int N, int lim);
void calcularSuma(double *suma, double *arr, int N);
void calcularPromedio(double *prom, double *suma, int N);
void desplegarArreglo(double *arr, int N);
void destruirArreglo(double *arr);

int main()
{
	double *numeros=NULL;
	int N=0, lim=0;
	double suma=0, promedio=0;
	
	printf("Ingresa la longitud del arreglo: ");
	scanf("%d", &N);
	
	printf("\nIngresa el numero mas grande para el arreglo: ");
	scanf("%d", &lim);//numero mas grande entre los enteros del arreglo
	
	numeros= crearArreglo(N);//se crea el arreglo con N celdas

	inicializarArreglo(numeros, N, lim);//llena el arreglo de numeros aleatorios
	desplegarArreglo(numeros, N);//muestra el contenido del arreglo
	
	calcularSuma(&suma, numeros, N);//por referencia se calcula la suma de los numeros
	printf("\nSuma de los numeros: %lf", suma);//imprime el resultado de la suma
	
	calcularPromedio(&promedio, &suma, N);//por referencia se obtiene el promedio de los numeros
	printf("\nPromedio de los numeros: %lf", promedio);//imprime el promedio

	destruirArreglo(numeros);//libera la memoria del arreglo
	
	return 0;
}

double *crearArreglo(N)
{
	double *arr=NULL;
	
	if(N<=0)//si N es menor o igual a 0, se termina la funcion
		return;
	
	arr= (double *) malloc(N*sizeof(double));
	
	return arr;
}

void inicializarArreglo(double *arr, int N, int lim)
{
	int k=0;
	
	if(arr==NULL || N<=0)//si el arreglo es nulo o N es menor o igual a 0, se termina la funcion
		return;
	
	srand(time(NULL));
	
	for(k=0; k<N; k++)
		arr[k]= rand()%(lim+1);//en la celda k se coloca un numero aleatorio entre 0 y lim+1 (sin considerar lim+1)
}

void calcularSuma(double *suma, double *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0 || suma==NULL)
		return;
	
	for(k=0; k<N; k++)
		(*suma)+=arr[k];//realiza la suma de los numeros; por ser paso por referencia no es necesario regresar el valor
}

void calcularPromedio(double *prom, double *suma, int N)
{
	if(suma==NULL || N<=0)
		return;
		
	*prom= *suma/N;//se calcula el promedio
}

void desplegarArreglo(double *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
	
	for(k=0; k<N; k++)
		printf("%lf, ", arr[k]);//imprime la celda k del arreglo
	printf("\n");
}

void destruirArreglo(double *arr)
{
	free(arr);
}
