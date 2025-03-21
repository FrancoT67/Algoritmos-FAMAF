#include <stdio.h>
#include <assert.h>
#define N 5

struct stonks
{
    int sube;
    int baja;
};

struct stonks stonks_master(int tam, int a[])
{
    int i = 0;
    struct stonks rest;
    rest.sube = 0;
    rest.baja = 0;

    while (i < tam - 1) // recorre el arreglo pero la posicion N no existe
    {
        if (a[i] <= a[i + 1])
        {
            rest.sube++;
        }
        else
        {
            rest.baja++;
        }

        i++;
    }

    return rest;
}

/*que dado un tamaño de arreglo tam y un arreglo a[] devuelve una estructura struct
stonks, donde en el campo sube contará la cantidad de veces que a[i] <= a[i+1] para i en el
rango 0 <= i < tam-1, de manera análoga baja contará la cantidad de veces que a[i] > a[i+1]
para el mismo rango.*/

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

    pedir_arreglo(a, N);

    struct stonks rest = stonks_master(N, a);
    printf(" sube: %d\n baja: %d", rest.sube, rest.baja);

    return 0;
}
