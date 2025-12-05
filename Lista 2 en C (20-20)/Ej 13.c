#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void iniciarArregloNormal(int arr[], int N);
void iniciarArregloAleatorio(int arr[], int N, int rango);
void imprimirArreglo(int arr[], int N);
void encontrarMasGrande(int arr[], int N);//busca el número más grande
void encontrarMasPequeno(int arr[], int N);//busca el número más pequeño
float calcularPromedio(int arr[], int N);//devuelve el promedio del contenido del arrelgo como flotante
void calcularDesviacionEstandar(int arr[], int N, float prom);
void ordenarAscendentemente(int arr[], int N);
void ordenarDescendentemente(int arr[], int N);
void desordenarAleatoriamente(int arr[], int N);
void destruirArreglo(int arr[]);//libera memoria del arreglo ingresado

int main()
{
    int i=0, j=0, k=0;
    int aux=0, N=0, limite=0;
    float promedio=0.0;
    
    printf("Ingresa el dato de la longitud del arreglo que desea: ");
    scanf("%d", &N);
    
	int arrRand[N];//arreglo para los numeros aleatorios
    
    printf("\nCual es el valor maximo que quieres que alcancen los numeros (limite)? (Solo valores enteros). ");
    scanf("%d", &limite);
    
    iniciarArregloAleatorio(arrRand, N, limite);//invoca la funcion para llenar el arreglo con numeros aleatorios
    
    printf("\nEl contenido del arreglo aleatorio es:\n");
    imprimirArreglo(arrRand, N);
    
    printf("\n\na) Encontrar el numero mas grande y el numero mas pequeño de todos.\n");
    encontrarMasGrande(arrRand, N);
    encontrarMasPequeno(arrRand, N);
    
    printf("\n\nb) Calcular el valor promedio y la desviacion estandar de todos los numeros.\n");
    promedio = calcularPromedio(arrRand, N);
    
    calcularDesviacionEstandar(arrRand, N, promedio);
    
    printf("\n\nc) Ordenar los numeros de forma ascendente y descendente.\n");
    printf("\nOrden ascendente:\n");
	ordenarAscendentemente(arrRand, N);
    
	printf("\nOrden descendente:\n");
	ordenarDescendentemente(arrRand, N);
    
    printf("\n\nd) Desordenar aleatoriamente el arreglo.\n");
    printf("\nEl arreglo desordenado aleatoriamente queda de esta forma: \n");
    desordenarAleatoriamente(arrRand, N);
    
    destruirArreglo(arrRand);
    
    return 0;
}

void iniciarArregloNormal(int arr[], int N)//llena el arreglo de ceros
{//arr= arreglo; N= longitud del arreglo
	int k=0;	
	
	for(k=0; k<N; k++)
		arr[k]=0;
}

void iniciarArregloAleatorio(int arr[], int N, int rango)//llena el arreglo con números aleatorios
{//rango= número límite
	int k=0;
	
	srand(time(NULL));
	for(k=0; k<N; k++)
		arr[k]=rand()%rango;//genera un número aleatorio entre 0 y el limite
}

void imprimirArreglo(int arr[], int N)
{
	int k=0;
	
	for(k=0; k<N; k++)
		printf("%d, ", arr[k]);
}

void encontrarMasGrande(int arr[], int N)
{
	int k=0, mayor=0;
	
	mayor=arr[0];
	for(k=0; k<N; k++)
		if(mayor<arr[k])//compara si el número de 'mayor' es menor al de la posicion k del arreglo
			mayor= arr[k];//el número de la posición k del arreglo es más grande que 'mayor'
							//por lo tanto, 'mayor' obtiene ese valor
	printf("\nEl numero mas grande es: %d", mayor);
}

void encontrarMasPequeno(int arr[], int N)
{
	int k=0, menor=0;
	
	menor= arr[0];
	for(k=0; k<N; k++)
		if(menor>arr[k])//compara si el número de 'menor' es mayor al de la posicion k del arreglo
			menor= arr[k];//el número de la posición k del arreglo es más pequeño que 'menor'
							//por lo tanto, 'menor' obtiene ese valor
	printf("\nEl numero mas pequeño es: %d", menor);
}

