#include <stdio.h>

// Definiendo el tamaño constante.
#define N 5

// Expansion de librerias Personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

int prim_iguales(int tam, int a[]);
int main()
{
    int a[N];
    // Llenado del arreglo.
    printf("Va a ingresar %d valores para el arreglo a continuacion:\n", N);
    pedir_arreglo(N, a);

    // Mostrando el arreglo ingresado
    printf("\n\n");
    imprimir_arreglo(N, a);
    printf("\n");

    printf("La longitud del tramo inicial que es igual es: %d", prim_iguales(N, a));

    return 0;
}

int prim_iguales(int tam, int a[])
{

    int contadorIguales = 0;
    int elementoIgual = a[0];
    for (int i = 0; i < tam; i++)
    {
        if (a[i] != elementoIgual)
        {
            break;
        }
        else
        {
            contadorIguales += 1;
        }
    }
    int arregloIguales[contadorIguales];
    for (int j = 0; j < contadorIguales; j++)
    {
        arregloIguales[j] = elementoIgual;
    }
    printf("El arreglo con los valores repetidos son:");
    imprimir_arreglo(contadorIguales, arregloIguales);
    printf("\n");

    return contadorIguales;
}
