#include <stdio.h>
#include <stdlib.h>

struct Cola{
	int arreglo[5];
	int *ptrS;
	int *ptrM;
};

int menu();
void meter(struct Cola *ptrCola, int dato);
int sacar(struct Cola *ptrCola, int dato);
int colaLlena(struct Cola *ptrCola);
int colaVacia(struct Cola *ptrCola);
void resetear(struct Cola *ptrCola);
void mostrar(struct Cola *ptrCola);

int main()
{
	struct Cola cola, *miPtrCola;
	int miDato;
	
	printf("Cola circular...");
	
	miPtrCola= &cola;
	miPtrCola->ptrM= miPtrCola->arreglo;
	miPtrCola->ptrS= miPtrCola->arreglo;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(colaLlena(miPtrCola)==1)
					printf("\nLa cola esta llena!!");
				else
				{
					printf("\nIntroduce un numero entero: ");
					scanf("%d", &miDato);
					meter(miPtrCola, miDato);
				}
				break;
			case 2:
				if(colaVacia(miPtrCola)==1)
					printf("\nLa cola esta vacia!!");
				else
					printf("\nEl dato sacado es: %d", sacar(miPtrCola, miDato));
				break;
			case 3:	
				mostrar(miPtrCola);
				break;
			case 4:
				resetear(miPtrCola);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nIngresa un numero valido; 1, 2, 3, 4 o 5.");
		}	
	}
	
	return 0;
}

void meter(struct Cola *ptrCola, int dato)
{
	*ptrCola->ptrM= dato;
	if(ptrCola->ptrM== &ptrCola->arreglo[5])
		ptrCola->ptrM= ptrCola->arreglo;
	else
		ptrCola->ptrM++;
}

int sacar(struct Cola *ptrCola, int dato)
{
	dato= *ptrCola->ptrS;
	if(ptrCola->ptrS== &ptrCola->arreglo[5])
		ptrCola->ptrS= ptrCola->arreglo;
	else
		ptrCola->ptrS++;
	
	return dato;
}

int colaLlena(struct Cola *ptrCola)
{
	if(ptrCola->ptrM== ptrCola->ptrS-1 || (ptrCola->ptrM== &ptrCola->arreglo[5] && ptrCola->ptrS== ptrCola->arreglo))
		return 1;
	else if(ptrCola->ptrM==ptrCola->ptrS && ptrCola->ptrM== ptrCola->arreglo)
		return 0;
}

int colaVacia(struct Cola *ptrCola)
{
	if(ptrCola->ptrM== ptrCola->ptrS)
		return 1;
	else
		return 0;
}

void resetear(struct Cola *ptrCola)
{
	ptrCola->ptrM= ptrCola->arreglo;
	ptrCola->ptrS= ptrCola->arreglo;
}

void mostrar(struct Cola *ptrCola)
{
	int *pos;
	
	pos= ptrCola->ptrS;
	for(ptrCola->ptrS= ptrCola->arreglo; ptrCola->ptrS < &ptrCola->arreglo[5]; ptrCola->ptrS++)
		printf("%d ", *ptrCola->ptrS);
	
	ptrCola->ptrS= pos;
}

int menu()
{
	int c=0;
	
	printf("\n\nMenu de funciones:");
	printf("\nIngresa 1 para introducir datos.");
	printf("\nIngresa 2 para sacar datos.");
	printf("\nIngresa 3 para mostrar datos.");
	printf("\nIngresa 4 para reiniciar la cola (se elimina el contenido).");
	printf("\nIngresa 5 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}
