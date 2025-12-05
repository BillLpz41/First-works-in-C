#include <stdio.h>
#include <stdlib.h>

#define TAM 4

struct Pila{
	int arreglo[TAM];
	int *ptrCima1;
	int **ptrCima2;
};

int menu();
void meter(struct Pila **ptrPila2, int dato);
int pilaLlena(struct Pila **ptrPila2);
int sacar(struct Pila **ptrPila2);
int pilaVacia(struct Pila **ptrPila2);

int main()
{
	struct Pila pila, *miPtrPila1, **miPtrPila2;
	int miDato;
	
	miPtrPila1= &pila;
	miPtrPila2= &miPtrPila1;
	(*miPtrPila2)->ptrCima1= (*miPtrPila2)->arreglo;
	(*miPtrPila2)->ptrCima2= &(*miPtrPila2)->ptrCima1;
	
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

void meter(struct Pila **ptrPila2, int dato)
{
	**(*ptrPila2)->ptrCima2= dato;
	(*(*ptrPila2)->ptrCima2)++;
}

int pilaLlena(struct Pila **ptrPila2)
{
	if(*(*ptrPila2)->ptrCima2== &(*ptrPila2)->arreglo[TAM])
		return 1;
	else
		return 0;
}

int sacar(struct Pila **ptrPila2)
{
	(*(*ptrPila2)->ptrCima2)--;
	return (**(*ptrPila2)->ptrCima2);
}

int pilaVacia(struct Pila **ptrPila2)
{
	if(*(*ptrPila2)->ptrCima2== &(*ptrPila2)->arreglo[0])
		return 1;
	else
		return 0;
}
