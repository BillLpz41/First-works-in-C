#include <stdio.h>
// Entrada desde el teclado hasta que se pulsa ENTER

int main()
{
	int car;
	
	while((car= getc(stdin)) != '\n')
		putchar(car);
	return 0;
}
