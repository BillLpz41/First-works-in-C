#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct dato{
	char nombre[10];
	int edad;
};

struct datos{
	struct dato arreglo[TAM];
	int i;
};

int main()
{
	struct datos Var;
	
	printf("Caso 1 (solo instancias)...");
	for(Var.i=0; Var.i<TAM; Var.i++)
	{
		printf("\nCelda %d", Var.i);
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(Var.arreglo[Var.i].nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &Var.arreglo[Var.i].edad);
	}
	
	for(Var.i=0; Var.i<TAM; Var.i++)
	{
		printf("\nPersona/Celda %d:", Var.i);
		printf("\n\tNombre: %s en la direccion %lu", Var.arreglo[Var.i].nombre, &Var.arreglo[Var.i].nombre);
		printf("\n\tEdad: %d en la direccion %lu", Var.arreglo[Var.i].edad, &Var.arreglo[Var.i].edad);
	}
}
