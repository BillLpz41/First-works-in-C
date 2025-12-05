#include <stdio.h>
#include <stdlib.h>
//se establece que la matriz del argumento tendrá 3 columnas
void imprimirMatriz(int mat[][3], int N);
void escoba(int mat[][3]); //libera la memoria

int main()
{
	int N=3;
	int matA[N][N], matB[N][N], matC[N][N];
	int i=0, j=0, k=0;
	//se establecen los valores de las casillas de la matriz A
	matA[0][0]=1;
	matA[0][1]=7;
	matA[0][2]=5;
	
	matA[1][0]=8;
	matA[1][1]=4;
	matA[1][2]=0;
	
	matA[2][0]=3;
	matA[2][1]=6;
	matA[2][2]=3;
	
	printf("Matriz A:\n");
	imprimirMatriz(matA, N);
	//se establecen los valores de las casillas de la matriz B
	matB[0][0]=4;
	matB[0][1]=6;
	matB[0][2]=7;
	
	matB[1][0]=3;
	matB[1][1]=1;
	matB[1][2]=2;
	
	matB[2][0]=8;
	matB[2][1]=5;
	matB[2][2]=0;
	
	printf("\nMatriz B:\n");
	imprimirMatriz(matB, N);
	//las casillas de la matriz C adquieren el valor de la suma del producto punto entre matA y matB
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			matC[i][j]= 0;
			
			for(k=0; k<N; k++)
				matC[i][j]+= matA[i][k]*matB[k][j];//se realiza el producto punto
		}
	
	printf("\nMatriz C:\n");
	imprimirMatriz(matC, N);
	
	escoba(matA);
	escoba(matB);
	escoba(matC);
	
	return 0;
}
//mat= matriz A, B o C; N= longitud de la fila de la matriz
void imprimirMatriz(int mat[][3], int N)
{
	int i=0, j=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}

void escoba(int mat[][3])
{
	free(mat);
}
