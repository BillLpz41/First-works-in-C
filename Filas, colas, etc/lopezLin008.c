#include <stdio.h>
#include <stdlib.h>
//Version instancias.
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
	int i=0, j=0;
	char letra=' ';
	int pos=0, edad=0, c=0;
	
	printf("Version con instancias...");
	
	for(i=0; i<L; i++)
	{
		printf("\n**** Persona/Celda %d ****", i);
		printf("\n\tIngresa el nombre: ");
		fflush(stdin);
		gets(perfiles[i].nombre);
		
		printf("\n\tIngresa la edad: ");
		scanf("%d", &perfiles[i].edad);
		
		printf("\n\tIngresa la estatura: ");
		scanf("%f", &perfiles[i].est);
		
		printf("\n\tIngresa el sexo: ");
		fflush(stdin);
		perfiles[i].sexo= getchar();
		
		printf("\n\tIngresa el tipo de sangre: ");
		fflush(stdin);
		gets(perfiles[i].sangre);
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
		
		for(i=0; i<L; i++)
		{
			for(j=0; perfiles[i].nombre[j]!='\n'; j++)
			{
				if((perfiles[i].nombre[j]==letra || perfiles[i].nombre[j]==(letra+32) || perfiles[i].nombre[j]==(letra-32)) && (perfiles[i].edad>=edad))
				{
					printf("\n======Sujeto encontrado en la celda %d", i);
					printf("\n\tNombre: %s en la direccion de %lu", perfiles[i].nombre, &perfiles[i].nombre);
					printf("\n\tEdad: %d en la direccion de %lu", perfiles[i].edad, &perfiles[i].edad);
					printf("\n\tEstatura: %.2f en la direccion de %lu", perfiles[i].est, &perfiles[i].est);
					printf("\n\tSexo: %c en la direccion de %lu", perfiles[i].sexo, &perfiles[i].sexo);
					printf("\n\tTipo de sangre: %s en la direccion %lu", perfiles[i].sangre, &perfiles[i].sangre);
					break;
				}
				
			}
		}
		printf("\n\nNo se encontraron mas coincidencias.");
		
		return 0;
	}
	
	printf("\nIngresa la posicion de esa letra en el nombre (posicion 0 es la primera letra del nombre): ");
	scanf("%d", &pos);
	
	printf("\nIngresa la edad de las personas que quieres buscar: ");
	scanf("%d", &edad);
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<pos+1; j++)
		{
			if((perfiles[i].nombre[j]==letra || perfiles[i].nombre[j]==(letra+32) || perfiles[i].nombre[j]==(letra-32)) && perfiles[i].edad>=20)
			{
				printf("\n\n======Sujeto encontrado en la celda %d", i);
				printf("\n\tNombre: %s / en la direccion %lu", perfiles[i].nombre, &perfiles[i].nombre);
				printf("\n\tEdad: %d / en la direccion %lu", perfiles[i].edad, &perfiles[i].edad);
				printf("\n\tEstatura: %.2f / en la direccion %lu", perfiles[i].est, &perfiles[i].est);
				printf("\n\tSexo: %c / en la direccion %lu", perfiles[i].sexo, &perfiles[i].sexo);
				printf("\n\tTipo de sangre: %s / en la direccion %lu", perfiles[i].sangre, &perfiles[i].sangre);
				break;
			}
		}
	}
	printf("\n\nNo se encontraron mas coincidencias. Destruyendo datos...");
	
	for(i=0; i<L; i++)
		if(perfiles[i].nombre!=NULL)
			free(perfiles[i].nombre);	
	
	free(perfiles);
	
	return 0;
}
