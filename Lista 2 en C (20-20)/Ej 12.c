#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//funciones que devuelven un valor flotante
float convertorRadian(float ang);//el argumento de las funciones sin() y cos() es en radianes
float calcularAreaLados(int N, float a);//calcular el area conociendo la medida de los lados
float calcularPerimetroLados(int N, float a);//cacular el perimetro sabiendo la medida de los lados
float calcularAreaRadio(int N, float R);//area con solo radio
float calcularPerimetroRadio(int N, float R);//perimetro con solo radio

int main()
{
	float area=0, perimetro=0, longitud=0;
	int lados=0, c=0;
	float radio=0;
	int aux=0, altura=0, hipotenusa;
	
	printf("Calculo de area y perimetro de un poligono regular");
	printf("\nQue datos tienes? (Ingresa 0 o 1)\n");
	printf("0. Numero de lados y longitud de lado\n1. Radio del circulo inscrito.\n");
	scanf("%d", &c);
	
	if(c==0)//sabiendo numero de lados y longitud de lado
	{
		printf("\nIngresa el numero de lados del poligono: ");
		scanf("%d", &lados);
		printf("\nIngresa la medida de un lado: ");
		scanf("%f", &longitud);
		
		area= calcularAreaLados(lados, longitud);
		perimetro= calcularPerimetroLados(lados, longitud);
		
		printf("\nEl area del poligono de %d lados es de %f", lados, area);
		printf("\nEl perimetro del poligono de %d lados es de %f", lados, perimetro);
	}
	else if(c==1)//sabiendo el radio del circulo inscrito
	{
		printf("\nIngresa la cantidad de lados del poligono: ");
		scanf("%d", &lados);
		printf("\nIngresa el valor del radio: ");
		scanf("%f", &radio);
		
		area= calcularAreaRadio(lados, radio);
		perimetro= calcularPerimetroRadio(lados, radio);
		
		printf("\nEl area del poligono de %d lados y radio %f, es de %f", lados, radio, area);
		printf("\nEl perimetro del poligono de %d lados y radio %f, es de %f", lados, radio, perimetro);
	}
	else
		printf("\nNumero ingresado incorrecto.");
	
	return 0;
}
float convertorRadian(float ang)//ang= angulo
{//esta funcion es invocada en otras funciones
	float radian=0;
	
	radian= (ang*M_PI)/180;
	
	return radian;
}

float calcularAreaLados(int N, float a)//N= numero de lados = lados; a= longitud
{
	float A=0, altura=0, hipotenusa=0;//A= area
	float anguloA=0, anguloB=0;
	float radB=0;//anguloB en radianes
	
	anguloA= 360/N;
	anguloB= (180 - anguloA)/2;
	
	radB= convertorRadian(anguloB);
	
	hipotenusa=(a/2)/(cos(radB));
	altura= sqrt(pow(hipotenusa, 2) - pow(a/2, 2));
	
	printf("\nLa apotema del poligono es de %f\nY el radio es de %f", altura, hipotenusa);
	
	A=N*((a*altura)/2);
	
	return A;
}

float calcularPerimetroLados(int N, float a)
{
	float P=0, altura=0, hipotenusa=0;//P= perimetro
	float anguloA=0, anguloB=0;
	float radB=0;
	
	anguloA= 360/N;
	anguloB= (180 - anguloA)/2;
	
	radB= convertorRadian(anguloB);
	
	hipotenusa=(a/2)/(cos(radB));
	altura= sqrt(pow(hipotenusa, 2) - pow(a/2, 2));
	
	P=N*a;
	
	return P;
}

float calcularAreaRadio(int N, float R)
{
	float A=0, a=0, altura=0; 
	float anguloA=0, anguloC=0;
	float radC=0;
	
	anguloA= 360/N;
	anguloC= anguloA/2;
	
	radC= convertorRadian(anguloC);
	
	a= 2*R*sin(radC);	
	altura= (sqrt(pow(R, 2)) - pow(a/2, 2));
	
	printf("\nLa apotema del poligono es de %f\nY la longitud de sus lados es de %f", altura, a);
	
	A= N*((a*altura)/2);
	
	return A;
}

float calcularPerimetroRadio(int N, float R)
{
	float P=0, a=0, altura=0; 
	float anguloA=0, anguloC=0;
	float radC=0;
	
	anguloA= 360/N;
	anguloC= anguloA/2;
	
	radC= convertorRadian(anguloC);
	
	a= 2*R*sin(radC);	
	altura= (sqrt(pow(R, 2)) - pow(a/2, 2));
	
	P= N*a;
	
	return P;
}
