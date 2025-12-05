#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int edad;
	char nombre[30];
	char sexo;
};

struct nodo{
	struct Dato dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(struct Dato dato);
void meterNodo(struct nodo **ptrRef, struct Dato dato);
void sacarNodo(struct nodo **ptrRef);
void imprimirCont(struct nodo **ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2;
	struct Dato miDato;
	
	printf("Cola dinamica con doble apuntador y dato compuesto.");
	
	miRef1= NULL;
	miRef2= &miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngresa el nombre: ");
				fflush(stdin);
				gets(miDato.nombre);
				fflush(stdin);
				printf("\nIngresa la edad: ");
				scanf("%d", &miDato.edad);
				printf("\nIngresa el sexo: ");
				fflush(stdin);
				miDato.sexo= getchar();
				fflush(stdin);
				
				meterNodo(miRef2, miDato);
				
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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrSig= NULL;
	
	return ptrNuevo;
}

void meterNodo(struct nodo **ptrRef, struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if(*ptrRef== NULL)
		*ptrRef= ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= *ptrRef;
		*ptrRef= ptrNuevo;
	}
}

void sacarNodo(struct nodo **ptrRef)
{
	struct nodo *ptrVan, *ptrRetd, *ptrBas;
	
	if(*ptrRef==NULL)
		printf("\nLa cola esta vacia!");
	else if((*ptrRef)->ptrSig==NULL)
	{
		ptrBas= *ptrRef;
		*ptrRef=NULL;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
			, ptrBas->dato.nombre, ptrBas->dato.edad, ptrBas->dato.sexo);
		free(ptrBas);
	}
	else
	{
		ptrVan= (*ptrRef)->ptrSig;
		ptrRetd= *ptrRef;
		while(ptrVan->ptrSig!=NULL)
		{
			ptrRetd= ptrVan;
			ptrVan= ptrVan->ptrSig;
		}
			
		ptrBas= ptrRetd->ptrSig;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
			, ptrBas->dato.nombre, ptrBas->dato.edad, ptrBas->dato.sexo);
		ptrRetd->ptrSig=NULL;
		free(ptrBas);
	}
}

void imprimirCont(struct nodo **ptrRef)
{
	struct nodo *ptrRec;
	
	if(*ptrRef==NULL)
		printf("\nNo hay nada que mostrar.");
	else
	{
		ptrRec= *ptrRef;
		printf("\nEl contenido de la cola es: ");
		while(ptrRec!=NULL)
		{
			printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
			, ptrRec->dato.nombre, ptrRec->dato.edad, ptrRec->dato.sexo);
			ptrRec= ptrRec->ptrSig;
		}
	}
}
