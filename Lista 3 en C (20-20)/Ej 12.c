#include <stdio.h>
#include <stdlib.h>

float **crearMatriz(int M, int N);
void sumarMatrices(float **mZ, float **mX, float **mY, int M, int N);
void multiplicarMatrices(float **mZ, float **mX, float **mY, int M, int N);
void desplegarMatriz(float **matriz, int M, int N);
void destruirMatriz(float **matriz, int M);

int main()
{
	float **matrizA=NULL, **matrizB=NULL, **matrizC=NULL;
	int M=3, N=3;//M= filas; N= columnas
	//se crean las matrices de MxN con el mismo contenido
	matrizA= crearMatriz(M, N);
	matrizB= crearMatriz(M, N);
	matrizC= crearMatriz(M, N);
	
	printf("Matriz A:\n");
	desplegarMatriz(matrizA, M, N);//muestra el contenido de la matriz A
	
	printf("\nMatriz B:\n");
	desplegarMatriz(matrizB, M, N);//muestra el contenido de la matriz B
	
	printf("\nMatriz C:\n")
	desplegarMatriz(matrizC, M, N);//muestra el contenido de la matriz C
	
	sumarMatrices(matrizC, matrizA, matrizB, M, N);//la matriz C es la suma la matriz A con la matriz B
	printf("\nNueva matriz C (suma):\n");
	desplegarMatriz(matrizC, M, N);//muestra el nuevo contenido de la matriz C tras la suma
	
	multiplicarMatrices(matrizC, matrizA, matrizB, M, N);//la matriz C es el producto de la matriz A por la matriz B
	printf("\nNueva matriz C (multiplicacion):\n");
	desplegarMatriz(matrizC, M, N);//muestra el nuevo contenido de la matriz C tras la multplicacion
	//libera la memoria de las tres matrices
	destruirMatriz(matrizA, M);
	destruirMatriz(matrizB, M);
	destruirMatriz(matrizC, M);
	
	return 0;
}

float **crearMatriz(int M, int N)//doble apuntador porque será de dos dimensiones
{
	float **matriz= NULL;
	int i=0, j=0;
	
	matriz= (float **) malloc(M*sizeof(float *));//crea un arreglo horizontal de M celdas,
												//las cuales tendrán un arreglo vertical de N celdas
												//por eso el tamaño es de (float *)
	for(i=0; i<M; i++)
		matriz[i]= (float *) malloc(N*sizeof(float));//en la celda i se le crea un arreglo vertical de N celdas
													//como solo serán dos dimensiones, el tamaño es normal (float)
													//con esto, la estructura de la matriz estará hecha
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			matriz[i][j]= i*j;//el contenido es la multiplicacion del numero de fila y columna
	
	return matriz;//regresa la matriz
}

void sumarMatrices(float **mZ, float **mX, float **mY, int M, int N)
{
	int i=0, j=0;
	
	if(mZ==NULL || mX==NULL || mY==NULL)//si la matriz C, A o B es nula, se termina la función
		return;
		
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			mZ[i][j]= mX[i][j] + mY[i][j];//la casilla i,j de la matriz C es la suma de las celdas i,j de las otras dos matrices
}

void multiplicarMatrices(float **mZ, float **mX, float **mY, int M, int N)
{
	int i=0, j=0, k=0;
	
	if(mZ==NULL || mX== NULL || mY==NULL)
		return;
	
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
		{
			mZ[i][j]=0;//se sustituye el contenido de la casilla por un 0, así no interferirá en la suma
			for(k=0; k<N; k++)
				mZ[i][j]+= mX[i][k] * mY[k][j];//similar al producto punto, se van multplicando cada casilla
											//de la cada fila de la matriz A por cada celda de cada columna 
											//de la matriz B; y a esta multiplicación se le suma la casilla de la matriz C
		}
}

void desplegarMatriz(float **matriz, int M, int N)
{
	int i=0, j=0;
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
			printf("%.2f\t", matriz[i][j]);//imprime la celda i,j de la matriz
		printf("\n");
	}
	printf("\n");
}

void destruirMatriz(float **matriz, int M)
{
	int i=0;
	
	for(i=0; i<M; i++)
		free(matriz[i]);//primero libera la memoria de cada arreglo vertical del arreglo horizontal
	free(matriz);//termina de liberar la memoria del arreglo horizontal
}
