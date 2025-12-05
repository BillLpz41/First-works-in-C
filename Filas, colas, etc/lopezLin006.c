#include <stdio.h>
#include <stdlib.h>

struct per{
	char cad[30];
	int edad;
	float est;
	char car;
};

int main()
{//Version 1. Instancias
	struct per arreglo[5];
	int i=0;
	
	for(i=0; i<5; i++)
	{
		printf("\nCelda %d", i);
		printf("\nIngresa el nombre ");
		fflush(stdin);
		gets(arreglo[i].cad);
		
		printf("\nIngresa edad ");
		scanf("%d", &arreglo[i].edad);
		
		printf("\nIngresa estatura ");
		scanf("%f", &arreglo[i].est);
		
		printf("\nIngresa sexo ");
		fflush(stdin);
		arreglo[i].car= getchar();
	}
	
	for(i=0; i<5; i++)
	{
		printf("\nEn la celda %d esta:", i);
		printf("\n\tEl nombre %s en la direccion %lu", arreglo[i].cad, &arreglo[i].cad);
		printf("\n\tLa edad %d en la direccion %lu", arreglo[i].edad, &arreglo[i].edad);
		printf("\n\tLa estatura %.2f en la direccion %lu", arreglo[i].est, &arreglo[i].est);
		printf("\n\tEl sexo %c en la direccion %lu", arreglo[i].car, &arreglo[i].car);
	}
	
	return 0;
}
