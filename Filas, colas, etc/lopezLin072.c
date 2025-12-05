#include <stdio.h>
#include <stdlib.h>

int fact(int n);

int main()
{
	int num;
	
	printf("Programa recursivo del factorial de un numero.");
	
	printf("\nIngresa el numero que quieres conocer su factorial: ");
	scanf("%d", &num);
	printf("\nEl factorial de %d es %d", num, fact(num));
	
	return 0;
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return(n * fact(n-1));
}
