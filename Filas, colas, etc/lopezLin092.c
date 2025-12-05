#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	int bal;
	struct nodo *ptrIzq;
	struct nodo *ptrDer;
};

int menu();

int maximo(int a, int b);//
int altura(struct nodo *ptr);//
struct nodo* nuevoNodo(int dato);//
void insertar(struct nodo **ptrRaiz, int dato);//
struct nodo* balancear(struct nodo **ptrRaiz, int contador);
void imprimirArbol(struct nodo **ptrRaiz, int contador);//
void preorden(struct nodo **ptrRaiz);//
void inorden(struct nodo **ptrRaiz);//
void postorden(struct nodo **ptrRaiz);//
void eliminar(struct nodo **ptr, int clave);
void calculaAltura(struct nodo *p);//
int maxProfundidad(struct nodo **ptrRaiz);//
void buscarDato(struct nodo **ptr, int clave);
struct nodo* rotaDerecha(struct nodo **ptr);//
struct nodo* rotaIzquierda(struct nodo **ptr);//

int main()
{
	struct nodo *raiz, **ptrRaizBase;
	int dato;
	
	printf("Programa de arbol binario con rotaciones.");
	
	raiz= NULL;
	ptrRaizBase= &raiz;
	
	for(;;)
	{
		switch(menu())
		{	
			case 1:
				printf("\nIntroduce un entero: ");
				scanf("%d", &dato);
				insertar(ptrRaizBase, dato);
				break;
			case 2:
				printf("\nContenido impreso en preorden:");
				preorden(ptrRaizBase);
				break;
			case 3:
				printf("\nContenido impreso en inorden:");
				inorden(ptrRaizBase);
				break;
			case 4:
				printf("\nContenido impreso en postorden:");
				postorden(ptrRaizBase);
				break;
			case 5:	
				printf("\nArbol Impreso: ");
				imprimirArbol(ptrRaizBase, 1);
				break;
			case 6:
				printf("\nArbol rotado hacia la derecha:");
				rotaDerecha(ptrRaizBase);
				break;
			case 7:
				printf("\nArbol rotado hacia la izquierda:");
				rotaIzquierda(ptrRaizBase);
				break;
			case 8:
				printf("\nLa profundidad es: %d", maxProfundidad(ptrRaizBase));
				break;
			case 9:	
				exit(0);
				break;
			default:
				printf("\nIngresa un numero valido.\n");
		}
	}
	return 0;
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
	printf("\nIngresa 6 para rotar hacia la derecha.");
	printf("\nIngresa 7 para rotar hacia la izquierda.");
	printf("\nIngresa 8 para calcular la maxima profundidad.");
	printf("\nIngresa 9 para finalizar programa.\n");
	scanf("%d", &c);

	return c;
}

struct nodo* nuevoNodo(int dato)
{
	struct nodo *ptrN;
	
	ptrN= (struct nodo*) malloc(sizeof(struct nodo));
		ptrN->dato= dato;
		ptrN->ptrDer=NULL;
		ptrN->ptrIzq=NULL;		
	
	return ptrN;
}

int maximo(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int altura(struct nodo *ptr)
{
	if(ptr== NULL)
		return 0;
	else
		return (ptr->bal);
}

void insertar(struct nodo **ptrRaiz, int dato)
{
	if(*ptrRaiz==NULL)
		*ptrRaiz= nuevoNodo(dato);
	else if( ((*ptrRaiz)->dato) > dato)
		insertar( &((*ptrRaiz)->ptrIzq), dato);
	else
		insertar( &((*ptrRaiz)->ptrDer), dato);
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
		printf(" %d ", (*ptrRaiz)->dato);
		imprimirArbol( &((*ptrRaiz)->ptrIzq), i+1);
	}
}

void preorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		printf("\n\tDato: %d", (*ptrRaiz)->dato);
		preorden( &((*ptrRaiz)->ptrIzq));
		preorden( &((*ptrRaiz)->ptrDer));
	}
}

void inorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		inorden( &((*ptrRaiz)->ptrIzq));
		printf("\n\tDato: %d", (*ptrRaiz)->dato);
		inorden( &((*ptrRaiz)->ptrDer));
	}
}

void postorden(struct nodo **ptrRaiz)
{
	if(*ptrRaiz!=NULL)
	{
		postorden( &((*ptrRaiz)->ptrIzq));
		postorden( &((*ptrRaiz)->ptrDer));
		printf("\n\tDato: %d", (*ptrRaiz)->dato);
	}
}

void calculaAltura(struct nodo *p)
{
	p->bal= 1 + maximo(altura(p->ptrIzq), altura(p->ptrDer));
}

int maxProfundidad(struct nodo **ptrRaiz)
{
	int profIzq, profDer;
	
	if(ptrRaiz==NULL)
		return 0;
	else
	{
		profIzq= maxProfundidad(&(*ptrRaiz)->ptrIzq);
		profDer= maxProfundidad(&(*ptrRaiz)->ptrDer);
	
		if(profIzq > profDer)
			return (profIzq+1);
		else
			return (profDer+1);
	}
}

struct nodo* rotaDerecha(struct nodo **ptr)
{
	struct nodo *temp;
	
	temp= (*ptr)->ptrIzq;
	(*ptr)->ptrIzq= temp->ptrDer;
	temp->ptrDer= *ptr;
	calculaAltura(*ptr);
	calculaAltura(temp);
	
	return temp;
}

struct nodo* rotaIzquierda(struct nodo **ptr)
{
	struct nodo *temp;
	
	temp= (*ptr)->ptrDer;
	(*ptr)->ptrDer= temp->ptrIzq;
	temp->ptrIzq= *ptr;
	calculaAltura(*ptr);
	calculaAltura(temp);
	
	return temp;
}

