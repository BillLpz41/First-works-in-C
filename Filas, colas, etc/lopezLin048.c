#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

struct nodo *crearNodo(int dato);
void meterNodo(struct nodo ***ptrRef, int dato);
void sacarNodo(struct nodo ***ptrRef);
void imprimirCont(struct nodo ***ptrRef);
int menu();

int main()
{
	struct nodo *miRef1, **miRef2, ***miRef3;
	int miDato;
	
	printf("Pila dinamica dato simple y triple apuntador.");
	
	miRef1=NULL;
	miRef2= &miRef1;
	miRef3= &miRef2;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &miDato);
				
				meterNodo(miRef3, miDato);
				
				break;	
			case 2:
				sacarNodo(miRef3);
				
				break;
			case 3:
				imprimirCont(miRef3);
				
				break;			
			case 4:
				exit(0);	
				
				break;
			default: 
				printf("\nIngresa un numero valido: 1, 2, 3 o 4.\n");
		}
	}
	
	return 0;
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrSig=NULL;
		
	return ptrNuevo;
}

void meterNodo(struct nodo ***ptrRef, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if((**ptrRef)==NULL)
		**ptrRef = ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= **ptrRef;
		**ptrRef= ptrNuevo;
	}
}

void sacarNodo(struct nodo ***ptrRef)
{
	struct nodo *ptrBasura;
	
	if((**ptrRef)==NULL)
		printf("\nLa pila esta vacia...");
	else
	{
		ptrBasura= **ptrRef;
		**ptrRef= ptrBasura->ptrSig;
		printf("\n\tEl entero ingresado fue: %d", ptrBasura->dato);
		free(ptrBasura);
	}
	
}

void imprimirCont(struct nodo ***ptrRef)
{
	struct nodo *ptrRecorrer;
	
	if(**ptrRef==NULL)
		printf("\n\tSin contenido.");
	else
	{
		ptrRecorrer= **ptrRef;
		printf("\n\tEl contenido de la pila es: ");
		while(ptrRecorrer!=NULL)
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrSig;
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
