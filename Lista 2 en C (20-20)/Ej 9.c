#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cifrasMayusculas(char num[]);
double baseNbase10(char num[], int baseN, int L);

int main()
{
    int N=8;//longitud de arreglo
    char digito[N];//arreglo de caracteres para el número en base N
    float baseN[N];//arreglo de flotantes para el valor númerico de las cifras (en caso de ser mayor a base decimal)
    double num=0.0;//resultado en base decimal
    int k=0, base=0;//base= base inicial del número

    printf("Introduce la base que quieres convertir a decimal:");
    scanf("%d", &base);
	
	//el digito menos significativo es el de la casilla 0
    printf("\nIngresa el numero (el numero debe ser de 8 cifras o menos): ");
    scanf("%s", digito);
	cifrasMayusculas(digito);
    num = baseNbase10(digito, base, N);

    printf("\nEl numero en base decimal es: %lf", num);
	//libera la memoria de los arreglos
	free(baseN);
	free(digitoN);
	
    return 0;
}
//num= digito
void cifrasMayusculas(char num[])
{
	int i=0;
	
	for(i=0; num[i]!='\0'; i++)
	    if(num[i]>96 && num[i]<123)//rango ASCII de 'a' con 97 y 'z' con 122,
            num[i]-= 32;//la resta lo lleva al rango 'A' con 65 y 'Z' con 90
}
//baseN= base N inicial; L= longitud del digito (N=8)
double baseNbase10(char num[], int baseN, int L)
{
	int i=0, aux=0;
	double b10=0.0;//para el número convertido en base 10
	
	for(i=0; i<L; i++)
	{
		if(num[i]>47 && num[i]<58)//'0' es 48 en ASCII y '9' es 57
		{
			aux= (int) num[i];//convierte en entero el numero del arreglo de caracteres
			aux-= 48;//resta el numero para que esté en el rango de 0 y 9
			b10 += aux*pow(baseN, i);//calcula el numero decimal
		}
		else if(num[i]>64 && num[i]<91)//en caso de que sea una letra, ya estaría en mayusculas
		{
			aux= (int) num[i];//convierte en entero el caracter del arreglo de caracteres
			aux-= 55;//resta el numero para que esté en el rango de mayor a 10
			b10 += aux*pow(baseN, i);//calcula el numero decimal
		}
	}
	
	return b10;//regresa el numero decimal
}
