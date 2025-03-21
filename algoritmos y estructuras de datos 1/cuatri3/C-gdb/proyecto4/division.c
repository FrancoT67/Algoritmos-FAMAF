#include <stdio.h>
#include <assert.h>

struct div_t
{
    int cociente;
    int resto;
};

/***

 * Éste si es con el algoritmo de la division.

***/
struct div_t division(int num, int div)
{
    struct div_t resultado;
    resultado.cociente = 0;
    resultado.resto = num;
    if (div != 0)
    {
        while (resultado.resto >= div)
        {
            resultado.cociente = resultado.cociente + 1;
            resultado.resto = resultado.resto - div;
        }
    }
    return resultado;
};

/***

 *funciona pero es lo que se pide

***/

// struct div_t division(int num, int div)
// {
//     struct div_t resultado;
//     if (div != 0)
//     {
//         resultado.cociente = num / div;
//         resultado.resto = num % div;
//     }
//     return resultado;
// };

int main()
{
    int x = 0;
    int y = 0;
    printf("Ingrese valor para %c: \n", 'x');
    scanf("%d", &x);
    printf("Ingrese valor para %c: \n", 'y');
    scanf("%d", &y);
    struct div_t result = division(x, y);
    printf("Cociente: %d\n", result.cociente);
    printf("resto: %d\n", result.resto);
    return 0;
}
