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

    // Instanciacion de Variables Auxiliares.
    int xaux = x;
    int yaux = y;
    int zaux = z;

    // validacion de que los valores originales hayan sido guardados en variables auxiliares.
    assert(x == xaux && y == yaux && z == zaux);

    /*
    {Pre: x = X, y = Y}
    x, y := x + 1, x + y
    {Post: x = X + 1, y = X + Y}
    */
    // Logica pedida ⬆.
    x = xaux + 1;
    y = xaux + yaux;

    printf("El valor de X=%d.\nEL valor de Y=%d.\n", x, y);
    return 0;
}