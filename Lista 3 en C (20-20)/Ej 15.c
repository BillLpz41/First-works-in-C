#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complejo
{
	float real;
	float imaginario;
	float magnitud;
	float fase;
} *Complejo, t_complejo;

Complejo *crearArregloComplejo(int N);
void calcularRaicesComplejas(Complejo *raices, int N);
Complejo crearNumeroComplejoCartesiano(float re, float im);
Complejo crearNumeroComplejoPolar(float rho, float phi);
void convertirCartesiano(float *re, float *im, float rho, float phi);
void convertirPolar(float *rho, float *phi, float re, float im);
void destruirArregloComplejo(Complejo *arr, int N);

int main()
{
	Complejo *a= NULL;//crea un arreglo de estructuras
	int N=0;
	int k=0;
	
	printf("Ingresa las raices de z^N que quieres calcular: ");
	scanf("%d", &N);
	
	a= crearArregloComplejo(N);//crea un arreglo de estructuras de numeros complejos
	calcularRaicesComplejas(a, N);//calcula las raices del numero complejo
	//imprime los atributos de cada estructura del arreglo
	for(k=0; k<N; k++)
		printf("\nz%d: Real: %f Imaginario: %f Magnitud: %f Fase: %f", k, a[k]->real, a[k]->imaginario, 
																	a[k]->magnitud, a[k]->fase);
	
	destruirArregloComplejo(a, N);//libera la memoria del arreglo con estructuras
	
	return 0;
}

Complejo *crearArregloComplejo(int N)
{
	Complejo *arr=NULL;
	int k=0;
	
	arr= (Complejo *) malloc(N*sizeof(t_complejo));//crea un arreglo de N celdas de tamaño de una estructura
													//complejo estatica; cada celda tiene una estructura
	for(k=0; k<N; k++)
		arr[k]= crearNumeroComplejoCartesiano(0.0, 0.0);//crea un numero complejo cartesiano en la celda k
	
	return arr;//retorna el arreglo estructura
}
//Complejo *raices es un parametro para un arreglo
void calcularRaicesComplejas(Complejo *raices, int N)
{
	float phi=0.0;
	int k=0;
	
	if(raices==NULL)//si el arreglo es nulo, se termina la funcion
		return;
		
	phi= 2.0*M_PI/((float) N);//sigue la formula para calcular las raices y convierte el numero N en flotante
								//para que sean compatibles los tipos de datos
	for(k=0; k<N; k++)
	{
		raices[k]= crearNumeroComplejoPolar(1.0, 0.0);//en la celda k se le crea su parte polar
		raices[k]->fase= k * phi;//el atributo fase de la estructura de la celda k se le da el valor
								//de la multiplicacion de k y phi
		convertirCartesiano(&(raices[k])->real, &(raices[k])->imaginario, raices[k]->magnitud, raices[k]->fase);
		//convierte la parte polar de la estructura de la celda en su representacion cartesiana
	}
}

Complejo crearNumeroComplejoCartesiano(float re, float im)
{
	Complejo z=NULL;
	float rho= 0.0, phi= 0.0;
	
	z= (Complejo) malloc(sizeof(t_complejo));//reserva memoria para crear una estructura
	convertirPolar(&rho, &phi, re, im);//convierte re e im a su representacion polar
	z->	real= re;
	z->imaginario= im;
	z->magnitud= rho;
	z->fase= phi;
	
	return z;  
}

Complejo crearNumeroComplejoPolar(float rho, float phi)
{
	Complejo z= NULL;
	float re= 0.0, im= 0.0;
	
	z= (Complejo) malloc(sizeof(t_complejo));
	convertirCartesiano(&re, &im, rho, phi);//convierte rho y phi a su representacion polar
	z->real= re;
	z->imaginario= im;
	z->magnitud= rho;
	z->fase= phi;
	
	return z;
}

void convertirCartesiano(float *re, float *im, float rho, float phi)
{
	float rad=0.0;
	
	rad= ((phi)*M_PI)/180;//en la funciones trigonometricas, el argumento está en radianes
	*re= rho * cos(rad);//magnitud por el coseno del radian
	*im= rho * sin(rad);//magnitud por el seno del radian
}

void convertirPolar(float *rho, float *phi, float re, float im)
{
	float rad=0.0;
	
	rad= 180/M_PI;
	*rho= sqrt(pow(re, 2) + pow(im, 2));
	*phi= atan(im/re) * rad;
}

void destruirArregloComplejo(Complejo *arr, int N)
{
	int k=0;
	
	if(arr==NULL)//si el arreglo estructura es nulo, termina la funcion 
		return;
	
	for(k=0; k<N; k++)
		if(arr[k]!=NULL)//si la celda k del arreglo estructura no es nulo
			free(arr[k]);//libera la memoria de la estructura de esa celda
			
	free(arr);//se termina de liberar la memoria del arreglo
}
