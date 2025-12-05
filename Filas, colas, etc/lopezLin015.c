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
	struct datos *ptrE;
	ptrE= &Var;
	
	printf("Caso 3 (apuntador a instancia)...");
	for(ptrE->i= 0; ptrE->i < TAM; (ptrE->i)++)
	{
		printf("\nCelda %d", ptrE->i);
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(ptrE->arreglo[ptrE->i].nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &ptrE->arreglo[ptrE->i].edad);
	}
	
	for(ptrE->i= 0; ptrE->i < TAM; (ptrE->i)++)
	{
		printf("\nPersona/Celda %d:", ptrE->i);
		printf("\n\tNombre: %s en la direccion %lu", ptrE->arreglo[ptrE->i].nombre, &ptrE->arreglo[ptrE->i].nombre);
		printf("\n\tEdad: %d en la direccion %lu", ptrE->arreglo[ptrE->i].edad, &ptrE->arreglo[ptrE->i].edad);
	}
}
