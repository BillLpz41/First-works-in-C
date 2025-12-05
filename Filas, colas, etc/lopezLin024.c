#include <stdio.h>
#include <stdlib.h>

#define TAM 4

struct pila{
	int arreglo[TAM];
	int *ptrCima;
};

int menu();
void meter(struct pila **ptrPila, int dato);
int pilaLlena(struct pila **ptrPila);
int sacar(struct pila **ptrPila);
int pilaVacia(struct pila **ptrPila);

int main()
{
	struct pila pila;
	struct pila *miPtrPila1;
	struct pila **miPtrPila2;
	int miDato;
	
	miPtrPila1= &pila;
	miPtrPila2= &miPtrPila1;
	(*miPtrPila2)->ptrCima= (*miPtrPila2)->arreglo;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(pilaLlena(miPtrPila2)== 1)
					printf("\nLa pila esta LLENA!!");
				else
				{
					printf("\nIngresa un numero entero: ");
					scanf("%d", &miDato);
					meter(miPtrPila2, miDato);
				}	
				break;
			case 2:
				if(pilaVacia(miPtrPila2)== 1)
					printf("\nLa pila esta VACIA!!");
				else
					printf("\nEl dato sacado es %d", sacar(miPtrPila2));
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

void meter(struct pila **ptrPila, int dato)
{
	*(*ptrPila)->ptrCima= dato;
	(*ptrPila)->ptrCima++;
}

int sacar(struct pila **ptrPila)
{
	(*ptrPila)->ptrCima--;
	return (*(*ptrPila)->ptrCima);
}

int pilaLlena(struct pila **ptrPila)
{
	if((*ptrPila)->ptrCima== &(*ptrPila)->arreglo[TAM])
		return 1;
	else
		return 0;
}

int pilaVacia(struct pila **ptrPila)
{
	if((*ptrPila)->ptrCima== (*ptrPila)->arreglo)
		return 1;
	else
		return 0;
}
