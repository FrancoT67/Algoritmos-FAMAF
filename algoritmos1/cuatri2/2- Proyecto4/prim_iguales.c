#include <stdio.h>
#include "./funcionesAux.h"
#include "./funcionesAuxArreglos.h"
#define tamañoArreglo 5
/**
 * Ejemplos de ejecucion:
 * ./primC.exe
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es:[1,2,3,4,5]
    La longitud del tramo inicial cuyos elementos son iguales es:1
 * ./primC.exe
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:1
    Ingrese un valor para la posicion 2:1
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es:[1,1,1,4,5]
    el mayor tramo inicial del arreglo a[] que tiene a todos sus elementos iguales es:[1,1,1]
    La longitud del tramo inicial cuyos elementos son iguales es:3
*/

int prim_iguales(int tam, int a[]);

int main()
{
    int longitud = 0;
    int arreglo[tamañoArreglo];
    pedir_arreglo(tamañoArreglo, arreglo);
    printf("El arreglo generado es:");
    imprimir_arreglo(tamañoArreglo, arreglo);
    longitud = prim_iguales(tamañoArreglo, arreglo);
    printf("La longitud del tramo inicial cuyos elementos son iguales es:%d", longitud);
    return 0;
}

int prim_iguales(int tam, int a[])
{
    int longitudIguales = 0;
    int i = 0;
    while (i < tam)
    {
        if (a[0] != a[i])
        {

            break;
        }
        longitudIguales = longitudIguales + 1;
        i = i + 1;
    }
    if (longitudIguales > 1)
    {
        printf("el mayor tramo inicial del arreglo a[] que tiene a todos sus elementos iguales es:");
        imprimir_arreglo(longitudIguales, a);
    }

    return longitudIguales;
}
