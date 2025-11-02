#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

/**
 * Ejemplos de ejecucion:
 *  .\absC.exe
    Ingrese un entero para la variable x:12
    El valor absoluto de 12 es:12
*  .\absC.exe
    Ingrese un entero para la variable x:-12
    El valor absoluto de -12 es:12
*  .\absC.exe
    Ingrese un entero para la variable x:0
    El valor absoluto de 0 es:0
*/

// Firma de la funcion absoluto.
int absoluto(int num);
int main()
{
    int x, xAux = 0;
    x = pedirEntero('x');
    xAux = x;
    x = absoluto(x);
    assert(x >= 0);
    printf("El valor absoluto de %d es:%d", xAux, x);
    return 0;
}

int absoluto(int num)
{
    if (num < 0)
    {
        return num * (-1);
    }

    return num;
}
