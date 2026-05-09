#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    unsigned int i = 0;
    bool res = true;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            res = false;
        }
        i++;
    }
    /* si uno terminó antes que el otro, no son iguales */
    if (s1[i] != s2[i])
    {
        res = false;
    }
    return res;
}
bool fstring_less_eq(fixstring s1, fixstring s2)
{
    unsigned int i = 0;
    bool res = false;

    while (s1[i] != '\0' &&
           s2[i] != '\0' &&
           s1[i] == s2[i])
    {
        i++;
    }

    res = (s1[i] <= s2[i]);

    return res;
}