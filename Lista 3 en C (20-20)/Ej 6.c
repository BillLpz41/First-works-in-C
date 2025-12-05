#include <stdio.h>
#include <stdlib.h>

char *crearArreglo(int N);
void relatar(char *cadena);
void concatenar(char *nuevo, char *prefijo, char *sufijo);
void redactar(char *texto, char *cadena);
void destruirArreglo(char *arr);

int main()
{
	char linea0[60]= "¿Encontraria a la Maga? ";
	char linea1[60]= "Andabamos sin buscarnos ";
	char linea2[60]= "pero sabiendo que andabamos para encontrarnos.";
	char linea3[60]= " Rayuela, Julio Cortazar.";
	char *rayuela= NULL;
	int k=0;
	
	rayuela= crearArreglo(339);//crea un arreglo de caracteres de 339 celdas
	
	concatenar(rayuela, linea0, linea1);//rayuela tiene la union de linea0 y linea1 (con un espacio entre ellos)
	relatar(rayuela);//imprime la cadena rayuela
	
	concatenar(rayuela, linea1, linea2);//rayuela es la union de linea1 y linea2 (sin linea0)
	relatar(rayuela);
	
	concatenar(rayuela, linea2, linea3);//rayuela es la union de linea2 y linea3 (sin linea1)
	relatar(rayuela);
	
	rayuela= crearArreglo(339);//volver a crear el arreglo para deshacerse de la cadena que tenia
	
	redactar(rayuela, linea0);//la cadena rayuela (que no tiene nada) se une con linea0
	redactar(rayuela, linea1);//la cadena rayuela (que tiene de contenido linea0) se une con linea1
	redactar(rayuela, linea2);//la cadena rayuela (que tiene de contenido linea1) se une con linea2
	redactar(rayuela, linea3);//la cadena rayuela (que tiene de contenido linea2) se une con linea3
	
	relatar(rayuela);//imprime el contenido de rayuela con todas las lineas unidas
	
	destruirArreglo(rayuela);//libera la memoria del arreglo
	
	return 0;
}

char *crearArreglo(int N)
{
	char *arr=NULL;
	
	arr=(char *) malloc(N*sizeof(char));
	
	return arr;
}

void relatar(char *cadena)
{
	int c=0;
	
	if(cadena==NULL)
		return;
		
	for(c=0; cadena[c]!='\0'; c++)
		printf("%c", cadena[c]);//imprime la celda k de la cadena
	printf("\n\n");
}

void concatenar(char *nuevo, char *prefijo, char *sufijo)
{
	int k=0, q=0;
	
	if(nuevo==NULL || prefijo==NULL || sufijo==NULL)//si alguno de los tres arreglos es nulo, se termina la funcion
		return;
		
	for(k=0, q=0; prefijo[k]!='\0'; k++, q++)
		nuevo[q]= prefijo[k];//coloca en la celda q del arreglo nuevo (rayuela) el caracter de la celda k
						
	for(k=0; sufijo[k]!='\0'; k++, q++)
		nuevo[q]= sufijo[k];//para lograr concatenar las dos cadenas, el arreglo nuevo empieza en la celda q,
						//el cual conserva su valor del ciclo anterior, y va añadiendo caracteres del otro arreglo
	nuevo[q]='\0';//se coloca el fin de cadena
}

void redactar(char *texto, char *cadena)
{
	int k=0, q=0;
	
	if(texto==NULL || cadena==NULL)
		return;
		
	for(q=0; texto[q]!='\0'; q++);//avanza el contador q para no sobreponer los otros caracteres
	
	for(k=0; cadena[k]!='\0'; k++, q++)//apartir de donde se quedó el contador q, se comienzan a colocar
		texto[q]= cadena[k];			//los caracteres de la celda k del arreglo cadena
										//de esta manera, se podrá concatenar ambas cadenas y las próximas
	texto[q]='\0';//fin de cadena
}

void destruirArreglo(char *arr)
{
	free(arr);
}
