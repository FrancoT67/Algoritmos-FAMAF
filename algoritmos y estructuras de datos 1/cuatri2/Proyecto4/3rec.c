#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 7

struct sum_t
{
    int suma_dentro;
    int suma_fuera;
};
struct sum_t suma_rango(int a, int b, int array[], int tam)
{
    struct sum_t respuesta;
    int dentro = 0;
    int fuera = 0;
    int i = 0;
    while (i < tam)
    {
        if (array[i] >= a && array[i] <= b)
        {
            dentro = dentro + array[i];
        }
        if (array[i] < a || array[i] > b)
        {
            fuera = fuera + array[i];
        }
        i = i + 1;
    }
    respuesta.suma_dentro = dentro;
    respuesta.suma_fuera = fuera;
    return respuesta;
}

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
int pedirEntero(char name)
{
    int n = 0;
    printf("Ingrese un valor entero para la variable %c:", name);
    scanf("%d", &n);
    return n;
}
int main()
{
    int num1, num2 = 0;
    int arreglo[N];
    assert(N > 0);
    num1 = pedirEntero('a');
    num2 = pedirEntero('b');
    pedir_arreglo(N, arreglo);
    imprimir_arreglo(N, arreglo);
    printf("Dentro del rango: %d\n", suma_rango(num1, num2, arreglo, N).suma_dentro);
    printf("Fuera del rango: %d\n", suma_rango(num1, num2, arreglo, N).suma_fuera);

    return 0;
}
