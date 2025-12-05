#include <stdio.h>
//Entrada desde un archivo de disco y se envia a pantalla

int main()
{
	int car;
	
	FILE *ent;
	//El archivo prueba.txt debe existir
	// en el directorio de trabajo y se envia a pantalla
	
	ent= fopen("prueba.txt", "r");
	while((car= getc(ent)) != EOF)//End Of File; fin de archivo
		putchar(car);
	fclose(ent);
	
	return 0;
}
