#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;	
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo **ptrRef, int dato);
void sacarNodo(struct nodo **ptrRef);
void imprimirCont(struct nodo **ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2;
	int midato;
	
	printf("Cola circular con unico doble apuntador y dato simple.");
	
	miRef1=NULL;
	miRef2= &miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);
				
				meterNodo(miRef2, midato);
				
				break;	
			case 2:
				sacarNodo(miRef2);
				
				break;	
			case 3:
				imprimirCont(miRef2);
				
				break;		
			case 4:
				exit(0);	
				
				break;
			default: 
				printf("\nIngresa un numero valido.\n");
		}
	}
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterNodo(struct nodo **ptrRef, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if(*ptrRef== NULL)
	{
		*ptrRef= ptrNuevo;
		ptrNuevo->ptrSig= *ptrRef;
		ptrNuevo->ptrAnt= *ptrRef;
	}
	else
	{
		ptrNuevo->ptrSig= (*ptrRef);
		ptrNuevo->ptrAnt= (*ptrRef)->ptrAnt;
		(*ptrRef)->ptrAnt= ptrNuevo;
		(*ptrRef)->ptrSig= ptrNuevo;
		*ptrRef= ptrNuevo;
	}
}

void sacarNodo(struct nodo **ptrRef)
{
	struct nodo *ptrBasura;
	
	if(*ptrRef== NULL)
		printf("\nLa cola dinamica esta vacia...");
	else if((*ptrRef)->ptrSig== *ptrRef && (*ptrRef)->ptrAnt== *ptrRef)
	{
		ptrBasura= (*ptrRef);
		printf("El dato sacado fue: %d", ptrBasura->dato);
		*ptrRef= NULL;
		free(ptrBasura);
	}
	else
	{
		ptrBasura= (*ptrRef)->ptrAnt;
		ptrBasura->ptrAnt->ptrSig= *ptrRef;
		(*ptrRef)->ptrAnt= ptrBasura->ptrAnt;
		printf("El dato sacado fue: %d", ptrBasura->dato);
		free(ptrBasura);
	}
}

void imprimirCont(struct nodo **ptrRef)
{
	struct nodo *ptrRecorrer;
	
	if(*ptrRef==NULL)
		printf("\nSin contenido. Nada que mostrar.");
	else
	{
		ptrRecorrer= (*ptrRef)->ptrAnt;	
		printf("\nEl contenido de la cola es: ");
		while(ptrRecorrer != (*ptrRef))
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrAnt;
		}	
		printf("%d, ", ptrRecorrer->dato);
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
