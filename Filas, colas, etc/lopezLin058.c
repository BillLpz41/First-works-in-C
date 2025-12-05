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
void meterNodo(struct nodo *ptrRef1, struct Dato dato);
void sacarNodo(struct nodo *ptrRef1);
void imprimirCont(struct nodo *ptrRef1);

int main()
{
	struct nodo *miRef1;
	struct Dato midato;
	
	printf("Cola circular con unica cabecera y dato compuesto.");
	
	midato.edad= -1000;
	midato.sexo= 'u';
	miRef1= crearNodo(midato);
	
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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterNodo(struct nodo *ptrRef1, struct Dato dato)
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
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
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
