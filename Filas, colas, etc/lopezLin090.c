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
void meterDato(struct nodo **ptrRef1, struct nodo **ptrRef2, struct Dato dato);
void sacarDato(struct nodo **ptrRef2, struct nodo **ptrRef1, struct Dato dato);
void imprimirCont(struct nodo **ptrRef1, struct nodo **ptrRef2);

int main()
{
	struct nodo *miRef1, *miRef2, **ptrRef1, **ptrRef2;
	struct Dato midato;
	
	printf("Lista circular con dos doble apuntador y doble enlace (dato compuesto).");
	
	miRef1= NULL;
	miRef2= NULL;
	
	ptrRef1= &miRef1;
	ptrRef2= &miRef2;
	
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
				
				meterDato(ptrRef1, ptrRef2, midato);
				
				break;	
			case 2:
				printf("\n\tIndroduce el nombre que quieres buscar y quitar (cuidado con las mayusculas): ");
				fflush(stdin);
				gets(midato.nombre);
				fflush(stdin);

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

struct nodo *crearNodo(struct Dato dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrSig= NULL;
		ptrN->ptrAnt= NULL;
		
	return ptrN;
}

void meterDato(struct nodo **ptrRef1, struct nodo **ptrRef2, struct Dato dato)
{
	struct nodo *ptrN, *ptr1, *ptr2;
	
	ptrN= crearNodo(dato);
	
	if((*ptrRef1)== NULL && (*ptrRef2)== NULL)
	{
		*ptrRef1= ptrN;
		*ptrRef2= ptrN;
		(*ptrRef1)->ptrSig= *ptrRef1;
		(*ptrRef2)->ptrAnt= *ptrRef2;
	}
	else if(*ptrRef1== *ptrRef2)
	{
		if(strcmp((*ptrRef1)->dato.nombre, dato.nombre)==0)
		{
			printf("\nNo se permiten datos repetidos.");
			return;
		}
		else if(strcmp((*ptrRef1)->dato.nombre, dato.nombre)== -1)
		{
			(*ptrRef1)->ptrSig= ptrN;
			ptrN->ptrAnt= *ptrRef1;
			ptrN->ptrSig= *ptrRef1;
			(*ptrRef1)->ptrAnt= ptrN;
			*ptrRef2= ptrN;			
		}
		else if(strcmp((*ptrRef1)->dato.nombre, dato.nombre)== 1)
		{
			(*ptrRef1)->ptrAnt= ptrN;
			ptrN->ptrSig= *ptrRef1;
			ptrN->ptrAnt= *ptrRef2;
			(*ptrRef2)->ptrSig= ptrN;
			*ptrRef1= ptrN;
		}
	}
	else
	{
		ptr1= *ptrRef1;
		ptr2= (*ptrRef1)->ptrSig;
		while(ptr2 != *ptrRef1)
		{
			if(strcmp(ptr1->dato.nombre, dato.nombre)==0 && strcmp(ptr2->dato.nombre, dato.nombre)==0)
			{
				printf("\nNo se permiten datos repetidos.");
				return;
			}
			else if(strcmp(ptr1->dato.nombre, dato.nombre)==-1 && strcmp(dato.nombre, ptr2->dato.nombre)==-1)
			{
				ptr1->ptrSig= ptrN;
				ptrN->ptrAnt= ptr1;
				ptrN->ptrSig= ptr2;
				ptr2->ptrAnt= ptrN;
				return;
			}
			else if(strcmp(ptr1->dato.nombre, dato.nombre)==1 && strcmp(dato.nombre, ptr2->dato.nombre)==-1)
			{
				ptrN->ptrSig= ptr1;
				ptr1->ptrAnt= ptrN;
				*ptrRef1= ptrN;
				(*ptrRef1)->ptrAnt= *ptrRef2;
				(*ptrRef2)->ptrSig= *ptrRef1;
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
		(*ptrRef2)->ptrSig= *ptrRef1;
		(*ptrRef1)->ptrAnt= *ptrRef2;
	}
}

void sacarDato(struct nodo **ptrRef2, struct nodo **ptrRef1, struct Dato dato)
{
	struct nodo *ptrBasura, *ptrRecorrer, *ptr1, *ptr2;
	
	if((*ptrRef2)== NULL && (*ptrRef1)==NULL)
		printf("\nLa lista dinamica esta vacia...");
	else if(*ptrRef1== *ptrRef2 && strcmp((*ptrRef2)->dato.nombre, dato.nombre)==0)
	{
		ptrBasura= *ptrRef2;
		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
				, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
		free(ptrBasura);
		*ptrRef2=NULL;
		*ptrRef1=NULL;
		
		return;
	}
	else
	{
		ptrRecorrer= *ptrRef2;
		ptr1= (*ptrRef2)->ptrSig;
		ptr2= (*ptrRef2)->ptrAnt;
		
		while(ptr2 != *ptrRef2)
	    {
	    	if(strcmp(ptrRecorrer->ptrAnt->dato.nombre, dato.nombre)==0 && ptr2->ptrAnt== *ptrRef2)
	    	{
	    		ptrBasura= ptrRecorrer->ptrAnt;
	      		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
	          	*ptrRef1= ptrBasura->ptrSig;
				(*ptrRef2)->ptrSig= *ptrRef1; 
				(*ptrRef1)->ptrAnt= *ptrRef2;
				ptrRecorrer->ptrAnt=NULL;
					  				
	       		free(ptrBasura);
	       	    return;
			}
	        else if(strcmp(ptrRecorrer->dato.nombre, dato.nombre)==0)
	        {
	        	if(ptr1== *ptrRef2 && ptr2== *ptrRef2)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
	            	*ptrRef2= NULL;
					*ptrRef1= NULL;
					  				
	        		free(ptrBasura);
	        	    return;
				}
	        	else if(ptrRecorrer== *ptrRef2)
	        	{
	        		ptrBasura= ptrRecorrer;
	          		printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);
	            	*ptrRef2= ptrBasura->ptrAnt;
					(*ptrRef2)->ptrSig= *ptrRef1; 
					(*ptrRef1)->ptrAnt= *ptrRef2;
					ptrRecorrer=NULL;
					  				
	        		free(ptrBasura);
	        	    return;
				}
				else if(ptrRecorrer== *ptrRef1)
				{
					ptrBasura= ptrRecorrer;
					printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);	            	*ptrRef1= ptrBasura->ptrSig;
	            	(*ptrRef1)->ptrAnt= *ptrRef2;
	            	(*ptrRef2)->ptrSig= *ptrRef1;
	            	ptrRecorrer=NULL;
	            	
	        		free(ptrBasura);
					return;
				}
				else
				{
					ptrBasura= ptrRecorrer;
					printf("\nLos datos encontrados y sacados fueron:\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
						, ptrBasura->dato.nombre, ptrBasura->dato.edad, ptrBasura->dato.sexo);	            	ptr1->ptrAnt= ptr2;
	            	ptr2->ptrSig= ptr1;
					ptrRecorrer=NULL;
								
	        		free(ptrBasura);
					return;
				}
	        }
	        else if(ptr2== *ptrRef2 || ptrRecorrer== *ptrRef1)
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
			printf("\n\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
				, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
		printf("\n\n\tNombre: %s\n\tEdad: %d\n\tSexo: %c"
				, ptrRecorrer->dato.nombre, ptrRecorrer->dato.edad, ptrRecorrer->dato.sexo);
	}
}
