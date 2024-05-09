#include <stdio.h>

/* Libreria personal para mostrar datos */
#include "./entradasInt.h"

/* Reescritura del Ejericicio 4.B con funciones. */
int main()
{

    /* Inicializacion de Variables. */
    int x = 0;
    int y = 0;
    int z = 0;
    int m = 0;

    /* Ingreso de Valores a las variables. */
    printf("-------------------------------------\n\n");
    x = pedirEntero('x');
    printf("-------------------------------------\n\n");
    y = pedirEntero('y');
    printf("-------------------------------------\n\n");
    z = pedirEntero('z');
    printf("-------------------------------------\n\n");
    m = pedirEntero('m');
    printf("-------------------------------------\n\n");

    /* Comprobacion entre X e Y. */
    if (x < y)
    {
        m = x;
    }
    else
    {
        m = y;
    }

    /* Comprobacion entre M y Z. */
    if (m < z)
    {
        m = m;
        z = z;
    }
    else
    {
        z = m;
    }

    /* Visualización de los Valores. */
    printf("********************************************\n\n");
    imprimeEntero('x', x);
    printf("********************************************\n\n");
    imprimeEntero('y', y);
    printf("********************************************\n\n");
    imprimeEntero('z', z);
    printf("********************************************\n\n");
    imprimeEntero('m', m);
    printf("El valor final de M es: %d\n\n ", m);
    printf("********************************************\n\n");

    /**
     * Pregunta: ¿Qué ventajas encontras en esta nueva versión?.
     * Respuesta: Que se evita el codigo repetitivo y se optimiza el tiempo de escritura.
     * Pregunta: ¿Podrías escribir alguna otra función en ese ejercicio, cual?.
     * Respuesta:No se me ocurre otra funcion.
     * Pregunta: ¿En qué otros ejercicios de ese Proyecto lo podrías utilizar?.
     * Respuesta:en el 2,3,4 y 5.
     */

    return 0;
}
