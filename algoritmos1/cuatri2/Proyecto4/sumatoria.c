#include <stdio.h>
#include <assert.h>
// Auxiliares generales.
#include "./funcionesAux.h"
// Auxiliares de arreglos.
#include "./funcionesAuxArreglos.h"

/**
 * Ejemplo de ejecucion:
 *  .\sumatoriaC.exe
    Ingrese un valor positivo para T que sera el tamaño del arreglo.
    Ingrese un valor entero para T:1
    Ingrese un valor para la posicion 0:2
    El arreglo generado es: [2]
    El resultado de la suma de todos los elementos es : 2

 *  .\sumatoriaC.exe
    Ingrese un valor positivo para T que sera el tamaño del arreglo.
    Ingrese un valor entero para T:5
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es: [1,2,3,4,5]
    El resultado de la suma de todos los elementos es : 15
*/

int sumatoria(int tam, int a[]);
int main()
{
    int tamaño, resultado = 0;
    printf("Ingrese un valor positivo para T que sera el tamaño del arreglo.\n");
    tamaño = pedirEntero('T');
    assert(tamaño > 0);
    int arreglo[tamaño];
    pedir_arreglo(tamaño, arreglo);
    resultado = sumatoria(tamaño, arreglo);
    imprimir_arreglo(tamaño, arreglo);
    printf("El resultado de la suma de todos los elementos es : %d", resultado);

    return 0;
}

int sumatoria(int tam, int a[])
{

    int res = 0;
    int i = 0;
    while (i < tam)
    {
        res = res + a[i];
        i = i + 1;
    }

    return res;
}
