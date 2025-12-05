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
void impContenido(struct nodo *ptrRef);

int main()
{
	struct nodo *miRef;
	int miDato;
	
	printf("Pila con nodo de cabecera con funciones.");

	miRef= crearNodo(-1000);//crea el nodo de cabecera	
	
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
				impContenido(miRef);
				
				break;	
			case 3:
				sacarNodo(miRef);	
				
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
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato=dato;
		ptrN->ptrSig=NULL;
		
	return ptrN;
}

void meterNodo(struct nodo *ptrRef, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if(ptrRef->ptrSig==NULL)
		ptrRef->ptrSig=ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= ptrRef->ptrSig;
		ptrRef->ptrSig= ptrNuevo;
	}
}

void sacarNodo(struct nodo *ptrRef)
{
	struct nodo *ptrBas;
	
	if(ptrRef==NULL)
		printf("\nLa pila esta vacia.");
	else
	{
		ptrBas= ptrRef->ptrSig;
		ptrRef->ptrSig= ptrBas->ptrSig;
		printf("\nEl dato sacado es %d", ptrBas->dato);
		free(ptrBas);
	}
}

void impContenido(struct nodo *ptrRef)
{
	struct nodo *ptrRec;
	
	ptrRec= ptrRef->ptrSig;
	printf("\nEl contenido de la pila es: ");
	while(ptrRec!=NULL)
	{
		printf("%d ", ptrRec->dato);
		ptrRec= ptrRec->ptrSig;
	}
}
