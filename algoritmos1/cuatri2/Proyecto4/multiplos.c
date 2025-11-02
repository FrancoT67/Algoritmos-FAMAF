#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
// funciones auxiliare generales.
#include "./funcionesAux.h"
// funciones auxiliare arreglos.
#include "./funcionesAuxArreglos.h"

/**
 * Ejemplos de ejecucion:
 *  .\multiC.exe
    ingrese un valor positivo para T que ser├í el tama├▒o del arreglo.
    Ingrese un valor entero para T:5
    Ingrese un valor para la posicion 0:2
    Ingrese un valor para la posicion 1:4
    Ingrese un valor para la posicion 2:6
    Ingrese un valor para la posicion 3:8
    Ingrese un valor para la posicion 4:10
    El arreglo generado es: [2,4,6,8,10]
    Son Pares:: verdadero
    Ingrese un valor para M que sera el numero para buscar multiplos:
    Ingrese un valor entero para M:3
    Existe Multiplos: verdadero

 *  .\multiC.exe
    ingrese un valor positivo para T que ser├í el tama├▒o del arreglo.
    Ingrese un valor entero para T:5
    Ingrese un valor para la posicion 0:1
    Ingrese un valor para la posicion 1:2
    Ingrese un valor para la posicion 2:3
    Ingrese un valor para la posicion 3:4
    Ingrese un valor para la posicion 4:5
    El arreglo generado es: [1,2,3,4,5]
    Son Pares: falso
    Ingrese un valor para M que sera el numero para buscar multiplos:
    Ingrese un valor entero para M:4
    Existe Multiplos: verdadero


*/

bool todos_pares(int tam, int a[]);
bool existe_multiplo(int m, int tam, int a[]);
int main()
{
    int tamaño, multiplo = 0;
    bool pares, multiplos = false;
    printf("ingrese un valor positivo para T que será el tamaño del arreglo.\n");
    tamaño = pedirEntero('T');
    assert(tamaño > 0);
    int arreglo[tamaño];
    pedir_arreglo(tamaño, arreglo);
    imprimir_arreglo(tamaño, arreglo);
    pares = todos_pares(tamaño, arreglo);
    printf("Son Pares");
    imprimeBool(":", pares);
    printf("Ingrese un valor para M que sera el numero para buscar multiplos:\n");
    multiplo = pedirEntero('M');
    multiplos = existe_multiplo(multiplo, tamaño, arreglo);
    printf("Existe Multiplos");
    imprimeBool(":", multiplos);

    return 0;
}

bool todos_pares(int tam, int a[])
{
    int i = 0;
    bool res = true;
    while (i < tam)
    {
        res = (res && (a[i] % 2 == 0));
        i = i + 1;
    }

    return res;
}

bool existe_multiplo(int m, int tam, int a[])
{

    int i = 0;
    bool res = false;
    while (i < tam)
    {
        res = (res || (a[i] % m == 0));
        i = i + 1;
    }

    return res;
}
