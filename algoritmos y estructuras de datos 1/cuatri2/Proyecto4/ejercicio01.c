#include <stdio.h>
#include <assert.h>

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
    int veces = 0;
    printf("Ingrese un numero entero positivo para repetir la palabra 'Hola':");
    scanf("%d", &veces);
    assert(veces > 0);
    hola_hasta(veces);

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
