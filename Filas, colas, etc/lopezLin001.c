#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arreglo=NULL;
	int *ptr=NULL;
	int N= 4;
	
	arreglo= (int *) malloc(N*sizeof(int));
	
	for(ptr=arreglo; ptr<= &arreglo[N-1]; ptr++)
	{
		printf("\nIngresa entero: ");
		scanf("%d", ptr);
	}
	
	for(ptr=arreglo; ptr<= &arreglo[N-1]; ptr++)
		printf("\nEn la celda %d esta el valor de %d en la direccion de %lu", 
				(int) (ptr-arreglo), *ptr, ptr);
	
	return 0;
}
