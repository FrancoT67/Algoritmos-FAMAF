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
        for (int i = 0; i < long_s1; i++)
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
    int tam1 = fstring_length(s1);
    int tam2 = fstring_length(s2);

    return res;
}
