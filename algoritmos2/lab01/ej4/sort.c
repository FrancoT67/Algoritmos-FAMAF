#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length)
{
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j)
    {
        if (!goes_before(a[min_pos], a[j]))
        {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length)
{
    for (unsigned int i = 0; i < length; ++i)
    {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}

static void insert(int a[], unsigned int i)
{
    int aux = a[i];
    unsigned int j = i;
    while (j > 0 && !goes_before(a[j - 1], aux))
    {
        a[j] = a[j - 1];
        j--;
        // array_dump(a, length);
    }
    a[j] = aux;
}

void insertion_sort(int a[], unsigned int length)
{
    for (unsigned int i = 1; i < length; ++i)
    {
        // assert(array_is_sorted(a, i));
        insert(a, i);
    }
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der)
{
    unsigned int ppiv = izq; /* pivot es el primer elemento del arreglo */
    unsigned int i = izq + 1;
    unsigned int j = der;
    while (i <= j)
    {
        if (goes_before(a[i], a[ppiv]))
        {
            i++;
        }
        else if (goes_before(a[ppiv], a[j])) // goes_before(valorMasChico, valorMasGrande)=== valorMasChico <= valorMasGrande
        {
            j--;
        }
        else
        {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
    if (der > izq)
    {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, ppiv - 1);
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length)
{
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
