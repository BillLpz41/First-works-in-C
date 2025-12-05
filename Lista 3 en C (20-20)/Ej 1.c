#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *arr= NULL;
	char *cadena= NULL;
	int N= 26, M= 100, k=0, q=0;
	char letra= 'A';//valor en ASCII de 65
	
	arr= (char *) malloc((N+1)*sizeof(char));//crea un arreglo de N+1 celdas (27)
	cadena= (char *) malloc((N+1)*sizeof(char));//son 27 celdas puesto que se añade el fin de cadena
	
	for(k=0; k<N; k++)
		arr[k]= letra + k;//se coloca la letra correspondiente en ASCII al sumarse con k
		
	arr[26]= '\0';//fin de cadena
	
	for(k=0; k<N; k++)
		printf("%c ", arr[k]);//imprime el abecedario celda por celda
	printf("\n%s\n", arr);//imprime el abecedario
	
	for(q=0, k=0; k<N; k+=2, q++)
		cadena[q]= arr[k];//coloca la letras que esten en celdas pares
	
	cadena[q]= '\0';//fin de cadena
	
	printf("%s\n", cadena);//imprime el arreglo cadena (letras del abecedario en posiciones pares)
	
	for(q=0, k=N-1; k>=0; k-=6, q++)
		cadena[q]=arr[k];//coloca la letra de la posicion multiplo de 6 empezando en la celda 25 ('Z')
		
	cadena[q]= '\0';//fin de cadena
	
	printf("%s\n", cadena);//imprime el abecedario comenzando en 'Z' y bajando de 6 en 6 hasta 'B'
	
	for(q=0; q<N; q++)
		arr[q]= arr[q+1];//coloca la letra de la posicion q+1; se omite la letra 'A'
		
	printf("%s\n", arr);//imprime el abecedario sin la primera letra
	//libera la memoria de los dos arreglos
	free(arr);
	free(cadena);
	
	return 0;
}
