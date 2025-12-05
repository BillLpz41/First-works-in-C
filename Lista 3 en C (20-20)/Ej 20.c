#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *crearArreglo(int N, int lim);
void desplegarArreglo(int *arr, int N);
void ordenarRapidamente(int *arr, int inf, int sup);
int particionar(int *arr, int inf, int sup);

int main()
{
    int *sec=NULL;
    int N=0, limite=0;
    
    printf("Ordenamiento rapido con Quicksort (orden ascendente).\n");
    
    printf("Introduce la cantidad de enteros: ");
    scanf("%d", &N);
    
    printf("\nIntroduce el numero mas grande entre los enteros: ");
    scanf("%d", &limite);
    
    sec= crearArreglo(N, limite);//crea el arreglo de N celdas, cuyo numero más grande es el de 'limite'
    
    printf("El contenido inicial la secuencia de numeros es:\n");
    desplegarArreglo(sec, N);//imprime el contenido del arreglo
    
    ordenarRapidamente(sec, 0, N-1);//inicia la recursión; el parametro inf es 0 porque se comienza en 0,
    								//el parametro sup es N-1 porque es la última celda del arreglo
    
    printf("\n\nCon el metodo Quicksort, la secuencia de numero es:\n");
    desplegarArreglo(sec, N);//imprime el contenido ordenado del arreglo 
    
    return 0;
}

int *crearArreglo(int N, int lim)
{
	int *arr=NULL;
	int k=0;
	
	arr=(int *) malloc(N*sizeof(int));
	
	srand(time(NULL));
	
	for(k=0; k<N; k++)
		arr[k]= rand()%(lim+1);
		
	return arr;
}

void desplegarArreglo(int *arr, int N)
{
	int k=0;
	
	if(arr==NULL)
		return;
	
	for(k=0; k<N; k++)
		printf("%d ", arr[k]);
	printf("\n");
}

void ordenarRapidamente(int *arr, int inf, int sup)
{
    int pivote=0;
    
    if(arr==NULL)
        return;
        
    if(inf<sup)//comprueba que 'sup' sea mayor que 'inf'
    {
        pivote=particionar(arr, inf, sup);//la variable pivote tiene el valor de i 
        ordenarRapidamente(arr, inf, pivote-1);//se invoca la función de forma recursiva hasta que la condición
        										//no se cumpla (sup es menor a inf); mientras tanto, 
												//se va ordenando el arreglo con la instruccion anterior
        ordenarRapidamente(arr, pivote+1, sup);//se invoca la función de manera recursiva hasta que inf sea mayor
        										//a sup; mientras tanto, la funcion 'particionar' termina de ordenar
        										//el arreglo
    }
}

int particionar(int *arr, int inf, int sup)
{
    int pivote=0, aux=0, i=0, j=0;
    
    pivote=arr[sup];//obtiene el valor de la casilla 'sup' del arreglo
    i=inf;//obtiene el valor de 'inf'
    
    for(j=inf; j<sup; j++)
        if(arr[j]<pivote)//si el valor en la casilla j es menor a pivote, se hace un cambio de posiciones
        {				//con la celda i del mismo arreglo
            aux=arr[j];
            arr[j]=arr[i];
            arr[i]=aux;
            i++;
        }
    //termina de hacer el cambio de posiciones con el último valor de i y j
    aux=arr[sup];
    arr[j]=arr[i];
    arr[i]=aux;
    
    return i;//retorna el valor de i para la otra variable 'pivote'
}
