#include <stdio.h>

/*
+------------------+-------------------------+-----------------------+
| programa          | usuario ingresa un σ 0 |  produce una salida σ |
+------------------+-------------------------+-----------------------+
| 1.a ejecución 1   |        x → 1           |   x → 5               |
+------------------+-------------------------+-----------------------+
| 1.a ejecución 2   |        x → 2           |   x → 5               |
+------------------+-------------------------+-----------------------+
| 1.a ejecución 3   |        x → 3           |   x → 5               |
+------------------+-------------------------+-----------------------+
| 1.b ejecución 1   |        x → 2, y → 3    |   x → 5,  y → 6       |
+------------------+-------------------------+-----------------------+
| 1.b ejecución 2   |        x → 3, y → 3    |   x → 6,  y → 6       |
+------------------+-------------------------+-----------------------+
| 1.b ejecución 3   |        x → 3, y → 4    |   x → 7,  y → 8       |
+------------------+-------------------------+-----------------------+
| 1.c ejecución 1   |        x → 3, y → 3    |   x → 6,  y → 6       |
+------------------+-------------------------+-----------------------+
| 1.c ejecución 2   |        x → 4,  y → 5   |   x → 14, y → 10      |
+------------------+-------------------------+-----------------------+
| 1.c ejecución 3   |        x → 7,  y → 8   |   x → 23, y → 16      |
+------------------+-------------------------+-----------------------+


*/

int main()
{
    /*Inicializacion de Variables*/
    int x = 0;
    int y = 0;
    /*Inicializacion de Variables Auxiliares para guardar los valores originales*/
    int copiaY = 0;
    int copiaX = 0;

    /* Traduccion del ejericio 1.a */
    printf("********** Traduccion del ejericio 1.A ********** \n\t");
    /* Ingreso de valores a las variables */
    printf("Ingrese un valor numerico para X :");
    scanf("%d", &x);
    x = 5;
    printf("\t El valor de X es: %d\n\n", x);

    /*Traduccion del ejercicio 1.b*/
    printf("********** Traduccion del ejericio 1.B ********** \n\t");
    /* Ingreso de valores a las variables */
    printf("Ingrese un valor numerico para X :");
    scanf("%d", &x);
    printf("\tIngrese un valor numerico para Y :");
    scanf("%d", &y);

    /* Variables Auxiliares para preservar los valores originales*/
    copiaX = x;
    copiaY = y;

    x = x + y;
    y = y + y;
    printf("\t El valor de X es: %d y el de Y es: %d\n\n", x, y);

    /*Traduccion del ejercicio 1.c*/
    printf("********** Traduccion del ejericio 1.C ********** \n\t");
    /* Ingreso de valores a las variables */
    printf("Ingrese un valor numerico para X : ");
    scanf("%d", &x);
    printf("\tIngrese un valor numerico para Y : ");
    scanf("%d", &y);

    /* Variables Auxiliares para preservar los valores originales*/
    copiaX = x;
    copiaY = y;

    y = copiaY + copiaY;
    x = copiaX + copiaY;
    printf("\t El valor de X es: %d y el de Y es: %d\n\n", x, y);

    return 0;
}