float calcularPromedio(int arr[], int N)
{
	int k=0, suma=0;
	float prom=0;
	
	for(k=0; k<N; k++)
		suma+=arr[k];
		
	prom=suma/N;
	printf("\nEl promedio del arreglo es: %f", prom);
}

void calcularDesviacionEstandar(int arr[], int N, float prom)
{
	int k=0;
	float desEst=0, sumatoria=0;
	int newArr[N];//arreglo para almacenar la resta del número del arreglo de números aleatorios
				//con el promedio, elevado al cuadrado
	iniciarArregloNormal(newArr, N);
	
	for(k=0; k<N; k++)
		newArr[k]=pow(arr[k]-prom, 2);
		
	for(k=0; k<N; k++)
		sumatoria+=newArr[k];//sumatoria de las restas
		
	desEst= sqrt(sumatoria/(N-1));//calcula la desviación estandar
	printf("\nLa desviacion estandar es: %f", desEst);
	
}

void ordenarAscendentemente(int arr[], int N)
{//de menor a mayor
	int i=0, j=0, aux=0;
	
	for(i=0; i<N; i++)
		for(j=i+1; j<N; j++)//j=i+1 para el número siguiente
			if(arr[j]<arr[i])//comprueba que el número siguiente sea menor al número en la posición i
			{//como el número de la posición i es mayor, entonces se intercambia de lugar
				aux= arr[j];//para el intercambio, aux adquiere el valor del número siguiente
				arr[j]=arr[i];//ahora el número siguiente es el de la posición i
				arr[i]=aux;//la posición i adquiere el valor de aux
			}
			
	for(i=0; i<N; i++)
		printf("%d, ", arr[i]);
}

void ordenarDescendentemente(int arr[], int N)
{//de mayor a menor
	int i=0, j=0, aux=0;
	
	for(i=0; i<N; i++)
		for(j=i+1; j<N; j++)
			if(arr[j]>arr[i])//comprueba si el número siguiente es mayor al de la posición actual
			{//se intercambiarán de posiciones para que quede de mayor a menor
				aux= arr[j];
				arr[j]=arr[i];
				arr[i]=aux;
			}
			
	for(i=0; i<N; i++)
		printf("%d, ", arr[i]);
}

void desordenarAleatoriamente(int arr[], int N)
{
	int i=0, j=0, k=0, aux=0;
    int arrRep[N], newArrRand[N]; //arrRep almacenará las posiciones que se hayan repetido.
							    //newArrRand tendrá el orden aleatorio.
    
    iniciarArregloNormal(arrRep, N+1);
    iniciarArregloNormal(newArrRand, N);
    
    srand(time(NULL));
    
    arrRep[0]=0;//con lo siguiente, la posicion 0 ya estará en uso
    newArrRand[0]=arr[0];//asignar al arreglo de orden aleatorio el primer dato del arreglo de enteros
    					//sin embargo, le quita un poco de aleatoriedad.
    for(i=1; i<N; i++) //se inicia en i=1 ya que en la posicion 0 de ambos arreglos ya hay un valor.
    {
        k=(rand()%(N-1))+1; //busca una posicion aleatoria entre 1 y N para no incluir el 0.
        
        for(j=0; j<=i; j++)
        {
			if(arrRep[j] != k)//comprueba que la posición no se haya repetido
            {
				newArrRand[i]=arr[k];
             	arrRep[i+1]=k;//se añade la posición actual para que después no se vuelva a repetir
            }
            else
            {//es posible que se repita la posición y se haya realizado las operaciones anteriores
			 	newArrRand[i]=0;//se resuelve con cambiar el número de la posición i por un 0
                arrRep[i+1]=0;//también con quitar la posición repetida
                i--;//y mantener el contador igual
                break;//se rompe el segundo ciclo para que se repita el proceso con el mismo valor de i
        	}
        }
    }
	
	imprimirArreglo(newArrRand, N);
	
	destruirArreglo(arrRep);
	destruirArreglo(newArrRand);
}

void destruirArreglo(int arr[])
{
	free(arr);
}
