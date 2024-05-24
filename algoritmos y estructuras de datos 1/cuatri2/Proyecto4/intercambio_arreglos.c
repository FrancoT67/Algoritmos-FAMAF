#include <stdio.h>
#include <assert.h>
#define tamañoArreglo 5
// Auxiliares generales.
#include "./funcionesAux.h"
// Auxiliares de arreglos.
#include "./funcionesAuxArreglos.h"
/**
 * Ejemplo de Ejecucion:
 *  .\intercamC.exe
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
    tamaño = tamañoArreglo;
    int arreglo[tamaño];
    pedir_arreglo(tamaño, arreglo);
    imprimir_arreglo(tamaño, arreglo);
    printf("ingrese un valor entre 0 y %d para intercambiar en el arreglo\n", tamaño - 1);
    printf("Posicion:");
    pos1 = pedirEntero('1');
    pos2 = pedirEntero('2');
    intercambiar(tamaño, arreglo, pos1, pos2);
    printf("Luego de intercambiar los valores de las posiciones %d y %d\n", pos1, pos2);
    imprimir_arreglo(tamaño, arreglo);

    return 0;
}

void intercambiar(int tam, int a[], int i, int j)
{
    int valorOriginalSinModificar = 0;
    assert(i >= 0 && i < tam && j >= 0 && j < tam && i != j);
    valorOriginalSinModificar = a[i];
    a[i] = a[j];
    a[j] = valorOriginalSinModificar;
}
