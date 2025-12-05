#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *crearArreglo(int N);
void iniciarArreglo(int *arr, int N, int lim);
void iniciarArregloNormal(int *arr, int N);
void ordenarArreglo(int *arr, int N);
void desordenarArreglo(int *arr, int N);
void desplegarArreglo(int *arr, int N);
void destruirArreglo(int *arr);

int main()
{
	int *enteros=NULL;
	int N=0, limite=0;
	
	printf("Ingresa la cantidad de enteros que desees: ");
	scanf("%d", &N);
	
	printf("Ingresa el valor maximo de los numeros enteros: ");
	scanf("%d", &limite);//numero mas grande entre los enteros
	
	enteros= crearArreglo(N);//crea un arreglo de N celdas
	iniciarArreglo(enteros, N, limite);//llena las celdas de numeros aleatorios entre 0 y limite
	
	printf("\nEl contenido del arreglo es:\n");
	desplegarArreglo(enteros, N);//imprime el arreglo
	
	ordenarArreglo(enteros, N);//ordena el arreglo
	printf("\nEl arreglo ordenado es:\n");
	desplegarArreglo(enteros, N);
	
	printf("\nEl arreglo desordenado es:\n");
	desordenarArreglo(enteros, N);//desordena el arreglo
	
	destruirArreglo(enteros);
	
	return 0;
}

int *crearArreglo(int N)
{
	int *arr=NULL;
	
	if(N<=0)//si N es menor o igual a 0, no habra que reservar memoria, por lo que se termina la funcion
		return;
	
	arr= (int *) malloc(N*sizeof(int));//reserva memoria para N celdas
	
	return arr;
}

void iniciarArreglo(int *arr, int N, int lim)
{
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
		
	srand(time(NULL));
	
	for(k=0; k<N; k++)
		arr[k]=rand()%(lim+1);//en la celda k se coloca un numero aleatorio entre 0 y el numero limite
}

void iniciarArregloNormal(int *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
	
	for(k=0; k<N; k++)
		arr[k]=0;//coloca un 0 en la celda k
}

void ordenarArreglo(int *arr, int N)
{
	int i=0, j=0, c=0, aux=0;
	
	printf("\nOrden ascendente (0) o descendente (1)? ");
	scanf("%d", &c);//consulta para saber si el ordenamiento sera ascendente o descendente
	
	if(arr==NULL || N<=0); 
		return;
	
	if(c==0)//orden ascendente
	{
		for(i=0; i<N; i++)
			for(j=i+1; j<N; j++)
				if(arr[j]<arr[i])
				{//intercambio de contenidos de celdas
					aux= arr[j];
					arr[j]= arr[i];
					arr[i]= aux;
				}
	}
	else if(c==1)//orden descendente
	{
		for(i=0; i<N; i++)
			for(j=i+1; j<N; j++)
				if(arr[j]>arr[i])
				{
					aux= arr[j];
					arr[j]= arr[i];
					arr[i]= aux;
				}
	}
	else
		printf("\nNumero invalido.\n");
}

void desordenarArreglo(int *arr, int N)
{
	int *posRep= NULL, *numDesor= NULL;//posRep= posicion repetidas; numDesor= arreglo con los numeros desordenados
	int i=0, j=0, pos=0;
	
	if(arr==NULL || N<=0)
		return;
	
	posRep= crearArreglo(N+1);
	iniciarArregloNormal(posRep, N+1);//llena de ceros el arreglo
	
	numDesor= crearArreglo(N);//la cantidad de numeros es la misma al del arreglo original
	iniciarArregloNormal(numDesor, N);
	//debido a que posRep fue inicializado, no es necesario poner 0 en la celda 0
	numDesor[0]= arr[0];//esto es para que funcione el desordenamiento
	srand(time(NULL));
	
	for(i=1; i<N; i++)
	{
		pos= (rand()%N-1)+1;//genera un numero aleatorio pero evita el 0 porque ya fue usado
		
		for(j=0; j<=i; j++)
		{
			if(posRep[j]!=pos)//comprueba que la posicion no se haya repetido
			{
				numDesor[i]= arr[pos];
				posRep[i+1]= pos;//añade la posicion repetidas
			}
			else
			{//es posible que se repita la posición y se haya realizado las operaciones anteriores
				numDesor[i]=0;//se resuelve con cambiar el número de la posición i por un 0
				posRep[i+1]=0;//también con quitar la posición repetida
				i--;//y mantener el contador igual
				break;//se rompe el segundo ciclo para que se repita el proceso con el mismo valor de i
			}
		}
	}	
	
	desplegarArreglo(numDesor, N);//imprime el arreglo
	//libera la memoria de ambos arreglos
	destruirArreglo(posRep);	
	destruirArreglo(numDesor);
}

void desplegarArreglo(int *arr, int N)
{
	int k=0;
	
	if(arr==NULL || N<=0)
		return;
		
	for(k=0; k<N; k++)
		printf("%d ", arr[k]);
	printf("\n");
}

void destruirArreglo(int *arr)
{
	free(arr);
}
