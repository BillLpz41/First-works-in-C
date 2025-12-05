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
void meter(struct datos **ptrE);
void sacar(struct datos **ptrE);

int main()
{
	struct datos Var;
	struct datos *miptrE;
	struct datos **miptrE2;
	
	printf("Caso 6 (extra).");
	
	miptrE= &Var;
	miptrE2= &miptrE;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				meter(miptrE2);
				break;
			case 2:
				sacar(miptrE2);
				break;
			case 3:
				exit(0);
			default:
				printf("\nIngresa un numero valido.\n");
		}
	}
	
	return 0;
}

int menu()
{
	int c=0;
	
	printf("\n\nMenu de funciones:");
	printf("\nIngresa 1 para introducir datos.");
	printf("\nIngresa 2 para imprimir datos.");
	printf("\nIngresa 3 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

void meter(struct datos **ptrE)
{
	for((*ptrE)->ptrA= (*ptrE)->arreglo; (*ptrE)->ptrA < &(*ptrE)->arreglo[TAM]; (*ptrE)->ptrA++)
	{
		printf("\nCelda %d", (int) ((*ptrE)->ptrA - (*ptrE)->arreglo));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets((*ptrE)->ptrA->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &(*ptrE)->ptrA->edad);
		fflush(stdin);
	}
}

void sacar(struct datos **ptrE)
{
	
	for((*ptrE)->ptrA= (*ptrE)->arreglo; (*ptrE)->ptrA < &(*ptrE)->arreglo[TAM]; ((*ptrE)->ptrA)++)
	{
		printf("\nPersona/Celda %d con direccion %lu:", (int) ((*ptrE)->ptrA - (*ptrE)->arreglo), (*ptrE)->ptrA);
		printf("\n\tNombre: %s en la direccion %lu", ((*ptrE)->ptrA)->nombre, &((*ptrE)->ptrA)->nombre);
		printf("\n\tEdad: %d en la direccion %lu", ((*ptrE)->ptrA)->edad, &((*ptrE)->ptrA)->edad);
	}
}
