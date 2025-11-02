#include <stdio.h>
#define N 5

int sumatoria(int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);

int main()
{
    int arreglo[N];
    pedir_arreglo(N, arreglo);
    imprimir_arreglo(N, arreglo);
    printf("\n La suma de los elementos del arreglo es:%d", sumatoria(N, arreglo));

    return 0;
}

int sumatoria(int tam, int a[])
{
    int res = 0;
    int i = 0;
    while (i < tam)
    {
        res = res + a[i];
        i++;
    }

    return res;
}

void pedir_arreglo(int n_max, int a[])
{
    int i = 0;
    while (i < n_max)
    {
        printf("\nIngrese un valor para a[%d]:", i);
        scanf("%d", &a[i]);
        i++;
    }
}

void imprimir_arreglo(int n_max, int a[])
{
    int i = 0;
    printf("\nEl arreglo ingresado es:\n");
    printf("[");
    while (i < n_max - 1)
    {
        printf("%d,", a[i]);
        i++;
    }
    printf("%d]", a[n_max - 1]);
}