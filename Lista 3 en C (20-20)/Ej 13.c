#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **hyper=NULL;//un doble apuntador
    int *p=NULL, *q= NULL;
    
	int x= 2020;
    printf("\nx= 2020;\t x= %d, &x= %X", x, &x);//se imprime el valor de x y su direccion de memoria
    
    p= &x;
    printf("\np= &x;\t\t p= %X, *p= %d, &p= %X", p, *p, &p);
    //'p' apunta a &x, por lo que *p es 2020 y 'p' es &x
    hyper= &p;
    printf("\nhyper= &p;\t hyper= %X, *hyper= %X, **hyper= %d, &hyper= %X", hyper, *hyper, **hyper, &hyper);
    //hyper apunta a &p, por lo que hyper es &p, *hyper es &x, y **hyper es 2020 
    q= *hyper;
    printf("\nq= *hyper;\t q= %X, *q= %d, &q= %X", q, *q, &q);
    //'q' tiene lo que apunta *hyper, que es &x, por lo que *q es 2020
	*q= 2021;
    printf("\n*q= 2021;\t **hyper= %d, *q= %d, *p= %d, x= %d", **hyper, *q, *p, x);
    //*q cambia a 2021, por lo que **hyper, *p y x cambian a este valor tambien
    return 0;
}

