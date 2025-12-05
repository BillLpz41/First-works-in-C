#include <stdio.h>
// salida a pantalla usando salida estandar
int main()
{
	char arreglo[15]= "\nHola mundo";
	char *ptr= arreglo;
	// enviamos cadena a salida estandar y de error estandar
	puts(arreglo);
	fputs(arreglo, stdout);
	fputs(arreglo, stderr);
	
	printf("\nadios mundo1");
	fprintf(stdout, "\nadios mundo2");
	fprintf(stderr, "\nadios mundo3");
	
	puts(ptr);
	fputs(ptr, stdout);
	fputs(ptr, stderr);
	
	return 0;	
}
