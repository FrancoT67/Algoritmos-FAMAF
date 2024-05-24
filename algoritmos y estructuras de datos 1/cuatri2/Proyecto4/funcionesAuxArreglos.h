#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void pedir_arreglo(int n_max, int a[])
{

    int i = 0;
    int valor = 0;
    while (i < n_max)
    {
        printf("Ingrese un valor para la posicion %d:", i);
        scanf("%d", &valor);
        a[i] = valor;
        valor = 0;
        i = i + 1;
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
