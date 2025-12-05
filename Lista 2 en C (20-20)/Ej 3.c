#include <stdio.h>
#include <stdlib.h>

//firmas para las funciones de los ciclos for
void opcionA(int n);
void opcionB(int n);
void opcionC(int n);
void opcionD(int n);
//firmas de las funciones de los ciclos en version while
void opcionWhileA(int n);
void opcionWhileB(int n);
void opcionWhileC(int n);
void opcionWhileD(int n);

int main()
{
    int N=0, c=0, w=0;//con c se determinará el valor de N;
						//con w se determina si se calculará con la version for o while
    printf("El valor de k varia. Ingresa un numero para conocer el valor de k en funcion del valor de N.\n");
    printf("0. N=0; 1. N=1; 2. N=10; 3. N=30; 4. N=60; 5. N=90; 6. N=100; ");
    scanf("%d",&c);

    printf("\nIngresa 0 si quieres obtener el valor de k mediante ciclos for o 1 si lo quieres obtener con ciclos while. ");
    scanf("%d", &w);

    if(w==0)//version for
    {
        printf("Se procedera a obtener el valor de k con ciclos for...\n");
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
                N=30;
                opcionA(N);
                opcionB(N);
                opcionC(N);
                opcionD(N);

                break;

            case 4:
                N=60;
                opcionA(N);
                opcionB(N);
                opcionC(N);
                opcionD(N);

                break;

            case 5:
                N=90;
                opcionA(N);
                opcionB(N);
                opcionC(N);
                opcionD(N);

                break;

            case 6:
                N=100;
                opcionA(N);
                opcionB(N);
                opcionC(N);
                opcionD(N);

                break;
        }
    }
    else if(w==1)//version while
    {
        printf("Se procedera a obtener el valor de k con ciclos while...");
        switch(c)
        {
            case 0:
                N=0;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 1:
                N=1;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 2:
                N=10;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 3:
                N=30;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 4:
                N=60;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 5:
                N=90;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;

            case 6:
                N=100;
                opcionWhileA(N);
                opcionWhileB(N);
                opcionWhileC(N);
                opcionWhileD(N);

                break;
        }
    }
    return 0;
}
//funciones para los ciclos for
void opcionA(int n)
{
    int k=0;
    printf("a)\n");
    for(k=0; k<n; k++)
        printf("%d\n",k);
    printf("Final= %d\n", k);
}

void opcionB(int n)
{
    int k=0;
    printf("b)\n");
    for(k=n; k>=0; k--)
        printf("%d\n", k);
    printf("Final= %d\n", k);
}

void opcionC(int n)
{
    int k=0;
    printf("c)\n");
    for(k=1; k<n; k*=2)
        printf("%d\n", k);
    printf("Final= %d\n", k);
}

void opcionD(int n)
{
    int k=0;
    printf("d)\n");
    for(k=n; k>0; k/=2)
        printf("%d\n", k);
    printf("Final= %d", k);
}
//funciones para las versiones while de los ciclos
void opcionWhileA(int n)
{
    int k=0;
    printf("a)\n");
    while(k<n)
    {
        printf("%d\n", k);
        k++;
    }
    printf("Final= %d\n", k);
}

void opcionWhileB(int n)
{
    int k=n;
    printf("b)\n");
    while(k>=0)
    {
        printf("%d\n", k);
        k--;
    }
    printf("Final= %d\n", k);
}

void opcionWhileC(int n)
{
    int k=1;
    printf("c)\n");
    while(k<n)
    {
        printf("%d\n", k);
        k*=2;
    }
    printf("Final= %d\n", k);
}

void opcionWhileD(int n)
{
    int k=n;
    printf("d)\n");
    while(k>0)
    {
        printf("%d\n", k);
        k/=2;
    }
    printf("Final= %d\n", k);
}
