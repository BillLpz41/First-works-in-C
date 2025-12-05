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
	struct nodo *ptrAnt;	
};

int menu();
struct nodo *crearNodo(struct Dato dato);
void meterNodo(struct nodo **ptrRef, struct Dato dato);
void sacarNodo(struct nodo **ptrRef);
void imprimirCont(struct nodo **ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2;
	struct Dato midato;
	
	printf("Cola circular con unico doble apuntador y dato compuesto.");
	
	miRef1=NULL;
	miRef2= &miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa el nombre: ");
				fflush(stdin);
				gets(midato.nombre);
				fflush(stdin);
				printf("\nIngresa la edad: ");
				scanf("%d", &midato.edad);
				printf("\nIngresa el sexo: ");
				fflush(stdin);
				midato.sexo= getchar();
				fflush(stdin);;
				
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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterNodo(struct nodo **ptrRef, struct Dato dato)
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
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
		*ptrRef= NULL;
		free(ptrBasura);
	}
	else
	{
		ptrBasura= (*ptrRef)->ptrAnt;
		ptrBasura->ptrAnt->ptrSig= *ptrRef;
		(*ptrRef)->ptrAnt= ptrBasura->ptrAnt;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
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
			printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrAnt;
		}	
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
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
