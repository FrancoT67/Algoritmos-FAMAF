// (x → 0 , y → 0 , z → 0 , b → 0 , w → 0 )
// de manera que las siguientes expresiones tengan el valor indicado:
// |Expresion                        | Valor
// | x % 4 == 0                      | True
// | x + y == 0 && y - x == (-1) * z | True
// | not b && w                      | False

#include <stdio.h>
#include "./helpers/entradasInt.h"
#include "./helpers/entradasBool.h"

int main()
{
    int x;
    int y;
    int z;
    int b;
    int w;
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');
    b = pedirEntero('b');
    w = pedirEntero('w');
    separador();

    printf("x mod 4 == 0 -> True  \n\t");
    imprimeBool('R', (x % 4 == 0));
    printf("x + y == 0 && y - x == (-1) * z -> True \n\t");
    imprimeBool('R', (x + y == 0 && y - x == (-1) * z));
    printf("not b && w -> False  \n\t");
    imprimeBool('R', (!b && w));

    return 0;
}
