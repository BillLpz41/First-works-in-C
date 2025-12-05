#include <stdio.h>
#include <stdlib.h>

#define TAM 3

struct dato{
	char nombre[10];
	int edad;
};

struct datos{
	struct dato arreglo[TAM];
	struct dato *ptrA1;
	struct dato **ptrA2;
};

int menu();
void meter(struct datos *ptrE);
void sacar(struct datos *ptrE);

int main()
{
	struct datos Var;
	struct datos *miptrE;
	
	printf("Caso 5 (extra).\n");

	miptrE= &Var;

	for(;;)
	{
		switch(menu())
		{
			case 1:
				meter(miptrE);
				break;
			case 2:
				sacar(miptrE);
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
	printf("\n\tIngresa 1 para introducir datos.");
	printf("\n\tIngresa 2 para imprimir datos.");
	printf("\n\tIngresa 3 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

void meter(struct datos *ptrE)
{
	ptrE->ptrA1= ptrE->arreglo;
	for(ptrE->ptrA2 = &ptrE->ptrA1; *ptrE->ptrA2 < &ptrE->arreglo[TAM]; (*ptrE->ptrA2)++)
	{
		printf("\nCelda %d", (int) (*ptrE->ptrA2 - ptrE->arreglo));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets((*ptrE->ptrA2)->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &(*ptrE->ptrA2)->edad);
		fflush(stdin);
	}
}

void sacar(struct datos *ptrE)
{
	ptrE->ptrA1= ptrE->arreglo;
	for(ptrE->ptrA2= &ptrE->ptrA1; *ptrE->ptrA2 < &ptrE->arreglo[TAM]; (*ptrE->ptrA2)++)
	{
		printf("\nPersona/Celda %d con direccion %lu:", (int) (*ptrE->ptrA2 - ptrE->arreglo), (*ptrE->ptrA2));
		printf("\n\tNombre: %s en la direccion %lu", (*ptrE->ptrA2)->nombre, &(*ptrE->ptrA2)->nombre);
		printf("\n\tEdad: %d en la direccion %lu", (*ptrE->ptrA2)->edad, &(*ptrE->ptrA2)->edad);
	}
}
