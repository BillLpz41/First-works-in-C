#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

int menu();
struct nodo *crearNodo(int dato);
void meterDato(struct nodo ***ptrRef, int dato);
void sacarDato(struct nodo ***ptrRef, int dato);
void imprimirCont(struct nodo ***ptrRef);

int main()
{
	struct nodo *miRef1, **miRef2, ***miRef3;
	int midato;

	printf("Lista en orden ascendente con un triple apuntador.");

	miRef1= NULL;
	miRef2= &miRef1;
	miRef3= &miRef2;

	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);

				meterDato(miRef3, midato);

				break;
			case 2:
				printf("\nIngresa el dato que quieres buscar y quitar: ");
				scanf("%d", &midato);

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

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrN;

	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig=NULL;

	return ptrN;
}

void meterDato(struct nodo ***ptrRef, int dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;

	ptrN= crearNodo(dato);

	if(**ptrRef==NULL)
	{
		(**ptrRef)= ptrN;
		ptrN->ptrSig=NULL;
	}
	else if((**ptrRef)->ptrSig==NULL)
	{
		if((**ptrRef)->dato== dato)
		{
			printf("\nNo se permiten datos repetidos.");
			return;
		}
		else if(dato < (**ptrRef)->dato)
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
			if(ptr1->dato== dato && ptr2->dato== dato)
			{
				printf("\nNo se permiten datos repetidos.");
				return;
			}
			else if(ptr1->dato < dato && dato < ptr2->dato)
			{
				ptr1->ptrSig= ptrN;
				ptrN->ptrSig= ptr2;
				return;
			}
			else if(ptr1->dato > dato && dato < ptr2->dato)
			{
				ptrN->ptrSig= ptr1;
				**ptrRef= ptrN;
				ptrN= ptrN->ptrSig;
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

void sacarDato(struct nodo ***ptrRef, int dato)
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
	        if(ptrRecorrer->dato == dato)
	        {
	        	if(ptr1==NULL)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	**ptrRef= ptrRecorrer->ptrSig;
					           				
	        		free(ptrBasura);
	        	    return;
				}
				else
				{
					ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
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

	if(*ptrRef==NULL)
		printf("\nSin contenido en la lista.");
	else
	{
		ptrRecorrer= **ptrRef;
		printf("\nEl contenido de la lista es: ");
		while(ptrRecorrer != NULL)
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
	}
}
