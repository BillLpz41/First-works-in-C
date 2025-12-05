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

struct nodo *crearNodo(struct Dato dato);
void meterNodo(struct nodo ***ptrRef, struct Dato dato);
void sacarNodo(struct nodo ***ptrRef);
void imprimirCont(struct nodo ***ptrRef);
int menu();

int main()
{
	struct nodo *miRef1, **miRef2, ***miRef3;
	struct Dato miDato;
	
	printf("Pila con dato compuesto y triple apuntador.");
	
	miRef1=NULL;
	miRef2= &miRef1;
	miRef3= &miRef2;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngrese el nombre: ");
				fflush(stdin);
				gets(miDato.nombre);
				
				printf("\nIngresa la edad: ");
				scanf("%d", &miDato.edad);
				fflush(stdin);
				
				printf("\nIngresa el sexo: ");
				fflush(stdin);
				miDato.sexo= getchar();
				fflush(stdin);
				
				meterNodo(miRef3, miDato);
				
				break;	
			case 2:
				sacarNodo(miRef3);
				
				break;
			case 3:
				imprimirCont(miRef3);
				
				break;			
			case 4:
				exit(0);	
				
				break;
			default: 
				printf("\nIngresa un numero valido: 1, 2, 3 o 4.\n");
		}
	}
	
	return 0;
}

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->ptrSig=NULL;
		
	return ptrNuevo;
}

void meterNodo(struct nodo ***ptrRef, struct Dato dato)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato);
	if((**ptrRef)==NULL)
		**ptrRef = ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= **ptrRef;
		**ptrRef= ptrNuevo;
	}
}

void sacarNodo(struct nodo ***ptrRef)
{
	struct nodo *ptrBasura;
	
	if((**ptrRef)==NULL)
		printf("\nLa pila esta vacia...");
	else
	{
		ptrBasura= **ptrRef;
		**ptrRef= ptrBasura->ptrSig;
		printf("\n\tEl nombre es: %s", ptrBasura->dato.nombre);
		printf("\n\tLa edad es: %d", ptrBasura->dato.edad);
		printf("\n\tEl sexo es: %c", ptrBasura->dato.sexo);
		free(ptrBasura);
	}
	
}

void imprimirCont(struct nodo ***ptrRef)
{
	struct nodo *ptrRecorrer;
	
	if(**ptrRef==NULL)
		printf("\nNo hay nada que mostrar");
	else
	{
		ptrRecorrer= **ptrRef;
		printf("\nEl contenido de la pila es:");
		while(ptrRecorrer!=NULL)
		{
			printf("\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c\n", ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrSig;
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
