#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;	
};

int menu();
struct nodo *crearNodo(int dato);
void meterDato(struct nodo *ptrRef1, struct nodo *ptrRef2, int dato);
void sacarDato(struct nodo *ptrRef2, struct nodo *ptrRef1, int dato);
void imprimirCont(struct nodo *ptrRef1, struct nodo *ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2;
	int midato;
	
	printf("Lista circular con doble cabecera y dato simple y doble enlace.");
	
	miRef1= crearNodo(-1000);
	miRef2= crearNodo(-2000);
	
	miRef1->ptrSig= miRef2;
	miRef1->ptrAnt= miRef2;
	miRef2->ptrSig= miRef1;
	miRef2->ptrAnt= miRef1;
	
	for(;;)
	{
		switch(menu())
		{
			case 1:	
				printf("\nIngresa un entero: ");
				scanf("%d", &midato);
				
				meterDato(miRef1, miRef2, midato);
				
				break;	
			case 2:
				printf("\nIngresa el dato que quieres buscar y quitar: ");
				scanf("%d", &midato);

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

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterDato(struct nodo *ptrRef1, struct nodo *ptrRef2, int dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;
	
	ptrN= crearNodo(dato);
	
	if(ptrRef1->ptrSig== ptrRef2 && ptrRef2->ptrAnt== ptrRef1)
	{
		ptrN->ptrAnt= ptrRef1;
		ptrN->ptrSig= ptrRef2;
		ptrRef1->ptrSig= ptrN;
		ptrRef2->ptrAnt= ptrN;
	}
	else
	{
		ptr1= ptrRef1;
		ptr2= ptrRef1->ptrSig;
		while(ptr2 != ptrRef2)
		{
			if(ptr1->dato== dato && ptr2->dato==dato)
			{
				printf("\nNo se permiten datos repetidos.");
				return;
			}
			else if(ptr1->dato< dato && dato< ptr2->dato)
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
		ptr1->ptrSig= ptrN;
		ptrN->ptrAnt= ptr1;
		ptrN->ptrSig= ptrRef2;
		ptrRef2->ptrAnt= ptrN;
	}
}

void sacarDato(struct nodo *ptrRef2, struct nodo *ptrRef1, int dato)
{
	struct nodo *ptrBasura, *ptrRecorrer, *ptr1, *ptr2;
	
	if(ptrRef2->ptrAnt== ptrRef1 && ptrRef1->ptrSig== ptrRef2)
		printf("\nLa lista dinamica esta vacia...");
	else
	{
		ptrRecorrer= ptrRef2;
		ptr1= ptrRef2->ptrSig;
		ptr2= ptrRef2->ptrAnt;
		
		while(ptrRecorrer!= ptrRef1)
	    {
	        if(ptrRecorrer->dato == dato)
	        {
	        	if(ptr1== ptrRef2 && ptr2== ptrRef1)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	ptrRef2->ptrAnt= ptrRef1;
					ptrRef1->ptrSig= ptrRef2;  				
					  				
	        		free(ptrBasura);
	        	    return;
				}
	        	else if(ptr1== ptrRef2)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	ptrRef2->ptrAnt= ptrBasura->ptrAnt;
	            	(ptrBasura->ptrAnt)->ptrSig= ptrRef2;					
					  				
	        		free(ptrBasura);
	        	    return;
				}
				else if(ptrRecorrer->ptrAnt== ptrRef1)
				{
					ptrBasura= ptrRecorrer;
	          		printf("\nEl dato encontrado y sacado fue: %d", ptrBasura->dato);
	            	ptrRef1->ptrSig= ptrBasura->ptrSig;
	            	(ptrBasura->ptrSig)->ptrAnt= ptrRef1;
	            	
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
	        else if(ptr2== ptrRef2 || ptrRecorrer== ptrRef1)
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
			printf("%d, ", ptrRecorrer->dato);
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
