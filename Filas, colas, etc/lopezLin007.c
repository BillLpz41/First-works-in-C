#include <stdio.h>
#include <stdlib.h>

struct per{
	char cad[30];
	int edad;
	float est;
	char car;
};

int main()
{//Version 2. Apuntadores a un arreglo
	struct per arreglo[5];
	struct per *ptr;
	
	for(ptr=arreglo; ptr < &arreglo[5]; ptr++)
	{
		printf("\nCelda %d", (int) (ptr-arreglo));
		printf("\nIngresa el nombre ");
		fflush(stdin);
		gets(ptr->cad);
		
		printf("\nIngresa la edad ");
		scanf("%d", &ptr->edad);
		
		printf("\nIngresa la estatura ");
		scanf("%f", &ptr->est);
		
		printf("\nIngresa el sexo ");
		fflush(stdin);
		ptr->car= getchar();
	}
	
	for(ptr=arreglo; ptr < &arreglo[5]; ptr++)
	{
		printf("\nEn la celda %d esta:", (int) (ptr-arreglo));
		printf("\n\tEl nombre %s en la direccion %lu", ptr->cad, &ptr->cad);
		printf("\n\tLa edad %d en la direccion %lu", ptr->edad, &ptr->edad);
		printf("\n\tLa estatura %.2f en la direccion %lu", ptr->est, &ptr->est);
		printf("\n\tEl sexo %c en la direccion %lu", ptr->car, &ptr->car);
	}
	
	return 0;
}
