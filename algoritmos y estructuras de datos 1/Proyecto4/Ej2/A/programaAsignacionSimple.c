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

    // Instanciacion de Variables Auxiliares.
    int xaux = x;
    int yaux = y;
    int zaux = z;

    assert(x == xaux && y == yaux && z == zaux);
    printf("\n****************** **********************\n");
    printf("******* Ejecucion de Funcion 1 ******* \n");
    /*
        {Pre: x = X, y = Y}
        x, y := x + 1, x + y
        {Post: x = X + 1, y = X + Y}
    */

    // Lógica pedida en ⬆ .
    x = xaux + 1;
    y = xaux + yaux;

    printf("El valor de X=%d.\nEL valor de Y=%d.\n", x, y);
    printf("\n****************** **********************\n");
    printf("******* Ejecucion de Funcion 2 ******* \n");
    /*
        {Pre: x = X, y = Y, z = Z}
        x, y, z := y, y + x + z, y + x
        {Post: x = Y, y = Y + X + Z, z = Y + X}
    */

    // Lógica pedida en ⬆ .
    x = yaux;
    y = yaux + xaux + zaux;
    z = yaux + xaux;

    printf("El valor de X=%d.\nEL valor de Y=%d.\nEL valor de Z=%d.\n", x, y, z);

    return 0;
}
