#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "./funcionesAuxArreglos.h"
#include "./funcionesAux.h"

#define tamañoArreglo 5

int minimos_pares(int tam, int a[]);
int minimos_impares(int tam, int a[]);
int main()
{
    int tamaño = tamañoArreglo;

    int arreglo[tamaño];
    pedir_arreglo(tamaño, arreglo);
    imprimir_arreglo(tamaño, arreglo);

    printf("El menor valor par del arreglo es:%d\n", minimos_pares(tamaño, arreglo));
    printf("El menor valor impar del arreglo es:%d\n", minimos_impares(tamaño, arreglo));
    printf("El menor valor del arreglo es:%d", minimo(minimos_impares(tamaño, arreglo), minimos_pares(tamaño, arreglo)));

    return 0;
}

int minimos_pares(int tam, int a[])
{
    int menor = INT_MAX;
    int i = 0;
    while (i < tam)
    {
        if (a[i] % 2 == 0 && a[i] < menor)
        {
            menor = a[i];
        }
        i = i + 1;
    }

    return menor;
}

int minimos_impares(int tam, int a[])
{
    int menor = INT_MAX;
    int i = 0;
    while (i < tam)
    {
        if (a[i] % 2 != 0 && a[i] < menor)
        {
            menor = a[i];
        }
        i = i + 1;
    }

    return menor;
}
