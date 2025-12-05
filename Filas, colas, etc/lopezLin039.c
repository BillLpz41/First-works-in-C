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
void imprimirInv(struct nodo *ptrRef2, struct nodo *ptrRef1);

int main()
{
	struct nodo *ptrRef1, *ptrRef2;
	int miDato;
	
	printf("Cola dinamica con doble cabecera con doble enlace.");
	
	ptrRef1= crearNodo(-1000);
	ptrRef2= crearNodo(-2000);
	
	ptrRef1->ptrSig= ptrRef2;
	ptrRef2->ptrAnt= ptrRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese entero ");
				scanf("%d", &miDato);
				meterNodo(ptrRef1, ptrRef2, miDato);
				
				break;	
			case 2:
				sacarNodo(ptrRef2, ptrRef1);
				
				break;	
			case 3:
				imprimirCont(ptrRef1, ptrRef2);
				
				break;		
			case 4:
				imprimirInv(ptrRef2, ptrRef1);
				
				break;
			case 5:
				exit(0);	
				
				break;
			default: 
				printf("\nIngresa un numero valido.\n");
		}
	}
	
	return 0;	
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->ptrAnt= NULL;
		ptrNuevo->ptrSig= NULL;
		ptrNuevo->dato= dato;
		
	return ptrNuevo;
}

void meterNodo(struct nodo *ptrRef1, struct nodo *ptrRef2, int dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if(ptrRef1->ptrSig==ptrRef2 && ptrRef2->ptrAnt==ptrRef1)
	{
		ptrNuevo->ptrSig= ptrRef2;
		ptrRef1->ptrSig= ptrNuevo;
		ptrRef2->ptrAnt= ptrNuevo;
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

void sacarNodo(struct nodo *ptrRef2, struct nodo *ptrRef1)
{
	struct nodo *ptrBasura;
	
	if(ptrRef1->ptrSig==ptrRef2 && ptrRef2->ptrAnt==ptrRef1)
		printf("\nLa cola esta VACIA.");
	else
	{
		ptrBasura= ptrRef2->ptrAnt;
		ptrRef2->ptrAnt= ptrBasura->ptrAnt;
		ptrBasura->ptrAnt->ptrSig= ptrRef2;
		printf("\nEl dato sacado es: %d", ptrBasura->dato);
		free(ptrBasura);
	}
	
}

void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= ptrRef1->ptrSig;
	printf("\nEl contenido de la cola es: ");
	while(ptrRecorrer!=ptrRef2)
	{
		printf("%d, ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
}

void imprimirInv(struct nodo *ptrRef2, struct nodo *ptrRef1)
{
	struct nodo *ptrRecorrerInv;
	
	ptrRecorrerInv= ptrRef2->ptrAnt;
	printf("\nEl contenido de la cola es (orden inverso): ");
	while(ptrRecorrerInv!=ptrRef1)
	{
		printf("%d, ", ptrRecorrerInv->dato);
		ptrRecorrerInv= ptrRecorrerInv->ptrAnt;
	}
}

int menu()
{
	int c=0;
	
	printf("\n\nMenu de funciones:");
	printf("\nIngresa 1 para introducir dato.");
	printf("\nIngresa 2 para sacar dato.");
	printf("\nIngresa 3 para imprimir datos.");
	printf("\nIngresa 4 para imprimir datos de forma inversa.");
	printf("\nIngresa 5 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}
