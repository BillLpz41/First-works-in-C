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
void meterNodo(struct nodo *ptrRef1, struct nodo *ptrRef2, struct Dato dato);
void sacarNodo(struct nodo *ptrRef2, struct nodo *ptrRef1);
void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2;
	struct Dato midato;
	
	printf("Cola circular con nodos de cabecera y dato compuesto.");
	
	midato.edad= -1000;
	midato.sexo= 'e';
	miRef1= crearNodo(midato);
	
	midato.edad= -2000;
	midato.sexo= 'e';
	miRef2= crearNodo(midato);
	
	miRef1->ptrSig= miRef2;
	miRef1->ptrAnt= miRef2;
	miRef2->ptrSig= miRef1;
	miRef2->ptrAnt= miRef1;
	
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
				fflush(stdin);
				
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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterNodo(struct nodo *ptrRef1, struct nodo *ptrRef2, struct Dato dato)
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
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);		
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
			printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
			, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
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
