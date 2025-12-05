#include <stdio.h>
#include <stdlib.h>

struct dom{
	char cad[30];
	int num;
};

struct dato{
	char nombre[28];
	int edad;
	struct dom dom;
};

struct pila{
	struct dato arreglo[3];
	struct dato *ptrCima1;
	struct dato **ptrCima2;
};

void meter(struct pila **ptrPila2, struct dato *datos);
int pilaLlena(struct pila **ptrPila2);
void sacar(struct pila **ptrPila2, struct dato *datos);
int pilaVacia(struct pila **ptrPila2);

int main()
{
	struct pila miPila, *miPtrPila1, **miPtrPila2;
	struct dato misDatos, *miPtrDato;
	
	miPtrPila1= &miPila;
	miPtrPila2= &miPtrPila1;
	(*miPtrPila2)->ptrCima1= (*miPtrPila2)->arreglo;
	(*miPtrPila2)->ptrCima2= &(*miPtrPila2)->ptrCima1;
	
	miPtrDato= &misDatos;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				if(pilaLlena(miPtrPila2)== 1)
					printf("\nLa pila esta LLENA!!");
				else
				{
					printf("\n\tIngresa el nombre de la persona: ");
					fflush(stdin);
					gets(miPtrDato->nombre);
					
					printf("\n\tIngresa la edad de la persona: ");
					scanf("%d", &miPtrDato->edad);
					
					printf("\n\tIngresa el nombre de la calle: ");
					fflush(stdin);
					gets(miPtrDato->dom.cad);
					
					printf("\n\tIngresa el numero de la calle: ");
					scanf("%d", &miPtrDato->dom.num);
					
					meter(miPtrPila2, miPtrDato);
				}	
				break;
			case 2:
				if(pilaVacia(miPtrPila2)== 1)
					printf("\nLa pila esta VACIA!!");
				else
				{
					sacar(miPtrPila2, miPtrDato);
					
					printf("\nLos datos sacados son:");
					printf("\n\tNombre: %s", miPtrDato->nombre);
					printf("\n\tEdad: %d", miPtrDato->edad);
					printf("\n\tCalle: %s Num. %d", miPtrDato->dom.cad, miPtrDato->dom.num);
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

void meter(struct pila **ptrPila2, struct dato *datos)
{
	**(*ptrPila2)->ptrCima2= *datos;
	(*(*ptrPila2)->ptrCima2)++;
}

int pilaLlena(struct pila **ptrPila2)
{
	if(*(*ptrPila2)->ptrCima2== &(*ptrPila2)->arreglo[3])
		return 1;
	else
		return 0;
}

void sacar(struct pila **ptrPila2, struct dato *datos)
{
	(*(*ptrPila2)->ptrCima2)--;
	*datos= **(*ptrPila2)->ptrCima2;
}

int pilaVacia(struct pila **ptrPila2)
{
	if(*(*ptrPila2)->ptrCima2== &(*ptrPila2)->arreglo[0])
		return 1;
	else
		return 0;
}
