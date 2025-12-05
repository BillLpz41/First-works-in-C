#include <stdio.h>
#include <stdlib.h>

char *crearCadena(int N);
void desplegarCadena(char *cadena);
void destruirCadena(char *cadena);

int main()
{
	char *texto=NULL;
	int N=100;
	
	texto= crearCadena(N);//crea un arreglo de N celdas para una cadena de texto
	
	printf("Ingresa una cadena: ");
	fflush(stdin);
	getline(&texto, &N, stdin);//se ingresa una cadena de texto
	
	printf("\nLa cadena ingresada es:\n");
	desplegarCadena(texto);//muestra el contenido del arreglo texto

	destruirCadena(texto);//libera la memoria del arreglo texto
	
	return 0;
}

char *crearCadena(int N)
{
	char *cad=NULL;
	
	cad= (char *) malloc(N*sizeof(char));
	
	return cad;//regresa el arreglo con la cadena de contenido
}

void desplegarCadena(char *cadena)
{
	int k=0;
	
	if(cadena==NULL)
		return;
		
	for(k=0; cadena[k]!='\0'; k++)
		printf("%c", cadena[k]);//imprime la celda k del arreglo
	printf("\n");
}

void destruirCadena(char *cadena)
{
	free(cadena);
}
