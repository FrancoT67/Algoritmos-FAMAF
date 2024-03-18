#include <stdio.h>

// Expansion de Libreria Personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/imprimeTexto.h"

// Definicion de Prototipos.
void intercambiar(int tam, int a[], int i, int j);

int main()
{
    // Instanciacion de Variables.
    int pos1 = 0;
    int pos2 = 0;
    int tamañoArreglo = 0;

    // Solicitud del tamaño del Arreglo al Usuario.
    printf("Ingrese un valor entero positivo para el tamaño del arreglo:");
    scanf("%d", &tamañoArreglo);

    // Creamos el arreglo de tamano tamañoArreglo.
    int a[tamañoArreglo];

    // Solicitamos los valores para el Arreglo.
    pedir_arreglo(tamañoArreglo, a);

    // Mostramos el arreglo ingresado.
    printf("\n");
    imprimir_arreglo(tamañoArreglo, a);
    printf("\n\t");

    // Solicitamos las posiciones para el intercambio de valores en el arreglo ingresado.
    pos1 = pedirEntero('I');
    printf("\n\t");
    pos2 = pedirEntero('J');

    // Verificarion de que los valores no sean mayores que las posibles posiciones del arreglo.
    if (tamañoArreglo < pos1 || tamañoArreglo < pos2)
    {
        imprimeTexto("Las posicion de I y de J no pueden ser mayores a ");
        printf(":%d", (tamañoArreglo - 1));
        assert(tamañoArreglo < pos1 || tamañoArreglo < pos2);
    }
    if (pos1 < 0 || pos2 < 0)
    {
        imprimeTexto("Las posicion de I y de J no pueden ser menores a 0.\n");
        assert(pos1 > 0 || pos2 > 0);
    }

    // Llamada a la funcion para Intercambiar los valores.
    intercambiar(tamañoArreglo, a, pos1, pos2);
    printf("\n");

    // Mostramos el arreglo ingresado luego de la modificacion.
    imprimir_arreglo(tamañoArreglo, a);

    return 0;
}

// Definición del Prototipoo intercambiar.
void intercambiar(int tam, int a[], int i, int j)
{

    // Definicion de Variables Auxiliares.
    int arregloValorIAux = 0;
    int arregloValorJAux = 0;

    // Validacion de que los valores de las posiciones ingresados no sean mayores que el tamaño del arreglo.
    assert(tam > i && tam > j);

    // Guardado de los Valores originales de las posiciones ingresadas.
    arregloValorIAux = a[i];
    arregloValorJAux = a[j];

    // Intercambio de los valores en las posiciones ingresadas.
    a[i] = arregloValorJAux;
    a[j] = arregloValorIAux;
}
