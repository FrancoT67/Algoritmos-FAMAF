#include <stdio.h>
#include <stdbool.h>
#include "./funcionesAux.h"
#include "./funcionesAuxArreglos.h"
#define T 4
/**
 * Ejemplo de ejecucion:
 *  .\asocC.exe
    Clave a Buscar: r
    Clave: t
    Valor: 2
    Clave: y
    Valor: 3
    Clave: u
    Valor: 7
    Clave: o
    Valor: 2
    [t:2,y:3,u:7,o:2]
    Si :
            C=Verdadero => existe la clave en el arreglo.
            C=Falso => NO existe la clave en el arreglo.
    C: falso
 * Clave a Buscar: t
    Clave: r
    Valor: 1
    Clave: t
    Valor: 2
    Clave: y
    Valor: 4
    Clave: u
    Valor:6
    [r:1,t:2,y:4,u:6]
    Si :
            C=Verdadero => existe la clave en el arreglo.
            C=Falso => NO existe la clave en el arreglo.
    C: verdadero

*/

typedef char clave_t;
typedef int valor_t;

struct asoc
{
    clave_t clave;
    valor_t valor;
};
void pedirArreglo(int tam, struct asoc a[])
{
    int i = 0;
    while (i < tam)
    {
        printf("Clave: ");
        scanf(" %c", &a[i].clave); // Espacio antes de %c para consumir cualquier espacio en blanco
        printf("Valor: ");
        scanf("%d", &a[i].valor);
        i = i + 1;
    }
}
void imprimirArreglo(int tam, struct asoc a[])
{
    printf("[");
    int i = 0;
    while (i < (tam - 1))
    {
        printf("%c:%d,", a[i].clave, a[i].valor);
        i = i + 1;
    }
    printf("%c:%d]\n", a[tam - 1].clave, a[tam - 1].valor);
}

bool asoc_existe(int tam, struct asoc a[], clave_t c);
int main()
{
    struct asoc arreglo[T];
    bool res;
    clave_t claveBusca;
    printf("Clave a Buscar: ");
    scanf(" %c", &claveBusca); // Espacio antes de %c para consumir cualquier espacio en blanco
    pedirArreglo(T, arreglo);
    imprimirArreglo(T, arreglo);
    res = asoc_existe(T, arreglo, claveBusca);
    printf("Si :\n\tC=Verdadero => existe la clave en el arreglo.\n\tC=Falso => NO existe la clave en el arreglo.\n");
    imprimeBool('C', res);
    return 0;
}

bool asoc_existe(int tam, struct asoc a[], clave_t c)
{

    int i = 0;
    while (i < tam)
    {
        if (a[i].clave == c)
        {
            return true;
        }
        i = i + 1;
    }

    return false;
}
