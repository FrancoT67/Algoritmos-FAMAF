#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./funcionesAux.h"
#include "./funcionesAuxArreglos.h"
#define T 4

int fun10A(int i, int s, int A[]);
/**
 * | Estado | i  | s  |
 * | σ0     | -3 | 5  |
 * | σ10    | 0  | 0  |
 * | σ01    | 0  | 0  |
 * | σ02    | 1  | 2  |
 * | σ11    | 1  | 2  |
 * | σ12    | 2  | 12 |
 * | σ21    | 2  | 12 |
 * | σ22    | 3  | 22 |
 * | σ31    | 3  | 22 |
 * | σ32    | 4  | 21 |
 * | σ3     | 4  | 12 |
 *
 */

int fun10B(int i, int c, int A[]);
/**
 * | Estado | i | A.i | c  |
 * | σ0     | 3 | -   | 12 |
 * | σ10    | 0 | 12  |  1 |
 * | σ01    | 0 | 12  |  1 |
 * | σ02    | 1 | -9  |  1 |
 * | σ11    | 1 | -9  |  1 |
 * | σ12    | 2 | 10  |  1 |
 * | σ21    | 2 | 10  |  1 |
 * | σ22    | 3 | -1  |  2 |
 * | σ31    | 3 | -1  |  2 |
 * | σ32    | 4 | -   |  2 |
 * | σ3     | 4 | -   |  2 |
 */

int fun16B(int y, int N);

/**
 * Ejemplo de ejecucion:
 *  ******************** Traduccion del ej16 b) ********************
    Ingrese un valor entero para la variable Y:2
    Ingrese un valor entero para la variable n:0
    el resultado es:1
 *  ******************** Traduccion del ej16 b) ********************
    Ingrese un valor entero para la variable Y:5
    Ingrese un valor entero para la variable n:3
    el resultado es:125
 *  ******************** Traduccion del ej16 b) ********************
    Ingrese un valor entero para la variable Y:8
    Ingrese un valor entero para la variable n:-4
    Assertion failed: y = Y && N >= 0, file ej12.c, line 107
*/
int main()
{
    int i, s, c, Y, N = 0;
    int arreglo[T];

    printf(" ******************** Traduccion del ej10 a) ******************** \n");
    pedir_arreglo(T, arreglo);
    imprimir_arreglo(T, arreglo);
    i = pedirEntero('i');
    s = pedirEntero('s');
    s = fun10A(i, s, arreglo);
    imprimeEntero('s', s);
    printf(" ******************** Traduccion del ej10 b) ******************** \n");
    i = pedirEntero('i');
    c = pedirEntero('c');
    pedir_arreglo(T, arreglo);
    imprimir_arreglo(T, arreglo);
    c = fun10B(i, c, arreglo);
    imprimeEntero('c', c);
    printf(" ******************** Traduccion del ej16 b) ******************** \n");
    Y = pedirEntero('Y');
    N = pedirEntero('n');
    printf("el resultado es:%d", fun16B(Y, N));
    return 0;
}

int fun10A(int i, int s, int A[])
{

    i = 0;
    s = 0;
    while (i < T)
    {
        printf("antes asignacion -> i:%d,s:%d\n ", i, s);
        s = s + A[i];
        i = i + 1;
        printf("despues asignacion -> i:%d,s:%d\n", i, s);
    }
    return s;
}

int fun10B(int i, int c, int A[])
{
    i = 0;
    c = 0;
    while (i < T)
    {
        printf("antes asignacion -> i:%d,c:%d\n", i, c);
        if (A[i] > 0)
        {
            c = c + 1;
        }
        i = i + 1;
        printf("despues asignacion -> i:%d,c:%d\n", i, c);
    }

    return c;
}

int fun16B(int Y, int N)
{

    int x = 1;
    int y = Y;
    int n = 0;
    assert(y = Y && N >= 0);
    while (n != N)
    {
        x = x * y;
        n = n + 1;
    }
    assert(x = pow(Y, N));
    return x;
}
