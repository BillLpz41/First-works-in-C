#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr1=NULL;
	int **ptr2=NULL;
	int arreglo[3];
	
	ptr1= arreglo;
	
	for(ptr2=&ptr1; *ptr2 <= &arreglo[3]; (*ptr2)++)
	{
		printf("\nIngresa un entero: ");
		scanf("%d", *ptr2);
	}
	
	ptr1= arreglo;
	
	for(ptr2= &ptr1; *ptr2 <= &arreglo[3]; (*ptr2)++)
		printf("\nEn la celda %d tiene el valor de %d en la direccion %lu",
				(int) (*ptr2-arreglo), **ptr2, *ptr2);
				
	return 0;
}
