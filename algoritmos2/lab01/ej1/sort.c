#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void insert(int a[], unsigned int i, unsigned int length)
{

    while (i > 0 && goes_before(a[i], a[i - 1]) && i < length)
    {
        swap(a, i, i - 1);
        i--;
    }
}

void insertion_sort(int a[], unsigned int length)
{
    for (unsigned int i = 1; i < length; ++i)
    {
        insert(a, i, length);

        // Parte B: imprimir el arreglo en cada paso
        array_dump(a, length);

        // Parte C: verificar invariante: a[0..i] está ordenado
        assert(array_is_sorted(a, i));
    }
}
