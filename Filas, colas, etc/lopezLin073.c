#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int m, int n);

int main()
{
	int base, expo;
	
	printf("Programa recursivo de la potencia m^n.");
	
	printf("\nIngresa el numero de la base (entero positivo): ");
	scanf("%d", &base);
	if(base<=0)
		printf("\nSolo se valen los numeros enteros positivos!");
	else
	{
		printf("\nIngresa el exponente: ");
		scanf("%d", &expo);
		printf("\nEl numero %d elevado a la %d es %d", base, expo, potencia(base, expo));
	}
	
	return 0;
}

int potencia(int m, int n)
{
	if(n==0)
		return 1;
	else
		return( m * potencia(m, n-1) );
}
