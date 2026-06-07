#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

struct _list
{
    elem value;
    struct _list *next;
};

list empty()
{
    return NULL;
}

list addl(elem e, list l)
{
    list new_list = malloc(sizeof(struct _list)); /* crea la nueva lista de tamaño _list */
    new_list->value = e;                          /* le pone el valor "e" */
    new_list->next = l;                           /* lo conecta a la lista "l" que se pasa como argumento */
    return new_list;                              /* devuelve la lista nueva */
}
bool is_empty(list l)
{
    return l == NULL; /* devuelve true si la lista es vacía (NULL) y false en caso contrario */
}

elem head(list l)
{
    return l->value; /* devuelve el valor del primer elemento de la lista */
}

list tail(list l)
{
    assert(l != NULL); /* asegura que la lista no esté vacía antes de intentar acceder a su siguiente nodo */
    return l->next;    /* devuelve la lista sin el primer elemento, es decir, el siguiente nodo de la lista */
}

list addr(list l, elem e) /* agrega el elemento "e" al final de la lista "l" */
{
    list new_list = malloc(sizeof(struct _list));
    new_list->value = e;
    new_list->next = NULL;
    if (l == NULL)
    {
        l = new_list; /* si la lista es vacía, la nueva lista se convierte en la lista "l" */
    }
    else
    {
        list aux = l;
        while (aux->next != NULL) /* recorre la lista "l" hasta llegar al último nodo */
        {
            aux = aux->next; /* avanza al siguiente nodo de la lista */
        }
        aux->next = new_list; /* conecta el último nodo de la lista "l" con la nueva lista que contiene el elemento "e" */
    }
    return l; /* devuelve la lista "l" con el nuevo elemento agregado al final */
}

int length(list l)
{
    int count = 0; /* inicializa un contador para contar los elementos de la lista */

    while (l != NULL) /* mientras el siguiente nodo de la lista no sea NULL */
    {
        count++;     /* incrementa el contador por cada nodo que encuentra */
        l = l->next; /* avanza al siguiente nodo de la lista */
    }

    return count; /* devuelve el número total de elementos en la lista */
}

list concat(list l, list l0) /*añade a final de l todos los elementos de l0 */
{
    if (l == NULL)
    {
        l = l0; /* si la lista "aux" es vacía, devuelve la lista "l0" */
    }
    else
    {
        list aux = l;
        /* mientras el siguiente nodo de la lista "l" no sea vacío */
        while (aux->next != NULL)
        {
            aux = aux->next; /* avanza al siguiente nodo de la lista "l" */
        }
        aux->next = l0; /* conecta el último nodo de la lista "l" con la lista "l0" */
    }
    return l;
}

elem index(list l, int n)
{
    assert(n < length(l) && !is_empty(l)); /* asegura que el índice "n" sea menor que la longitud de la lista "l" para evitar acceder a un nodo inexistente y que la lista no esté vacía */
    for (int i = 0; i < n && l != NULL; i++)
    {
        l = l->next; /* avanza al siguiente nodo de la lista "l" hasta llegar al nodo en la posición "n" */
    }
    return l->value; /* devuelve el valor del nodo actual de la lista "l" */
}

list take(list l, int n)
{
    if (l == NULL || n <= 0)
    {
        l = empty(); /* si la lista "l" es vacía o el número de elementos a tomar "n" es menor o igual a 0, devuelve una lista vacía */
    }

    else if (n > length(l))
    {
        n = length(l); /* si el número de elementos a tomar "n" es mayor que la longitud de la lista "l", ajusta "n" al tamaño de la lista "l" */
    }
    else
    {
        list aux = l;
        int count = 1;
        while (aux->next != NULL && count < n)
        {                    /* recorre la lista "l" hasta llegar al nodo en la posición "n" o hasta el final de la lista */
            aux = aux->next; /* avanza al siguiente nodo de la lista "l" */
            count++;         /* incrementa el contador para contar los nodos recorridos */
        }
        aux->next = NULL;
    }
    return l; /* devuelve la lista "l" hasta el N-nesimo nodo */
}

list drop(list l, int n)
{
    if (l != NULL && n >= length(l))
    {
        l = empty(); /* si el número de elementos a eliminar "n" es mayor que la longitud de la lista "l", devuelve una lista vacía */
    }
    else
    {
        for (int i = 0; i < n && l != NULL; i++) /*recorrer la lista l hasta llegar al nodo en la posición "n" */
        {
            l = l->next; /* avanza al siguiente nodo de la lista l hasta llegar al nodo en la posición "n" */
        }
    }

    return l; /* devuelve la lista "l" sin los primeros "n" elementos */
}

list copy_list(list l)
{
    list copy = NULL; /* inicializa una nueva lista "copy" como vacía (NULL) */
    if (l != NULL)
    {
        copy = malloc(sizeof(struct _list)); /* crea una nueva lista "copy" de tamaño _list */
        copy->value = l->value;              /* asigna el valor del primer nodo de la lista "l" al primer nodo de la nueva lista "copy" */
        copy->next = copy_list(l->next);     /* llama recursivamente a copy_list para copiar el siguiente nodo de la lista "l" y lo asigna al siguiente nodo de la nueva lista "copy" */
    }
    return copy; /* devuelve la nueva lista "copy" que es una copia de la lista "l" */
}

void destroy_list(list l)
{
    if (l != NULL) /* si la lista "l" no es vacía */
    {
        destroy_list(l->next); /* llama recursivamente a destroy_list para liberar la memoria del siguiente nodo de la lista "l" */
        free(l);               /* libera la memoria del nodo actual de la lista "l" */
    }
}
