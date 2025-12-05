#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int contenido;
	struct nodo *ptrIzq;
	struct nodo *ptrDer;
};

struct nodo *crearNodo(int dato);
void insertarNodo(struct nodo **ptrRaiz, int dato);
void imprimirInorden(struct nodo **ptrRaiz);
void imprimirPreorden(struct nodo **ptrRaiz);
void imprimirPostorden(struct nodo **ptrRaiz);
void imprimirArbol(struct nodo **ptrRaiz, int contador);
int menu();

int main()
{
	struct nodo *raiz, **ptrRaizBase;
	int dato;
	
	printf("Programa de arbol binario en inorden, preorden y postorden.");
	
	raiz= NULL;
	ptrRaizBase= &raiz;
	
	for(;;)
	{
		switch(menu())
		{	
			case 1:
				printf("\nIntroduce un entero: ");
				scanf("%d", &dato);
				insertarNodo(ptrRaizBase, dato);
				
				break;
			case 2:
				printf("\nContenido impreso en preorden:");
				imprimirPreorden(ptrRaizBase);
				
				break;
			case 3:
				printf("\nContenido impreso en inorden:");
				imprimirInorden(ptrRaizBase);
				
				break;
				
			case 4:
				printf("\nContenido impreso en postorden:");
				imprimirPostorden(ptrRaizBase);
				
				break;
			
			case 5:	
				printf("\nImpreso: ");
				imprimirArbol(ptrRaizBase, 1);
				
				break;
			case 6:
				exit(0);
			default:
				printf("\nIngresa un numero valido.\n");
		}
	}

	return 0;
}

struct nodo *crearNodo(int dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
	ptrN->contenido= dato;
	ptrN->ptrDer= NULL;
	ptrN->ptrIzq= NULL;
	
	return ptrN;
}

void insertarNodo(struct nodo **ptrRaiz, int dato)
{
	if(*ptrRaiz==NULL)
		*ptrRaiz= crearNodo(dato);
	else if( ((*ptrRaiz)->contenido) > dato)
		insertarNodo( &((*ptrRaiz)->ptrIzq), dato);
	else
		insertarNodo( &((*ptrRaiz)->ptrDer), dato);
}

void imprimirPreorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		printf("\n\tDato: %d", (*ptrRaiz)->contenido);
		imprimirPreorden( &((*ptrRaiz)->ptrIzq));
		imprimirPreorden( &((*ptrRaiz)->ptrDer));
	}
}

void imprimirInorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		imprimirInorden( &((*ptrRaiz)->ptrIzq));
		printf("\n\tDato: %d", (*ptrRaiz)->contenido);
		imprimirInorden( &((*ptrRaiz)->ptrDer));
	}
}

void imprimirPostorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		imprimirPostorden( &((*ptrRaiz)->ptrIzq));
		imprimirPostorden( &((*ptrRaiz)->ptrDer));
		printf("\n\tDato: %d", (*ptrRaiz)->contenido);
	}
}

void imprimirArbol(struct nodo **ptrRaiz, int contador)
{
	int i, j;
	i= contador;
	
	if(*ptrRaiz!=NULL)
	{
		imprimirArbol(&((*ptrRaiz)->ptrDer), i+1);
		printf("\n");
		for(j=1; j<i; j++)
			printf(" - ");
		printf(" %d ", (*ptrRaiz)->contenido);
		imprimirArbol( &((*ptrRaiz)->ptrIzq), i+1);
	}
}

int menu()
{
	int c=0;
	
	printf("\n\nMenu de funciones:");
	printf("\nIngresa 1 para introducir datos.");
	printf("\nIngresa 2 para imprimir en inorden.");
	printf("\nIngresa 3 para imprimir en preorden.");
	printf("\nIngresa 4 para imprimir en postorden.");
	printf("\nIngresa 5 para imprimir el arbol.");
	printf("\nIngresa 6 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}
