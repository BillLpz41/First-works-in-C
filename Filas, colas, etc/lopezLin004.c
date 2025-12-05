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
	struct persona per1, per2;
	printf("\nEl tamanio de persona es %d", sizeof(struct persona));
	
	struct persona var1;
	//meter en var1 con .
	printf("\nIngresa nombre ");
	gets(var1.nombre);
	
	printf("\nIngresa edad ");
	scanf("%d", &var1.edad);
	
	printf("\nIngresa estatura ");
	scanf("%f", &var1.est);

	fflush(stdin);
	printf("\nIngresa sexo ");
	var1.sexo= getchar();
	
	printf("\nLa direccion de var1 es %lu", &var1);
	printf("\nEl nombre es %s y esta en la direccion %lu", var1.nombre, &var1.nombre);
	printf("\nLa edad es %d y esta en la direccion %lu", var1.edad, &var1.edad);
	printf("\nLa estatura es %.2f y esta en la direccion %lu", var1.est, &var1.est);
	printf("\nEl sexo es %c y esta en la direccion %lu", var1.sexo, &var1.sexo);
	
	return 0;
}
