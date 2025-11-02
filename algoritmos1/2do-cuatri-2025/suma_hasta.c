#include <stdio.h>
#include <assert.h>
int suma_hasta(int n)
{
    int res;
    int i = 0;
    while (i < n)
    {
        res = res + i;
        i++;
    }

    return res;
}
int main()
{
    int numero = 0;
    printf("Ingrese la cantidad de naturales a sumar:");
    scanf("%d", &numero);
    if (numero < 0)
    {
        printf("el numero ingresado debe ser positivo\n");
        assert(numero >= 0);
    }

    printf("El resultado es:%d", suma_hasta(numero));
    return 0;
}