#include <stdio.h>
#include <stdlib.h>

struct persona{
	char nombre[30];
	int edad;
	float est;
	char sexo;
};

int main()
{	
	struct persona var1, *ptr;
	//meter en var1 con ->
	ptr= &var1;
	
	printf("\nIngresa nombre ");
	gets(ptr->nombre);
	
	printf("\nIngresa edad ");
	scanf("%d", &ptr->edad);
	
	printf("\nIngresa estatura ");
	scanf("%f", &ptr->est);

	fflush(stdin);
	printf("\nIngresa sexo ");
	ptr->sexo= getchar();
	
	printf("\nLa direccion de var1 es %lu y de ptr es %lu", &var1, &ptr);
	printf("\nEl nombre es %s y esta en la direccion %lu", ptr->nombre, &ptr->nombre);
	printf("\nLa edad es %d y esta en la direccion %lu", ptr->edad, &ptr->edad);
	printf("\nLa estatura es %.2f y esta en la direccion %lu", ptr->est, &ptr->est);
	printf("\nEl sexo es %c y esta en la direccion %lu", ptr->sexo, &ptr->sexo);
	
	return 0;
}
