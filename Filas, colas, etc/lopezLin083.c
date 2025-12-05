#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void meterDato(struct nodo *ptrRef1, struct nodo *ptrRef2, struct Dato dato);
void sacarDato(struct nodo *ptrRef2, struct nodo *ptrRef1, struct Dato dato);
void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2;
	struct Dato midato;

	printf("Lista en orden ascendente con dos nodos de cabecera con doble enlace (dato compuesto).");
	
	midato.edad= -10000;
	strcpy(midato.nombre, "0000");
	midato.sexo= 'q';
	miRef1= crearNodo(midato);
	
	midato.edad= -20000;
	strcpy(midato.nombre, "0000");
	midato.sexo= 'e';
	miRef2= crearNodo(midato);
	
	miRef1->ptrSig= miRef2;
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

				meterDato(miRef1, miRef2, midato);

				break;
			case 2:
				printf("\n\tIndroduce el nombre que quieres buscar y quitar (cuidado con las mayusculas): ");
				fflush(stdin);
				gets(midato.nombre);
				fflush(stdin);

				sacarDato(miRef2, miRef1, midato);

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
		ptrN->ptrAnt=NULL;
		
	return ptrN;
}

void meterDato(struct nodo *ptrRef1, struct nodo *ptrRef2, struct Dato dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;

	ptrN= crearNodo(dato);

	if(ptrRef1->ptrSig== ptrRef2 && ptrRef2->ptrAnt== ptrRef1)
	{
		ptrN->ptrSig= ptrRef2;
		ptrRef1->ptrSig= ptrN;
		ptrRef2->ptrAnt= ptrN;
		ptrN->ptrAnt= ptrRef1;
	}
	else
	{
		ptr1= ptrRef1;
		ptr2= ptrRef1->ptrSig;
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
				ptrN->ptrAnt= ptr1;
				ptr2->ptrAnt= ptrN;
				return;
			}
			else
			{
				ptr1= ptr1->ptrSig;
				ptr2= ptr2->ptrSig;
			}
		}
		(ptr1->ptrAnt)->ptrSig= ptrN;
		ptrN->ptrAnt= ptr1->ptrAnt;
		ptr1->ptrAnt= ptrN;
		ptrN->ptrSig= ptr1;
	}
}

void sacarDato(struct nodo *ptrRef2, struct nodo *ptrRef1, struct Dato dato)
{
	struct nodo *ptrBasura, *ptrRecorrer;
	int bandera=0;
	
	ptrRecorrer= ptrRef2;
	
	if(ptrRef1->ptrSig== ptrRef2 && ptrRef2->ptrAnt== ptrRef1)
		printf("\nLa lista esta vacia!!");
	else
	{
		while(ptrRecorrer->ptrAnt!=NULL)
	    {
	        if(strcmp(ptrRecorrer->ptrAnt->dato.nombre, dato.nombre)==0)
	        {
	        	ptrBasura= ptrRecorrer->ptrAnt;
	            printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
					, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
		        ptrRecorrer->ptrAnt= ptrBasura->ptrAnt;
				(ptrBasura->ptrAnt)->ptrSig= ptrRecorrer;
								
	        	free(ptrBasura);
				bandera=1;
	            break;
	        }
	        else
	            ptrRecorrer = ptrRecorrer->ptrAnt;
	    }
		if(bandera!=1)
			printf("\nEl dato ingresado no fue encontrado.");
	}
}

void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2)
{
	struct nodo *ptrRecorrer;

	if(ptrRef1->ptrSig==ptrRef2 && ptrRef2->ptrAnt==ptrRef1)
		printf("\nSin contenido en la lista.");
	else
	{
		ptrRecorrer= ptrRef1->ptrSig;
		printf("\nEl contenido de la lista es: ");
		while(ptrRecorrer != ptrRef2)
		{
			printf("\n\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
				, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
	}
}
