#include <stdio.h>
#include <stdlib.h>

struct pila{
	int arreglo[5];
	int *ptrc;
};

int menu();
void meter(struct pila *ptrPila, int dato);
int pilaLlena(struct pila *ptrPila);
int sacar(struct pila *ptrPila);
int pilaVacia(struct pila *ptrPila);

int main()
{
	struct pila miPila, *miPtrPila;
	int miDato;
	
	miPtrPila= &miPila;
	miPtrPila->ptrc= miPtrPila->arreglo;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(pilaLlena(miPtrPila)==1)//esta llena
					printf("\nLa pila esta LLENA.");
				else
				{
					printf("\nIngresa el dato entero: ");
					scanf("%d", &miDato);
					meter(miPtrPila, miDato);
				}
				break;
			case 2:
				if(pilaVacia(miPtrPila)==1)//esta vacia
					printf("\nLa pila esta VACIA.");
				else
					printf("El dato sacado es %d", sacar(miPtrPila));
				break;
			case 3:
				exit(0);
			default:
				printf("\nIngresa un numero valido.\n");
		}
	}
	
	return 0;
}

void meter(struct pila *ptrPila, int dato)
{
	*ptrPila->ptrc= dato;
	ptrPila->ptrc++;
}

int pilaLlena(struct pila *ptrPila)
{
	if(ptrPila->ptrc== &ptrPila->arreglo[5])
		return 1;
	else
		return 0;
}

int sacar(struct pila *ptrPila)
{
	ptrPila->ptrc--;
	return (*ptrPila->ptrc);
}

int pilaVacia(struct pila *ptrPila)
{
	if(ptrPila->ptrc== &ptrPila->arreglo[0])
		return 1;
	else
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
