#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *u=NULL, *v=NULL, *w=NULL, *x=NULL, *y=NULL, *z=NULL;
	int a=2, b=3, c=5, d=7, e=11, f=13;
	
	printf("Direcciones de memoria:\n");
	printf("\n&a= %X, &b= %X, &c= %X, &d= %X, &e= %X, &f= %X"
			,&a, &b, &c, &d, &e, &f);
	printf("\n&u= %X, &v= %X, &w= %X, &x= %X, &y= %X, &z= %X"
			,&u, &v, &w, &x, &y, &z);
	
	printf("\nValores iniciales:\n");
	printf("\na= %d, b= %d, c= %d, d= %d, e= %d, f= %d", a, b, c, d, e, f);	
	
	printf("\nInicio de operacioes...");
		
	u= &a; //u hace referencia a la direccion de 'a'
	printf("\nu= &a: u= %X, *u= %d, a= %d", u, *u, a);
	
	*u=90; //*u y 'a' cambia de valor a 90
	printf("\n*u= 90: *u= %d, a= %d", *u, a);
		
	v= &e; //v hace referencia a 'e'
	printf("\nv= &e: v= %X, *v= %d, e= %d", v, *v, e);
	
	e++; //'e' aumenta en 1; *v tambien lo hace
	printf("\ne++: *v= %d, e= %d", *v, e);
	
	x= v; //x obtiene la direccion que hace referencia v (&e)
	printf("\nx= v: x= %X, *x= %d, v= %X", x, *x, v);
	
	(*u)--; //*u se resta en 1
	printf("\n*u= (*u)-- -> (*u)--: *u= %d, a= %d", *u, a);
	
	*x= (*u) + 23; //*x es la suma de *u (89) y 23, por lo que *v y 'e' cambia de valor
	printf("\n*x= (*u)+23: *x= %d, *v= %d, e= %d", *x, *v, e);
	
	y= &c; //'y' apunta a la direccion de c
	printf("\ny= &c: y= %X, *y= %d, c= %d", y, *y, c);
	
	w= &b; //'w' hace referencia a la direccion de b
	printf("\nw= &b: w= %X, *w= %d, b= %d", w, *w, b);
	
	d *=e; //'d' es la multiplicacion de 'd' y 'e'
	printf("\nd *= e: d= %d", d);
	
	f--; //'f' se resta en 1
	printf("\nf--: f= %d", f);
	
	z= &d; //'z' hace referencia a la direccion de 'd'
	printf("\nz= &d: z= %X, *z= %d, d= %d", z, *z, d);
	
	(*z)+=0; //*z se suma con 0
	printf("\n(*z) +=0: z= %X, *z= %d, d= %d", z, *z, d);
	
	u= v; //'u' tiene la direccion que hace referencia 'v' (la direccion de e)
	printf("\nu= v: u= %X, v= %X, *u= %d, *v= %d, e= %d", u, v, *u, *v, e);
	
	(*z)*= 6; //*z es la multiplicacion de *z por 6
	printf("\n(*z)*=6: z= %X, *z= %d, d= %d", z, *z, d);
	
	z= u; //'z' tiene la direccion que hace referencia u (direccion de 'e')
	printf("\nz= u: z= %X, u= %X, *z= %d, *u= %d, *v= %d, e= %d", z, u, *z, *u, *v, e);
	//muestra los valores antes de la suma (puesto que 'w' apunta a 'b')
	printf("\n*w= a+b+c+d+e+f: a= %d, b= %d, c= %d, d= %d, e= %d, f= %d", a, b, c, d, e, f);
	*w= a+b+c+d+e+f;
	printf("*w= %d, b= %d", *w, b); //resultado y nuevo valor de 'b'
	
	*w -= 2019; //*w es la resta de si mismo con 2019
	printf("\n*w -=2019: *w= %d, b= %d", *w, b);
	
	c++; //'c' aumenta en 1 (6)
	printf("\nc++: c= %d", c);
	
	e--; //'e' se resta en 1 (111)
	printf("\ne--: e= %d", e);
	
	u= &a; //'u' tiene la direccion de 'a'
	printf("\nu=&a: u= %X, *u= %d, a= %d", u, *u, a);
	
	v= &b; //'v' tiene la direccion de 'b'
	printf("\nv= &b: v= %X, *v= %d, b= %d", v, *v, b);
	
	w= &c; //'w' apunta a la direccion de 'c' y a su vez 'y' tambien puede cambiar de valor por *w
	printf("\nw= &c: w= %X, *w= %d, c= %d", w, *w, c);

	*x= d+(*u); //*x es la suma de 'd' (4704) y *u (89); ademas, 'e' cambia de valor a este
	printf("\n*x= d+(*u): *x= %d, d= %d, *u= %d, e= %d", *x, d, *u,e);
	
	*y= e+(*v); //*y es la suma de 'e' (4793) y *v (2906); ademas, *w y 'c' cambian de valor a este
	printf("\n*y= e+(*v): *y= %d, e= %d, *v= %d, *w= %d c= %d", *y, e, *v, *w, c);
	
	*z= f+(*w); //*z es la suma de 'f' (12) y *w (7699); ademas, 'e' cambia de valor a este
	printf("\n*z= f+(*w): *z= %d, f= %d, *w= %d, e= %d", *z, f, *w, e);
	
	return 0;
}
