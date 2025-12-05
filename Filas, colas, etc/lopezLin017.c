#include <stdio.h>
#include <stdlib.h>

#define TAM 3

struct dato{
	char nombre[10];
	int edad;
};

struct datos{
	struct dato arreglo[TAM];
	struct dato *ptrA;
};

int menu();
void meter(struct datos *ptrE);
void sacar(struct datos *ptrE);

int main()
{
	struct datos Var;
	struct datos *miPtrE;
	
	miPtrE= &Var;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				meter(miPtrE);
				break;
			case 2:
				sacar(miPtrE);
				break;
			case 3:
				exit(0);
			default:
				printf("\nSeleccione unicamente 1 o 2\n");
		}
	}
	
	return 0;
}

int menu()
{
	int eleccion;
	printf("\n1 para meter datos.");
	printf("\n2 para sacar datos.");
	printf("\n3 para salir.\n");
	scanf("%d", &eleccion);
	
	return eleccion;
}

void meter(struct datos *ptrE)
{
	for(ptrE->ptrA= ptrE->arreglo; ptrE->ptrA < &ptrE->arreglo[TAM]; (ptrE->ptrA)++)
	{
		printf("\nIngrese el nombre: ");
		fflush(stdin);
		gets(ptrE->ptrA->nombre);
		
		printf("\nIngrese la edad: ");
		scanf("%d", &ptrE->ptrA->edad);
		fflush(stdin);
	}
}

void sacar(struct datos *ptrE)
{
	for(ptrE->ptrA= ptrE->arreglo; ptrE->ptrA < &ptrE->arreglo[TAM]; (ptrE->ptrA)++)
	{
		printf("\nCelda %d (direccion %lu):", (int) (ptrE->ptrA - ptrE->arreglo), ptrE->ptrA);
		printf("\n\tNombre %s con direccion %lu", ptrE->ptrA->nombre, &ptrE->ptrA->nombre);
		printf("\n\tEdad %d con la direccion %lu", ptrE->ptrA->edad, &ptrE->ptrA->edad);
	}
}
