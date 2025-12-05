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
void meterNodo(struct nodo ***ptrRef1, struct nodo ***ptrRef2, struct Dato dato);
void sacarNodo(struct nodo ***ptrRef2, struct nodo ***ptrRef1);
void imprimirCont(struct nodo ***ptrRef1, struct nodo ***ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2, **miRef3, **miRef4, ***miPtrRef1, ***miPtrRef2;
	struct Dato midato;
	
	printf("Cola circular con triple apuntador y dato compuesto.");
	
	miRef1= NULL;
	miRef2= NULL;
	
	miRef3= &miRef1;
	miRef4= &miRef2;
	miPtrRef1= &miRef3;
	miPtrRef2= &miRef4;
	
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
				
				meterNodo(miPtrRef1, miPtrRef2, midato);
				
				break;	
			case 2:
				sacarNodo(miPtrRef2, miPtrRef1);
				
				break;	
			case 3:
				imprimirCont(miPtrRef1, miPtrRef2);
				
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
	printf("\n1 para introducir los datos.");
	printf("\n2 para sacar los datos.");
	printf("\n3 para imprimir todos los datos.");
	printf("\n4 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
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

void meterNodo(struct nodo ***ptrRef1, struct nodo ***ptrRef2, struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	
	if((**ptrRef1)== NULL && (**ptrRef2)== NULL)
	{
		**ptrRef1= ptrNuevo;
		**ptrRef2= ptrNuevo;
		(**ptrRef1)->ptrSig= **ptrRef1;
		(**ptrRef2)->ptrAnt= **ptrRef2;
	}
	else
	{
		ptrNuevo->ptrSig= (**ptrRef1);
		(**ptrRef1)->ptrAnt= ptrNuevo;
		(**ptrRef1)= ptrNuevo;
	}
}

void sacarNodo(struct nodo ***ptrRef2, struct nodo ***ptrRef1)
{
	struct nodo *ptrBasura;
	
	if((**ptrRef2)== NULL && (**ptrRef1)==NULL)
		printf("\nLa cola dinamica esta vacia...");
	else if((**ptrRef1)==(**ptrRef2))
	{
		ptrBasura= **ptrRef2;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
		free(ptrBasura);
		**ptrRef2=NULL;
		**ptrRef1=NULL;
	}
	else
	{
		ptrBasura= (**ptrRef2);
		(**ptrRef2)= ptrBasura->ptrAnt;
		ptrBasura->ptrAnt=NULL;
		(**ptrRef2)->ptrSig=NULL;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
		free(ptrBasura);
	}
}

void imprimirCont(struct nodo ***ptrRef1, struct nodo ***ptrRef2)
{
	struct nodo *ptrRecorrer;
	
	ptrRecorrer= (**ptrRef2);
	if(ptrRecorrer== NULL)
		printf("\nNo hay contenido que mostrar.");
	else
	{
		printf("\nEl contenido de la cola es: ");
		while(ptrRecorrer != **ptrRef1)
		{
			printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
			, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrAnt;
		}
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
		, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
	}
}
