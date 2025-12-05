#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void iniciarArreglo(int arr[], int N);
void secuenciaA(int arr[], int N, int lim);//1,4,7,10,13,...
void secuenciaB(int arr[], int N, int lim);//2,4,8,16,32,...
void secuenciaC(int arr[], int N, int lim);//1,3,6,10,15,...
void secuenciaD(int arr[], int N, int lim);//1,4,9,16,25,...
void secuenciaE(int arr[], int N, int lim);//Fibonacci
void secuenciaF(int arr[], int N, int lim);//numeros primos

int main()
{
    int num=0, aux=0, c=0, L=100;//L= longitud de arreglo
    int limite= pow(2,(4*sizeof(int)));//el rango límite por tipo de variable
    int secuencia[L];
    
    secuenciaA(secuencia, L, limite);
    secuenciaB(secuencia, L, limite);
    secuenciaC(secuencia, L, limite);
    secuenciaD(secuencia, L, limite);
    secuenciaE(secuencia, L, limite);
    secuenciaF(secuencia, L, limite);
    
    free(secuencia);
    
    return 0;
}

void iniciarArreglo(int arr[], int N)//llena de ceros el arreglo
{
	int i=0;
	for(i=0; i<N; i++)
		arr[i]=0;
}
//arr= arreglo secuencia; N= longitud de arreglo; lim= valor límite de tipo de dato
void secuenciaA(int arr[], int N, int lim)
{//secuencia de un número impar, par, impar, par...
	int k=0;
	
	printf("\nSecuencia a)\n");
	iniciarArreglo(arr, N);
	for(k=0; k<N; k++)
    {
    	if((3*k+1)<=lim)//verifica que no sobrepase el valor límite
    	{
    		arr[k]=3*k+1;
    		printf("%d, ", arr[k]);
		}	
    	else
    	{
    		printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
	}
    printf("\n\n");
}

void secuenciaB(int arr[], int N, int lim)
{//secuencia de numeros pares iniciando en 2
	int k=0, c=0;
	
	printf("\nSecuencia b)\n");
    iniciarArreglo(arr, N);
    for(k=0, c=1; k<N; k++, c++)
    {
    	if((2*c)<=lim)
    	{
    		arr[k]=2*c;
    		printf("%d, ", arr[k]);
		}
    	else
    	{
    		printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
	}
    printf("\n\n");
}

void secuenciaC(int arr[], int N, int lim)
{//secuencia de dos numeros impares, dos pares, dos impares, dos pares...
	int k=0, c=0, aux=0;
	
	printf("\nSecuencia c)\n");
    iniciarArreglo(arr, N);
    aux=1;//la secuencia comienza con 1
    for(k=0, c=2; k<N; k++, c++)
    {
    	if(aux<=lim)
    	{
    		arr[k]=aux;
    		printf("%d, ", arr[k]);
		}
    	else
    	{
    		printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
		aux+=c;//la suma de un número impar con uno par es impar
				//y la suma de un impar con un impar es par 
	}
    printf("\n\n");
}

void secuenciaD(int arr[], int N, int lim)
{//secuencia de impar, par, impar, par...
	int k=0, c=0, aux=0;
	
	printf("\nSecuencia d)\n");
    iniciarArreglo(arr, N);
    aux=1;//la secuencia comienza en 1
    for(k=0, c=3; k<N; k++, c+=2)
    {
    	if(aux<=lim)
    	{
    		arr[k]=aux;
    		printf("%d, ", arr[k]);
		}
    	else
    	{
    		printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
		aux+=c;//la suma de un impar con un impar es par y viceversa
	}
	printf("\n\n");	
}

void secuenciaE(int arr[], int N, int lim)
{//secuencia de la suma del número anterior y el anterior a ese
	int k=0, c=0, aux=0;
	
	printf("\nSecuencia e) Suma de Fibonacci.\n");
	iniciarArreglo(arr, N);
	arr[0]=0;//establecer los primeros dos números
	arr[1]=1;
	for(k=2; k<N; k++)
	{
		if((arr[k-1] + arr[k-2]) <= lim)
		{//suma el número anterior y el anterior a ese es el número actual
			arr[k]= arr[k-1] + arr[k-2];
			printf("%d, ", arr[k]);
		}		
		else
		{
			printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
	}
    printf("\n\n");
}

void secuenciaF(int arr[], int N, int lim)
{//secuencia de numeros primos
	int k=0, c=0, aux=0, num=0;
	
	printf("\nSecuencia f) Numeros primos.\n");
    iniciarArreglo(arr, N);
    for(k=0, num=1; k<N; k++, num++)
	{
		if(num<=lim)
		{//resetea el valor de aux y c al inicio de cada ciclo
			aux=1;
   		    c=2;
    	 
		    while(c<=num/2 && aux)
     	    {	//si se inicia el ciclo, significa que ya existe
     	    	//un número que logra esa division, por lo que
     	    	//ese número no es primo al no cumplir la condición de números primos
        		if(num%c==0)//se busca terminar el ciclo logrando que el residuo sea 0
        	    	aux=0;
            	c++;
    		}
    
		    if(aux)
    	    {
        	    arr[k]=num;
            	printf("%d, ", arr[k]);
        	}
	        else//si no hubo un número primo, el contador
    	        k--;//mantiene su valor actual para que no haya
    	}			//saltos de posiciones del arreglo
		else		
		{
			printf("\nEl numero supera el tamaño del tipo de variable. Fin del bucle.");
    		break;
		}
    }
    printf("\n\n");
}
