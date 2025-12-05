#include <stdio.h>
#include <stdlib.h>
//Tipo de dato definido por el usuario
//estructura autoreferenciada
struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int main()
{
	struct nodo *ptrRef, *ptrNuevo, *ptrRecorrer, *ptrBasura;
	
	ptrRef= NULL; //apuntador de referencia. NUNCA se debe perder
	
	//se crea el primer nodo. Se asignan los campos de la instancia de estructura
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig= NULL;
	
	ptrRef= ptrNuevo; //se ancla el apuntador de referencia al nodo creado
	/********************************************************/
	//Se crea el segundo nodo y asignan los campo de la instancia de estructura
	ptrNuevo= (struct nodo*)malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig= NULL;	
	
	//Se hacen los enlaces cuidando el orden de estos.
	//El nuevo nodo debe ser apuntado por el apuntador de referencia
	ptrNuevo->ptrSig= ptrRef;
	ptrRef= ptrNuevo;
	
	/********************************************/
	//Se crea el tercer nodo y asignan los campos de la instancia de estructura
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig= NULL;
		
	//Se hacen los enlaces cuidando el ordne de éstos.
	//El nuevo nodo debe ser apuntado por el apuntador de referencia		
	ptrNuevo->ptrSig= ptrRef;
	ptrRef= ptrNuevo;
		
	/*****************************************************/
	//Se crea el cuarto nodo y asignan los campos de la instancia de estructura
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		printf("\nIngresa un entero: ");
		scanf("%d", &ptrNuevo->dato);
		ptrNuevo->ptrSig= NULL;
			
	//Se hacen los enlaces cuidando el orden de éstos.
	//El nuevo nodo debe ser apuntado por el apuntador de referencia
	ptrNuevo->ptrSig= ptrRef;
	ptrRef= ptrNuevo;
		
	//Hasta el momento hay 4 nodos enlazados
	//meta datos recordando el orden (ejem: 10, 20, 30, 40)
		
	//Comprobanción el contenido, haciendo un recorrido
	// nodo por nodo desde a referencia sin moverlo
		
	ptrRecorrer= ptrRef;
		
	printf("\nEl contenido de los nodos del ultimo al primer ingresados\n");
	while(ptrRecorrer != NULL){
		printf("%d ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}
		
	ptrBasura= ptrRef;
	ptrRef= ptrBasura->ptrSig;
	printf("\nEl dato borrado es %d", ptrBasura->dato);
	free(ptrBasura);
	
	ptrRecorrer= ptrRef;
	
	printf("\nEl contenido de los nodo del ultimo al primero ingresados\n");
	while(ptrRecorrer != NULL){
		printf("%d ", ptrRecorrer->dato);
		ptrRecorrer= ptrRecorrer->ptrSig;
	}	
	
	return 0;
}
