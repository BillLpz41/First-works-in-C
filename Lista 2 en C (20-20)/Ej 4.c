#include <stdio.h>
#include <stdlib.h>

//firmas de funciones para los ciclos de los incisos
void opcionA(int n);
void opcionB(int n);
void opcionC(int n);
void opcionD(int n);

int main()
{
    int N=0, c=0;//c determinará el valor de N

    printf("Escoge un valor para N:\n0. N=0; 1. N=1; 2. N=10; 3. N=20; 4. N=40; 5. N=60; 6. N=80; 7. N=100; ");
    scanf("%d", &c);

    switch(c)
    {
        case 0:
            N=0;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 1:
            N=1;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 2:
            N=10;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 3:
            N=20;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 4:
            N=40;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 5:
            N=60;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 6:
            N=80;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;

        case 7:
            N=100;
            opcionA(N);
            opcionB(N);
            opcionC(N);
            opcionD(N);
        break;
    }

    return 0;
}
//funciones de los ciclos de los incisos
void opcionA(int n)
{
    int i=0, j=0;
    printf("a)\n");
    for(i=0, j=0; i<n && j<n; i+=6, j+=6)
        printf("i=%d, j=%d\n", i, j);
    printf("Final= i=%d, j=%d\n", i, j);
}

void opcionB(int n)
{
    int i=0, j=0;
    printf("b)\n");
    for(i=0, j=0; i<n || j<n; i+=6, j+=6)
        printf("i=%d, j=%d\n", i, j);
    printf("Final= i=%d, j=%d\n", i, j);
}

void opcionC(int n)
{
    int i=0, j=0;
    printf("c)\n");
    for(i=n, j=0; i>0 && j<n; i-=6, j+=6)
        printf("i=%d, j=%d\n", i, j);
    printf("Final= i=%d, j=%d\n", i, j);
}

void opcionD(int n)
{
    int i=0, j=0;
    printf("d)\n");
    for(i=n, j=0; i>0 || j<n; i-=6, j+=6)
        printf("i=%d, j=%d\n", i, j);
    printf("Final= i=%d, j=%d\n", i, j);
}
