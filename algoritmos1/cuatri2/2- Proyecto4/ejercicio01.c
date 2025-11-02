#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

// Firma del prototipo hola_hasta
void hola_hasta(int n);

// Ejemplo de ejecucion:
/*
 ./ej1C
Ingrese un numero para repetir la palabra 'Hola':1

        Hola
 ./ej1C
Ingrese un numero para repetir la palabra 'Hola':4

        Hola
        Hola
        Hola
        Hola
 ./ej1C
Ingrese un numero para repetir la palabra 'Hola':16

        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola
        Hola

*/

int main()
{
    int n = 0;
    n = pedirEntero('n');
    assert(n > 0);
    hola_hasta(n);

    return 0;
}

void hola_hasta(int n)
{
    while (n > 0)
    {
        printf("\n\tHola");
        n = n - 1;
    }
}
