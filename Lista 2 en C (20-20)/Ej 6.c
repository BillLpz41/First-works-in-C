#include <stdio.h>
#include <stdlib.h>

//firma de la funcion que regresará un valor entero
int convertir(int a, int b, int c, int d);

void main()
{
    int u=0, v=0, w=0, x=0, y=0, z=0;
    
    for(u=0; u<=1; u++)
        for(v=0; v<=1; v++)
            for(w=0; w<=1; w++)
                for(x=0; x<=1; x++)
                {
                    y=convertir(u, v, w, x);//u=a, v=b, w=c, x=d
                    z=convertir(x, w, v, u);//x=a, w=b, v=c, u=d
                    printf("Con u= %d, v= %d, w=%d & x= %d, tenemos que y= %d, z= %d\n", u, v, w, x, y ,z);
                }
}

//realiza la conversion binaria a decimal
int convertir(int a, int b, int c, int d)
{
    int e=0;
    e=8*a + 4*b + 2*c + 1*d;
 // a=1; b=2; c=3; d=4; //Esta parte del codigo es innecesaria, pues solamente utiliza memoria.

    return e;//regresa el valor de e; u y z obtienen ese valor
}
