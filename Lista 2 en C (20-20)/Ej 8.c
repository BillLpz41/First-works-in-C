#include <stdio.h>
#include <stdlib.h>

void opcionA(int n, int arr[]);
void opcionB(int n, int arr[]);
void opcionC(int n, int arr[]);
void opcionD(int n, int arr[]);

int main()
{
    int arr[100];
    int N=0;//cantidad de números

    printf("Ingresa un valor positivo cualquiera para N, pero que sea igual o menor a 100: ");
    scanf("%d", &N);
	
	//invocar las funciones para realizar los ciclos distintos y liberar memoria
    opcionA(N, arr);
    opcionB(N, arr);
    opcionC(N, arr);
    opcionD(N, arr);
    free(arr);

    return 0;
}

void opcionA(int n, int arr[])//imprime números pares
{
    int k=0, c=0;

    printf("\na)");
    for(k=0; k<n; k++)
    {
        arr[k]=2*k;
        printf("\narr[%d]= %d", k, arr[k]);
    }

}

void opcionB(int n, int arr[])//imprime números impares
{
    int k=0, c=0;

    printf("\nb)");
    for(k=0; k<n; k++)
    {
        arr[k]= 2*k+1;
        printf("\narr[%d]= %d", k, arr[k]);
    }
}

void opcionC(int n, int arr[])//imprime números pares y al final un cero
{
    int k=0, c=0;

    printf("\nc)");
    for(k=0, c=1; k<n && c<n; k++, c++)
    {
        arr[k]= 2*k;
        arr[c]=0;
        printf("\narr[%d]= %d", k, arr[k]);
    }
    printf("\narr[%d]= %d", k, arr[k]);
}

void opcionD(int n, int arr[])//imprime ceros y al final un número impar
{
    int k=0, c=0;

    printf("\nd)");
    for(k=0,c=1;k<n && c<n; k++, c++)
    {
        arr[k]=0;
        arr[c]=2*k+1;
        printf("\narr[%d]= %d", k, arr[k]);
    }
    printf("\narr[%d]= %d", k, arr[k]);
}
