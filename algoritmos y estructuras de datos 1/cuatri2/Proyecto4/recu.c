#include <stdio.h>
#include <assert.h>

int pedirEntero(char name)
{
    int n = 0;
    // lo que hace es recibir un char como parametro, y asi decir que ése es el nombre de la variable que va a almacenar el valor, pero puede serlo, como puede llamarse de otra forma y el mensaje no cambiariía a menos que le pasemos otro char como parámetro.
    printf("Ingrese un valor entero para la variable %c:", name);
    scanf("%d", &n);
    return n;
}

void imprimeEntero(char name, int x)
{
    printf("el valor de %c es :%d\n", name, x);
}
/*
ingrese un valor entero para la variable x:12
Ingrese un valor entero para la variable y:3
el valor de x es :3
el valor de y es :21
*/
int main()
{
    int x, y = 0;
    int X, Y = 0;
    x = pedirEntero('x');
    y = pedirEntero('y');
    X = x;
    Y = y;
    assert(x == X && y == Y && 2 * X != Y);
    x = Y % (2 * X - Y);
    y = 2 * (X - Y) + Y;
    assert(x == (Y % y) && y == 2 * (X - Y) + Y);
    imprimeEntero('x', x);
    imprimeEntero('y', y);
    return 0;
}
