#include <stdio.h>
#include <stdlib.h>
//Version apuntador.
struct persona{
	char nombre[50];
	int edad;
	float est;
	char sexo;
	char sangre[3];
};

int main()
{
	int L= 3;
	struct persona perfiles[L];
	struct persona *ptr1;
	struct persona **ptr2;
	int i=0;
	char letra=' ';
	int pos=0, edad=0, c=0;
	
	ptr1= perfiles;
	
	printf("Version con apuntadores...\n");
	for(ptr2= &ptr1; *ptr2 < &perfiles[L]; (*ptr2)++)
	{
		printf("\n**** Persona/Celda %d ****", (int) (*ptr2-perfiles));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets((*ptr2)->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &(*ptr2)->edad);
		
		printf("\n\tIngresa la estatura: ");
		scanf("%f", &(*ptr2)->est);
		
		printf("\n\tIngresa el sexo: ");
		fflush(stdin);
		(*ptr2)->sexo= getchar();
		
		printf("\n\tIngresa el tipo de sangre: ");
		fflush(stdin);
		gets((*ptr2)->sangre);
		fflush(stdin);
	}
	
	printf("\n\nIngresa la letra que debe tener los nombres: ");
	fflush(stdin);
	letra= getchar();

	printf("\nQuieres buscar el nombre por la posicion de la letra? Si (1)/No (0): ");
	scanf("%d", &c);
	
	ptr1=perfiles;

	if(c==0)
	{
		printf("\nIngresa la edad de las personas que quieres buscar: ");
		scanf("%d", &edad);
	
		for(ptr2=&ptr1; *ptr2 < &perfiles[L]; (*ptr2)++)
		{
			for(i=0; (*ptr2)->nombre[i]!='\n'; i++)
				if(((*ptr2)->nombre[i]==letra || (*ptr2)->nombre[i]==(letra+32) || (*ptr2)->nombre[i]==(letra-32)) && (((*ptr2)->edad) >= edad))
				{
					printf("\n\n======Sujeto encontrado en la celda %d", (int) (*ptr2-perfiles));
					printf("\n\tNombre: %s / en la direccion %lu", (*ptr2)->nombre, &(*ptr2)->nombre);
					printf("\n\tEdad: %d / en la direccion %lu", (*ptr2)->edad, &(*ptr2)->edad);
					printf("\n\tEstatura: %.2f / en la direccion %lu", (*ptr2)->est, &(*ptr2)->est);
					printf("\n\tSexo: %c / en la direccion %lu", (*ptr2)->sexo, &(*ptr2)->sexo);
					printf("\n\tTipo de sangre: %s / en la direccion %lu", (*ptr2)->sangre, &(*ptr2)->sangre);
					break;
				}
		}
		printf("\n\nNo se encontraron mas coincidencias.");
		
		return 0;
	}
	
	printf("\nIngresa la posicion de esa letra en el nombre (posicion 0 es la primera letra del nombre): ");
	scanf("%d", &pos);
	
	printf("\nIngresa la edad de las personas que quieres buscar: ");
	scanf("%d", &edad);
	
	for(ptr2=&ptr1; *ptr2 < &perfiles[L]; (*ptr2)++)
	{
		for(i=0; i<pos+1; i++)
			if(((*ptr2)->nombre[i]==letra || (*ptr2)->nombre[i]==(letra+32) || (*ptr2)->nombre[i]==(letra-32)) && (((*ptr2)->edad) >=edad))
			{
				printf("\n\n======Sujeto encontrado en la celda %d", (int) (*ptr2-perfiles));
				printf("\n\tNombre: %s / en la direccion %lu", (*ptr2)->nombre, &(*ptr2)->nombre);
				printf("\n\tEdad: %d / en la direccion %lu", (*ptr2)->edad, &(*ptr2)->edad);
				printf("\n\tEstatura: %.2f / en la direccion %lu", (*ptr2)->est, &(*ptr2)->est);
				printf("\n\tSexo: %c / en la direccion %lu", (*ptr2)->sexo, &(*ptr2)->sexo);
				printf("\n\tTipo de sangre: %s / en la direccion %lu", (*ptr2)->sangre, &(*ptr2)->sangre);
				break;
			}
	}
	printf("\n\nNo se encontraron mas coincidencias. Destruyendo datos...");
	
	return 0;
}
