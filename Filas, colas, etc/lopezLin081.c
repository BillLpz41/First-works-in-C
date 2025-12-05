#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
};

int menu();
struct nodo *crearNodo(int dato);
void meterDato(struct nodo **ptrRef1, struct nodo **ptrRef2, int dato);
void sacarDato(struct nodo **ptrRef2, struct nodo **ptrRef1, int dato);
void imprimirCont(struct nodo **ptrRef1, struct nodo **ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2, **ptrRef1, **ptrRef2;
	int midato;

	printf("Lista en orden ascendente con dos doble apuntadores.");

	miRef1= NULL;
	miRef2= NULL;
	ptrRef1= &miRef1;
	ptrRef2= &miRef2;

	for(;;)
	{
		switch(menu())
		{
			case 1:
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);

				meterDato(ptrRef1, ptrRef2, midato);

				break;
			case 2:
				printf("\nIngresa el dato que quieres buscar y quitar: ");
				scanf("%d", &midato);

				sacarDato(ptrRef2, ptrRef1, midato);

				break;
			case 3:
				imprimirCont(ptrRef1, ptrRef2);

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
		ptrN->ptrAnt=NULL;
		
	return ptrN;
}

void meterDato(struct nodo **ptrRef1, struct nodo **ptrRef2, int dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;

	ptrN= crearNodo(dato);

	if(*ptrRef1==NULL && *ptrRef2==NULL)
	{
		*ptrRef1= ptrN;
		*ptrRef2= ptrN;
	}
	else if((*ptrRef1)->ptrAnt== NULL && (*ptrRef1)->ptrSig== NULL)
	{
		if((*ptrRef1)->dato == dato)
		{
			printf("\nNo se permiten datos repetidos.");
			return;
		}
		else if((*ptrRef1)->dato < dato)
		{
			(*ptrRef1)->ptrSig= ptrN;
			ptrN->ptrAnt= *ptrRef1;
			*ptrRef2= ptrN;
			return;
		}
		else if((*ptrRef1)->dato > dato)
		{
			(*ptrRef1)->ptrAnt= ptrN;
			ptrN->ptrSig= *ptrRef1;
			*ptrRef1= ptrN;
			ptrN= ptrN->ptrSig;
			return;
		}	
	}
	else
	{
		ptr1= *ptrRef1;
		ptr2= (*ptrRef1)->ptrSig;
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
				ptrN->ptrAnt= ptr1;
				ptrN->ptrSig= ptr2;
				ptr2->ptrAnt= ptrN;
				return;
			}
			else if(ptr1->dato > dato && dato < ptr2->dato)
			{
				ptrN->ptrSig= ptr1;
				ptr1->ptrAnt= ptrN;
				*ptrRef1= ptrN;
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
		ptrN->ptrAnt= ptr1;
		*ptrRef2= ptrN;
	}
}

void sacarDato(struct nodo **ptrRef2, struct nodo **ptrRef1, int dato)
{
	struct nodo *ptrBasura, *ptrRecorrer, *ptr1, *ptr2;
	
	if(*ptrRef1==NULL && *ptrRef2==NULL)
		printf("\nLa lista esta vacia!!");
	else
	{
		ptrRecorrer= *ptrRef2;
		ptr1= (*ptrRef2)->ptrSig;
		ptr2= (*ptrRef2)->ptrAnt;
		
		while(ptrRecorrer!=NULL)
	    {
	        if(ptrRecorrer->dato == dato)
	        {
	        	if(ptr1==NULL && ptr2==NULL)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	*ptrRef2= NULL;
					*ptrRef1= NULL;
					  				
	        		free(ptrBasura);
	        	    return;
				}
	        	else if(ptr1==NULL)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	*ptrRef2= ptrBasura->ptrAnt;
					(*ptrRef2)->ptrSig= NULL; 
					  				
	        		free(ptrBasura);
	        	    return;
				}
				else if(ptrRecorrer->ptrAnt==NULL)
				{
					ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	*ptrRef1= ptrBasura->ptrSig;
	            	(*ptrRef1)->ptrAnt= NULL;
	            	
	        		free(ptrBasura);
					return;
				}
				else
				{
					ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	ptr1->ptrAnt= ptr2;
	            	ptr2->ptrSig= ptr1;
								
	        		free(ptrBasura);
					return;
				}
	        }
	        else if(ptr2==NULL || ptrRecorrer== NULL)
	        	break;
	        else
	        {
	        	ptr1= ptrRecorrer;
	        	ptrRecorrer= ptr2;
	        	ptr2= ptr2->ptrAnt;
			}
	    }
		printf("\nEl dato ingresado no fue encontrado.");
	} 
}

void imprimirCont(struct nodo **ptrRef1, struct nodo **ptrRef2)
{
	struct nodo *ptrRecorrer;

	if(*ptrRef1==NULL && *ptrRef2==NULL)
		printf("\nSin contenido en la lista.");
	else
	{
		ptrRecorrer= *ptrRef1;
		printf("\nEl contenido de la lista es: ");
		while(ptrRecorrer != *ptrRef2)
		{
			printf("%d, ", ptrRecorrer->dato);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
		printf("%d", ptrRecorrer->dato);
	}
}
