#include <stdio.h>
#include <stdlib.h>
//se establece que el volumen del argumento tendrá 3 de largo y 3 de ancho 
void desplegarMatriz(int vol[][3][3], int N);//imprime en forma de matrices el contenido del volumen (impreso en partes)
void limpiarVolumen(int vol[][3][3]);//libera memoria

int main()
{
	int N=3;//tamñano del alto, largo y ancho del volumen
	int volumen[N][N][N];
	int i=0, j=0, k=0;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			for(k=0; k<N; k++)
				volumen[i][j][k]= i*j*k;//almacena el producto del valor del alto, largo y ancho
	
	printf("El contenido del volumen dividido por partes es:\n");
				
	desplegarMatriz(volumen, N);
	limpiarVolumen(volumen);
	
	return 0;
}

void desplegarMatriz(int vol[][3][3], int N)
{//imprime el volumen en N partes, tomando de referencia la altura
	int i=0, j=0, k=0;
	
	for(i=0; i<N; i++)
	{
		printf("i= %d\n", i);
		for(j=0; j<N; j++)
		{
			for(k=0; k<N; k++)
				printf("%d\t", vol[i][j][k]);
			printf("\n");
		}
			
		printf("\n");
	}
	
}

void limpiarVolumen(int vol[][3][3])
{
	free(vol);
}
