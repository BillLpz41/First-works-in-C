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
	struct datos *ptrE;
	ptrE= &Var;
	
	printf("Caso 4 (apuntador simple)...");
	for(ptrE->ptrA= ptrE->arreglo; ptrE->ptrA < &ptrE->arreglo[TAM]; (ptrE->ptrA)++)
	{
		printf("\nCelda %d", (int) (ptrE->ptrA-ptrE->arreglo));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(ptrE->ptrA->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &ptrE->ptrA->edad);
	}
	
	for(ptrE->ptrA= ptrE->arreglo; ptrE->ptrA < &ptrE->arreglo[TAM]; (ptrE->ptrA)++)
	{
		printf("\nPersona/Celda %d:", (int) (ptrE->ptrA-ptrE->arreglo));
		printf("\n\tNombre: %s en la direccion %lu", ptrE->ptrA->nombre, &ptrE->ptrA->nombre);
		printf("\n\tEdad: %d en la direccion %lu", ptrE->ptrA->edad, &ptrE->ptrA->edad);
	}
}
