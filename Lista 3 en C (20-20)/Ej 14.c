#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//se declara una estructura complejo para representar numeros complejos
typedef struct complejo
{
	float real;//parte real
	float imaginario;//parte imaginaria
	float magnitud;//parte real en polar (radio)
	float fase;//parte imaginaria en polar (angulo)
} *Complejo, t_complejo;
//Se define el tipo de estructura, uno tiendo un apuntador (dinamico) y otro no (estatico)
Complejo crearNumeroComplejoCartesiano(float re, float im);
Complejo crearNumeroComplejoPolar(float rho, float phi);
void convertirCartesiano(float *re, float *im, float rho, float phi);
void convertirPolar(float *rho, float *phi, float re, float im);
void sumarComplejos(Complejo w, Complejo z0, Complejo z1);
void multiplicarComplejos(Complejo w, Complejo z0, Complejo z1);
void desplegarComplejo(Complejo z);
void destruirComplejo(Complejo z);

int main()
{
	Complejo a= NULL, b=NULL, suma= NULL, mult= NULL; //se definen estructuras de numeros complejos
	//a y b son los numeros, suma es la suma entre estos dos, y mult es la multiplicacion entre los dos primeros
	float x=0.0, y=0.0, r=0.0, phi=0.0;
	//x= parte real, y= parte imaginaria, r (rho)= magnitud (radio), phi= fase (angulo)
	
	printf("Ingresa el valor de la parte real del numero complejo CARTESIANO: ");
	scanf("%f", &x);
	
	printf("\nIngresa el valor de la parte imaginaria del numero complejo CARTESIANO: ");
	scanf("%f", &y);
	
	a= crearNumeroComplejoCartesiano(x, y);//se crea un número complejo cartesiano a partir de x & y;
											//además, también se hace el calculo para su forma polar
	printf("\nEl primer numero complejo tiene los siguientes valores:\n");
	desplegarComplejo(a);//imprime el numero complejo a (contenido de la estructura)
	
	printf("\n\nIngresa el valor de la magnitud del numero complejo POLAR: ");
	scanf("%f", &r);
	
	printf("\nIngresa el valor de la fase del numero complejo POLAR: ");
	scanf("%f", &phi);
	
	b= crearNumeroComplejoPolar(r, phi);//se crea un numero complejo polar a partir de r (rho) & phi
	printf("\nEl segundo numero complejo tiene los siguientes valores:\n");
	desplegarComplejo(b);//imprime el numeor complejo b (contenido de la estructura)
	
	suma= crearNumeroComplejoCartesiano(0.0, 0.0);
	sumarComplejos(suma, a, b);
	printf("\n\n\nLa suma de los dos numeros complejos dio estos valores:\n");
	desplegarComplejo(suma);//imprime el numero complejo suma
	
	mult= crearNumeroComplejoPolar(1.0, 0.0);
	multiplicarComplejos(mult, a, b);
	printf("\n\n\nLa multiplicacion de los dos numeros complejos dio estos valores:\n");
	desplegarComplejo(mult);//imprime el numero complejo mult
	//libera la memoria de las estructuras
	destruirComplejo(a);
	destruirComplejo(b);
	destruirComplejo(suma);
	destruirComplejo(mult);
	
	return 0;
}

Complejo crearNumeroComplejoCartesiano(float re, float im)
{
	Complejo z=NULL;//declara una estructura con valor nulo
	float rho= 0.0, phi= 0.0;
	
	z= (Complejo) malloc(sizeof(t_complejo));//se reserva memoria para la estructura, con tamaño de t_complejo
	convertirPolar(&rho, &phi, re, im);//convierte los valores de re e im a su equivalente polar rho y phi
	z->	real= re;//al atributo real se le asigna el valor de re
	z->imaginario= im;//al atributo imaginario se le asigna el valor de im
	z->magnitud= rho;//al atributo magnitud se le asigna el valor de rho
	z->fase= phi;//al atributo fase se le asigna el valor de phi
	
	return z;//regresa el numero complejo (la estructura)
}

Complejo crearNumeroComplejoPolar(float rho, float phi)
{
	Complejo z= NULL;
	float re= 0.0, im= 0.0;
	
	z= (Complejo) malloc(sizeof(t_complejo));
	convertirCartesiano(&re, &im, rho, phi);//convierte los valores de rho y phi a su equivalencia cartesiana
	z->real= re;
	z->imaginario= im;
	z->magnitud= rho;
	z->fase= phi;
	
	return z;
}

void convertirCartesiano(float *re, float *im, float rho, float phi)
{
	float rad=0.0;//las funciones trigonometricas requieren como argumento el dato en radianes
	
	rad= ((phi)*M_PI)/180;//obtiene el valor en radianes de phi
	*re= rho * cos(rad);//calcula el valor de re con el coseno de rad
	*im= rho * sin(rad);//calcula el valor de im con el seno de rad
}

void convertirPolar(float *rho, float *phi, float re, float im)
{
	float rad=0.0;
	
	rad= 180/M_PI;//se calcula el valor de 1 radian
	*rho= sqrt(pow(re, 2) + pow(im, 2));//se aplica el teorema de Pitágoras
	*phi= atan(im/re) * rad;//para calcular la fase, hay que multiplicar el resultado de la funcion trigonometrica
							//por un radian, esto es debido al valor que resulta de la funcion trigonometrica
}

void sumarComplejos(Complejo w, Complejo z0, Complejo z1)
{
	if(w==NULL || z0==NULL || z1==NULL)
		return;
		
	w->real= z0->real + z1->real;//realiza la suma de las partes reales
	w->imaginario= z0->imaginario + z1->imaginario;//realiza la suma de las parte imaginarias
	convertirPolar(&(w->magnitud), &(w->fase), w->real, w->imaginario);//convierte a polar mediante paso por
																		//referencia
}

void multiplicarComplejos(Complejo w, Complejo z0, Complejo z1)
{
	if(w==NULL || z0==NULL || z1==NULL)
		return;
		
	w->magnitud= z0->magnitud * z1->magnitud;//realiza el producto de las partes reales
	w->fase= z0->fase + z1->fase;//en la multiplicación, los exponentes se suma
	convertirCartesiano(&(w->real), &(w->imaginario), w->magnitud, w->fase);//convierte a cartesiano mediante paso
																			//por referencia
	
}

void desplegarComplejo(Complejo z)
{
	printf("\nParte cartesiana real: %f", z->real);
	printf("\nParte cartesiana imaginaria: %f", z->imaginario);
	printf("\nParte polar real (magnitud): %f", z->magnitud);
	printf("\nParte polar imaginaria (fase): %f%c", z->fase, 248);
}

void destruirComplejo(Complejo z)
{
	free(z);
}
