#include <stdio.h>

int main()
{
	char arreglo[80];
	
	puts("ingreso desde un archivo de texto en disco\n");
	
	FILE *ent, *sal;
	ent= fopen("prueba.txt", "r");
	sal= fopen("salida.txt", "w");
	while(!feof(ent))
	{
		fgets(arreglo, 80, ent);
		fprintf(sal, arreglo); //o puts(arreglo) para imprimir en consola; otra alternativa putc(arreglo, sal) para archivo
	}
	fclose(ent);
	
	return 0;
}
