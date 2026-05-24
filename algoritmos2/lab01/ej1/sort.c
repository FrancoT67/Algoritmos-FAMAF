#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void insert(int a[], unsigned int i, unsigned int length)
{
    int aux = a[i];
    unsigned int j = i;
    while (j > 0 && !goes_before(a[j - 1], aux))
    {
        a[j] = a[j - 1];
        j--;
        array_dump(a, length);
    }
    a[j] = aux;
}

void insertion_sort(int a[], unsigned int length)
{
    for (unsigned int i = 1; i < length; ++i)
    {
        assert(array_is_sorted(a, i));
        insert(a, i, length);
    }
}