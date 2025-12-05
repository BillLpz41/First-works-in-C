#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;	
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo *ptrRef1, int dato);
void sacarNodo(struct nodo *ptrRef1);
void imprimirCont(struct nodo *ptrRef1);

int main()
{
	struct nodo *miRef1;
	int midato;
	
	printf("Cola circular con unica cabecera y dato simple.");
	
	miRef1= crearNodo(-1000);
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);
				
				meterNodo(miRef1, midato);
				
				break;	
			case 2:
				sacarNodo(miRef1);
				
				break;	
			case 3:
				imprimirCont(miRef1);
				
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

void meterNodo(struct nodo *ptrRef1, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if(ptrRef1->ptrSig== NULL && ptrRef1->ptrAnt== NULL)
	{
		ptrRef1->ptrSig= ptrNuevo;
		ptrRef1->ptrAnt= ptrNuevo;
		ptrNuevo->ptrSig= ptrRef1;
		ptrNuevo->ptrAnt= ptrRef1;
	}
	else
	{
		ptrNuevo->ptrSig= ptrRef1->ptrSig;
		ptrRef1->ptrSig->ptrAnt= ptrNuevo;
		ptrNuevo->ptrAnt= ptrRef1;
		ptrRef1->ptrSig= ptrNuevo;
	}
}

void sacarNodo(struct nodo *ptrRef1)
{
	struct nodo *ptrBasura;
	
	if(ptrRef1->ptrSig== ptrRef1 && ptrRef1->ptrAnt== ptrRef1)
		printf("\nLa cola dinamica esta vacia...");
	else
	{
		ptrBasura= ptrRef1->ptrAnt;
		ptrRef1->ptrAnt= ptrBasura->ptrAnt;
		ptrBasura->ptrAnt->ptrSig= ptrRef1;
		printf("\nEl dato sacado fue: %d", ptrBasura->dato);
		free(ptrBasura);
	}
}

void imprimirCont(struct nodo *ptrRef1)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= ptrRef1->ptrAnt;
	
	if(ptrRecorrer== ptrRef1)
		printf("\nSin contenido. Nada que mostrar.");
	else
	{
		printf("\nEl contenido de la cola es: ");
		while(ptrRecorrer != ptrRef1)
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrAnt;
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
