#include <stdio.h>

// Expansion de la libreria Assert.
#include <assert.h>
#include "../auxFunctions/arreglos.h"
#define N 6

// Defincion de Prototipos.
int sumatoria(int tam, int a[]);

int main()
{

    // Inicializacion de Varibles.
    int tamañoArreglo = N;

    // Creamos un arreglo de tamaño tamañoArreglo.
    int a[tamañoArreglo];

    // Solicitud de valores al Usuario.
    printf("Ingrese %d números para el arreglo: \n", N);

    // Llamamos a la función para pedir el arreglo al usuario.
    pedir_arreglo(tamañoArreglo, a);

    // Llamamos a la funcion imprimir_arreglo para mostrar el arreglo que ingresó el usuario.
    imprimir_arreglo(tamañoArreglo, a);
    printf("\n");

    // Imprimimos el resultado de la suma de los valores del arreglo.
    printf("el resultado de la suma del arreglo ingresado es: %d", sumatoria(tamañoArreglo, a));

    return 0;
}

// Definción del Prototipo Sumatoria.
int sumatoria(int tam, int a[])
{
    int resultadoSuma = 0;
    for (int i = 0; i < tam; i++)
    {
        resultadoSuma += a[i];
    }
    return resultadoSuma;
}
