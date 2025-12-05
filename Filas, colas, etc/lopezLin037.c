#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato{
	char cad[30];
	int edad;
	char sexo;
};

struct nodo{
	struct Dato dato;
	struct nodo *ptrSig;	
};

int menu();
struct nodo *crearNodo(struct Dato dato);
void meterNodo(struct nodo *ptrRef, struct Dato dato);
void sacarNodo(struct nodo *ptrRef);
void imprimirCont(struct nodo *ptrRef);

int main()
{
	struct nodo *miRef;
	struct Dato miDato;
	
	printf("Pila Version con datos y de cabecera.");
	
	strcpy(miDato.cad, "-0000");
	miDato.edad= -1000;
	miDato.sexo= 'x';	
	miRef= crearNodo(miDato);
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese el nombre: ");
				fflush(stdin);
				gets(miDato.cad);
				
				printf("\nIngresa la edad: ");
				scanf("%d", &miDato.edad);
				fflush(stdin);
				
				printf("\nIngresa el sexo: ");
				fflush(stdin);
				miDato.sexo= getchar();
				fflush(stdin);
				
				meterNodo(miRef, miDato);
				
				break;	
			case 2:
				imprimirCont(miRef);
				
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
	
	return 0;
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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrSig= NULL;
	
	return ptrNuevo;	
}

void meterNodo(struct nodo *ptrRef, struct Dato dato)
{
	struct nodo *ptrN;
	
	ptrN= crearNodo(dato);
	if(ptrRef->ptrSig==NULL)
		ptrRef->ptrSig= ptrN;
	else
	{
		ptrN->ptrSig= ptrRef->ptrSig;
		ptrRef->ptrSig= ptrN;
	}
}

void sacarNodo(struct nodo *ptrRef)
{
	struct nodo *ptrBasura;
	
	if(ptrRef->ptrSig==NULL)
		printf("\nLa pila esta vacia.");
	else
	{
		ptrBasura= ptrRef->ptrSig;
		ptrRef->ptrSig= ptrBasura->ptrSig;
		printf("\nDatos sacados:");
		printf("\n\tNombre: %s", ptrBasura->dato.cad);
		printf("\n\tEdad: %d", ptrBasura->dato.edad);
		printf("\n\tSexo: %c", ptrBasura->dato.sexo);
		free(ptrBasura);
	}	
	
}

void imprimirCont(struct nodo *ptrRef)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= ptrRef->ptrSig;
	printf("\nContenido de la pila: ");
	while(ptrRecorrer!=NULL)
	{
		printf("\n\tNombre: %s", ptrRecorrer->dato.cad);
		printf("\n\tEdad: %d", ptrRecorrer->dato.edad);
		printf("\n\tSexo: %c\n", ptrRecorrer->dato.sexo);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
}
