#include <stdio.h>

int main()
{
	int car;
	FILE *ent, *sal;
	
	ent= fopen("prueba.txt", "r");
	sal= fopen("salida.txt", "w");
	while((car= getc(ent)) != EOF)
	{
		if(car>= 'a' && car <= 'z')
			car= car-32;//suponiendo que todo esta en minusculas
		putc(car, sal);//las podra en mayuscula
	}
		
	fclose(ent);
	fclose(sal);
	
	return 0;
}
