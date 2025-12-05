#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//crea la estructura codice
typedef struct codice
{
	int *digitos;
	int base;
	int decimal;
	int N;
} *Codice, t_codice;//define los tipos de estructuras, *Codice (dinamico) y t_codice (estatico)

void crearCodiceBase(Codice *code, int *arr, int base, int N);
void crearCodiceDecimal(Codice *code, int dec, int base, int N);
void convertirBaseB(int *arr, int x, int base, int N);
int convertirBase10(int *arr, int base, int N);
int *crearArreglo(int N);
void desplegarCodice(Codice codigo);
void destruirCodice(Codice *code);
void destruirArreglo(int *arr);

int main()
{
	Codice codex= NULL, escrito= NULL;//crea dos estructuras, codex para el numero base b a decimal
									//y escrito para el numero decimal a base b
	int sec[8]={1, 3, 2, 0, 1, 1, 1 ,3};//numero en base 4
	int num=2019, b= 4, L= 8;//num= numero en decimal, b= base, L= longitud de arreglo
	
	crearCodiceBase(&codex, sec, b , L);//convierte el numero en base b a decimal
	desplegarCodice(codex);//imprime el contenido de la estructura codex
	
	crearCodiceDecimal(&escrito, num, b , L);//convierte el numero decimal a base b
	desplegarCodice(escrito);//imprime el contenido de la estructura escrito
	//libera la memoria de las estructuras
	destruirCodice(&codex);
	destruirCodice(&escrito);
	
	return 0;
}

void crearCodiceBase(Codice *code, int *arr, int base, int N)
{
	Codice glifo= NULL;
	int k=0;
	
	glifo= (Codice) malloc(sizeof(t_codice));//reserva memoria para una estructura
	
	glifo->digitos= crearArreglo(N);//al atributo digitos (que está declarado como un arreglo)
									//se le reserva memoria para almacenar el numero en base b	
	for(k=0; k<N; k++)
		glifo->digitos[k]= arr[k];//copia el numero en base b al atributo arreglo 'digito' de la estructura 
		
	glifo->base= base;//copia la base al atributo base de la estructura
	glifo->N= N;//copia la cantidad de digitos del numero en base b al atributo N de la estructura
	
	glifo->decimal= convertirBase10(arr, base, N);//convierte el numero en base b a base decimal
												//y ese valor lo regresa al atributo decimal de la estructura
	
	*code= glifo;//*code se vuelve la estructura que tiene los anteriores valores, por lo que no es necesario
				//regresar la estructura, ya que los cambios fueron hechos por referencia
}

void crearCodiceDecimal(Codice *code, int dec, int base, int N)
{
	Codice glifo= NULL;
	
	glifo= (Codice) malloc(sizeof(t_codice));
	
	glifo->digitos= crearArreglo(N);
	
	glifo->decimal= dec;//copia el valor de dec al atributo decimal de la estructura
	glifo->base= base;
	glifo->N= N;
	
	convertirBaseB(glifo->digitos, dec, base, N);//convierte el numero decimal (dec) a base b; el numero en base b
												//se obtiene por paso por referencia
	*code= glifo;
}
//el parametro *arr es de tipo entero porque recibirá el arreglo entero de la estructura.
void convertirBaseB(int *arr, int x, int base, int N)
{
	int lim=0, k=0, q=0, r=0;
	int dec= x;//dec copia el valor de x (=dec)
	
	if(arr==NULL)//si el arreglo de la estructura es nulo, fin de la funcion
		return;
	
	while(1)
	{//va dividiendo el numero decimal para saber cuantos digitos necesitará su forma en base b
		dec /= base;
		lim++;//una variable para conocer los digitos
		
		if(dec==0)//una vez dec sea 0, no es necesario seguir dividiendo
			break;
	}
	
	if(lim>N)//si lim es mayor a N, que es la longitud del arreglo, entonces no se podrá realizar la conversión
		return;//por falta de celdas del arreglo
	dec=x;//dec vuelve a tener el valor de x (=dec)
	
	while(1)
	{//se realiza un proceso similar al del primer ciclo
		q= dec/base;
		r=dec%base;//se obtiene el residuo de la division
		arr[k]=r;//el residuo es parte del numero en base b
		k++;//aumenta el contador para avanzar en celdas
		
		if(q==0)
			break;
			
		dec=q;//dec obtiene el valor de q para actualizar la division
	}
}

int convertirBase10(int *arr, int base, int N)
{
	int k=0, x=0;
	
	if(arr==NULL)
		return -1;//se retorna el valor de -1 para indicar que el arreglo es nulo
		
	for(k=0; k<N; k++)
		x+= arr[k]*pow(base, k);//la celda k del arreglo se multiplica por una potencia de la base, luego se suma
								//con x para ir obteniendo el numero en decimal
	return x;//retorna el numero en decimal
}

int *crearArreglo(int N)
{
	int *arr=NULL;
	int k=0;
	
	arr=(int *) malloc(N*sizeof(int));
	
	for(k=0; k<N; k++)
		arr[k]=0;//coloca un 0 en cada celda del arreglo
	
	return arr;
}

void desplegarCodice(Codice codigo)
{
	int k=0;
	
	if(codigo==NULL)
		return;
	
	printf("\nDigito: ");
	for(k=0; k<(codigo->N); k++)
		printf("%d", codigo->digitos[k]);
	printf(" (celda 0, digito menos significativo: %d)", codigo->digitos[0]);	
	printf("\nBase: %d", codigo->base);
	printf("\nDecimal: %d", codigo->decimal);
	printf("\nN: %d", codigo->N);
	printf("\n");
}

void destruirCodice(Codice *code)
{
	Codice q=NULL;//se crea una estructura nula	
	
	q= *code;//esa estructura se vuelve la estructura del parametro
	
	if(q==NULL)//se verifica si dicha estructura es nula, si es así, fin de la funcion
		return;
		
	if(q->digitos!=NULL)//si el arreglo de la estructura no es nulo,
		destruirArreglo(q->digitos);//el arreglo se pasa como parametro para liberar la memoria de ese arreglo
	//a los demás atributos de la estructura se le da valor 0
	q->decimal= 0;
	q->base= 0;
	q->N= 0;
	
	free(q);//se termina de liberar la memoria de la estructura
}

void destruirArreglo(int *arr)
{
	free(arr);//libera la memoria del arreglo
}
