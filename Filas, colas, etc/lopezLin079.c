#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato{
	char nombre[30];
	int edad;
	char sexo;
};

struct nodo{
	struct Dato dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(struct Dato dato);
void meterDato(struct nodo ***ptrRef, struct Dato dato);
void sacarDato(struct nodo ***ptrRef, struct Dato dato);
void imprimirCont(struct nodo ***ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2, ***miRef3;
	struct Dato midato;
	
	printf("Lista con datos de usuario con un triple apuntador (ordenamiento por nombre).");
	
	miRef1=NULL;
	miRef2= &miRef1;
	miRef3= &miRef2;
	
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
				
				meterDato(miRef3, midato);

				break;	
			case 2:
				printf("\n\tIndroduce el nombre que quieres buscar y quitar (cuidado con las mayusculas): ");
				fflush(stdin);
				gets(midato.nombre);
				fflush(stdin);
							
				sacarDato(miRef3, midato);
				
				break;	
			case 3:
				imprimirCont(miRef3);
				
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
		ptrN->ptrSig=NULL;
		
	return ptrN;
}

void meterDato(struct nodo ***ptrRef, struct Dato dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;
	
	ptrN= crearNodo(dato);
	
	if(**ptrRef==NULL)
	{
		**ptrRef= ptrN;
		ptrN->ptrSig=NULL;
	}
	else if((**ptrRef)->ptrSig==NULL)
	{
		if(strcmp((**ptrRef)->dato.nombre, dato.nombre)==0)
		{
			printf("\nNo se permiten datos repetidos.");
			return;
		}
		else if(strcmp(dato.nombre, (**ptrRef)->dato.nombre)==-1)
		{
			ptrN->ptrSig= **ptrRef;
			**ptrRef= ptrN;
			ptrN= ptrN->ptrSig;
			return;
		}
		else
		{
			(**ptrRef)->ptrSig= ptrN;
			return;
		}
	}
	else
	{
		ptr1= **ptrRef;
		ptr2= (**ptrRef)->ptrSig;
		while(ptr2 != NULL)
		{
			if(strcmp(ptr1->dato.nombre, dato.nombre)==0 && strcmp(ptr2->dato.nombre, dato.nombre)==0)
			{
				printf("\nNo se permiten datos repetidos.");
				return;
			}	
			else if(strcmp(ptr1->dato.nombre, dato.nombre)==-1 && strcmp(ptr2->dato.nombre, dato.nombre)==1)
			{
				ptr1->ptrSig= ptrN;
				ptrN->ptrSig= ptr2;
				return;
			}
			else
			{
				ptr1= ptr1->ptrSig;
				ptr2= ptr2->ptrSig;
			}
		}
		ptr1->ptrSig= ptrN;
	}
}

void sacarDato(struct nodo ***ptrRef, struct Dato dato)
{
	struct nodo *ptrBasura, *ptrRecorrer, *ptr1, *ptr2;
	
	if(**ptrRef==NULL)
		printf("\nLa lista esta vacia!!");
	else
	{
		ptrRecorrer= **ptrRef;
		ptr1= NULL;
		ptr2= (**ptrRef)->ptrSig;
		
		while(ptrRecorrer!=NULL)
		{
			if(strcmp(ptrRecorrer->dato.nombre, dato.nombre)==0)
			{
				if(ptr1==NULL)
				{
					ptrBasura= ptrRecorrer;
					printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
					**ptrRef= ptrRecorrer->ptrSig;
					
					free(ptrBasura);
					return;
				}
				else
				{
					ptrBasura= ptrRecorrer;
					printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
					ptr1->ptrSig= ptr2;
					
					free(ptrBasura);
					return;
				}
			}
			else if(ptr2==NULL || ptrRecorrer==NULL)
				break;	
			else
			{
				ptr1= ptrRecorrer;
	        	ptrRecorrer= ptr2;
	        	ptr2= ptr2->ptrSig;
			}
		}
		printf("\nEl dato ingresado no fue encontrado.");
	}		
}

void imprimirCont(struct nodo ***ptrRef)
{
	struct nodo *ptrRecorrer;
	
	if(**ptrRef==NULL)
		printf("\nSin contenido en la lista.");
	else
	{
		ptrRecorrer= **ptrRef;
		printf("\nEl contenido de la lista es: ");
		while(ptrRecorrer != NULL)
		{
			printf("\n\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
				, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
	}
}
