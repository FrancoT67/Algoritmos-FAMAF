#include <stdio.h>
#include <assert.h>
#include "./funcionesAux.h"
#define tamañoArreglo 5

/**
 * Ejemplo de ejecucion:
 *  .\entradaC.exe
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es: [1,2,3,4,5]
 *  .\entradaC.exe
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    El arreglo generado es: [1,2,3]

*/

void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);
int main()
{
    int tamaño = 0;
    tamaño = tamañoArreglo;

    int a[tamaño];
    pedir_arreglo(tamaño, a);
    imprimir_arreglo(tamaño, a);
    return 0;
}

void pedir_arreglo(int n_max, int a[])
{

    int i = 0;
    int valor = 0;
    while (i < n_max)
    {
        printf("Ingrese un valor para la posicion %d:", i);
        scanf("%d", &valor);
        a[i] = valor;
        valor = 0;
        i = i + 1;
    }
}

void imprimir_arreglo(int n_max, int a[])
{

    printf("El arreglo generado es: [");
    int i = 0;
    while (i < (n_max - 1))
    {
        printf("%d,", a[i]);
        i = i + 1;
    }
    printf("%d]\n", a[n_max - 1]);
}
