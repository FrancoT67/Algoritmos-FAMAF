#include <stdio.h>
#include <assert.h>

// Inclusion de Libreria propia
#include "./funcionesAux.h"
/**
 * Ejemplo de ejecucion:
 *  .\interC.exe
    Ingrese un entero para la variable x:12
    Ingrese un entero para la variable y:15
    El valor original de X es : 12
    El valor modificado de X es : 15
    El valor original de Y es : 15
    El valor modificado de Y es : 12
*  .\interC.exe
    Ingrese un entero para la variable x:13
    Ingrese un entero para la variable y:17
    El valor original de X es : 13
    El valor modificado de X es : 17
    El valor original de Y es : 17
    El valor modificado de Y es : 13
*/

// Firma de la funcion 'intercambio'.
void intercambio(int variable1, int variable2);
int main()
{
    int x, y = 0;
    x = pedirEntero('x');
    y = pedirEntero('y');
    intercambio(x, y);
    return 0;
}

void intercambio(int variable1, int variable2)
{
    int z = variable1;
    int z2 = variable2;
    variable1 = variable2;
    variable2 = z;
    assert(variable1 == z2 && variable2 == z);
    printf("El valor original de X es : %d \nEl valor modificado de X es : %d \n", z, variable1);
    printf("El valor original de Y es : %d \nEl valor modificado de Y es : %d \n", z2, variable2);
}
