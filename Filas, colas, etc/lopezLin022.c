#include <stdio.h>
#include <stdlib.h>

int menu();
void meter(int *ptrCima, int dato);
int pilaLlena(int *pila, int *ptrCima);
int sacar(int *ptrCima);
int pilaVacia(int *pila, int *ptrCima);

int main()
{
	int arreglo[5];
	int *ptrc;
	int miDato=0;
	
	ptrc= arreglo;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(pilaLlena(arreglo, ptrc)==1)//esta llena
					printf("\nLa pila esta LLENA.");
				else
				{
					printf("\nIngresa el dato entero: ");
					scanf("%d", &miDato);
					meter(ptrc, miDato);
					ptrc++;
				}
				break;
			case 2:
				if(pilaVacia(arreglo, ptrc)==1)//esta vacia
					printf("\nLa pila esta VACIA.");
				else
				{
					ptrc--;
					printf("El dato sacado es %d", sacar(ptrc));

				}
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

void meter(int *ptrCima, int dato)
{
	*ptrCima= dato;
}

int pilaLlena(int *pila, int *ptrCima)
{
	if(ptrCima== &pila[5])
		return 1;
	else
		return 0;
}

int sacar(int *ptrCima)
{
	return (*ptrCima);
}

int pilaVacia(int *pila, int *ptrCima)
{
	if(ptrCima== &pila[0])
		return 1;
	else
		return 0;
}
