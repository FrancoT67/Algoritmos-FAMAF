#include <stdio.h>

int main()
{
    /* ********** Tracuccion del 1.h ********** */
    printf("**************** Tracuccion del Ej1.H **************\n\n");

    /*Inicializacion de Variables*/
    int i = 0;

    /* Ingreso de valores a las variables */
    printf("Ingrese el valor de I: ");
    scanf("%d", &i);
    printf("\n");

    /*Incio del Ciclo*/
    while (i != 0)
    {
        i = i - 1;

        /* Visualizacion del estado de la variable en cada iteración.*/
        printf("el valor de I es %d\n", i);
    }
    printf("\n");

    /* ********** Tracuccion del 1.I ********** */
    printf("********** Tracuccion del Ej1.I ********************\n\n");

    /*Reseteo de valores para la variable.*/
    i = 0;

    /* Ingreso de valores a las variables */
    printf("Ingrese el valor de I: ");
    scanf("%d", &i);

    while (i != 0)
    {
        i = 0;

        /* Visualizacion del estado de la variable. */
        printf("el valor de I es %d\n\n", i);
        return 0;
    }

    /* Visualizacion del estado final de la variable. */
    printf("el valor de I es %d\n\n", i);

    return 0;
}
