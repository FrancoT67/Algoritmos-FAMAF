#include <stdio.h>
#include <assert.h>
// Auxiliares generales.
#include "./funcionesAux.h"
// Auxiliares de arreglos.
#include "./funcionesAuxArreglos.h"
/**
 * Ejemplo de Ejecucion:
 *  .\intercamC.exe
    Ingrese un valor positivo entero para T que sera el tamano del arreglo.
    Ingrese un valor entero para la variable T:5
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es: [1,2,3,4,5]
    ingrese un valor entre 0 y 4 para intercambiar en el arreglo
    Posicion:Ingrese un valor entero para la variable 1:0
    Ingrese un valor entero para la variable 2:1
    Luego de intercambiar los valores de las posiciones 0 y 1
    El arreglo generado es: [2,1,3,4,5]
*/

void intercambiar(int tam, int a[], int i, int j);
int main()
{
    int pos1, pos2, tamaño = 0;
    printf("Ingrese un valor positivo entero para T que sera el tamano del arreglo.\n");
    tamaño = pedirEntero('T');
    assert(tamaño > 0);
    int arreglo[tamaño];
    pedir_arreglo(tamaño, arreglo);
    imprimir_arreglo(tamaño, arreglo);
    printf("ingrese un valor entre 0 y %d para intercambiar en el arreglo\n", tamaño - 1);
    printf("Posicion:");
    pos1 = pedirEntero('1');
    assert(pos1 >= 0 && pos1 < tamaño);

    pos2 = pedirEntero('2');
    assert(pos2 >= 0 && pos2 < tamaño && pos1 != pos2);
    intercambiar(tamaño, arreglo, pos1, pos2);
    printf("Luego de intercambiar los valores de las posiciones %d y %d\n", pos1, pos2);
    imprimir_arreglo(tamaño, arreglo);

    return 0;
}

void intercambiar(int tam, int a[], int i, int j)
{
    int valorOriginalSinModificar = 0;
    assert(tam > 0);
    valorOriginalSinModificar = a[i];
    a[i] = a[j];
    a[j] = valorOriginalSinModificar;
}
