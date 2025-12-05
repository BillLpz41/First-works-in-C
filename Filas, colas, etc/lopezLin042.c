#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;	
};

int menu();
struct nodo *crearNodo(int dato);
void meterNodo(struct nodo *ptrRef1, struct nodo *ptrRef2, int dato);
void sacarNodo(struct nodo *ptrRef2, struct nodo *ptrRef1);
void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2;
	int midato;
	
	printf("Cola circular con cabecera y dato simple.");
	
	miRef1= crearNodo(-1000);
	miRef2= crearNodo(-2000);
	
	miRef1->ptrSig= miRef2;
	miRef1->ptrAnt= miRef2;
	miRef2->ptrSig= miRef1;
	miRef2->ptrAnt= miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);
				
				meterNodo(miRef1, miRef2, midato);
				
				break;	
			case 2:
				sacarNodo(miRef2, miRef1);
				
				break;	
			case 3:
				imprimirCont(miRef1, miRef2);
				
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

void meterNodo(struct nodo *ptrRef1, struct nodo *ptrRef2, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if(ptrRef1->ptrSig== ptrRef2 && ptrRef2->ptrAnt== ptrRef1)
	{
		ptrNuevo->ptrAnt= ptrRef1;
		ptrNuevo->ptrSig= ptrRef2;
		ptrRef1->ptrSig= ptrNuevo;
		ptrRef2->ptrAnt= ptrNuevo;
	}
	else
	{
		ptrNuevo->ptrSig= ptrRef1->ptrSig;
		ptrRef1->ptrSig->ptrAnt= ptrNuevo;
		ptrNuevo->ptrAnt= ptrRef1;
		ptrRef1->ptrSig= ptrNuevo;
	}
}

void sacarNodo(struct nodo *ptrRef2, struct nodo *ptrRef1)
{
	struct nodo *ptrBasura;
	
	if(ptrRef2->ptrAnt== ptrRef1 && ptrRef1->ptrSig== ptrRef2)
		printf("\nLa cola dinamica esta vacia...");
	else
	{
		ptrBasura= ptrRef2->ptrAnt;
		ptrRef2->ptrAnt= ptrBasura->ptrAnt;
		ptrBasura->ptrAnt->ptrSig= ptrRef2;
		printf("\nEl dato sacado fue: %d", ptrBasura->dato);
		free(ptrBasura);
	}
}

void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= ptrRef2->ptrAnt;
	
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
