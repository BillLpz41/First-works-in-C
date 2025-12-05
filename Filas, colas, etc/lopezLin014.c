#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct dato{
	char nombre[10];
	int edad;
};

struct datos{
	struct dato arreglo[TAM];
	struct dato *ptrA;
};

int main()
{
	struct datos Var;
	
	printf("Caso 2 (instancia de estructura que contiene un apuntador)...");
	for(Var.ptrA=Var.arreglo; Var.ptrA < &Var.arreglo[TAM]; Var.ptrA++)
	{
		printf("\nCelda %d", (int) (Var.ptrA-Var.arreglo));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(Var.ptrA->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &Var.ptrA->edad);
	}
	
	for(Var.ptrA= Var.arreglo; Var.ptrA< &Var.arreglo[TAM]; Var.ptrA++)
	{
		printf("\nPersona/Celda %d:", (int) (Var.ptrA-Var.arreglo));
		printf("\n\tNombre: %s en la direccion %lu", Var.ptrA->nombre, &Var.ptrA->nombre);
		printf("\n\tEdad: %d en la direccion %lu", Var.ptrA->edad, &Var.ptrA->edad);
	}
}
