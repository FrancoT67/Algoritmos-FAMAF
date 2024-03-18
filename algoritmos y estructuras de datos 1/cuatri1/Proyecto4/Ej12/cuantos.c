#include <stdio.h>

// Expansion de libreria personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

// Definicion del struct comp_t.

struct comp_t
{

    int menores;
    int iguales;
    int mayores;
};

// Definicion del Prototipo cuantos.
struct comp_t cuantos(int tam, int a[], int elem);

int main()
{
    // Instanciacion de Variables
    int elemento = 0;
    int tam = 0;

    // Ingreso del tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    // Creacion del arreglo con tamaño ingresado.
    int a[tam];

    // Solicitud de los valores para el arreglo.
    pedir_arreglo(tam, a);

    // Impresion del arreglo creado.
    imprimir_arreglo(tam, a);
    printf("\n");

    // Pedido del elemento que se quiere buscar en el arreglo.
    printf("Ingrese el elemento que desea buscar: ");
    scanf("%d", &elemento);

    // Llamada a la función cuantos y mostrar los resultados obtenidos.
    printf("La cantidad de elementos menores que %d son: %d\nLa cantidad de elementos iguales que %d son: %d\nLa cantidad de elementos mayores que %d son: %d\n", elemento, cuantos(tam, a, elemento).menores, elemento, cuantos(tam, a, elemento).iguales, elemento, cuantos(tam, a, elemento).mayores);

    return 0;
}

struct comp_t cuantos(int tam, int a[], int elem)
{
    int igualesCont = 0;
    int menoresCont = 0;
    int mayoresCont = 0;
    struct comp_t cantidades;
    for (int i = 0; i < tam; i++)
    {
        if (a[i] == elem)
        {
            igualesCont += 1;
        }
        if (a[i] < elem)
        {
            menoresCont += 1;
        }
        if (a[i] > elem)
        {
            mayoresCont += 1;
        }
    }
    cantidades.iguales = igualesCont;
    cantidades.menores = menoresCont;
    cantidades.mayores = mayoresCont;
    return cantidades;
}
