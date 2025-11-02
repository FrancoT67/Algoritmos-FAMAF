#include <stdio.h>
#include <assert.h>
#include "funcionesAux.h"
#include "funcionesAuxArreglos.h"
#define N 4

/**
 * Ejemplos de ejecucion:
 *  .\cuantosC.exe
    Ingrese un valor entero para la variable n:2
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    [1,2,3,4]
    Menores:1
    Iguales:1
    Mayores:2
 *  .\cuantosC.exe
    Ingrese un valor entero para la variable n:2
    Ingrese un valor para la posicion 0:2
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:-3
    Ingrese un valor para la posicion 3:8
    [2,2,-3,8]
    Menores:1
    Iguales:2
    Mayores:1
*/

struct comp_t
{
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem);

int main()
{
    int numero;
    numero = pedirEntero('n');
    int arreglo[N];
    pedir_arreglo(N, arreglo);
    imprimir_arreglo(N, arreglo);
    printf("Menores:%d\nIguales:%d\nMayores:%d\n", cuantos(N, arreglo, numero).menores, cuantos(N, arreglo, numero).iguales, cuantos(N, arreglo, numero).mayores);

    return 0;
}
struct comp_t cuantos(int tam, int a[], int elem)
{
    int i = 0;
    int menoresElem = 0;
    int igualesElem = 0;
    int mayoresElem = 0;
    struct comp_t resultado;
    while (i < tam)
    {
        if (elem == a[i])
        {
            igualesElem = igualesElem + 1;
        }
        if (elem > a[i])
        {
            menoresElem = menoresElem + 1;
        }
        if (elem < a[i])
        {
            mayoresElem = mayoresElem + 1;
        }
        i = i + 1;
    }
    resultado.iguales = igualesElem;
    resultado.menores = menoresElem;
    resultado.mayores = mayoresElem;
    return resultado;
}
