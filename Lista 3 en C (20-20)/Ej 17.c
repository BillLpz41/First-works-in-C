#include <stdio.h>
#include <stdlib.h>

int *leer(char *nombre, int *N);
void escribir(char *nombres, int *arr, int N);
void duplicar(int *arr, int N);
void destruirArreglo(int *arr);

int main()
{
	char name0[30]="numeros.txt", name1[30]="escrito.txt", name2[30]="doble.txt";
	//nombre de los archivos en el mismo directorio
	int *sec=NULL;//arreglo para la secuencia de numeros
	int k=0, N=0;
	
	sec= leer(name0, &N);//se crea el arreglo sec y guarda N numeros del archivo name
	
	printf("Contenido de la secuencia: ");
	for(k=0; k<N; k++)
		printf("%d ", sec[k]);//imprime la secuencia inicial
	
	escribir(name1, sec, N);//en el archivo de name1 se escribe los N numeros de la secuencia
	duplicar(sec, N);//los valores del arreglo se duplican
	
	escribir(name2, sec, N);//en el archivo de name2 se escribe los N numeros de la secuencia con valor duplicado
		
	printf("\n\nValores duplicados:\n");
	for(k=0; k<N; k++)
		printf("%d ", sec[k]);//imprime la secuencia de valores duplicados
	
	destruirArreglo(sec);
		
	return 0;
}

int *crearArreglo(int N)
{
	int *arr=NULL;
	
	if(N<=0)
		return;
	
	arr= (int *) malloc(N*sizeof(N));
	
	return arr;
}

int *leer(char *nombre, int *N)
{
	FILE *archivo= NULL;//crea un fichero que determina la operacion que se hará con el archivo
	int *arr= NULL;
	int k=0, x=0, lim=0;
	
	if(nombre==NULL || N==NULL)//si alguno de los dos es nulo, finaliza la funcion
		return;
	
	archivo= fopen(nombre, "r");//abre el archivo cuyo nombre está en el arreglo nombre y se realiza
								//la operacion de leer "r" (read)
	if(archivo==NULL)//si el fichero es nulo, acaba la funcion
		return;
	
	printf("Cantidad de enteros: ");
	scanf("%d", &lim);//se limita la cantidad de enteros para el arreglo
	
	*N= lim;//tambien cambia de valor al que se apunta
	arr= crearArreglo(lim);//se crea el arreglo de enteros
	
	if(arr==NULL)
		return;
	
	for(k=0; k<lim; k++)
	{
		fscanf(archivo, "%d", &x);//lee del archivo el dato en la lista de numeros
		arr[k]=x;//y lo asigna al arreglo hasta que el ciclo termine
	}
	
	return arr;//regresa el arreglo a la secuencia
}

void escribir(char *nombre, int *arr, int N)
{
	FILE *archivo= NULL;
	int k=0, x=0;
	
	archivo= fopen(nombre, "w");//abre el archivo y realiza la operación de escribir "w" (write)
	
	if(archivo==NULL || arr==NULL || N<=0)//N no debe ser menor o igual a 0
		return;
	
	printf("\nLa cantidad de enteros es de: %d", N);
	
	for(k=0; k<N; k++)
	{
		x=arr[k];//'x' se le asigna el numero de la celda k del arreglo
		fprintf(archivo, "%d\n", x);//y lo imprime en el otro archivo
	}
}

void duplicar(int *arr, int N)
{//duplica el valor de los numeros del arreglo
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
		
	for(k=0; k<N; k++)
		arr[k]*=2;
}

void destruirArreglo(int *arr)
{
	free(arr);
}
