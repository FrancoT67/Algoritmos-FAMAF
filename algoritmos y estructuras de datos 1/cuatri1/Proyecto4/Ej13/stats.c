#include <stdio.h>

// Expansion de libreria personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

// Definicion del tipo datos_t.
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
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    // Creacion del arreglo.
    float a[tam];

    // Solicitud de datos al usuario para el arreglo.
    pedir_arregloFloat(tam, a);

    // Mostrar el arreglo.
    imprimir_arregloFloat(tam, a);

    // Asignación de los resultados a una variable resultado de tipo datos_t.
    struct datos_t resultados = stats(tam, a);

    // Impresion de la informacion obtenida.
    printf("\nMaximo del arreglo: %.2f\nMinimo del arreglo: %.2f\nPromedio del arreglo: %.2f\n", resultados.maximo, resultados.minimo, resultados.promedio);

    return 0;
}

// Definicion de los Prototipos.
struct datos_t stats(int tam, float a[])
{

    struct datos_t resultado;

    float minimoF = a[0];
    float maximoF = a[0];
    float promedioF = 0;

    for (int i = 0; i < tam; i++)
    {
        promedioF += a[i];

        if (a[i] > maximoF)
        {
            maximoF = a[i];
        }
        if (a[i] < minimoF)
        {
            minimoF = a[i];
        }
    }

    resultado.maximo = maximoF;
    resultado.minimo = minimoF;
    resultado.promedio = promedioF / tam;

    return resultado;
}
