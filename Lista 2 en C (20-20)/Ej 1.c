#include <stdio.h>
#include <stdlib.h>

int valorA(int x, int y);//realiza la operacion de la opcion a
int valorB(int x, int y);//realiza la operacion de la opcion b
int valorC(int x, int y);//realiza la operacion de la opcion c

int main()
{
    int x=0, y=0, c=0;//variable c para determinar qué valores tendrán x & y

    printf("Escoge una opcion para conocer el valor de z dependiendo el valor de x & y (ingresa el numero)\n");
    printf("0. x=0, y=0\n1. x=0, y=1\n2. x=1, y=0\n3. x=1, y=1\n");
    scanf("%d", &c);

    if(c==0)//para x=0, y=0
    {
        x=0;
        y=0;

        valorA(x, y);
        valorB(x, y);
        valorC(x, y);
    }
    else if(c==1)//para x=0, y=1
    {
        x=0;
        y=1;

        valorA(x, y);
        valorB(x, y);
        valorC(x, y);
    }
    else if(c==2)//para x=1, y=0
    {
        x=1;
        y=0;

        valorA(x, y);
        valorB(x, y);
        valorC(x, y);
    }
    else if(c==3)//para x=1, y=1
    {
        x=1;
        y=1;

        valorA(x, y);
        valorB(x, y);
        valorC(x, y);
    }
    else
        printf("\nEl numero ingresado no es valido para estas opciones.");

    return 0;
}

int valorA(int x, int y)
{
    int z=0;

    if(((x==0) && (y==1)) || ((x==1) && (y==0)))
            z=1;
        else
            z=0;

    printf("\na) El valor de z es: %d", z);
}
int valorB(int x, int y)
{
    int z=0;

    if(((x==1) || (y==0)) && ((x==0) && (y==1)))
        z=1;
    else
        z=0;

    printf("\nb) El valor de z es: %d", z);
}
int valorC(int x, int y)
{
    int z=0;

    if(x==0)
    {
        if(y==0)
            z=0;
        else
            z=1;
    }
    else
    {
        if(y==0)
            z=2;
        else
            z=3;
    }

    printf("\nc) El valor de z es: %d", z);
}
