#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"

int main()
{

    // Instanciacion de Variables.
    int x = 0;
    int y = 0;
    int z = 0;

    // Solicitud de Datos al Usuario.
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');

    // Instanciación de Variables Auxiliares.
    int xaux = x;
    int yaux = y;
    int zaux = z;

    // validacion de que los valores originales hayan sido guardados en variables auxiliares.
    assert(x == xaux && y == yaux && z == zaux);
    /*
        {Pre: x = X, y = Y, z = Z}
        x, y, z := y, y + x + z, y + x
        {Post: x = Y, y = Y + X + Z, z = Y + X}
    */

    // Lógica pedida ⬆.
    x = yaux;
    y = yaux + xaux + zaux;
    z = yaux + xaux;

    printf("El valor de X=%d.\nEL valor de Y=%d.\nEL valor de Z=%d.", x, y, z);
    return 0;
}