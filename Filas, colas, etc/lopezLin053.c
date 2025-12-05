#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo ***ptrRef, int dato);
void sacarNodo(struct nodo ***ptrRef);
void imprimirCont(struct nodo ***ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2, ***miRef3;
	int miDato;
	
	printf("Cola dinamica con triple apuntador.");
	
	miRef1= NULL;
	miRef2= &miRef1;
	miRef3= &miRef2;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese entero ");
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
		ptrNuevo->ptrSig= NULL;
	
	return ptrNuevo;
}

void meterNodo(struct nodo ***ptrRef, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if(**ptrRef== NULL)
		**ptrRef= ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= **ptrRef;
		**ptrRef= ptrNuevo;
	}
}

void sacarNodo(struct nodo ***ptrRef)
{
	struct nodo *ptrVan, *ptrRetd, *ptrBas;
	
	if(**ptrRef==NULL)
		printf("\nLa cola esta vacia!");
	else if((**ptrRef)->ptrSig==NULL)
	{
		ptrBas= **ptrRef;
		**ptrRef=NULL;
		printf("\nEl dato sacado fue: %d", ptrBas->dato);
		free(ptrBas);
	}
	else
	{
		ptrVan= (**ptrRef)->ptrSig;
		ptrRetd= **ptrRef;
		while(ptrVan->ptrSig!=NULL)
		{
			ptrRetd= ptrVan;
			ptrVan= ptrVan->ptrSig;
		}
			
		ptrBas= ptrRetd->ptrSig;
		printf("\nEl dato sacado fue: %d", ptrBas->dato);
		ptrRetd->ptrSig=NULL;
		free(ptrBas);
	}
}

void imprimirCont(struct nodo ***ptrRef)
{
	struct nodo *ptrRec;
	
	if(**ptrRef==NULL)
		printf("\nNo hay nada que mostrar.");
	else
	{
		ptrRec= **ptrRef;
		printf("\nEl contenido de la cola es: ");
		while(ptrRec!=NULL)
		{
			printf("%d, ", ptrRec->dato);
			ptrRec= ptrRec->ptrSig;
		}
	}
	
}
