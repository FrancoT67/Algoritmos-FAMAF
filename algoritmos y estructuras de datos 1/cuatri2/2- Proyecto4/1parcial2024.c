/*
var x, y, z : Int;
{Pre: x = X, y = Y, z = Z, X > 0, Y > 0, Z > 0}
x, y, z := y + z, z * x, x / y
{Pos: x = Y + Z, y = Z * X, z = X / Y}
*/

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
int main()
{
  int x,y,z=0;
  int X,Y,Z=0;
  x=pedirEntero('x');
  y=pedirEntero('y');
  z=pedirEntero('z');
  X=x;
  Y=y;
  Z=z;
  assert(x == X && y == Y && z == Z && X > 0 && Y > 0 && Z > 0);
  x=Y+z;
  y=Z*X;
  z=X/Y;
  assert(x == Y + Z && y == Z * X && z == X / Y);
  imprimeEntero('x',x);
  imprimeEntero('y',y);
  imprimeEntero('z',z);
  return 0;
}

/**
var x, y, z : Int;
{Pre: x = X, y = Y, z = Z, X > 0, Y > 0, Z > 0}
x, y, z := y + z, z * x, x / y
{Pos: x = Y + Z, y = Z * X, z = X / Y}
*/

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
int main()
{
  int x,y,z=0;
  int X,Y,Z=0;
  x=pedirEntero('x');
  y=pedirEntero('y');
  z=pedirEntero('z');
  X=x;
  Y=y;
  Z=z;
  assert(x == X && y == Y && z == Z && X > 0 && Y > 0 && Z > 0);
  x=Y+z;
  y=Z*X;
  z=X/Y;
  assert(x == Y + Z && y == Z * X && z == X / Y);
  imprimeEntero('x',x);
  imprimeEntero('y',y);
  imprimeEntero('z',z);
  return 0;
}

/**
 * Ingrese un valor entero para la variable x:1
Ingrese un valor entero para la variable y:2
Ingrese un valor entero para la variable z:3
el valor de x es :5
el valor de y es :3
el valor de z es :0
  ./parcialC
Ingrese un valor entero para la variable x:0
Ingrese un valor entero para la variable y:0
Ingrese un valor entero para la variable z:0
parcialC: parcial2024.c:33: main: Assertion `x == X && y == Y && z == Z && X > 0 && Y > 0 && Z > 0' failed.
Abortado (`core' generado)
 * 
*/

