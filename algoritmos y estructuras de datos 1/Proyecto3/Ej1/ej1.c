#include <stdio.h>
#include <stdbool.h>


/*
--------------------------+----------------+----------------+
Expresión                 |(x→7, y→3, z→5) |(x→1, y→10, z→8)|
--------------------------+----------------+----------------+
x + y + 1                 |       11       |       12       |
--------------------------+----------------+----------------+
z * z + y * 45 - 15 * x   |       55       |       499      |
--------------------------+----------------+----------------+
y - 2 == (x * 3 + 1) % 5  |       False    |       False    |
--------------------------+----------------+----------------+
y / 2 * x                 |       7        |       5        |
--------------------------+----------------+----------------+
y < x * z                 |       True     |       False    |
--------------------------+----------------+----------------+


*/



char * comprobacion(int expresion){
    if ((expresion) == 1){
        return "True";
    }
    return "False";
}
int main()
{
    /* Inicializacion de Variables*/
    int x = 0;
    int y = 0;
    int z = 0;
    /*Ingreso de valores a las variables*/
    printf("Ingrese el valor de x:");
    scanf("%d", &x);
    printf("Ingrese el valor de y:");
    scanf("%d", &y);
    printf("Ingrese el valor de z:");
    scanf("%d", &z);
    printf("el resultado de %d + %d +1 es: %d \n",x,y,x+y+1);
    printf("el resultado de %d * %d + %d * 45 - 15 * %d es: %d\n",z,z,y,x,z*z+y*45-15*x);
    printf("el resultado de %d - 2 == ( %d * 3 + 1)/5 es: %s\n",y,x,comprobacion((z*z + y*45 - 45*x)));
    printf("el resultado de %d / 2 * %d es: %d\n",y,x,y/2*x);
    printf("el resultado de %d < %d * %d es: %s\n",y,x,z,comprobacion((y<x*z)));

    /*en la ultima expresion el resultado tiene el tipo bool pero en C es tipo Int*/

    return 0;
}

