#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{

    unsigned int res = 0, i = 0;

    while (s[i] != '\0' && i < FIXSTRING_MAX)
    {
        if (s[i] == '\0')
        {
            res = i;
        }
        i = +1;
    }
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    /*
     * COMPLETAR
     *
     */
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    /*
     * COMPLETAR
     *
     */
}
