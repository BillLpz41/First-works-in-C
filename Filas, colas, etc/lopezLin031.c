#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int main()
{
	struct nodo *ptrN, *ptrRef, *ptrRec, *ptrBas;
	
	ptrRef=NULL;
	//se crea el nodo auxiliar, pero no cuenta como informacion
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= -1000;
		ptrN->ptrSig=NULL;
	//el ptrReferencia se 'convierte' el nodo auxiliar
	ptrRef= ptrN;
	
	//crea un nuevo nodo con informacion
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa una edad del 0 al 120: ");
		scanf("%d", &ptrN->dato);
		ptrN->ptrSig=NULL;
	//el siguiente nodo del nodo de referencia es el nuevo nodo 
	ptrRef->ptrSig=ptrN;
	
	//se crea otro nuevo nodo con informacion
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa una edad del 0 al 120: ");
		scanf("%d", &ptrN->dato);
		ptrN->ptrSig=NULL;
	
	//este nuevo nodo irá entre el nodo de referencia y el nodo siguiente al de referencia	
	ptrN->ptrSig= ptrRef->ptrSig;//el nodo siguiente al nuevo nodo es el nodo siguiente del de referencia
	ptrRef->ptrSig=ptrN;//el nodo siguiente al nodo de referencia es el nuevo nodo
	
	//se crea otro nuevo nodo con informacion
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa una edad del 0 al 120: ");
		scanf("%d", &ptrN->dato);
		ptrN->ptrSig=NULL;
		
	//el nuevo nodo se coloca netre el de referencia y el nodo siguiente al de referencia	
	ptrN->ptrSig= ptrRef->ptrSig;
	ptrRef->ptrSig=ptrN;
	
	//para recorrer la pila, se inicia desde el nodo siguiente al de referencia
	//pues en este es donde está el último dato ingresado
	ptrRec= ptrRef->ptrSig;
	printf("\nDatos introducidos: ");
	while(ptrRec!=NULL)
	{
		printf("%d ", ptrRec->dato);
		ptrRec= ptrRec->ptrSig;//el recorrido comenzará por el nodo que le sigue al siguente del de referencia
	}
	//el apuntador de basura comienza con el nodo siguiente al de referencia
	ptrBas= ptrRef->ptrSig;
	ptrRef= ptrBas->ptrSig;//el nodo de referencia se convierte en el nodo siguiente al de basura
	printf("\nEl ultimo dato fue: %d\n", ptrBas->dato);
	free(ptrBas);
	
	//se comienza en el nodo de referencia, pues ahora ya no está el nodo auxiliar debido a lo anterior	
	ptrRec= ptrRef;//no se usa ptrRef->ptrSig porque ese ya no sería el penúltimo dato ingresado
					//(el último dato ingresado ya habría sido sacado), sino que el antepenúltimo
	printf("\nDatos introducidos: ");
	while(ptrRec!=NULL)
	{
		printf("%d ", ptrRec->dato);
		ptrRec= ptrRec->ptrSig;
	}
	
	return 0;
}
