#include <stdio.h>
#include <stdlib.h>

void arbolBinario(int nivel, int nodo, int limite);
void arbolBaseB(int nivel, int nodo, int limite, int base);

int main()
{
	int N=0, n=0, lim=0, base=0;//N= nivel, n= nodo, lim= profundidad de arbol, base= base numerica del arbol
	
	printf("Cuantos niveles (profundidad) del arbol quieres (para ambos arboles)? ");
	scanf("%d", &lim);
	printf("\n\n");
	
	arbolBinario(N, n, lim);//genera un arbol binario de profundidad 'lim'
	
	printf("\n\n\nDe que base quieres el segundo arbol? ");
	scanf("%d", &base);
	printf("\n");
	
	arbolBaseB(N, n, lim, base);//genera un arbol de base b con profundidad 'lim'
	
	return 0;
}

void arbolBinario(int nivel, int nodo, int limite)
{
	int k=0;
	
	if(nivel>=limite)//si el nivel es mayor o igual al limite, acaba la funcion
		return;
	
	for(k=0; k<nivel; k++)//genera espacios de acuerdo al nivel del arbol
		printf("\t");
		
	printf("nivel= %d, nodo= %d\n", nivel ,nodo);//imprime el nivel del arbol y su nodo
	
	arbolBinario(nivel+1, 2*nodo+0, limite);//crea las ramas del arbol con nodo 0
	arbolBinario(nivel+1, 2*nodo+1, limite);//crea las ramas del arbol con nodo 1
}

void arbolBaseB(int nivel, int nodo, int limite, int base)
{
	int k=0;
	
	if(nivel>=limite)
		return;
		
	for(k=0; k<nivel; k++)
		printf("\t");
		
	printf("nivel= %d, nodo %d\n", nivel, nodo);
	
	for(k=0; k<base; k++)
		arbolBaseB(nivel+1, base*nodo+k, limite, base);//crea las ramas del arbol partiendo del nodo 0 en el nivel 0
													//y luego desglosando niveles hasta 'base'^lim-1 nodos
													//por cada nivel se sigue la sucesion de nodos del anterior nivel		
}
