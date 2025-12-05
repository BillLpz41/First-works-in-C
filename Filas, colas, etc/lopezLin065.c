#include <stdio.h>

//Entrada desde el teclado usando entrada estandar
int main()
{
	int car;
	
	while((car= getchar()) != '\n')
		putchar(car);
	return 0;
}
