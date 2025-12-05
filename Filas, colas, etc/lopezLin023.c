#include <stdio.h>
#include <stdlib.h>

#define TAM 4

struct pila{
	int arreglo[TAM];
	int *ptrCima1;
	int **ptrCima2;
};

int menu();
void meter(struct pila *ptrPila, int dato);
int pilaLlena(struct pila *ptrPila);
int sacar(struct pila *ptrPila);
int pilaVacia(struct pila *ptrPila);

int main()
{
	struct pila pila;
	struct pila *miPtrPila;
	int miDato;
	
	miPtrPila= &pila;
	miPtrPila->ptrCima1= miPtrPila->arreglo;
	miPtrPila->ptrCima2= &miPtrPila->ptrCima1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(pilaLlena(miPtrPila)== 1)
					printf("\nLa pila esta LLENA!!");
				else
				{
					printf("\nIngresa un numero entero: ");
					scanf("%d", &miDato);
					meter(miPtrPila, miDato);
				}	
				break;
			case 2:
				if(pilaVacia(miPtrPila)== 1)
					printf("\nLa pila esta VACIA!!");
				else
					printf("\nEl dato sacado es %d", sacar(miPtrPila));
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

void meter(struct pila *ptrPila, int dato)
{
	**ptrPila->ptrCima2= dato;
	(*ptrPila->ptrCima2)++;
}

int pilaLlena(struct pila *ptrPila)
{
	if(*ptrPila->ptrCima2== &ptrPila->arreglo[TAM])
		return 1;
	else
		return 0;
}

int sacar(struct pila *ptrPila)
{
	(*ptrPila->ptrCima2)--;
	return (**ptrPila->ptrCima2);
}

int pilaVacia(struct pila *ptrPila)
{
	if(*ptrPila->ptrCima2== ptrPila->arreglo)
		return 1;
	else
		return 0;
}
