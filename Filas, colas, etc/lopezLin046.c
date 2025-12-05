#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nodo{
	float dato;
	char op;
	struct nodo *ptrSig;	
};

int menu();
struct nodo *crearNodo(float dato, char op);
void meterDato(struct nodo **ptrRef, float dato, char op);
void calcularDato(struct nodo **ptrRef);
void imprimirCont(struct nodo **ptrRef);

int main()
{
	struct nodo *pila, **ptrPila;
	float midato; 
	int c;
	char operador;
	
	printf("Programa para calcular expresion en notacion postfija.");
	pila= NULL;
	ptrPila= &pila;
	
	meterDato(ptrPila, -10000, ')');
	meterDato(ptrPila, -10000, ')');
	for(;;)
	{
		switch(menu())
		{
			case 1:	
		    	printf("\nVas a ingresar un entero (1) o un operador (2)? ");
				scanf("%d", &c);
				if(c==1)
				{
					printf("\n\tIngresa el entero: ");
					fflush(stdin);
					scanf("%f", &midato);
					fflush(stdin);
					meterDato(ptrPila, midato, 'E');
				}
				else if(c==2)
				{
					printf("\n\tIngresa el operador: ");
					fflush(stdin);
					scanf("\n%c", &operador);
					fflush(stdin);
					meterDato(ptrPila, -1000, operador);
				}
				else
					printf("\n\tNumero invalido.");
				break;	
			case 2:
				calcularDato(ptrPila);
				
				break;	
			case 3:
				imprimirCont(ptrPila);
				
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
	
	printf("\n\nQue quieres hacer?");
	printf("\n1 introducir los datos (el primer dato es el ultimo).");
	printf("\n2 realizar operaciones (calcular).");
	printf("\n3 imprimir todos los datos y operadores.");
	printf("\n4 finalizar el programa.\n");
	scanf("%d", &c);

	return c;
}

struct nodo *crearNodo(float dato, char op)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= (struct nodo*) malloc(sizeof(struct nodo));
		ptrNuevo->dato= dato;
		ptrNuevo->op= op;
		ptrNuevo->ptrSig= NULL;
		
	return ptrNuevo;
}

void meterDato(struct nodo **ptrRef, float dato, char op)
{
	struct nodo *ptrNuevo;
	
	ptrNuevo= crearNodo(dato, op);
	if(*ptrRef==NULL)
		*ptrRef= ptrNuevo;
	else
	{
		ptrNuevo->ptrSig= *ptrRef;
		*ptrRef= ptrNuevo;
	}
}

void calcularDato(struct nodo **ptrRef)
{
	struct nodo *ptrBasura, *ptrOperador, *ptrB, *ptrA;
	float resultado=0.0;
	
	if((*ptrRef)->op==')')
		printf("\nNo hay datos ni operadores.");
	else
	{
		ptrB= *ptrRef;
		ptrA= ptrB->ptrSig;
		ptrOperador= ptrA->ptrSig;
		
		while(ptrOperador != NULL || ptrA != NULL || ptrB != NULL)
		{
			if(ptrOperador->op== '+')
			{
				resultado= ptrB->dato + ptrA->dato;
				ptrB->dato= resultado;
				
				(*ptrRef)->ptrSig= ptrB;				
				ptrB->ptrSig= ptrOperador->ptrSig;
				
				ptrBasura= ptrOperador;
				free(ptrBasura);
				ptrBasura= ptrA;
				free(ptrBasura);
				
				ptrB= *ptrRef;
				ptrA= ptrB->ptrSig;
				ptrOperador= ptrA->ptrSig;
				
			}
			else if(ptrOperador->op== '*')
			{
				resultado= ptrB->dato * ptrA->dato;
				ptrB->dato= resultado;
				
				(*ptrRef)->ptrSig= ptrB;				
				ptrB->ptrSig= ptrOperador->ptrSig;
				
				ptrBasura= ptrOperador;
				free(ptrBasura);
				ptrBasura= ptrA;
				free(ptrBasura);
				
				ptrB= *ptrRef;
				ptrA= ptrB->ptrSig;
				ptrOperador= ptrA->ptrSig;
			}
			else if(ptrOperador->op== '-')
			{
				resultado= ptrB->dato - ptrA->dato;
				ptrB->dato= resultado;
				
				(*ptrRef)->ptrSig= ptrB;				
				ptrB->ptrSig= ptrOperador->ptrSig;
				
				ptrBasura= ptrOperador;
				free(ptrBasura);
				ptrBasura= ptrA;
				free(ptrBasura);
				
				ptrB= *ptrRef;
				ptrA= ptrB->ptrSig;
				ptrOperador= ptrA->ptrSig;
			}
			else if(ptrOperador->op== '/')
			{
				resultado= ptrB->dato / ptrA->dato;
				ptrB->dato= resultado;
				
				(*ptrRef)->ptrSig= ptrB;				
				ptrB->ptrSig= ptrOperador->ptrSig;
				
				ptrBasura= ptrOperador;
				free(ptrBasura);
				ptrBasura= ptrA;
				free(ptrBasura);
				
				ptrB= *ptrRef;
				ptrA= ptrB->ptrSig;
				ptrOperador= ptrA->ptrSig;
			}
			else if(ptrOperador->op== '^')
			{
				resultado= pow(ptrB->dato, ptrA->dato);
				ptrB->dato= resultado;
				
				(*ptrRef)->ptrSig= ptrB;				
				ptrB->ptrSig= ptrOperador->ptrSig;
				
				ptrBasura= ptrOperador;
				free(ptrBasura);
				ptrBasura= ptrA;
				free(ptrBasura);
				
				ptrB= *ptrRef;
				ptrA= ptrB->ptrSig;
				ptrOperador= ptrA->ptrSig;
			}
			else if(ptrOperador->op== ')' || ptrA->op==')' || ptrB->op== ')')
			{
				printf("\nEl resultado de la operacion es: %f", resultado);
		    	printf("\n\nDebido a fuerzas desconocidas, el programa termina aqui :D");
		    	exit(0);
			}
			else
			{
				ptrB= ptrB->ptrSig;
				ptrA= ptrA->ptrSig;
				ptrOperador= ptrOperador->ptrSig;
			}
		}
	}
}

void imprimirCont(struct nodo **ptrRef)
{
	struct nodo *ptrRecorrer;
	
	if((*ptrRef)->op==')')
		printf("\nNo hay nada que mostrar.");
	else
	{
		ptrRecorrer= *ptrRef;
		printf("\nLa operacion que ingresaste fue: ");
		while(ptrRecorrer->op != ')')
		{
			if(ptrRecorrer->dato>=0 && ptrRecorrer->op == 'E')
				printf("%.1f, ", ptrRecorrer->dato);
			else
				printf("%c, ", ptrRecorrer->op);
			ptrRecorrer= ptrRecorrer->ptrSig;
		}
	}
	
}
