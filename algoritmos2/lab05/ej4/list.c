#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list
{
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty()
{
    list res = malloc(sizeof(struct _list));
    res->size = 0;
    res->start = 0;
    return res;
}

list addl(elem e, list l)
{

    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e;
    l->size++;
    return l;
}

bool is_empty(list l)
{
    return l->size == 0;
}

elem head(list l)
{
    return l->a[l->start];
}

list tail(list l)
{
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size--;
    return l;
}

list addr(list l, elem e)
{
    l->a[(l->start + l->size) % MAX_LENGTH] = e;
    l->size++;
    return l;
}

int length(list l)
{
    return l->size;
}

list concat(list l, list l0)
{
    for (int i = 0; i < l0->size; i++)
    {
        l = addr(l, l0->a[(l0->start + i) % MAX_LENGTH]);
    }
    return l;
}

elem index(list l, int n)
{
    return l->a[(l->start + n) % MAX_LENGTH];
}

list take(list l, int n)
{
    if (n <= 0)
    {
        l->size = 0;
    }
    else if (n < l->size)
    {
        l->size = n;
    }

    return l;
}

list drop(list l, int n)
{
    if (n < l->size && n > 0)
    {
        l->start = (l->start + n) % MAX_LENGTH;
        l->size -= n;
    }
    else if (n >= l->size)
    {
        l->size = 0;
    }

    return l;
}