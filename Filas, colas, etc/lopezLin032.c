#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int main()
{
	struct nodo *ptrRef1, **ptrRef2, *ptrNuevo, *ptrRecorrer, *ptrBas;
	
	printf("Pila sin nodo de cabecera.");
	
	ptrRef1=NULL;
	ptrRef2= &ptrRef1;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");	
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig= NULL;
		
	(*ptrRef2)= ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig=NULL;
		
	ptrNuevo->ptrSig= *ptrRef2;
	*ptrRef2= ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig=NULL;
		
	ptrNuevo->ptrSig= *ptrRef2;
	*ptrRef2= ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig=NULL;
		
	ptrNuevo->ptrSig= *ptrRef2;
	*ptrRef2= ptrNuevo;
	
	ptrRecorrer= *ptrRef2;
	printf("\nEl contenido es: ");
	while(ptrRecorrer !=NULL)
	{
		printf("%d ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
	
	ptrBas= *ptrRef2;
	printf("\nEl dato sacado es: %d\n", ptrBas->dato);
	*ptrRef2= ptrBas->ptrSig;
	free(ptrBas);
	
	ptrRecorrer= *ptrRef2;
	printf("\nEl contenido es: ");
	while(ptrRecorrer != NULL)
	{
		printf("%d ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
	
	return 0;
}
