#include <stdio.h>
#include <stdlib.h>
//Version con apuntadores
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
	struct persona *ptr;
	
	printf("Version con apuntadores...");
	
	for(ptr=arreglo; ptr< &arreglo[3]; ptr++)
	{
		printf("\nCelda %d", (int) (ptr-arreglo));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);	
		gets(ptr->nombre);
		
		printf("\n\tIngresa el nombre de la calle: ");
		fflush(stdin);
		gets(ptr->dom.calle);
		
		printf("\n\tIngresa el numero exterior: ");
		scanf("%d", &ptr->dom.numExt);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &ptr->edad);
		
		printf("\n\tIngresa la estatura: ");
		scanf("%f", &ptr->est);
		
		printf("\n\tIngresa el sexo: ");
		fflush(stdin);
		ptr->sexo= getchar();
	}
	
	for(ptr=arreglo; ptr < &arreglo[3]; ptr++)
	{
		printf("\n\nEn la celda %d: ", (int) (ptr-arreglo));
		printf("\n\tEl nombre es: %s / en la direccion %lu", ptr->nombre, &ptr->nombre);
		printf("\n\tEl domicilio es: %s Num. Ext. %d / en la direccion %lu y %lu"
			, ptr->dom.calle, ptr->dom.numExt, &ptr->dom.calle, &ptr->dom.numExt);
		printf("\n\tLa edad es: %d / en la direccion %lu", ptr->edad, &ptr->edad);
		printf("\n\tLa estatura es: %.2f / en la direccion %lu", ptr->est, &ptr->est);
		printf("\n\tEl sexo es: %c / en la direccion %lu", ptr->sexo, &ptr->sexo);
	}
	
	return 0;
}
