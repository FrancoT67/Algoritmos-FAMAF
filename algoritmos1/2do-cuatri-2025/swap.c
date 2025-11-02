#include <stdio.h>

int main()
{
    int X = 1;
    int Y = 10;
    int Z = 30;
    int auxX = X;
    int auxY = Y;
    int auxZ = Z;

    printf("Antes x:%d\n", X);
    printf("Antes y:%d\n", Y);
    printf("Antes z:%d\n", Z);

    Z = auxX;
    X = auxY;
    Y = auxZ;

    printf(" Despues x:%d \n Original:%d\n", X, auxX);
    printf(" Despues y:%d \n Original:%d\n", Y, auxY);
    printf(" Despues z:%d \n Original:%d\n", Z, auxZ);
    return 0;
}
