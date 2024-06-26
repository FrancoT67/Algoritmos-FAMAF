#include <stdio.h>
#include "./funcionesAux.h"

struct div_t
{
    int cociente;
    int resto;
};

struct div_t division(int x, int y)
{
    struct div_t resultados;

    resultados.cociente = x / y;
    resultados.resto = x % y;
    return resultados;
};
int main()
{
    int num1, num2 = 0;

    printf("Ingrese un valor positivo para el numerador.\n");
    num1 = pedirEntero('A');
    printf("Ingrese un valor positivo para el divisor y DISTINTO de 0.\n");
    num2 = pedirEntero('B');
    if (num1 < 0)
    {
        while (num1 < 0)
        {
            printf("Los valores deben ser POSITIVOS.\nIngrese nuevamente los valores:\n");
            num1 = pedirEntero('A');
        }
    }
    if (num2 < 0)
    {
        while (num2 < 0)
        {
            printf("Los valores deben ser POSITIVOS.\nIngrese nuevamente los valores:\n");
            num2 = pedirEntero('B');
        }
    }

    if (num2 == 0)
    {
        while (num2 == 0)
        {
            printf("El cociente debe ser DISTINTO de 0\nIngrese nuevamente un valor:\n");
            num2 = pedirEntero('B');
        }
    }

    printf("El cociente de hacer %d/%d es:%d\n", num1, num2, division(num1, num2).cociente);
    printf("El resto de hacer %d/%d es:%d\n", num1, num2, division(num1, num2).resto);
    return 0;
}
