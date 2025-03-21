#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

/**
 * Ejecucion del programa:
 *  .\multi2C.exe
    Ingrese un entero para la variable x:12
    Ingrese un entero para la variable y:15
    Ingrese un entero para la variable z:89
    El valor ORIGINAL de X es :12
    El valor MODIFICADO de X es:15
    El valor ORIGINAL de Y es :15
    El valor MODIFICADO de Y es:116
    El valor ORIGINAL de Z es :89
    El valor MODIFICADO de Z es:27
 *  .\multi2C.exe
    Ingrese un entero para la variable x:12
    Ingrese un entero para la variable y:10
    Ingrese un entero para la variable z:8
    El valor ORIGINAL de X es :12
    El valor MODIFICADO de X es:10
    El valor ORIGINAL de Y es :10
    El valor MODIFICADO de Y es:30
    El valor ORIGINAL de Z es :8
    El valor MODIFICADO de Z es:22
*/
int main()
{
    int x, y, z = 0;
    int X, Y, Z = 0;
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');
    X = x;
    Y = y;
    Z = z;
    assert(x == X && y == Y && z == Z);
    x = Y;
    y = X + Y + Z;
    z = Y + X;
    assert(x == Y && y == Y + X + Z && z == Y + X);
    printf("El valor ORIGINAL de X es :%d\nEl valor MODIFICADO de X es:%d\n", X, x);
    printf("El valor ORIGINAL de Y es :%d\nEl valor MODIFICADO de Y es:%d\n", Y, y);
    printf("El valor ORIGINAL de Z es :%d\nEl valor MODIFICADO de Z es:%d", Z, z);
    return 0;
}
