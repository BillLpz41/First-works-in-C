#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrsig;
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo **ptrRef, int dato);
void sacarNodo(struct nodo **ptrRef);
void impContenido(struct nodo **ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2;
	int midato;
	
	printf("Pila con doble apuntador.");
	
	miRef1=NULL;
	miRef2= &miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese entero ");
				scanf("%d", &midato);
				meterNodo(miRef2, midato);
				
				break;	
			case 2:
				impContenido(miRef2);
				
				break;	
			case 3:
				sacarNodo(miRef2);	
				
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
	printf("\nIngresa 1 para introducir datos.");
	printf("\nIngresa 2 para imprimir datos.");
	printf("\nIngresa 3 para sacar un dato.");
	printf("\nIngresa 4 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo=(struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrsig=NULL;
		
	return ptrNuevo;
}

void meterNodo(struct nodo **ptrRef, int dato)
{
	struct nodo *ptrN;
	
	ptrN= crearNodo(dato);
	if((*ptrRef)==NULL)
		*ptrRef= ptrN;
	else
	{
		ptrN->ptrsig= *ptrRef;
		*ptrRef= ptrN;
	}
}

void sacarNodo(struct nodo **ptrRef)
{
	struct nodo *ptrBas;
	
	ptrBas= *ptrRef;
	if((*ptrRef)==NULL)
		printf("\nLa cola esta vacia.");
	else
	{
		*ptrRef= ptrBas->ptrsig;
		printf("\nEl dato sacado es: %d", ptrBas->dato);
		free(ptrBas);
	}
	
}

void impContenido(struct nodo **ptrRef)
{
	struct nodo *ptrRec;
	
	ptrRec= *ptrRef;
	printf("\nEl contenido es: ");
	while(ptrRec!=NULL)
	{
		printf("%d, ", ptrRec->dato);
		ptrRec= ptrRec->ptrsig;
	}
}
