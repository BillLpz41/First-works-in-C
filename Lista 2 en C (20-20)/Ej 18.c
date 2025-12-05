#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float convertirReal(float re, float im, int op);//dependiendo el valor de 'op', regresará el número real 'x' o 'radio'
float convertirImaginario(float re, float im, int op);//dependiendo el valor de 'op', regresará 'y' o 'angulo'
void sumarComplejosCartesiano(float re0, float re1, float im0, float im1); //Suma numeros complejos cartesianos
void multiplicarComplejosCartesiano(float re0, float re1, float im0, float im1);//multiplica números complejos cartesianos
void sumarComplejosPolar(float re0, float re1, float im0, float im1);//suma números complejos polares
void multiplicarComplejosPolar(float re0, float re1, float im0, float im1);//multiplica números complejos cartesianos

int main()
{
	int c=0;//variable para decidir qué operaciones se harán
	float realX0=0, imaY0=0, realX1=0, imaY1=0;//realX & imaY es la parte real e imaginaria del número, respectivamente
	float radio0=0, angulo0=0, radio1=0, angulo1=0;//angulo es el ángulo del exponente en la forma polar
	float real=0, ima=0, radio=0, angulo=0;
	
	printf("Que quieres hacer? \n0. Convertir representacion de un numero complejo.");
	printf("\n1. Sumar y multiplicar numeros complejos.\n");
	scanf("%d", &c);
	
	if(c==0)//convertir la representación de un número complejo
	{
		printf("Que representacion de numero complejo quieres la conversion?\n");
		printf("0. Cartesiana a polar.\n1. Polar a cartesiana.\n");
		scanf("%d", &c);
		
		if(c==0)//conversion de cartesiana a polar
		{
			printf("\nEstas convirtiendo de cartesiana a polar...");
			printf("\nIngresa la parte real del primer numero complejo: ");
			scanf("%f", &real);
			
			printf("\nIngresa la parte imaginaria del primer numero complejo (sin incluir la 'i'): ");
			scanf("%f", &ima);
			
			radio= convertirReal(real, ima, c);
			angulo= convertirImaginario(real, ima, c);
			
			printf("\n\nEl numero complejo z = %.1f + i%.1f en su representacion polar es:\n", real, ima);
			printf("\nz= %fe^i(%f°)", radio, angulo);
		}
		else if(c==1)//conversion de polar a cartesiana
		{
			printf("\nEstas convirtiendo de polar a cartesianas...");
			printf("\nIngresa la parte real (el radio) del numero complejo: ");
			scanf("%f", &radio);
			
			printf("\nIngresa la parte imaginaria (el exponente, solo el valor del angulo): ");
			scanf("%f", &angulo);
			
			real = convertirReal(radio, angulo, c);
			ima = convertirImaginario(radio, angulo, c);
			
			printf("\n\nEl numero complejo z = %fe^i(%f°) en su representacion cartesiana es:", radio, angulo);
			printf("\nz = %f + i%f", real, ima);
		}
		else
		{
			printf("\nEl dato ingresado no es valido.\n");
		}
		
	}
	else if(c==1)//suma y multiplicación de complejos
	{
		printf("\nEscogiste la suma y multiplicacion de numeros complejos...");
		printf("\nDime, tus numeros complejos son cartesianos o polares?");
		printf("\n0. Cartesiano.\n1. Polar.\n");
		scanf("%d", &c);
		
		if(c==0)//teniendo números complejos cartesianos
		{
			printf("\nIngresa la parte real del primer numero complejo: ");
			scanf("%f", &realX0);
			
			printf("\nIngresa la parte imaginaria del primer numero complejo: ");
			scanf("%f", &imaY0);
			
			printf("\nIngresa la parte real del segundo numero complejo: ");
			scanf("%f", &realX1);
				
			printf("\nIngresa la parte imaginaria del segundo numero complejo: ");
			scanf("%f", &imaY1);	
			
			sumarComplejosCartesiano(realX0, realX1, imaY0, imaY1);
			multiplicarComplejosCartesiano(realX0, realX1, imaY0, imaY1);
		}
		else if(c==1)//teniendo números complejos polares
		{
			printf("\nIngresa la parte real (radio) del primer numero complejo: ");
			scanf("%f", &radio0);
			
			printf("\nIngresa la parte imaginaria (angulo) del primer numero complejo: ");
			scanf("%f", &angulo0);
			
			printf("\nIngresa la parte real del segundo (radio) numero complejo: ");
			scanf("%f", &radio1);
				
			printf("\nIngresa la parte imaginaria del segundo (angulo) numero complejo: ");
			scanf("%f", &angulo1);
			
			sumarComplejosPolar(radio0, radio1, angulo0, angulo1);
			multiplicarComplejosPolar(radio0, radio1, angulo0, angulo1);
		}
		else
		{
			printf("\nIntenta otra vez...");
		}
			
	}
	else
	{
		printf("Mmmm... Ese numero no...");
	}
	
	return 0;
}
//re= real; im= ima; op= c;
float convertirReal(float re, float im, int op)
{
	float x=0.0, r=0.0, rad=0.0;//x= parte real cartesiana; r= parte real polar (radio); rad= radianes
	
	if(op==0)//convierte de cartesiano 'x' a polar 'r'
	{
		r = sqrt(pow(re, 2) + pow(im, 2));
		return r;
	}
	else if(op==1)//convierte de polar 'r' a cartesiano 'x'
	{
		rad = (im*M_PI)/180;//las funciones sin() y cos() reciben como dato un valor en radianes
		x = re * cos(rad);
		return x;
	}
}

