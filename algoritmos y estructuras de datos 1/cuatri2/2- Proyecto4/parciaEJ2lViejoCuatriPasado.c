/*Ejericio 2:

Ejercicio 2
Considerar el siguiente código con asignaciones múltiples:
    var x, y, z : Int;
    {Pre: x = X, y = Y, z = Z, Z mod 2 ≠ Y mod 2}
    if (x mod 2 = 0)⟶
    x, y, z := x + 1, y + z + y, 2*x
    ◻ (x mod 2 ≠ 0)⟶
    x, y, z := x - 1, y - z - y, 2*x
    fi
    {Pos: z=2*X ∧ ((x=X+1 ∧ y=Y+Z+Y)) ∨ (x=X-1 ∧ y=Y-Z-Y))}
Escribir un programa en lenguaje C equivalente usando asignaciones simples teniendo en
cuenta que:
    ● Se deben verificar las pre y post condiciones usando la función assert().
    ● Los valores iniciales de x, y, z deben ser ingresados por el usuario
    ● Los valores finales de x, y, z deben mostrarse por pantalla usando la función imprimir_entero del proyecto 3.
NOTA: Poner como comentario al menos un ejemplo de ejecución, con los parámetros de
entrada y la salida de tu programa (puedes hacer un copiar y pegar de la consola)
*/

#include <assert.h>
#include <stdio.h>

int pedir_entero(char letra)
{
    int res;
    printf("Ingrese un valor para %c: ", letra);
    scanf("%d", &res);
    return res;
}

void imprime_entero(char letra, int entero)
{
    printf("%c=%d\n", letra, entero);
}

int main(void)
{
    int X, Y, Z;
    int x, y, z;
    X = pedir_entero('x');
    Y = pedir_entero('y');
    Z = pedir_entero('z');
    x = X;
    y = Y;
    z = Z;
    assert(x == X && y == Y && z == Z && Z % 2 != Y % 2);
    if (x % 2 == 0)
    {
        x = X + 1;
        y = Y + Z + Y;
        z = 2 * X;
    }
    else
    {
        x = X - 1;
        y = Y - Z - Y;
        z = 2 * X;
    }
    imprime_entero('x', x);
    imprime_entero('y', y);
    imprime_entero('z', z);
    assert(z == 2 * X &&
           ((x == X + 1 && y == Y + Z + Y) || (x == X - 1 && y == Y - Z - Y)));
    return 0;
}

/**
 * Ejercicio 3
Dada la siguiente estructura
struct stonks {
int sube;
int baja;
};
programar la función
struct stonks stonks_master(int tam, int a[]);
que dado un tamaño de arreglo tam y un arreglo a[] devuelve una estructura struct
stonks, donde en el campo sube contará la cantidad de veces que a[i] <= a[i+1] para i en el
rango 0 <= i < tam-1, de manera análoga baja contará la cantidad de veces que a[i] > a[i+1]
para el mismo rango.

*/