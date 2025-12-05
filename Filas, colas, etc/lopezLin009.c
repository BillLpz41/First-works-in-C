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
	int L= 10;
	struct persona perfiles[L];
	struct persona *ptr;
	int i=0;
	char letra=' ';
	int pos=0, edad=0, c=0;
	
	printf("Version con apuntadores...\n");
	for(ptr=perfiles; ptr < &perfiles[L]; ptr++)
	{
		printf("\n**** Persona/Celda %d ****", (int) (ptr-perfiles));
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(ptr->nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &ptr->edad);
		
		printf("\n\tIngresa la estatura: ");
		scanf("%f", &ptr->est);
		
		printf("\n\tIngresa el sexo: ");
		fflush(stdin);
		ptr->sexo= getchar();
		
		printf("\n\tIngresa el tipo de sangre: ");
		fflush(stdin);
		gets(ptr->sangre);
	}
	
	printf("\n\nIngresa la letra que debe tener los nombres: ");
	fflush(stdin);
	letra= getchar();
	
	printf("\nQuieres buscar el nombre por la posicion de la letra? Si (1)/No (0): ");
	scanf("%d", &c);
	
	if(c==0)
	{
		printf("\nIngresa la edad de las personas que quieres buscar: ");
		scanf("%d", &edad);
	
		for(ptr=perfiles; ptr < &perfiles[L]; ptr++)
		{
			for(i=0; ptr->nombre[i]!='\n'; i++)
				if((ptr->nombre[i]==letra || ptr->nombre[i]==(letra+32) || ptr->nombre[i]==(letra-32)) && (ptr->edad>=edad))
				{
					printf("\n\n======Sujeto encontrado en la celda %d", (int) (ptr-perfiles));
					printf("\n\tNombre: %s / en la direccion %lu", ptr->nombre, &ptr->nombre);
					printf("\n\tEdad: %d / en la direccion %lu", ptr->edad, &ptr->edad);
					printf("\n\tEstatura: %.2f / en la direccion %lu", ptr->est, &ptr->est);
					printf("\n\tSexo: %c / en la direccion %lu", ptr->sexo, &ptr->sexo);
					printf("\n\tTipo de sangre: %s / en la direccion %lu", ptr->sangre, &ptr->sangre);
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
	
	for(ptr=perfiles; ptr < &perfiles[L]; ptr++)
	{
		for(i=0; i<pos+1; i++)
			if((ptr->nombre[i]==letra || ptr->nombre[i]==(letra+32) || ptr->nombre[i]==(letra-32)) && (ptr->edad>=20))
			{
				printf("\n\n======Sujeto encontrado en la celda %d", (int) (ptr-perfiles));
				printf("\n\tNombre: %s / en la direccion %lu", ptr->nombre, &ptr->nombre);
				printf("\n\tEdad: %d / en la direccion %lu", ptr->edad, &ptr->edad);
				printf("\n\tEstatura: %.2f / en la direccion %lu", ptr->est, &ptr->est);
				printf("\n\tSexo: %c / en la direccion %lu", ptr->sexo, &ptr->sexo);
				printf("\n\tTipo de sangre: %s / en la direccion %lu", ptr->sangre, &ptr->sangre);
				break;
			}
	}
	printf("\n\nNo se encontraron mas coincidencias. Destruyendo datos...");
	
	for(ptr=perfiles; ptr < &perfiles[L]; ptr++)
		if(ptr->nombre != NULL)
			free(ptr->nombre);	
	
	free(ptr);
	
	return 0;
}
