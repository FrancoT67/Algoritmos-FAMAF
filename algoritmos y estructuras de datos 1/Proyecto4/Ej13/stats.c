#include <stdio.h>

// Expansion de libreria personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

struct datos_t
{
    float maximo;
    float minimo;
    float promedio;
};

// Definicion de prototipos.
struct datos_t stats(int tam, float a[]);
int main()
{
    // Instanciacion de Variables.
    int tam = 0;

    // Solicitud del tamaño del arreglo.
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    // Creacion del arreglo.
    float a[tam];

    // Solicitud de datos al usuario para el arreglo.
    pedir_arregloFloat(tam, a);

    // Mostrar el arreglo.
    imprimir_arregloFloat(tam, a);

    return 0;
}

struct datos_t stats(int tam, float a[])
{

    struct datos_t resultado;
    int minimo = 0;
    int maximo = 0;
    int promedio = 0;

    return resultado;
}
