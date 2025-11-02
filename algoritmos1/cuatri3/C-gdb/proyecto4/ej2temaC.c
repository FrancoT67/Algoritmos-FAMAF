#include <stdio.h>
#include <assert.h>

/*var x, y, z : Int;
{Pre: x = X, y = Y, z = Z, Z mod 2 ≠ Y mod 2}
if (x mod 2 = 0)⟶
x, y, z := x + 1, y + z + y, 2*x
◻ (x mod 2 ≠ 0)⟶
x, y, z := x - 1, y - z - y, 2*x
fi
{Pos: z=2*X ∧ ((x=X+1 ∧ y=Y+Z+Y)) ∨ (x=X-1 ∧ y=Y-Z-Y))}
*/

int pedir_entero(char a)
{
    int x = 0;
    printf("ingrese un valor para %c:", a);
    scanf("%d", &x);
    return x;
}

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    int X, Y, Z;

    x = pedir_entero('x');
    y = pedir_entero('y');
    z = pedir_entero('z');
    X = x;
    Y = y;
    Z = z;
    assert((x == X) && (y == Y) && (z == Z) && (Z % 2 != Y % 2));

    if (x % 2 == 0)
    {
        x = X + 1;
        y = Y + Z + Y;
        z = 2 * X;
    }
    else if (x % 2 != 0)
    {
        x = X - 1;
        y = Y - Z - Y;
        z = 2 * X;
    }
    assert((z = 2 * X) && (((x = X + 1) && (y = Y + Z + Y)) || ((x = X - 1) && (y = Y - Z - Y))));
    printf("los valores son: \n x=%d\n y=%d\n z=%d\n", x, y, z);

    return 0;
}
