#include <stdio.h>
#include <stdlib.h>

void moverDisco(char dest, char aux, char fte, int N, int *cont);

int main()
{
	char fuente= 'A', auxiliar= 'B', destino= 'C';//torres
	int N= 0, contador= 0;//N= cantidad de discos, contador= numero de movimiento de disco
	
	printf("Cuantos discos hay? ");
	scanf("%d", &N);
	
	moverDisco(destino, auxiliar, fuente, N, &contador);//inicia la recursión
	
	return 0;
}

void moverDisco(char dest, char aux, char fte, int N, int *cont)
{
	if(N==0)//si no hay discos, se termina la funcion
		return;
		
	moverDisco(aux, dest, fte, N-1, cont);//mueve el primer disco (el que esté más arriba) de la torre fuente hasta  
										//la torre auxiliar teniendo como ayuda la torre destino.
										//los terminos de torre fuente, auxiliar y destino cambian dependiendo
										//de qué disco se mueva y en qué torre se encuentre
	printf("%d. Mover disco %d: de %c a %c\n", *cont, N, fte, dest);//imprime qué paso es, qué disco es, y
																//a qué torre mueve el disco 
	
	(*cont)++;//aumenta el valor del contador para el siguiente paso
	
	moverDisco(dest, fte, aux, N-1, cont);//termina de mover el disco de la torre auxiliar hasta la torre destino
										//usando como apoyo la torre fuente
}
