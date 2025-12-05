#include <stdio.h>
//Lectura de un archivo usando caracter por caracter con fread
int main()
{
	puts("Ingreso de texto desde un archivo con read\n");
	
	char c;
	FILE *ent, *sal;
	
	ent= fopen("prueba.txt", "r");
	sal= fopen("salida.txt", "w");// para ponerlo en un directorio aparte, se usa . (directorio actual)
								//y .. directorio padre (subir de directorio); en windows se usa \\ para separar directorios
	while(fread(&c, sizeof c, 1, ent) > 0)
		putc(c, sal);//imprimir en el archivo de salida caracter por caracter
		//putchar(c) imprimir uno por uno en consola
	fclose(ent);
	
	return 0;
}
