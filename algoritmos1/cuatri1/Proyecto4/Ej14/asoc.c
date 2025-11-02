#include <stdio.h>

// Expansion de libreria para manejo de tipos bool.
#include <stdbool.h>

// Expansion de libreria para usar Assert.
#include <assert.h>

// Definiendo el tamaño fijo del arreglo.
#define N 5

// Defincion de typedefs.
typedef char clave_t;
typedef int valor_t;

// Definicion del tipo asoc.
struct asoc
{
    clave_t clave;
    valor_t valor;
};

// Definicion de Prototipos.
void crearArregloStruct(int tamaño, struct asoc a[]);
void imprimirArregloStruct(int tamaño, struct asoc a[]);
bool asoc_existe(int tam, struct asoc a[], clave_t c);

int main()
{
    // Instanciacion de variables.
    char claveBuscar = 'a';

    // Solicitando el caracter a buscar.
    printf("Ingrese un caracter para buscar en el arreglo(Si ingresa una palabra, se tomara la primer letra como caracter a buscar):");
    scanf(" %c", &claveBuscar);

    // Creando un arreglo de tipo asoc.
    struct asoc a[N];

    // Ingreso de valores al arreglo.
    crearArregloStruct(N, a);

    // Muestra del arreglo ingresado.
    imprimirArregloStruct(N, a);

    // Asignacion del resultado de la funcion a una variable auxiliar.
    int resultado = asoc_existe(N, a, claveBuscar);

    // Informando si existe o no la clave.
    if (resultado == true)
    {
        printf("\nLa clave '%c' SI existe en el arreglo.\n\n", claveBuscar);
    }
    else
    {
        printf("\nLa clave '%c' NO existe en el arreglo.\n\n", claveBuscar);
    }

    return 0;
}

bool asoc_existe(int tam, struct asoc a[], clave_t c)
{
    for (int i = 0; i < tam; i++)
    {
        if (a[i].clave == c)
        {
            return true;
        }
    }

    return false;
}

void crearArregloStruct(int tamaño, struct asoc a[])
{

    // Validación de que el valor ingresado sea Positivo.
    if (tamaño <= 0)
    {
        printf("No se puede crear un arreglo con valores menores a 0");
    }
    assert(tamaño > 0);

    for (int i = 0; i < tamaño; ++i)
    {
        printf("Ingrese un valor para a[%d].clave:", i);
        scanf(" %c", &a[i].clave);
        printf("Ingrese un valor para a[%d].valor:", i);
        scanf("%d", &a[i].valor);
    }
}

void imprimirArregloStruct(int tamaño, struct asoc a[])
{

    printf("El arreglo ingresado es: [");
    for (int i = 0; i < tamaño; ++i)
    {
        if (i == tamaño - 1)
        {
            printf(" %c:%d ] ", a[i].clave, a[i].valor);
        }
        else
        {
            printf(" %c:%d,", a[i].clave, a[i].valor);
        }
    }
}
