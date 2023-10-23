#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/imprimeTexto.h"

int suma_hasta(int n);
int main()
{
    int veces = 0;
    int resultado = 0;
    veces = pedirEntero('v');
    if (veces < 0)
    {
        imprimeTexto("\n\t************************************************\n\n\tSe debe ingresar un valor positivo, es decir mayor o igual a 0.\n\n\t************************************************");
        assert(veces >= 0);
    }
    assert(veces >= 0);
    resultado = suma_hasta(veces);
    assert(resultado >= 0);

    printf("El resultado de la suma de los primeros %d naturales es: %d", veces, resultado);

    return 0;
}

int suma_hasta(int n)
{
    int acumulador = 0;
    for (int i = 0; i <= n; i++)
    {
        printf("\t%d + %d\n", acumulador, i);
        acumulador += i;
    }
    return acumulador;
}
