#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

/**
 * Ejemplos de ejecucion:
 *  .\multi1C.exe
    Ingrese un entero para la variable x:12
    Ingrese un entero para la variable y:15
    El valor ORIGINAL de X es :12
    El valor MODIFICADO de X es:13
    El valor ORIGINAL de Y es :15
    El valor MODIFICADO de Y es:27
 * .\multi1C.exe
    Ingrese un entero para la variable x:17
    Ingrese un entero para la variable y:23
    El valor ORIGINAL de X es :17
    El valor MODIFICADO de X es:18
    El valor ORIGINAL de Y es :23
    El valor MODIFICADO de Y es:40
*/

int main()
{
    int x, X, y, Y = 0;
    x = pedirEntero('x');
    X = x;
    y = pedirEntero('y');
    Y = y;
    assert(x == X && y == Y);
    x = X + 1;
    y = X + Y;
    assert(x == X + 1 && y == X + Y);
    printf("El valor ORIGINAL de X es :%d\nEl valor MODIFICADO de X es:%d\n", X, x);
    printf("El valor ORIGINAL de Y es :%d\nEl valor MODIFICADO de Y es:%d", Y, y);
    return 0;
}
