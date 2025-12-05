#include <stdio.h>
#include <stdlib.h>
//se establece que la matriz del argumento tendrá 8 columnas
void iniciarMatriz(int mat[][8], int N);//llena la matriz con ceros
void imprimirMatriz(int mat[][8], int N);//libera memoria

int main()
{
	int matriz[8][8];
	int pieza[8]={1, 4, 2, 3, 7, 0, 6, 5};
	int i=0, j=0, k=0, N=8;
	
	iniciarMatriz(matriz, N);
	
	printf("Contenido de la matriz al principio:\n");
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(i%2==0)
				matriz[i][j]=j%2;//si i es par, la casilla de la matriz tendrá el residuo de la mitad de j
			else
				matriz[i][j]= (j+1)%2;//si i es impar, la casilla de la matriz tendrá el residuo de la mitad de j+1
		}
	
	imprimirMatriz(matriz, N);
	
	printf("\nNuevo contenido de la matriz:\n");
	
	for(i=0, k=N; i<N; i++, k--)
	{
		j=pieza[k];//j adquiere el número del arreglo pieza en su posición k
		matriz[i][j]= k;//se coloca en determinada casilla de la matriz el valor de k
	}
	
	imprimirMatriz(matriz, N);
	
	free(matriz);
	
	return 0;
}
//mat= matriz; N= longitud de la fila de la matriz
void iniciarMatriz(int mat[][8], int N)
{
	int i=0, j=0;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			mat[i][j]=0;
}

void imprimirMatriz(int mat[][8], int N)
{
	int i=0, j=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}
