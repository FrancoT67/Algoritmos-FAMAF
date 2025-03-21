#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5
int es_primo(int num)
{
    if (num <= 1)
    {
        return 0; // No es primo
    }
    int i = 2;
    while (i * i <= num)
    {
        if (num % i == 0)
        {
            return 0; // No es primo
        }
        i++;
    }
    return 1; // Es primo
}

void llena_con_primos(int n_max, int a[])
{

    int i = 0;
    int valor = 0;
    while (i < n_max)
    {
        printf("Ingrese un valor para la posicion %d:", i);
        scanf("%d", &valor);
        if (es_primo(valor) == 1)
        {
            a[i] = valor;
            valor = 0;
            i = i + 1;
        }
        else
        {
            printf("El numero ingresado debe ser primo\n");
        }
    }
}

void imprimir_arreglo(int n_max, int a[])
{

    printf("[");
    int i = 0;
    while (i < (n_max - 1))
    {
        printf("%d,", a[i]);
        i = i + 1;
    }
    printf("%d]\n", a[n_max - 1]);
}

int main()
{
    int arreglo[N];
    assert(N > 0);
    llena_con_primos(N, arreglo);
    imprimir_arreglo(N, arreglo);
    return 0;
}
