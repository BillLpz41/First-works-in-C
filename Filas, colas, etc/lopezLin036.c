#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo *ptrRef, int dato);
void sacarNodo(struct nodo *ptrRef);
void imprimirCont(struct nodo *ptrRef);

int main()
{
	struct nodo *miRef;
	int miDato;
	
	printf("Cola con nodo de cabecera.");
	
	miRef= crearNodo(-1000);
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese entero ");
				scanf("%d", &miDato);
				meterNodo(miRef, miDato);
				
				break;	
			case 2:
				sacarNodo(miRef);
				
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
	printf("\nIngresa 1 para introducir dato.");
	printf("\nIngresa 2 para sacar dato.");
	printf("\nIngresa 3 para imprimir datos.");
	printf("\nIngresa 4 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrSig=NULL;
	
	return ptrNuevo;
}

void meterNodo(struct nodo *ptrRef, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if(ptrRef->ptrSig==NULL)
		ptrRef->ptrSig= ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= ptrRef->ptrSig;
		ptrRef->ptrSig= ptrNuevo;
	}
}

void sacarNodo(struct nodo *ptrRef)
{
	struct nodo *ptrVan, *ptrRetd, *ptrBas;
	
	ptrVan= ptrRef->ptrSig;
	ptrRetd= ptrRef;
	
	if(ptrRef->ptrSig==NULL)
		printf("\nLa cola esta vacia!");
	else
	{
		while(ptrVan->ptrSig!=NULL)//si se usa la condicion ptrVan!=NULL, se llega hasta el último dato.
		{
			ptrRetd= ptrVan;
			ptrVan= ptrVan->ptrSig;
		}//al terminar el ciclo se mueve el puntero
		
		ptrBas= ptrRetd->ptrSig;
		ptrRetd->ptrSig=NULL;
		printf("El dato sacado fue: %d", ptrBas->dato);
		free(ptrBas);
	}
}

void imprimirCont(struct nodo *ptrRef)
{
	struct nodo *ptrRec;
	
	ptrRec= ptrRef->ptrSig;
	printf("\nEl contenido de la cola es: ");
	while(ptrRec!=NULL)
	{
		printf("%d, ", ptrRec->dato);
		ptrRec= ptrRec->ptrSig;
	}
}
