#include <stdio.h>
#include <stdlib.h>

#define EXITO 1
#define ERROR 0

char *crearCadena(int N);
int compararCadenas(char *cadena, char*cadenaB);
int invertirCadena(char *inversion, char *original);
void destruirCadena(char *cadena);

int main()
{
	char *texto0=NULL, *texto1=NULL, *cadena=NULL, *invertido=NULL;
	int diferencias=0, resultado=0;
	//se crean los arreglos para las cadenas
    int N=100;
	texto0= crearCadena(N);
	texto1= crearCadena(N);
	cadena= crearCadena(N);
	invertido= crearCadena(N);
	
	printf("Ingresa la primera cadena:\n");
    getline(&texto0, &N, stdin);
    
	printf("\nIngresa la segunda cadena:\n");
	getline(&texto1, &N, stdin);
	
	diferencias= compararCadenas(texto0, texto1);
	printf("\nHay %d diferencias entre la primera y segunda cadena.", diferencias);
	//imprime la cantidad de diferencias entre la primera y segunda cadena
	
	printf("\nIngresa la cadena que quieras invertir:\n");
	getline(&cadena, &N, stdin);
	
	resultado= invertirCadena(invertido, cadena);//la función devuelve un valor que determina si fue exitoso el proceso
	
	if(resultado==EXITO)//si resultado es 1
		printf("\nLa inversion de la cadena se realizo con exito.");
	else//si resultado es 0
		printf("\nLa inversion de la cadena fracaso.");
	
	printf("\n%s", invertido);//se imprime la cadena invertida
	//se libera memoria de todas las cadenas
	destruirCadena(texto0);
	destruirCadena(texto1);
	destruirCadena(cadena);
	destruirCadena(invertido);
	
	return 0;
}

char *crearCadena(int N)
{
	char *cad=NULL;
	
	cad= (char *) malloc(N*sizeof(char));
	
	return cad;
}

int compararCadenas(char *cadena, char *cadenaB)
{
	int i=0, j=0, aux=0;
	
	if(cadena==NULL || cadenaB==NULL)
		return 0;//si alguna de las dos cadenas es nula, se retorna 0
	//en caso de que una cadena sea más larga que otra, se tiene un comparador OR 
	for(i=0, j=0; cadena[i]!='\0' || cadenaB[j]!='\0'; i++, j++)
		if(cadena[i]!=cadenaB[j])//comprueba si las celdas son diferentes
			aux++;//por ser diferentes, se añade un 1 al contador aux, que será las diferencias
	
	return aux;//se retorna la cantidad de diferencias
}

int invertirCadena(char *inversion, char *original)
{
	int k=0, L=0;
	
	if(original==NULL)//si es nulo, se retorna 0
		return ERROR;
	
	for(k=0; original[k]!='\0'; k++);//se obtiene la longitud de la cadena
	L=k;
	
	for(k=0; k<L; k++)
		inversion[k]= original[L-(k+1)];//en el arreglo invertido, se coloca el caracter de la celda anterior al fin
										//de cadena, y luego el anterior a este
	inversion[L]='\0';//fin de cadena
	
	return EXITO;//retorna 1
}

void destruirCadena(char *cadena)
{
	free(cadena);
}
