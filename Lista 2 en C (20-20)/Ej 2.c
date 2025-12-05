#include <stdio.h>
#include <stdlib.h>

int opcionA(int n);//inciso a) en forma while
int opcionB(int n);//inciso b) en forma while
int opcionC(int n);//inciso c) en forma while
int opcionForA(int n);//inciso a) version for
int opcionForB(int n);//inciso b) version for
int opcionForC(int n);//inciso c) version for

int main()
{
    int N=0;//valor para N
    int a=0;//se determinará con qué valor de N se harán los ciclos
    int f=0;//se determinará la forma del ciclo

    printf("Con que valor de N quieres conocer el valor de c en los bucles?\n");
    printf("0. N=0; 1. N=1; 2. N=10; 3. N=30; 4. N=60; 5. N=90; 6. N=100;");
    scanf("%d", &a);

    printf("\nCon que version quieres saber el valor de c? Con while (ingresa 0) o for (ingresa 1). ");
    scanf("%d", &f);

    if(f==0)//version con ciclos while
    {

        switch(a)
        {
            case 0:
                N=0;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 1:
                N=1;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 2:
                N=10;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 3:
                N=30;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 4:
                N=60;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 5:
                N=90;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;

            case 6:
                N=100;
                opcionA(N);
                opcionB(N);
                opcionC(N);
            break;
        }
    }
    else if(f==1)//version con ciclos for
    {
        switch(a)
        {
            case 0:
                N=0;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 1:
                N=1;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 2:
                N=10;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 3:
                N=30;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 4:
                N=60;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 5:
                N=90;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;

            case 6:
                N=100;
                opcionForA(N);
                opcionForB(N);
                opcionForC(N);
            break;
        }
    }
    else
        printf("Hey, no ingresaste una opcion valida.");

    return 0;
}
//funciones para los ciclos while
int opcionA(int n)
{
    int c=0;

    printf("\n");

    while(c<n)
    {
        c+=10;
    }
    printf("a) El valor de c es: %d",c );
}

int opcionB(int n)
{
    int c=0;

    printf("\n");

    while(1)
    {
        if(c==n)
            break;
        c+=10;
    }
    printf("b) El valor de c es: %d", c);
}

int opcionC(int n)
{
    int c=0;

    printf("\n");

    while(1)
    {
        c+=10;
        if(c==n)
            break;
    }
    printf("c) El valor de c es: %d", c);
}
//funciones para los ciclos en version for
int opcionForA(int n)
{
    int c=0, i=0;

    printf("\n");

    for(i=0; c<n; i++, c+=10);

    printf("\na)Con la version for, c vale: %d", c);
}

int opcionForB(int n)
{
    int c=0, i=0;

    printf("\n");

    for(i=0; i>0; i++)
    {
        if(c==n)
            break;
        c+=10;
    }
    printf("\nb)Con la version for, c vale: %d", c);
}
int opcionForC(int n)
{
    int c=0, i=0;

    printf("\n");

    for(i=0; i>0; i++)
    {
        c+=10;
        if(c==n)
            break;
    }
    printf("\nc)Con la version for, c vale: %d", c);
}
