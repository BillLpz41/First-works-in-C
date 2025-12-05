#include <stdio.h>
#include <stdlib.h>

struct cola{
	int arreglo[5];
	int *ptrM;
	int *ptrS;
};

int menu();
void meter(struct cola *ptrCola, int dato);
void sacar(struct cola *ptrCola, int *dato);
int colaLlena(struct cola *ptrCola);
int colaVacia(struct cola *ptrCola);
void resetear(struct cola *ptrCola);
void mostrar(struct cola *ptrCola);

main()
{
	struct cola cola, *miptrCola;
	int miDato;

	printf("Cola lineal.");
	
	miptrCola= &cola;
	miptrCola->ptrM= miptrCola->arreglo;
	miptrCola->ptrS= miptrCola->arreglo;
	
	for(;;)
		{
			switch(menu())
			{
				case 1:
					if(colaLlena(miptrCola)==1)
						printf("\nLa cola esta LLENA!");
					else
					{
						printf("\nIntroduce un numero entero: ");
						scanf("%d", &miDato);
						meter(miptrCola, miDato);
					}
					break;
				case 2:
					if(colaVacia(miptrCola)==1)
						printf("\nLa cola esta VACIA!");
					else
					{
						sacar(miptrCola, &miDato);
						printf("\nEl dato sacado es: %d", miDato);
					}
					break;
				case 3:
					resetear(miptrCola);
					break;
				case 4:
					mostrar(miptrCola);
					break;
				case 5:
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
	printf("\nIngresa 3 para reiniciar la cola (se elimina el contenido).");
	printf("\nIngresa 4 para mostrar el contenido de la cola (no saca los datos).");
	printf("\nIngresa 5 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

void meter(struct cola *ptrCola, int dato)
{
	*ptrCola->ptrM= dato;
	(ptrCola->ptrM)++;
}

int colaLlena(struct cola *ptrCola)
{
	if(ptrCola->ptrM == &ptrCola->arreglo[5])
		return 1;
	else
	 	return 0;
}

void sacar(struct cola *ptrCola, int *dato)
{
	*dato= *ptrCola->ptrS;
	(ptrCola->ptrS)++;
}

int colaVacia(struct cola *ptrCola)
{
	if(ptrCola->ptrM == ptrCola->ptrS)
		return 1;
	else
		return 0;
}

void resetear(struct cola *ptrCola)
{
	for(ptrCola->ptrM= ptrCola->arreglo; ptrCola->ptrM < &ptrCola->arreglo[5]; ptrCola->ptrM++)
		*ptrCola->ptrM= 0;
	ptrCola->ptrM= ptrCola->arreglo;
	ptrCola->ptrS= ptrCola->arreglo;
}

void mostrar(struct cola *ptrCola)
{
	int *pos;
	
	pos= ptrCola->ptrS;
	
	printf("\nEl contenido de la cola es: ");
	for(ptrCola->ptrS= ptrCola->arreglo; ptrCola->ptrS < &ptrCola->arreglo[5]; ptrCola->ptrS++)
		printf("%d, ", *ptrCola->ptrS);
		
	ptrCola->ptrS= pos;
}
