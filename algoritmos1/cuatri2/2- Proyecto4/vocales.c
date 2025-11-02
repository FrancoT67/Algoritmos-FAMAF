#include <stdio.h>

// Inclusion de libreria personal con Funciones Auxiliares.
#include "./funcionesAux.h"
// Inclusion de libreria para Bools.
#include <stdbool.h>
/**Ejemplo de ejecucion:
 *  .\vocalesC.exe
    Ingrese un valor Char para la variable C:a
    La letra a es (1 = Vocal, 0 = Consonante):1
 *  .\vocalesC.exe
    Ingrese un valor Char para la variable C:r
    La letra r es (1 = Vocal, 0 = Consonante):0
*/

// firma de es_vocal.
bool es_vocal(char letra);
int main()
{
    char c = 's';
    c = pedirChar('C');
    printf("La letra %c es (1 = Vocal, 0 = Consonante):%d", c, es_vocal(c));
    return 0;
}

bool es_vocal(char letra)
{
    char vocales[5] = "aeiou";
    int i = 0;
    while (i < 5)
    {
        if (letra == vocales[i])
        {
            return true;
        }
        i = i + 1;
    }

    return false;
}
