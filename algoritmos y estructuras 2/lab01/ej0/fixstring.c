#include <stdbool.h>

#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{

    unsigned int i = 0;

    while (i < FIXSTRING_MAX && s[i] != '\0')
    {

        i = i + 1;
    }
    assert(i < FIXSTRING_MAX);
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool res = true;

    unsigned int long_s1 = fstring_length(s1);
    unsigned int long_s2 = fstring_length(s2);

    if (long_s1 == long_s2)
    {
        for (unsigned int i = 0; i < long_s1; i++)
        {
            res = s1[i] == s2[i];
        }
    }
    else
    {
        res = false;
    }

    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    bool res = true;
    unsigned int i = 0;
    unsigned int tam1 = fstring_length(s1);
    unsigned int tam2 = fstring_length(s2);

    while (i < tam1 && i < tam2 && res && s1[i] == s2[i])
    {
        // por la guarda s1[i] == s2[i] busco la posicion donde s1[i] != s2[i].
        i++;
    }

    if (i < tam1 && i < tam2)
    {
        // Comparo donde s1 != s2 teniendo ya la posicion de ambos por el while anterior
        res = s1[i] < s2[i];
    }
    else if (tam1 != tam2)
    {
        // si el tamaño de s1 es menor a s2 entonces ya la palabra s1 es menor a la palabra s2.
        res = tam1 < tam2;
    }

    // si son iguales, res sigue valiendo true
    return res;
}
