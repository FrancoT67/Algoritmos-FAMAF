#include <stdio.h>

// Expansion de la libreria para manejo de los limites de los valores.
#include <limits.h>

// Expansion de librerias propias con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

// Definiendo el tamaño cnstante del arreglo.
#define N 5

// Defincion de Prototipos.
int minimo_pares(int tam, int a[]);
int minimo_impares(int tam, int a[]);

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

    // Muestra del Minimo Elemento Par del arreglo.
    printf("\n");
    printf("Minimo par: %d\n", minimo_pares(N, a));

    // Muestra del Minimo Elemento Impar del arreglo.
    printf("Minimo impar: %d\n", minimo_impares(N, a));

    return 0;
}

int minimo_pares(int tam, int a[])
{
    int i;
    int min = INT_MAX;

    for (i = 0; i < tam; i++)
    {
        if (a[i] % 2 == 0 && a[i] < min)
        {
            min = a[i];
        }
    }

    if (min == INT_MAX)
    {
        return -1;
    }
    else
    {
        return min;
    }
}
int minimo_impares(int tam, int a[])
{
    int i;
    int min = INT_MAX;

    for (i = 0; i < tam; i++)
    {
        if (a[i] % 2 != 0 && a[i] < min)
        {
            min = a[i];
        }
    }

    if (min == INT_MAX)
    {
        return -1;
    }
    else
    {
        return min;
    }
}