#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define EXITO 1

char *crearCadena(int N);
int copiarCadenas(char *destino, char *fuente);
int concatenarCadenas(char *sol, char *cadA, char *cadB);
void imprimirResultado(int res);
void desplegarCadena(char *cadena);
void destruirCadena(char *cadena);

int main()
{
	char *cadena0=NULL, *copia=NULL;
	char *cadena1=NULL, *cadena2=NULL;
	int N=100, resultado=0;
	
	printf("Se procede a copiar una cadena...");

	cadena0= crearCadena(N);//se crea el arreglo para la primera cadena
	
	printf("\nIngresa el contenido de la primera cadena (la longitud debe ser la misma que la longitud contando el fin de cadena):\n");
	getline(&cadena0, &N, stdin);//se introduce la primerea cadena (cadena0) para su copia
	
	printf("\nLa cadena copiada es: ");
	resultado= copiarCadenas(copia, cadena0);//la funcion devuelve EXITO o ERROR segun sea el caso
	imprimirResultado(resultado);	//de acuerdo al valor del resultado, se imprime un texto en especifico
	
	printf("\nSe procede con concatenar dos cadenas...\n");
	
	cadena1= crearCadena(N);//se crea el arreglo para la segunda cadena
	
	printf("\nIngresa el contenido de la segunda cadena (la longitud debe ser la misma que la longitud contando el fin de cadena):\n");
	getline(&cadena1, &N, stdin);//se introduce la cadena1 para su concatenación
	
	printf("\nLa cadena concatenada es: ");
	resultado= concatenarCadenas(cadena2, cadena0, cadena1);//la funcion unirá la cadena0 con la cadena1 y 
												//cadena2 será la cadena concatenada; además, el valor de
	imprimirResultado(resultado);				//retorno determinará si la operacion fue un exito o fracaso
	//libera la memoria de todas las cadenas
	destruirCadena(cadena0);
	destruirCadena(copia);
	destruirCadena(cadena1);
	destruirCadena(cadena2);
	
	return 0;
}

char *crearCadena(int N)
{
	char *cad=NULL;
	
	cad= (char *) malloc(N*sizeof(char));
	
	return cad;
}

int copiarCadenas(char *destino, char *fuente)
{
	int k=0, L=0;
	
	if(fuente==NULL)
		return ERROR;//puesto que falló, retorna el valor de 0
	
	for(k=0; fuente[k]!='\0'; k++);//se obtiene la longitud de la cadena
	
	L=k;
	destino= crearCadena(L);//se reserva la memoria para el arreglo copia
	
	for(k=0; fuente[k]!='\0'; k++)
		destino[k]= fuente[k];//se coloca en la misma celda el contenido del arreglo original
		
	desplegarCadena(destino);//imprime la cadena copiada

	return EXITO;//puesto que todo salió bien, retorna el valor de 1
}

int concatenarCadenas(char *sol, char *cadA, char *cadB)
{
	int k=0, q=0, L=0, C=0;
	
	if(cadA==NULL || cadB==NULL)
		return ERROR;
	//se calcula la longitud de cada arreglo
	for(k=0; cadA[k]!='\0'; k++);
	L=k;
	
	for(k=0; cadB[k]!='\0'; k++);
	C=k;
	
	sol= crearCadena(L+C);//se crea un arreglo con la suma de las longitudes de ambas cadenas
	
	for(k=0, q=0; cadA[k]!='\0'; k++, q++)
		sol[q]= cadA[k];//se coloca cada caracter de la primera cadena en la cadena para concatenar
		
	sol[q-1]=' ';//se añade un espacio en la celda donde hubo un salto de linea
	//se suma un valor extra a q para que no sobreponga el caracter anterior
	for(k=0; cadB[k]!='\0'; k++, q++)//se mantiene el valor de q
		sol[q]= cadB[k];//se coloca cada caracter de la segunda cadena
	
	sol[q]='\0';
	desplegarCadena(sol);//imprime el contenido de la cadena concatenada
		
	return EXITO;	
}

void imprimirResultado(int res)
{
	if(res==ERROR)//si el resultado es 0
		printf("\nEl proceso fracaso\n");
	else if(res==EXITO)//si el resultado es 1
		printf("\nEl proceso fue existoso!!\n");
	else//si no es ninguno de los dos
		printf("\nHubo un fallo desconocido...\n");		
}

void desplegarCadena(char *cadena)
{
	int k=0;
	
	if(cadena==NULL)
		return;
	
	for(k=0; cadena[k]!='\0'; k++)
		printf("%c", cadena[k]);
	printf("\n");
}

void destruirCadena(char *cadena)
{
	free(cadena);
}
