#include <stdio.h>
#include <stdlib.h>

//firmas de los dos ciclos
void opcionA(int a, int b, int arr1[], int arr2[]);//a, b y c son las posiciones del arreglo
void opcionB(int a, int b, int c, int arr1[], int arr2[], int arr3[]);//arr1, arr2 y arr3 son los arreglos que
										//con los que se realizarán los ciclos

int main()
{
    int i=0, j=0, k=0, r=0;//i, j, k para ir obteniendo los distintos valores de los arreglos
    //variable r para decidir entre el primer ciclo o el segundo
    int N[7]={1,2,3,5,7,11,13};//valores para N, L, M
	int L[7]={1,2,3,5,7,11,13};
	int M[7]={1,2,3,5,7,11,13};
    
    printf("Ingresa 0 para el ciclo de dos arreglos y 1 para el ciclo de tres arreglos.\n");
    scanf("%d",&r);
    
    if(r==0)
    {//los ciclos se hacen para que se obtengan los valores del arreglo N y M
    	for(i=0; i<7; i++)
    		for(j=0; j<7; j++)
    			opcionA(i,j,N,M);
    }
    else if(r==1)
    {
     	for(i=0; i<7; i++)
            for(j=0; j<7; j++)
                for(k=0; k<7; k++)
                    opcionB(i,j,k,N,M,L);
    }
    else
		printf("\nNumero incorrecto. Intente de nuevo.");
		
    return 0;
}

//arr1 es N, arr2 es M, y arr3 es L
void opcionA(int a, int b, int arr1[], int arr2[])
{
	int i=0, j=0;
	
	for(i=0;i<arr1[a];i++)
		for(j=0;j<arr2[b];j++)
			printf("N= %d M= %d i= %d j= %d\n", arr1[a], arr2[b], i, j);
			
	printf("Final N= %d M= %d i= %d j= %d\n", arr1[a], arr2[b], i, j);
}

void opcionB(int a, int b, int c, int arr1[], int arr2[], int arr3[])
{
	int i=0, j=0, k=0;
	
	for(i=0; i<arr1[a]; i++)
		for(j=0; j<arr2[b]; j++)
			for(k=0; k<arr3[c]; k++)
				printf("N= %d M= %d L= %d i= %d j=%d\n", arr1[a], arr2[b], arr3[c], i, j);
				
	printf("Final N= %d M=%d L=%d i= %d j= %d\n", arr1[a], arr2[b], arr3[c], i, j);
}
