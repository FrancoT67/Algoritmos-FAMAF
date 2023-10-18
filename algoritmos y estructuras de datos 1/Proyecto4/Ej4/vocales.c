#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>
// Expansion de libreria Bools.
#include <stdbool.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/entradasBool.h"

bool es_vocal(char letra);
int main()
{

    int resultado = 0;
    char vocal = 'a';
    resultado = es_vocal(vocal);
    imprimeBool(vocal, resultado);

    return 0;
}

bool es_vocal(char letra)
{

    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++)
    {
        if (letra == vocales[i])
        {
            return true;
        }
        return false;
    }

    return false;
}
