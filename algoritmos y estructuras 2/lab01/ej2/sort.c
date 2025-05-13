#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
    /* needs implementation */

    if (izq > der)
    {
        int ppiv = partition(a, izq, der);
        partition(a, izq, der);
        quick_sort_rec(a, izq, ppiv - 1);
        quick_sort_rec(a, ppiv + 1, der);
    }

    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */
}

void quick_sort(int a[], unsigned int length)
{
    if (length > 0)
    {
        quick_sort_rec(a, 0, length - 1);
    }
}
