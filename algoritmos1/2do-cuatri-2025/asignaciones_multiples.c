#include <stdio.h>
#include <assert.h>
int main()
{
    /** Programa 1
        {Pre: x = X, y = Y}
        x, y := x + 1, x + y
        {Post: x = X + 1, y = X + Y}
    */
    int x = 0;
    int y = 0;

    printf("Ingrese un valor para la Variable X:");
    scanf("%d", &x);

    printf("\nIngrese un valor para la Variable Y:");
    scanf("%d", &y);

    printf("\nvalor de X:%d", x);
    printf("\nvalor de Y:%d", y);
    int xaux = x;
    int yaux = y;
    printf("\nvalor de Xaux:%d", xaux);
    printf("\nvalor de Yaux:%d\n", yaux);
    printf("\nvalor de Xaux:%d", xaux);
    printf("\nvalor de Yaux:%d", yaux);
    assert(x == xaux && y == yaux);
    x = xaux + 1;
    y = xaux + yaux;
    assert(x == xaux + 1 && y == xaux + yaux);
    printf("\nvalor de X:%d", x);
    printf("\nvalor de Y:%d", y);
    printf("\nvalor de Xaux:%d", xaux);
    printf("\nvalor de Yaux:%d", yaux);

    /** Programa 2
     {Pre: x = X, y = Y, z = Z}
     x, y, z := y, y + x + z, y + x
     {Post: x = Y, y = Y + X + Z, z = Y + X}
     */
    x = 0;
    y = 0;
    int z = 0;

    printf("\nIngrese un valor para la Variable X:");
    scanf("%d", &x);

    printf("\nIngrese un valor para la Variable Y:");
    scanf("%d", &y);

    printf("\nIngrese un valor para la Variable Z:");
    scanf("%d", &z);

    printf("\nvalor de X:%d", x);
    printf("\nvalor de Y:%d", y);
    printf("\nvalor de Z:%d", z);
    xaux = x;
    yaux = y;
    int zaux = z;

    assert(x == xaux && y == yaux && z == zaux);
    printf("\nvalor de X:%d", x);
    printf("\nvalor de Y:%d", y);
    printf("\nvalor de Z:%d", z);
    printf("\nvalor de Xaux:%d", xaux);
    printf("\nvalor de Yaux:%d", yaux);
    printf("\nvalor de Zaux:%d", zaux);

    x = yaux;
    y = yaux + xaux + zaux;
    z = yaux + xaux;

    assert(x == yaux && y == yaux + xaux + zaux && z == yaux + xaux);
    printf("\nvalor de X:%d", x);
    printf("\nvalor de Y:%d", y);
    printf("\nvalor de Z:%d", z);
    printf("\nvalor de Xaux:%d", xaux);
    printf("\nvalor de Yaux:%d", yaux);
    printf("\nvalor de Zaux:%d", zaux);

    return 0;
}
