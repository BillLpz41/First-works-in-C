#include <stdio.h>
#include <stdlib.h>

char *crearCadena(int N);
int buscarCaracter(char *cadena, char caracter);
int obtenerLongitudCadena(char *cadena);
void destruirCadena(char *cadena);

int main()
{
	char *frase=NULL;
	char letra;
	int posicion=0, longitud=0, N=100;
	
	frase= crearCadena(N);//se crea un arreglo de 100 celdas
	
	printf("Introduzca una palabra: ");
	getline(&frase, &N, stdin);//se introduce una cadena
	
	longitud= obtenerLongitudCadena(frase);//obtiene la longitud del arreglo
	
	printf("\nLa frase tiene una longitud de %d caracteres.", longitud);//se imprime la longitud del arreglo
	
	printf("\nIntroduce un caracter que quieras buscar en esa frase: ");
	scanf(" %c", &letra);//se introduce un caracter
	
	posicion= buscarCaracter(frase, letra);//devuelve la posición del caracter que se introdujo
	
	if(posicion>=0)//se comprueba si la posición es mayor o igual a 0 e imprime la posición		
		printf("\nLa primera coincidencia con el caracter '%c' fue en la posicion %d (comenzando desde la posicion 0).", letra, posicion);
	else//si no (la función devuelve -1), imprime que no se encontró el caracter 
		printf("\nEl caracter '%c' no se encuentra en la frase ingresada.", letra);

	destruirCadena(frase);//libera la memoria del arreglo

	return 0;
}

char *crearCadena(int N)
{
	char *cad=NULL;
	
	cad= (char *) malloc(N*sizeof(char));
	
	return cad;
}

int buscarCaracter(char *cadena, char caracter)
{
	int k=0;
	
	if(cadena==NULL)
		return;
	
	for(k=0; cadena[k]!='\0'; k++)
		if(cadena[k]==caracter)//comprueba si el caracter de la celda k de 'cadena' es igual al caracter que se busca
			return k;//si es así, se regresa el valor de k, que es la posición de ese caracter
			
	return -1;//si no se encuentra, regresa -1, dando a entender que ese caracter no está en esa cadena
}

int obtenerLongitudCadena(char *cadena)
{
	int k=0;
	
	if(cadena==NULL)
		return;
	
	for(k=0; cadena[k]!='\0'; k++);
	
	return k;	
}

void destruirCadena(char *cadena)
{
	free(cadena);
}
