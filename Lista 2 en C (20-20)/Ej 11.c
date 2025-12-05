#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void crearPrimos(int prim[], int N);
void iniciarArreglo(int arr[], int N);
void imprimirFactores(int fact[], int N);
void comprobarFactores(int fact[], int c, int N);
void limpiarArreglo(int arr[]);

int main()
{
	int N=100, aux=0, cont=0, i=0, j=0;//N servirá como la longitud del arreglo y también como el número a descomponer
	int primos[N];
	int factores[N];//almacenará los factores primos
	
	iniciarArreglo(primos, N);
	iniciarArreglo(factores, N);
	crearPrimos(primos, N);//invoca la funcion para llenar el arreglo 'primos' de números primos
	
	printf("Ingresa el numero con el que quieres encontrar sus numeros primos: ");	
	scanf("%d", &N);
	
	aux=N;//después N será modificado, así que se guarda una copia de su valor en una variable auxiliar
	
	for(i=0; i<N; i++)
	{
	    if(primos[i]>N || cont>50)//si N es muy grande o no se encuentran factores primos aún, cont actuará de limitador
	        break;//de esa forma, si no se encuentra un factor primo, acabará el ciclo al llegar a más de cierta cantidad de iteraciones
	    else
	    {
		
    		if(N%primos[i]==0)//comprueba que el número primo de la casilla i sea factor primo de N
	    	{
		    	factores[j]=primos[i];//el factor primo se le asigna en la posicion j
			    N/=primos[i];//N se divide entre ese factor primo para seguir buscando más números
		    	j++;
		    }
		    else
		    	cont++;
		}
	}
	
	imprimirFactores(factores, j);
	comprobarFactores(factores, j, aux);//comprueba que los factores primos den como resultado N
	
	limpiarArreglo(primos);
	limpiarArreglo(factores);
	
	return 0;
}

void crearPrimos(int prim[], int N)
{
	int k=0, num=0, aux=0, c=0;
	
	for(k=0, num=1; k<N; k++, num++)
	{
			aux=1;
   		    c=2;
    	 
		    while(c<=num/2 && aux)
     	    {
        		if(num%c==0)
        	    	aux=0;
            	c++;
    		}
    
		    if(aux)
    	    {
        	    prim[k]=num;
        	}
	        else
    	        k--;	
    }
}

void iniciarArreglo(int arr[], int N)//llena el arreglo de ceros
{
	int k=0;
	
	for(k=0; k<N; k++)
		arr[k]=0;
}

void imprimirFactores(int fact[], int c)
{
	int k=0;
	
	printf("\nLos factores primos que conforma el numero son:\n");
	for(k=0; k<c; k++)
		printf("%d, ", fact[k]);
}

void comprobarFactores(int fact[], int c, int N)
{//fact= factores; c= j; N= aux
	int i=0, k=0, aux=1, num=0;//num será N
	//comprobará que el producto de todos los elementos del arreglo dé como resultado N
	for(k=0; k<c; k++)
		aux*=fact[k];
	printf("\nEl producto de los factores primos es: %d\n", aux);
	
	while(1)
	{
		if(num!=N)
			while(1)
			{//si la multiplicación no dio N, se buscará elevarlo a alguna potencia
				num= pow(aux, i);
				
				if(num==N)
					break;
				else
					i++;
			}
		else
		{
			printf("\nEl numero %d elevado a la %d da como resultado %d\n", aux, i, N);
			break;
		}	
	}	
}

void limpiarArreglo(int arr[])//libera la memoria
{
	free(arr);
}
