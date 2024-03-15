#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/imprimeTexto.h"

/* Declaracion de Prototipos de Ej1. A). */
void hola_hasta(int n);

int main()
{
    // Inicializacion de variables.
    int n = 0;

    // Solicitud de Datos al usuario.
    n = pedirEntero('n');

    // Control de que los valores sean Positivos.
    assert(n >= 0);

    // Llamado del Prototipo de Función.
    hola_hasta(n);

    return 0;
}

// Definicion del Prototipo.
void hola_hasta(int n)
{
    int i = 0;

    while (i < n)
    {
        // Funcion Auxiliar que imprime un texto pasado como argumento.
        imprimeTexto("Hola");
        i = i + 1;
    }
}
