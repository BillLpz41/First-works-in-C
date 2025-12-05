#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo **ptrRef1, struct nodo **ptrRef2, int dato);
void sacarNodo(struct nodo **ptrRef2, struct nodo **ptrRef1);
void imprimirCont(struct nodo **ptrRef1, struct nodo **ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2, **miPtrRef1, **miPtrRef2;
	int midato;
	
	printf("Cola dinamica con doble apuntador y dato simple.");
	
	miRef1= NULL;
	miRef2= NULL;
	
	miPtrRef1= &miRef1;
	miPtrRef2= &miRef2;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);
				
				meterNodo(miPtrRef1, miPtrRef2, midato);
				
				break;	
			case 2:
				sacarNodo(miPtrRef2, miPtrRef1);
				
				break;	
			case 3:
				imprimirCont(miPtrRef1, miPtrRef2);
				
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
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterNodo(struct nodo **ptrRef1, struct nodo **ptrRef2, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if((*ptrRef1)== NULL && (*ptrRef2)== NULL)
	{
		*ptrRef1= ptrNuevo;
		*ptrRef2= ptrNuevo;
	}
	else
	{
		ptrNuevo->ptrSig= (*ptrRef1);
		(*ptrRef1)->ptrAnt= ptrNuevo;
		(*ptrRef1)= ptrNuevo;
		
	}
}

void sacarNodo(struct nodo **ptrRef2, struct nodo **ptrRef1)
{
	struct nodo *ptrBasura;
	
	if((*ptrRef2)== NULL && (*ptrRef1)==NULL)
		printf("\nLa cola dinamica esta vacia...");
	else if((*ptrRef1)==(*ptrRef2) && (*ptrRef1)->ptrAnt==NULL && (*ptrRef2)->ptrSig==NULL)
	{
		ptrBasura= *ptrRef2;
		printf("\nEl dato sacado es: %d", ptrBasura->dato);
		free(ptrBasura);
		*ptrRef2=NULL;
		*ptrRef1=NULL;
	}
	else
	{
		ptrBasura= (*ptrRef2);
		(*ptrRef2)= ptrBasura->ptrAnt;
		ptrBasura->ptrAnt=NULL;
		(*ptrRef2)->ptrSig=NULL;
		printf("\nEl dato sacado es: %d", ptrBasura->dato);
		free(ptrBasura);
	}
}

void imprimirCont(struct nodo **ptrRef1, struct nodo **ptrRef2)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= (*ptrRef1);
	printf("\nEl contenido de la cola es: ");
	while(ptrRecorrer != NULL)
	{
		printf("%d, ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
	
	ptrRecorrer= (*ptrRef2);
	printf("\nEl contenido de la cola en orden inverso es: ");
	while(ptrRecorrer != NULL)
	{
		printf("%d, ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrAnt;
	}
}
