#include <stdio.h>
#include <stdlib.h>

void invertirCad(char *ptr, char *cad);

int main()
{
	char cadena[50], *ptr;
	
	printf("Programa recursivo para invertir una cadena.");
	
	printf("\nIngresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	fflush(stdin);
	
	ptr= cadena;
	
	printf("\nLa cadena invertida es: ");
	invertirCad(ptr, cadena);
	return 0;
}

void invertirCad(char *ptr, char *cad)
{
	if(*ptr=='\0')
		return;
	else
	{
		invertirCad(ptr+1, cad);
		putchar(*ptr);
	}
}
