#include <stdio.h>
#include <stdbool.h>

/* Cuadro 1

σ 0: (x → 13, y → 3 ,i → 0 )
    i := 0
    do (x ≥ y) →
        x := x − y
        i := i + 1
        [σ 0.1, σ 1.1, σ 2.1, σ 3.1]
    od

σ 1: (x → 10, y → 3 ,i → 1 )
    Luego de iter. 1
σ 2: (x → 4, y → 3 ,i → 2 ) ,
    Luego de iter. 2
σ 3: (x → 7, y → 3 ,i → 3 )
    Luego de iter. 3
σ 4: (x → 1, y → 3 ,i → 4 )
    Luego de iter. 4

*/

/* Cuadro 2
σ 0: (x → 5,i → 0 ,res → False   ) ,
    i := 2
    res := T rue
    do (i < x ∧ res) →
        res := res ∧ (mod(x, i) 6 = 0)
        i := i + 1
        [σ 0.1, σ 1.1, σ 2.1 ]
    od

σ 1:(x → 5, i → 2, res → True)
    Luego de iter. 1
σ 2 : (x → 5 ,i → 3, res → True ) ,
    Luego de iter. 2
σ 3 : (x → 5, i → 4, res → True )
    Luego de iter. 3
*/

/* Defincion de la funcion correspondiente al ejercicio 1 del practico. */
int ejercicio1(int valorX, int valorY)
{
    int i = 0;
    while (valorX >= valorY)
    {
        valorX = valorX - valorY;
        i = i + 1;
        printf(" El valor de X es :%d \n El valor de Y es:%d\n en la iteracion n°(I): %d\n", valorX, valorY, i);
    }
    return 0;
}

/* Defincion de la funcion correspondiente al ejercicio 2 del practico. */
int ejercicio2(int valorX, int valorI, int res)
{
    if (res < 0 || res > 1)
    {
        printf("valor Incorrecto, se definira a Res como 1(True).\n");
    }
    res = 1;
    valorI = 2;
    while (valorI < valorX && res)
    {
        res = res && ((valorX % valorI) != 0);
        if (res == 1)
        {
            printf(" El valor de X es :%d \n El valor de boolExpresion es: True\n El valor de I es: %d\n *** En la iteracion n°(I): %d ***\n", valorX, valorI, (valorI - 1));
            valorI = valorI + 1;
        }
        else
        {
            printf(" El valor de X es :%d \n El valor de boolExpresion es: False\n El valor de I es: %d\n *** En la iteracion n°(I): %d ***\n", valorX, valorI, (valorI - 1));
            valorI = valorI + 1;
        }
    }
    return 0;
}

int main()
{

    /*Inicializacion de Variables*/
    int x = 0;
    int y = 0;
    int i = 0;
    int boolExpresion = 1;

    /* Peticion de datos y Llamado a la funcion ejercicio1. */
    printf("****************** Ejercicio 5.B1) ******************\n\n");
    printf("Ingrese el valor para X:");
    scanf("%d", &x);
    printf("Ingrese el valor para Y: ");
    scanf("%d", &y);
    printf("%d\n\n", ejercicio1(x, y));

    /* Peticion de datos y Llamado a la funcion ejercicio2. */
    printf("****************** Ejercicio 5.B2) ******************\n\n");

    /* Reseteo del valor de la Variable. */
    x = 0;
    printf("Ingrese el valor para X: ");
    scanf("%d", &x);
    printf("Ingrese 1(True) o 0(False): ");
    scanf("%d", &boolExpresion);
    printf("%d\n", ejercicio2(x, i, boolExpresion));

    printf("****************** Ejercicio 5.B3) ******************\n\n");

    /*Inicializacion de Variables*/
    x = 0;
    y = 0;

    /* Llamado a la funcion ejercicio1 con valores predefinidos. */
    printf("Programa 1 con X=%d, Y=%d %d\n\n", 10, 9, ejercicio1(10, 9));
    printf("Programa 1 con X=%d, Y=%d %d\n\n", 9, 8, ejercicio1(9, 8));
    printf("Programa 1 con X=%d, Y=%d %d\n\n", 8, 7, ejercicio1(8, 7));

    /* La funcion B1 lo que hace es buscar los multiplos del número x */
    printf("***************** Fin Programa 1 *******************\n\n");

    /*Inicializacion de Variables*/
    x = 0;
    y = 0;

    /* Llamado a la funcion ejercicio2 con valores predefinidos. */
    printf("Programa 2 con X=%d, y Res en True.\n\n", ejercicio2(10, 0, 0));
    printf("Programa 2 con X=%d, y Res en False.\n\n", ejercicio2(9, 2, 1));
    printf("Programa 2 con X=%d, y Res en True.\n\n", ejercicio2(8, 3, 1));

    /* La funcion ejercicio2 lo que hace es verificar si el número ingresado es Impar. */
    printf("***************** Fin Programa 2 *******************\n\n");

    return 0;
}
