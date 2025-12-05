#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//los nombres de las funciones describen lo que hacen, y devuelven un valor de tipo flotante
float calcularCinetica(float m, float v0, float g, float t);
float calcularPotencial(float m, float v0, float h0, float g, float t);
float calcularCineticaCircular(float m, float A, float w, float t, float phi);//para movimiento circular
float calcularPotencialCircular(float k, float A, float w, float t, float phi);//para movimiento circular
float calcularHamiltoniano(float cinet, float poten);
float calcularLagrangiano(float cinet, float poten);

int main()
{
    float K=0, U=0, L=0, H=0;//K es la energia cinetica; U, la potencial; L, el lagrangiano; H, el hamiltoniano
    float masa=0, vel_0=0, altura_0=0, tiempo=0, grav=9.8;//vel_0 es la velocidad inicial; grav es la gravedad
    float coefResort=0, amplitud=0, frecAng=0, phi=0;//coefResorte= coeficiente de resorte; frecAng= frecuencia angular
    int c=0;//variable para decidir qué calcular

    printf("Que quieres calcular? (Ingresa el numero respectivo)\n0. Caida libre.\n1. Ascenso.\n2. Movimiento circular uniforme.\n");
    scanf("%d", &c);

    printf("\nIngresa el valor del tiempo: ");
    scanf("%f", &tiempo);

    if(c==0)//calcula la caida libre
    {
        printf("\nEstas calculando la caida libre...");
        printf("\nIngresa el valor de la masa: ");
        scanf("%f", &masa);

        printf("\nIngresa el valor de la velocidad inicial: ");
        scanf("%f", &vel_0);

        printf("\nIngresa el valor de la altura inicial: ");
        scanf("%f", &altura_0);

        K=calcularCinetica(masa, vel_0, grav, tiempo);
        U=calcularPotencial(masa, vel_0, altura_0, grav, tiempo);
        H=calcularHamiltoniano(K, U);
        L=calcularLagrangiano(K, U);

        printf("\nLa energia cinetica K es de: %f", K);
        printf("\nLa energia potencial U es de: %f", U);
        printf("\nEl Hamiltoniano H es de: %f", H);
        printf("\nEl Lagrangiano L es de: %f", L);
    }
    else if(c==1)//ascenso
    {
        printf("\nEstas calculando el ascenso...\nNota: la gravedad es negativa.");
        grav*=-1;

        printf("\nIngresa el valor de la masa: ");
        scanf("%f", &masa);

        printf("\nIngresa el valor de la velocidad inicial: ");
        scanf("%f", &vel_0);

        printf("\nIngresa el valor de la altura inicial: ");
        scanf("%f", &altura_0);

        K=calcularCinetica(masa, vel_0, grav, tiempo);
        U=calcularPotencial(masa, vel_0, altura_0, grav, tiempo);
        H=calcularHamiltoniano(K, U);
        L=calcularLagrangiano(K, U);

        printf("\nLa energia cinetica K es de: %f", K);
        printf("\nLa energia potencial U es de: %f", U);
        printf("\nEl Hamiltoniano H es de: %f", H);
        printf("\nEl Lagrangiano L es de: %f", L);
    }
    else if(c==2)//calcular movimiento circular
    {
        printf("\nEstas calculando el movimiento circular uniforme...");
        printf("\nIngresa el valor de la masa: ");
        scanf("%f", &masa);

        printf("\nIngresa la amplitud: ");
        scanf("%f", &amplitud);

        printf("\nIngresa la frecuencia angular: ");
        scanf("%f", &frecAng);

        printf("\nIngresa el valor de la fase inicial (phi): ");
        scanf("%f", &phi);

        K=calcularCineticaCircular(masa, amplitud, frecAng, tiempo, phi);
        U=calcularPotencialCircular(masa, amplitud, frecAng, tiempo, phi);
        H=calcularHamiltoniano(K, U);
        L=calcularLagrangiano(K, U);

        printf("\nLa energia cinetica K es de: %f", K);
        printf("\nLa energia potencial U es de: %f", U);
        printf("\nEl Hamiltoniano H es de: %f", H);
        printf("\nEl Lagrangiano L es de: %f", L);

    }
    else
        printf("Numero invalido.");

    return 0;
}

float calcularCinetica(float m, float v0, float g, float t)
{//m= masa; v0= velocidad inicial; g=gravedad; t= tiempo
    float K=0;//K= energía cinética
    K=(1/2)*m*(pow((v0-g*t),2));

    return K;
}

float calcularPotencial(float m, float v0, float h0, float g, float t)
{//h0= altura inicial
    int U=0;//U= energía potencial
    U=m*g*(h0+(v0*t)-(1/2)*g*pow(t,2));

    return U;
}

float calcularCineticaCircular(float m, float A, float w, float t, float phi)
{//A= amplitud; w= frecuencia angular; phi= fase inicial
    float K=0;
    K= (1/2)*m*(pow(-A*w*sin(w*t+phi),2));

    return K;
}
float calcularPotencialCircular(float k, float A, float w, float t, float phi)
{//k= coeficiente de resorte
    float U=0;
    U= k*(pow(A*cos(w*t+phi),2));

    return U;
}
float calcularHamiltoniano(float cinet, float poten)
{//cinet= energía cinetica; potenc= energía potencial
    float H=0;
    H=cinet+poten;

    return H;
}

float calcularLagrangiano(float cinet, float poten)
{
    float L=0;
    L=cinet-poten;

    return L;
}

