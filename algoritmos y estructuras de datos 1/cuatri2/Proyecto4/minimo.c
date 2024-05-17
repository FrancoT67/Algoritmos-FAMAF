#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

// Firma de la funcion 'minimo'.
int minimo(int num1, int num2);
/* Ejemplos de ejecucion:
 .\minC.exe
    A continuacion ingresara 2 valores, evite que ambos sean el mismo.
    Ingrese un entero para la variable x:1
    Ingrese un entero para la variable y:-10
    El menor entre 1 y -10 es: -10
 .\minC.exe
    A continuacion ingresara 2 valores, evite que ambos sean el mismo.
    Ingrese un entero para la variable x:1
    Ingrese un entero para la variable y:1
    Assertion failed: x != y, file .\minimo.c, line 16
*/

int main()
{
    int x, y = 0;
    printf("A continuacion ingresara 2 valores, evite que ambos sean el mismo.\n");
    x = pedirEntero('x');
    y = pedirEntero('y');
    // Comprobacion de que no sean el mismo valor sino el programa no tiene nada que calcular.
    assert(x != y);
    printf("El menor entre %d y %d es: %d", x, y, minimo(x, y));
    return 0;
}

// Definicion de la funcion minimo
int minimo(int num1, int num2)
{

    if (num1 < num2)
    {
        return num1;
    }

    return num2;
}
