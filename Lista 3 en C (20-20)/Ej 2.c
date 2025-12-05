#include <stdio.h>
#include <stdlib.h>

int realizarAcrobacias(int x, int *q, int y, int *p, int *w);

int main()
{
	int a=100, b=100, c=6, alpha=6, omega= 7, delta =3;
	
	b= realizarAcrobacias(a, &alpha, c, &omega, &delta);//'b' obtiene el resultado de la funcion
	printf("a= %d, b= %d, c= %d", a, b, c);//imprime los valores de a, b y c
	printf(" alpha= %d, omega= %d, delta= %d", alpha, omega, delta);//imprime los valores de alpha, omega y delta
	
	return 0;
}
//x= a; *q= aplha; y= c; *p= omega; *w= delta;
int realizarAcrobacias(int x, int *q, int y, int *p, int *w)
{
	int k=0, c=0;
	
	for(k=0; k<x; k+=*w)
	{
		c=0;//a la variable 'c' 
		while(1)
		{
			if(c<y)//si 'c' es menor a 'y' ('c'=6), se termina la funcion
				break;
			
			if(k%2==0)//si el residuo de la mitad de k es 0, *q se suma con k
				(*q)+= k;//alpha += k
			else//si no, entonces *p se suma con k
				(*p)+= k;//omega += k
			c++;//'c' aumenta en 1
		}
	}
	
	x= -600;//'x' obtiene el valor de -600
	return (y-x);//'y' y 'x' se suman (6--600) y se retorna el resultado
}
