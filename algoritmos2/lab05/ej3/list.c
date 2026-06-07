#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list
{
    elem elems[MAX_LENGTH]; /* arreglo que alamcena los elementos */
    int size;               /* cantidad de elementos en la lista */
};

list empty()
{
    list res = malloc(sizeof(struct _list));
    res->size = 0;
    return res;
}

list addl(elem e, list l)
{
    for (int i = l->size; i > 0; i--)
    {
        l->elems[i] = l->elems[i - 1];
    }
    l->elems[0] = e;
    l->size++;

    return l;
}

bool is_empty(list l)
{
    return l->size == 0;
}

elem head(list l)
{
    return l->elems[0];
}

list tail(list l)
{
    for (int i = 0; i < l->size - 1; i++)
    {
        l->elems[i] = l->elems[i + 1];
    }

    l->size--;

    return l;
}

list addr(list l, elem e)
{
    l->elems[length(l)] = e;
    l->size++;
    return l;
}

int length(list l)
{
    return l->size;
}

list concat(list l, list l0)
{
    list aux = l;
    int aux_size = l->size + l0->size;
    for (int i = l->size; i < aux_size; i++)
    {
        aux->elems[i] = l0->elems[i - l->size];
    }
    l->size = aux_size;
    return l;
}

elem index(list l, int n)
{
    // if (n >= length(l))
    // {
    //     n = length(l) - 1;
    // }
    // else if (n < 0)
    // {
    //     n = 0;
    // }
    return l->elems[n];
}

list take(list l, int n)
{
    if (n < l->size)
    {
        l->size = n;
    }
    return l;
}
list drop(list l, int n)
{
    if (n < l->size && n >= 0)
    {
        for (int i = 0; i < l->size - n; i++)
        {
            l->elems[i] = l->elems[i + n];
        }

        l->size -= n;
    }
    return l;
}

list copy_list(list l)
{
    list res = malloc(sizeof(struct _list));
    for (int i = 0; i < l->size; i++)
    {
        res->elems[i] = l->elems[i];
    }
    res->size = l->size;

    return res;
}

void destroy_list(list l)
{
    free(l);
}