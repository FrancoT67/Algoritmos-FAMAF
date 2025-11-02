
/**
 * Ejercicio 3
Dada la siguiente estructura
struct stonks {
int sube;
int baja;
};
programar la función
struct stonks stonks_master(int tam, int a[]);
que dado un tamaño de arreglo tam y un arreglo a[] devuelve una estructura struct
stonks, donde en el campo sube contará la cantidad de veces que a[i] <= a[i+1] para i en el
rango 0 <= i < tam-1, de manera análoga baja contará la cantidad de veces que a[i] > a[i+1]
para el mismo rango.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define N 5

char pedir_entero(void)
{
    int res;
    scanf("%d", &res);
    return res;
}

void pedir_arreglo(int tam, int a[])
{
    int i = 0;
    while (i < tam)
    {
        printf("Ingrese elemento entero [%d/%d]: ", i + 1, tam);
        a[i] = pedir_entero();
        i = i + 1;
    }
}

struct stonks
{
    int sube;
    int baja;
};

struct stonks stonks_master(int tam, int a[])
{
    int i = 0;
    struct stonks stks;
    assert(tam > 1);

    stks.sube = 0;
    stks.baja = 0;

    while (i < tam - 1)
    {
        if (a[i] <= a[i + 1])
        {
            stks.sube = stks.sube + 1;
        }
        else
        {
            stks.baja = stks.baja + 1;
        }
        i = i + 1;
    }

    return stks;
}

int main(void)
{
    int a[N];
    struct stonks stks;

    pedir_arreglo(N, a);
    stks = stonks_master(N, a);

    printf("sube: %d\n"
           "baja: %d\n",
           stks.sube, stks.baja);

    return 0;
}