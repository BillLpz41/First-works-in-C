#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(int dato);
void meterDato(struct nodo *ptrRef, int dato);
void sacarDato(struct nodo *ptrRef, int dato);
void imprimirCont(struct nodo *ptrRef);

int main()
{
	struct nodo *miRef;
	int midato;

	printf("Lista en orden ascendente con un nodo de cabecera.");

	miRef= crearNodo(-1000);

	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);

				meterDato(miRef, midato);

				break;
			case 2:
				printf("\nIngresa el dato que quieres buscar y quitar: ");
				scanf("%d", &midato);

				sacarDato(miRef, midato);

				break;
			case 3:
				imprimirCont(miRef);

				break;
			case 4:
				exit(0);

				break;
			default:
				printf("\nIngresa un numero valido.\n");
		}
	}
}

int menu()
{
	int c=0;

	printf("\n\nMenu de funciones:");
	printf("\n1 para introducir los datos.");
	printf("\n2 para sacar los datos.");
	printf("\n3 para imprimir todos los datos.");
	printf("\n4 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrN;

	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig=NULL;

	return ptrN;
}

void meterDato(struct nodo *ptrRef, int dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;

	ptrN= crearNodo(dato);

	if(ptrRef->ptrSig==NULL)
	{
		ptrRef->ptrSig= ptrN;
		ptrN->ptrSig=NULL;
	}
	else
	{
		ptr1= ptrRef;
		ptr2= ptrRef->ptrSig;
		while(ptr2 != NULL)
		{
			if(ptr1->dato== dato || ptr2->dato==dato)
			{
				printf("\nNo se permiten datos repetidos.");
				return;
			}
			else if(ptr1->dato< dato && dato< ptr2->dato)
			{
				ptr1->ptrSig= ptrN;
				ptrN->ptrSig= ptr2;
				return;
			}
			else
			{
				ptr1= ptr1->ptrSig;
				ptr2= ptr2->ptrSig;
			}
		}
		ptr1->ptrSig= ptrN;
	}
}

void sacarDato(struct nodo *ptrRef, int dato)
{
	struct nodo *ptrBasura, *ptrRecorrer;
	int bandera=0;
	
	ptrRecorrer= ptrRef;
	ptrBasura= ptrRef;
	if(ptrRef->ptrSig==NULL)
		printf("\nLa lista esta vacia!!");
	else
	{
		while(ptrRecorrer->ptrSig!=NULL)
	    {
	        if(ptrRecorrer->ptrSig->dato == dato)
	        {
	        	ptrBasura= ptrRecorrer->ptrSig;
	            printf("\nEl dato encontrado y sacado fue: %d", ptrRecorrer->ptrSig->dato);
	            ptrRecorrer->ptrSig = ptrBasura->ptrSig;

	        	free(ptrBasura);
				bandera=1;
	            break;
	        }
	        else
	            ptrRecorrer = ptrRecorrer->ptrSig;
	    }
		if(bandera!=1)
			printf("\nEl dato ingresado no fue encontrado.");
	}
}

void imprimirCont(struct nodo *ptrRef)
{
	struct nodo *ptrRecorrer;

	if(ptrRef->ptrSig==NULL)
		printf("\nSin contenido en la lista.");
	else
	{
		ptrRecorrer= ptrRef->ptrSig;
		printf("\nEl contenido de la lista es: ");
		while(ptrRecorrer != NULL)
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
	}
}
