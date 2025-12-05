#include <stdio.h>
#include <stdlib.h>
//Version con instancias
struct domicilio{
	char calle[30];
	int numExt;
};

struct persona{
	char nombre[30];
	struct domicilio dom;
	int edad;
	float est;
	char sexo;
};

int main()
{
	struct persona arreglo[3];
	int i=0;
	printf("Version con instancias...");
	for(i=0; i<3; i++)
	{
		printf("\nCelda %d", i);
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);	
		gets(arreglo[i].nombre);
		
		printf("\n\tIngresa el nombre de la calle: ");
		fflush(stdin);
		gets(arreglo[i].dom.calle);
		
		printf("\n\tIngresa el numero exterior: ");
		scanf("%d", &arreglo[i].dom.numExt);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &arreglo[i].edad);
		
		printf("\n\tIngresa la estatura: ");
		scanf("%f", &arreglo[i].est);
		
		printf("\n\tIngresa el sexo: ");
		fflush(stdin);
		arreglo[i].sexo= getchar();
	}
	
	for(i=0; i<3; i++)
	{
		printf("\n\nEn la celda %d: ", i);
		printf("\n\tEl nombre es: %s / en la direccion %lu", arreglo[i].nombre, &arreglo[i].nombre);
		printf("\n\tEl domicilio es: %s Num. Ext. %d / en la direccion %lu y %lu", arreglo[i].dom.calle, arreglo[i].dom.numExt, &arreglo[i].dom.calle, &arreglo[i].dom.numExt);
		printf("\n\tLa edad es: %d / en la direccion %lu", arreglo[i].edad, &arreglo[i].edad);
		printf("\n\tLa estatura es: %.2f / en la direccion %lu", arreglo[i].est, &arreglo[i].est);
		printf("\n\tEl sexo es: %c / en la direccion %lu", arreglo[i].sexo, &arreglo[i].sexo);
	}
	
	return 0;
}
