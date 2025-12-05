#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define q 1.6E-19 //carga electrica de un electron

float inicializar(float f[]);// inicializa el arreglo para las fuerzas

int main()
{
    float op=0.0; //variable para determinar qué calculo de fuerza se realizará
    int i=0.0; //contador para ciclos
    //a) movimiento circular
    float f_Cir[3]; //arreglo para la fuerza circular en sus tres componentes
    float masa=0; //masa del cuerpo
    float vel_ang[3]; //velocidad angular en sus tres componentes
    float radio[3]; //radio en sus tres componentes
    //b) ley de elasticidad de Hooke
    float f_Elas[3]; //fuerza de elasticidad
    float gravedad[3]={0.0,0.0,-9.8}; //gravedad en su componente vertical
    float coefResort=0; //coeficiente de resorte
    float vec_pos[3]; //vector de posicion
    //c) fuerza de Lorentz
    float f_Lor[3]; //arreglo para la fuerza
    float E[3]; //arreglo para el campo electrico en sus tres componentes
    float v[3]; //velocidad en sus tres componentes
    float B[3]; //campo magnetico en sus tres componentes
    //d) desplazamiento angular
    float des[3]; //desplazamiento angular
    float theta=0; //desplazamiento angular inicial
    float t=0; //tiempo

    printf("Que desea calcular? (Ingresa el numero correspondiente a la formula)\n");
    printf("0. Movimiento circular.\n1. Elasticidad.\n2. Fuerza de Lorentz.\n3. Desplazamiento angular.\n");
    scanf("%f", &op);//se ingresa la opcion que se quiere calcular

    if(op==0.0)//opcion a)
    {
        inicializar(f_Cir);
        printf("Estas calculando el movimiento circular.\n");

        printf("Ingresa la masa del cuerpo: ");
        scanf("%f", &masa);

        for(i=0; i<3; i++)//se solicita el valor de cada variable en cada componente
        {
            printf("\nIngresa la velocidad angular del cuerpo en el %der componente: ", i+1);
            scanf("%f", &vel_ang[i]);

            printf("\nIngresa el %der componente del vector radio: ", i+1);
            scanf("%f",&radio[i]);

            f_Cir[i]=masa*(pow(vel_ang[i],2))*radio[i]; //calcula la fuerza en su componente correspondiente al valor i del ciclo
        }

		printf("\nFuerza del movimiento circular es: <%f, %f, %f>.\n", f_Cir[0], f_Cir[1], f_Cir[2]);
		free(f_Cir);
		free(vel_ang);
		free(radio);
    }
    else if(op==1.0)//opcion b)
    {
        inicializar(f_Elas);
        printf("Estas calculando la elasticidad.\n");

        printf("Ingresa la masa del cuerpo: ");
        scanf("%f", &masa);

        printf("\nIngresa el valor del coeficiente de resorte k: ");
        scanf("%f",&coefResort);

        for(i=0; i<3; i++)//se solicita ingresar el valor de cada variable para cada componente
        {
            printf("\nIngresa la velocidad angular del cuerpo en el %der componente: ", i+1);
            scanf("%f", &vel_ang[i]);

            printf("\nIngresa el %der componente del vector de posicion: ", i+1);
            scanf("%f",&radio[i]);

            f_Elas[i]=(masa*gravedad[i])-(coefResort*vec_pos[i]);
        }

        printf("\nFuerza de la elasticidad es: <%f, %f, %f>.\n", f_Elas[0], f_Elas[1], f_Elas[2]);
		free(f_Elas);
		free(vel_ang);
		free(gravedad);
		free(radio);
		free(vec_pos);
    }
    else if(op==2.0)//opcion c)
    {
        inicializar(f_Lor);
        printf("Estas calculando la fuerza de Lorentz.\n");

        for(i=0; i<3; i++)
        {
            printf("\nIngresa el valor del campo electrico en el %der componente: ", i+1);
            scanf("%f", &E[i]);

            printf("\nIngresa el valor del %der componente del campo magnetico: ", i+1);
            scanf("%f",&B[i]);

            printf("\nIngresa la velocidad en el %der componente: ", i+1);
            scanf("%f",&v[i]);
        }
//puesto que es un producto cruz, se calcula cada componente fuera del ciclo
        f_Lor[0]=(q*E[0])+ ( ( (q*v[1]*B[2]) - (q*v[2]*B[1])) - ( (q*v[0]*B[2]) - (q*v[2]*B[0]) ) + ( (q*v[0]*B[1]) - (q*v[1]*B[0]) ) );
        f_Lor[1]=(q*E[1])+ ( ( (q*v[1]*B[2]) - (q*v[2]*B[1])) - ( (q*v[0]*B[2]) - (q*v[2]*B[0]) ) + ( (q*v[0]*B[1]) - (q*v[1]*B[0]) ) );
        f_Lor[2]=(q*E[2])+ ( ( (q*v[1]*B[2]) - (q*v[2]*B[1])) - ( (q*v[0]*B[2]) - (q*v[2]*B[0]) ) + ( (q*v[0]*B[1]) - (q*v[1]*B[0]) ) );

        printf("\nLa fuerza de Lorentz es de: <%e, %e, %e>.\n", f_Lor[0], f_Lor[1], f_Lor[2]);
		free(f_Lor);
		free(E);
		free(B);
		free(v);
    }
    else if(op==3.0)//opcion d)
    {
        inicializar(des);
        printf("Estas calculando el desplazamiento angular.\n");

        printf("Ingresa el desplazamiento angular inicial: ");
        scanf("%f", &theta);

        printf("\nIngresa el tiempo: ");
        scanf("%f",&t);

        for(i=0; i<3; i++)
        {
            printf("\nIngresa la velocidad angular del cuerpo en el %der componente: ", i+1);
            scanf("%f", &vel_ang[i]);

            des[i]= theta + (vel_ang[i]*t) + ((1/2)*vel_ang[i]*(pow(t,2)));
        }

        printf("\nEl desplazamiento angular es: <%f, %f, %f>.\n", des[0], des[1], des[2]);
		free(des);
		free(vel_ang);
    }
    else
        printf("El numero ingresado no es valido.\n");
    
    return 0;
}

float inicializar(float f[])
{
    int i=0;
    for(i=0; i<3; i++) // llena el arreglo de ceros
        f[i]=0;
}
