#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXITO 1
#define ERROR 0

char *crearCadena(int N);
int convertirEnteroACadena(char *numero, int n);
int convertirCadenaANumero(int *n, char *numero);
int digitosEntero(int n);
void destruirNumero(char *numero);

int main()
{
	int num=0, l=0, resultado=0;
	char *numCad=NULL, *cadNum=NULL;
	
	printf("Ingresa un numero entero. ");
	scanf("%d", &num);//guarda el numero entero introducido
	
	l= digitosEntero(num);//se obtiene la cantidad de digitos del numero entero
	
	numCad= crearCadena(l);//se crea un arreglo con esa longitud
	
	resultado= convertirEnteroACadena(numCad, num);//se convierte el numero entero a una cadena de caracteres
	
	if(resultado==EXITO)//si el resultado es 1
		printf("\nLa conversion de entero a cadena fue un exito! El numero es: %s", numCad);
	else//si el resultado es 0
		printf("\nLa conversion ha fracasado.");	
	
	cadNum= crearCadena(50);
	printf("\nIntroduce un numero para convertir a entero (recuerda a%cadir el signo incluso si es positivo!!): ", 164);
	scanf("%s", cadNum);//se introduce un numero que se guardará en un arreglo de caracteres
	
	resultado= convertirCadenaAEntero(&num, cadNum);//la cadena se convierte en un número entero
	
	if(resultado==EXITO)//si el resultado es 1
		printf("\nLa conversion de cadena a entero fue un exito!! El numero entero es: %d", num);
	else//si el resultado es 0
		printf("\nAlgo salio mal. La conversion fall%c", 162);
	//libera la memoria del arreglo
	destruirNumero(numCad);
	destruirNumero(cadNum);
	
	return 0;
}

char *crearCadena(int N)
{
	char *cad=NULL;
	
	cad= (char *) malloc((N+2)*sizeof(char));//+2 por el signo y el fin de cadena
	
	return cad;
}

int convertirEnteroACadena(char *numero, int n)
{
	int i=0, j=0, l=0;
	char aux= ' ';
	
	if(numero==NULL)//si 'numero' es nulo, retorna 0
		return ERROR;
		
	if(n>=0)//si el n es mayor o igual a 0, en la celda 0 se coloca el signo positivo
		numero[0]='+';
	else//si no, entonces es negativo, y para que se realicen bien las operaciones, n se convierte en positivo
	{
		numero[0]='-';
		n*=-1;
	}
	
	for(i=1; n>0; i++)//puesto que en la celda 0 está el signo, i empieza en 1
	{
		numero[i]=n%10 + '0';//el residuo se suma con '0' (ASCII) para que el resultado sea en caracter
		n/=10;//se divide n entre 10
	}
	
	numero[i]='\0';//fin de cadena
	l=i;//i sirvió para obtener la longitud de la cadena,
		// y debido a que no se consideró el signo, no habrá que restarle 1
	
	for(i=1, j=l-1; i<l-1 && j>0; i++, j--)//j empieza en l-1 para evitar el fin de cadena
	{//se invierte el contenido del arreglo (sin considerar la celda 0)
		aux= numero[j];
		numero[j]= numero[i];
		numero[i]=aux;
	}
	
	return EXITO;//retorna 1
}

int convertirCadenaAEntero(int *n, char *numero)
{
	int i=0, l=0, aux=0;
	
	if(numero==NULL)//si 'numero' es nulo, retorna 0
		return ERROR;
	
	if(numero[0]=='-')//comprueba si la celda 0 tiene el signo negativo
		*n=-1;//al apuntador de n se le cambia de valor a -1 (porque luego se multiplicación)
	else//si no, entonces el signo es positivo
		*n=1;//al apuntador de n se le cambia de valor a 1
			
	for(i=0; numero[i]!='\0'; i++);//se obtiene la longitud de la cadena
	
	l= i-2;//la longitud se le resta 2 para evitar el signo y el fin de cadena
			//esto servirá para las potencias de 10	
	for(i=1; numero[i]!='\0'; i++, l--)
		aux+=(numero[i]-48)*pow(10,l);//la celda i del arreglo se le resta 48 para obtener su valor entero
										//luego, se multiplica por una potencia de 10; este producto se suma a aux
	(*n)*=aux;//*n es la multiplicación de sí mismo y aux
	
	return EXITO;//retorna el valor de 1
}

int digitosEntero(int n)
{
	int i=0;
	//funcion para obtener la cantidad de digitos del numero
	for(i=0; n>0; i++)
		n/=10;
	
	return i;
}

void destruirNumero(char *numero)
{
	free(numero);
}
