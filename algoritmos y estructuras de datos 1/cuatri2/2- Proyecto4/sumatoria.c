#include <stdio.h>
#include <assert.h>
#define N 5

int sumatoria(int tam, int a[])
{
    int result = 0;
    int i = 0;
    while (i < tam)
    {
        result = result + a[i];
        i = i + 1;
    }

    return result;
}

void pedir_arreglo(int a[], int tam)
{
    int i = 0;
    while (i < tam)
    {
        printf("Ingrese valor para %d: \n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
}
int main()
{
    int a[N];
    int result = 0;
    pedir_arreglo(a, N);
    result = sumatoria(N, a);
    printf("El resultado es: %d", result);

    return 0;
}
