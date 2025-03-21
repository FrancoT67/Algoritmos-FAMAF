#include <stdio.h>
int main()
{
    /*Inicializacion de Variables*/
    int x = 0;
    int y = 0;

    /*Traduccion del ejercicioo 1.e*/
    printf("*********************** Traduccion del ejercicioo 1.E *********************\n\n");

    /* Ingreso de valores a las variables */
    printf("Ingrese un valor numerico para X:");
    scanf("%d", &x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d", &y);

    if (x >= y)
    {
        x = 0;
    }
    else if (x <= y)
    {
        x = 2;
    }
    printf("El valor de X es %d y el de Y es %d\n\n", x, y);

    /*Reseteo de valores de las variables */
    x = 0;
    y = 0;

    /*Traduccion del ejercicioo 1.f*/
    printf("*********************** Traduccion del ejercicioo 1.F *********************\n\n");

    /* Ingreso de valores a las variables */
    printf("Ingrese un valor numerico para X:");
    scanf("%d", &x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d", &y);
    if (x >= y)
    {
        x = 0;
    }
    else if (x <= y)
    {
        x = 2;
    }
    printf("El valor de X es %d y el de Y es %d\n\n", x, y);

    return 0;
}