float convertirImaginario(float re, float im, int op)
{
	float y=0.0, ang=0.0, rad=0.0;//y= parte imaginaria cartesiana; ang= parte imaginaria polar (angulo)
	
	if(op==0)//convierte de cartesiano 'y' a polar 'ang'
	{
		rad = 180/M_PI;//obtiene el valor de 1 radian
		ang= atan(im/re) * rad;//la función atan() devuelve un valor en radianes; el producto lo convierte a grados
		return ang;
	}
	else if(op==1)//converite de polar 'ang' a cartesiano 'y'
	{
		rad = (im*M_PI)/180;
		y= re * sin(rad);
		return y;
	}
}
//re0= realX0; re1= realX1; im0= imaY0; im1= imaY1
void sumarComplejosCartesiano(float re0, float re1, float im0, float im1)
{//la suma de complejos en representación cartesiana es simplemente sumar semejantes
	float x=0, y=0;
	
	x= re0 + re1;
	y= im0 + im1;
	
	printf("\n\nLa suma de los numeros complejos es: ");
	printf("\nz = %f + i%f", x, y);
}

void multiplicarComplejosCartesiano(float re0, float re1, float im0, float im1)
{//el producto de dos números complejos en representación cartesiana es (re0*re1+i^2(im0*im1))+i(re0*im1+re1*im0)
	float x=0, y=0;
	
	x= re0*re1 - (im0*im1);
	y= re0*im1 + re1*im0;
	
	printf("\n\nLa multiplicacion de los numeros complejos es: ");
	printf("\nz= %f + i%f", x, y);
}

void sumarComplejosPolar(float re0, float re1, float im0, float im1)
{//es necesario pasar los números polares a cartesianos, hacer la suma y el resultado convertido a forma polar
	float x0=0.0, y0=0.0, r0=0.0, ang0=0.0;
	float x1=0.0, y1=0.0, r1=0.0, ang1=0.0;
	float xf=0.0, yf=0.0, rf=0.0, angf=0.0;//xf, yf, rf & angf son los resultados finales que se imprimirán
	
	x0= convertirReal(re0, im0, 1);
	y0= convertirImaginario(re0, im0, 1);
	
	x1= convertirReal(re1, im1, 1);
	y1= convertirImaginario(re1, im0, 1);
	
	xf= x0 + x1;
	yf= y0 + y1;
		
	rf= convertirReal(xf, yf, 0);
	angf= convertirImaginario(xf, yf, 0);
	
	printf("\n\nLa suma de los numeros complejos es: ");
	printf("\nz = %fe^i(%f°)", rf, angf);
}

void multiplicarComplejosPolar(float re0, float re1, float im0, float im1)
{//la multiplicación de complejos se factoriza la parte real y se suman los exponentes (angulo)
	float r=0, ang=0;
	
	r= re0*re1;
	ang= im0 + im1;
	
	printf("\n\nLa multiplicacion de los numeros complejos es: ");
	printf("\nz = %fe^i(%f°)", r, ang);
}

