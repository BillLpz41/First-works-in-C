#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int longitudDigito(char dig[]);//devuelve la cantidad de cifras de 'dig'
void cifrasMayusculas(char num[]);//convierte las letras del número a mayusculas
int baseNbase10(char numN[], int baseN, int L);//convierte el número de base N a base decimal
void base10baseM(int b10, char numM[], int baseM);//convierte el número de base decimal a base M
void invertirCifras(char numM[], int L);//invierte el orden de las cifras del número
void imprimir(char arr[]);
void elDestructor(char dig[]);//libera la memoria

int main()
{
	int baseN=0, baseM=0, base10=0;//baseN= la base N del número; baseM= la base final del número; base10= número en decimal
	char numN[25]="";//número en base N para convertir
	char numM[25]="";//número en base M
	int cifras=0;//cantidad de cifras
	int l=0;
	printf("Introduce la base N: "); //solicita la base N inicial.
    scanf("%d", &baseN);
	
	printf("\nIntroduce la base M: "); //solicita la base M final.
	scanf("%d", &baseM);
	
	printf("\nIntroduce el numero en base N que quieres convertir a base M: ");
	scanf("%s", numN); //solicita el numero en base N.
	imprimir(numN);
	cifrasMayusculas(numN);
	imprimir(numN);
	cifras=longitudDigito(numN);//'cifras' recibe la longitud de numN

	base10= baseNbase10(numN, baseN, cifras);//recibe la conversión de numN en base 10
	printf("\n%d", base10);
	printf("\nEl numero ingresado en base M es: ");

    base10baseM(base10, numM, baseM);//invoca la funcion para convertir de base 10 a baseM
	l=longitudDigito(numM);
	invertirCifras(numM, l);
	
	return 0;
}
//dig=numN;
int longitudDigito(char dig[])
{
	int k=0;
	
	for(k=0; dig[k]!='\0'; k++);
	
	return k;
}
//num= numN
void cifrasMayusculas(char num[])
{
	int i=0;
	
	for(i=0; num[i]!='\0'; i++)
	    if(num[i]>96 && num[i]<123)//rango ASCII de 'a' con 97 y 'z' con 122,
            num[i]-= 32;//la resta lo lleva al rango 'A' con 65 y 'Z' con 90
}
//numN= numero en base N; baseN= la base N inicial; L= cifras 
int baseNbase10(char numN[], int baseN, int L)
{
	int i=0, j=0, aux=0;
	int b10=0;//número convertido en base 10
	char letra= ' ';
	
	for(i=L-1, j=0; i>=0; i--, j++)//i=L-1 debido a que se evita el fin de cadena '\0'; j es el exponente para la base N
	{
		if(numN[i]>47 && numN[i]<58)//'0' es 48 en ASCII y '9' es 57
		{
			aux = (char) numN[i];
			aux-= 48;
			b10+= aux*pow(baseN, j); 
			//aux = numN[i] - 48;//la resta lo lleva a su valor entero
			//b10 += aux*pow(baseN, j);//la cifra se multiplica por una potencia de la base N
		}
		else if(numN[i]>64 && numN[i]<91)//en caso de que sea una letra, ya estaría en mayusculas
		{
			aux= (char) numN[i];
			aux-=55;
			b10+= aux*pow(baseN, j);
//			aux = numN[i] - 55;//la resta lo lleva a su valor entero de 10 o superior
//			b10 += aux*pow(baseN, j);
		}
	}
	
	return b10;
}
//número en base 10; numM= número en base M; baseM= la base M por convertir
void base10baseM(int b10, char numM[], int baseM)
{
	int i=0;
	int q=0, r=0, aux=0;
	char letra= ' ';
	
	for(i=0; b10>0; i++)
	{
		q= b10 / baseM;//aux almacena el residuo de la división
		r= b10 % baseM;
		b10= q;//divide el número en base 10 entre la base M
		
		if(r>=0 && r<=9)//comprueba que aux esté en el rango de entre 0 y 9
			    r+= 48;
		else if(r>=10)//si es mayor o igual a 10, se convierte el número a su forma de letra
			    r+=55;
		letra= (char) r;
		numM[i]= letra;
	}	
	numM[i]='\0';
//	l= longitudDigito(numM);//se obtiene la longitud del número en base M
//	invertirCifras(numM, l);//se invierte el orden del número en base M debido a que no estaba en el orden adecuado
}

void invertirCifras(char num[], int L)
{
	int i=0, j=0;
	char final[25]="";
	char aux=' ';
	
	for(i=0; i<L; i++)
	    final[i]=num[L-(i+1)];
	
	imprimir(final);
	//	final[i]= num[L-(i+1)];//L-(i+1) para que inicie en la última casilla sin considerar '\0'
	//coloca el final de cadena en la última casilla
}

void imprimir(char arr[])
{
	int k=0;
	
	printf("\n");
	for(k=0; arr[k]!='\0'; k++)
		printf("%c", arr[k]);
}

void elDestructor(char dig[])
{
	free(dig);
}

