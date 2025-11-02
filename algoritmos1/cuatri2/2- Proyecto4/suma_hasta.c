#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"

/**Ejemplos de ejecucion:
 * .\sumaC.exe
    Ingrese un entero para la variable x:12
    La suma de los 12 primeros numeros enteros es: 78
 *  .\sumaC.exe
    Ingrese un entero para la variable x:10
    La suma de los 10 primeros numeros enteros es: 55
 *  .\sumaC.exe
    Ingrese un entero para la variable x:3
    La suma de los 3 primeros numeros enteros es: 6
*/

//  Firma de la funcion suma_hasta.
int suma_hasta(int n);

int main()
{
    int x, resultado = 0;
    x = pedirEntero('x');
    assert(x >= 0);
    resultado = suma_hasta(x);
    assert(x >= 0);
    printf("La suma de los %d primeros numeros enteros es: %d", x, resultado);
    return 0;
}

// Definicion de la funcion suma_hasta
int suma_hasta(int n)
{
    int res = 0;
    while (n > 0)
    {
        res = res + n;
        n = n - 1;
    }
    assert(n >= 0);
    return res;
}
