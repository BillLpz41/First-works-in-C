#include <stdio.h>
//Lectura y escritura de un archivo a otro
 //usando buffer (línea por línea)

int main()
{
	puts("ingreso de texto desde un archivo usando read y un buffer (arreglo)\n)");
	
	char arreglo[40];
	FILE *ent, *sal;
	
	ent= fopen("prueba.txt", "r");
	sal= fopen("salida.txt", "w");
	
	while(fread(arreglo, sizeof(arreglo[40]), 3, ent) > 0)//lee de tres en tres
		fwrite(arreglo, sizeof(arreglo[40]), 3, sal);//imprime de tres en tres
	fclose(ent);
	fclose(sal);
	
	return 0;
}
