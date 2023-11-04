#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/imprimeTexto.h"

// Definciion del Struct div_t.
struct div_t
{
    int cociente;
    int resto;
};

// Prototipo de la funcion que recrea el algoritmo de la division.
struct div_t division(int x, int y);
int main()
{
    // Instanciacion de Variables.
    int x = 0;
    int y = 0;

    // Solicitud de los Valores al usuario.
    x = pedirEntero('x');
    y = pedirEntero('y');

    // Validacion del divisor.
    if (y == 0)
    {
        imprimeTexto("No se puede dividir por cero.");
        assert(y != 0);
    }

    printf("Los resuldatos de la division entre %d y %d: \nEl cociente es: %d\nEl resto es: %d", x, y, division(x, y).cociente, division(x, y).resto);

    return 0;
}

// Funcion que hace la Division
struct div_t division(int x, int y)
{

    struct div_t resultado;
    int contadorCociente = 0;

    while (x >= y)
    {
        x = x - y;
        contadorCociente += 1;
    }
    resultado.cociente = contadorCociente;
    resultado.resto = x;

    return resultado;
};