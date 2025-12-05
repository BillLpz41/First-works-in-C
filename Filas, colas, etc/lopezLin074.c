#include <stdio.h>
#include <stdlib.h>

int longitudCad(char *ptr, char *cad);

int main()
{
	char cadena[50], *ptr;
	
	printf("Programa recursivo para la longitud de una cadena.");
	
	printf("\nIngresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	fflush(stdin);
	
	ptr= cadena;
	
	printf("\nLa longitud de la cadena ingresada es de %d", longitudCad(ptr, cadena));
	
	return 0;
}

int longitudCad(char *ptr, char *cad)
{
	if(*ptr == '\0')
		return ((int) (ptr - cad));
	else
		longitudCad(ptr+1, cad);
}
