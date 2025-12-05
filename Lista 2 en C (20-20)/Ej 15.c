#include <stdio.h>
#include <stdlib.h>
//se establece que la matriz del argumento tendrá 10 columnas
void iniciarMatriz(int mat[][10], int N);//llena la matriz con ceros
void imprimirMatriz(int mat[][10], int N);//libera la memoria

int main()
{
	int matriz[10][10];
	int i=0, j=0, N=10;
	
	iniciarMatriz(matriz, N);
	
	printf("Matriz del primer ciclo doble:\n");
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			matriz[i][j]= i*j;//multiplicación de fila con columna
	
	imprimirMatriz(matriz, N);
	
	printf("Matriz del segundo ciclo doble:\n");
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			matriz[i][j]=i+j;//suma de fila con columna
			
	imprimirMatriz(matriz, N);

	free(matriz);
	
	return 0;
}
//mat= matriz; L= longitud de la fila de la matriz
void iniciarMatriz(int mat[][10], int N)
{
	int i=0, j=0;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			mat[i][j]=0;
}

void imprimirMatriz(int mat[][10], int N)
{
	int i=0, j=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}
