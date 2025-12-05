#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirCadena(char cad[]);
int obtenerLongitud(char cad[]);//regresa la longitud de la cadena como valor entero
void ordenarAscendentemente(char cad[]);
void ordenarDescendentemente(char cad[]);
void desordenarAleatoriamente(char cad[], char alfa[], int L);
void invertirCadena(char cad[], char alfa[], int L);
void convertirEnMayusculas(char cad[]);
void convertirEnMinusculas(char cad[]);
void anadirEspacio(char cad[], char cadEsp[]);
void destruirCadena(char cad[]);

int main()
{
	int l=0;
    char cadena[100]="";//cadena inicial
	char desorden[100]="";//cadena desordenada
    char conEspacios[2*100]="";//cadena con espacio entre caracteres con el doble de espacio que los otros arreglos
    
    printf("Ingrese una cadena de texto.\n");
    gets(cadena);//se usa gets() para que se pueda ingresar más de una palabra, caso que no ocurre con scanf()

    printf("La cadena es:\n");
    imprimirCadena(cadena);
	
	printf("\na) Encontrar la longitud de la cadena.\n");
    l= obtenerLongitud(cadena);
    printf("La longitud de la cadena es de %d caracteres.\n", l);
    
    printf("\nb) Ordenar alfabeticamente, en orden ascendente y descendente, las letras de la cadena.");
    printf("\nEl orden ascendete quedaria asi:\n");
	ordenarAscendentemente(cadena);
	printf("\nEl orden descendente quedaria de esta forma:\n");
    ordenarDescendentemente(cadena);
    
	printf("\nc) Desordenar aleatoriamente los caracteres de la cadena.\n");
	desordenarAleatoriamente(cadena, desorden, l);
	
	printf("\nd) Invertir el orden de los caracteres de la cadena.\n");
	invertirCadena(cadena, desorden, l);
	
	printf("\ne) Cambiar las letras de mayusculas a minusculas y viceversa.\n");
	printf("\nLa cadena en mayusculas es:\n");
	convertirEnMayusculas(cadena);
	printf("\nLa cadena en minusculas es:\n");
	convertirEnMinusculas(cadena);
	
	printf("\nf) Insertar un espacio entre dos caracteres.\n");
	anadirEspacio(cadena, conEspacios);
    
	destruirCadena(cadena);
	destruirCadena(desorden);
	destruirCadena(conEspacios);	
	
	return 0;
}
//cad es la cadena
void imprimirCadena(char cad[])
{
	int i=0;
	
	for(i=0; cad[i]!='\0'; i++)
		printf("%c", cad[i]);
}

int obtenerLongitud(char cad[])
{
	int k=0;
	
	for(k=0; cad[k]!='\0'; k++);//el contador aumenta mientras no encuentre el fin de cadena
	
	return k;
}

void ordenarAscendentemente(char cad[])
{
	int i=0, j=0;
	char aux=' ';
	
	for(i=0; cad[i]!='\0'; i++)
    {
        for(j=i+1; cad[j]!='\0'; j++)
        {
            if(cad[j]<cad[i])//la comparación es por su valor en ASCII
            {
                aux=cad[j];
                cad[j]=cad[i];
                cad[i]=aux;    
            }
        }
    }

    imprimirCadena(cad);
}

void ordenarDescendentemente(char cad[])
{
	int i=0, j=0;
	char aux[1]="";
	
	for(i=0; cad[i]!='\0'; i++)
    {
        for(j=i+1; cad[j]!='\0'; j++)
        {
            if(cad[j]>cad[i])
            {
                aux[0]=cad[j];
                cad[j]=cad[i];
                cad[i]=aux[0];
                
            }
        }
    }

    imprimirCadena(cad);
}

void desordenarAleatoriamente(char cad[], char alfa[], int L)
{//alfa= arreglo desordenado; L= longitud de cadena
	int i=0, j=0, k=0;
	int arrRep[L];
	//arrRep guardará las posiciones repetidas de la generación de posiciones aleatorias
	srand(time(NULL));
	
	arrRep[0]=0;
	alfa[0]=cad[0];//la primera casilla de alfa obtiene el primer caracter de la cadena
	
	for(i=1; i<L; i++)
	{
		k=(rand()%(L-1))+1;//generador de posiciones aleatorias; se evita la posicion 0
		for(j=0; j<=i; j++)
		{
			if(arrRep[j]!=k)
			{
				alfa[i]=cad[k];
				arrRep[i+1]=k;
			}
			else
			{
				alfa[i]=' ';//quita el caracter de la posición repetida
				arrRep[i+1]=0;//quita la posición repetida
				i--;//se mantiene el valor del contador
				break;
			}
		}
	}
	
	imprimirCadena(alfa);
	destruirCadena(alfa);
}

void invertirCadena(char cad[], char alfa[], int L)
{
	int i=0;
	//se requiere la longitud de la cadena para que se mantenga esa misma cantidad en el arreglo invertido
	for(i=0; i<L; i++)
    	alfa[i]=cad[L-(i+1)];//se usa la posición L-(i+1) para evitar colocar el final de cadena en la primer casilla
    cad[L]='\0';//en la última casilla se coloca el final de cadena
    
    imprimirCadena(cad);
}

void convertirEnMayusculas(char cad[])
{
	int i=0;
	
	for(i=0; cad[i]!='\0'; i++)
        if(cad[i]>96 && cad[i]<123)//'a' en ASCII es 97, y 'A' es 65, y para llegar a ese caracter
            cad[i]=cad[i]-32;//se hace la resta de 32; con ese rango de valores se evita convertir
							//a los caracteres que ya están en mayúsculas y otros caracteres  
    imprimirCadena(cad);
}

void convertirEnMinusculas(char cad[])
{
	int i=0;
	
	for(i=0; cad[i]!='\0'; i++)
        if(cad[i]>64 && cad[i]<91)//'A' en ASCII es 65 y 'Z' es 90, así que para llegar a 97 ('a') se le suma 32
            cad[i]=cad[i]+32;//con este rango de valores se evita convertir las letras minúsculas
    
	imprimirCadena(cad);    
}

void anadirEspacio(char cad[], char cadEsp[])
{//cadEsp= cadena con espacios
	int i=0;
	
	for(i=0; cad[i]!='\0';i++)
    {
        cadEsp[2*i]=cad[i];//se coloca un caracter en cada posición par del arreglo 
        cadEsp[2*i+1]=' ';//se coloca un espacio en cada posición impar del arreglo
    }
    
    imprimirCadena(cadEsp);
}

void destruirCadena(char cad[])
{
	free(cad);
}
