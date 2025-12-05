#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a=5, b;
	int *ptr1;
	int **ptr2;
	
	ptr1= &a;
	ptr2= &ptr1;
	b= **ptr2;
	
	printf("El valor de a es %d y su direccion es %lu \n", a, &a);
	printf("El valor de ptr1 es %lu, su contenido es %d y su direccion es %lu \n", ptr1, *ptr1, &ptr1);
	printf("El valor de ptr2 es %lu, su contenido es %lu y su direccion es %lu \n", ptr2, *ptr2, &ptr2);
	printf("El valor de b es %d y su direccion es %lu \n", b, &b);
	printf("El valor de b es %d con ptr1 \n", *ptr1);
	printf("El valor de b es %d con ptr2 \n", **ptr2);
	
	return 0;
}
