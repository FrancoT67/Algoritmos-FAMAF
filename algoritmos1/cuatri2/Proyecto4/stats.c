#include <stdio.h>
#include <limits.h>
#include "./funcionesAux.h"
#include "./funcionesAuxArreglos.h"
#define T 4

/**
 * Ejemplos de ejecucion:
 *  .\statsC.exe
    Ingrese un valor para la posicion 0:1.5
    Ingrese un valor para la posicion 1:2.3
    Ingrese un valor para la posicion 2:-9.8
    Ingrese un valor para la posicion 3:10.5
    el arreglo:[1.500000,2.300000,-9.800000,10.500000] tiene:
        Minimo=-9.800000
        Maximo=10.500000
        Promedio=1.125000

*/

struct datos_t
{
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(int tam, float a[]);
int main()
{
    float arreglo[T];
    pedir_arregloFloat(T, arreglo);
    printf("el arreglo:");
    imprimir_arregloFloat(T, arreglo);
    printf("tiene:\n\t Minimo=%f\n\tMaximo=%f\n\tPromedio=%f", stats(T, arreglo).minimo, stats(T, arreglo).maximo, stats(T, arreglo).promedio);
    return 0;
}

struct datos_t stats(int tam, float a[])
{
    struct datos_t resultados;
    int i = 0;
    float min = INT_MAX;
    float max = INT_MIN;
    float prom = 0;
    while (i < tam)
    {
        if (min >= a[i])
        {
            min = a[i];
        }
        if (max <= a[i])
        {
            max = a[i];
        }
        prom = prom + a[i];
        i = i + 1;
    }
    resultados.maximo = max;
    resultados.minimo = min;
    resultados.promedio = prom / tam;
    return resultados;
}
