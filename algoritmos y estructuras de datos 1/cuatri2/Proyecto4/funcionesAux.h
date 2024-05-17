#include <stdio.h>
/* Inclusion de Biblioteca necesaria para el tipo Bool. */

#include <stdbool.h>

// INICIO Funciones definidas para Int.
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
// FIN Funciones ya definidas para Int.

// INICIO Funciones definidas para Bools.
bool pedirBooleano(char name)
{
    int x = 0;
    printf("Ingrese 1 para True o 0 para False para agregar en la variable %c:\n", name);
    scanf("%d", &x);
    if (x > 1)
    {
        printf("Ingresaste un valor mayor a 1. \nEntonces se definio como 1 la opcion que elegiste.\n");
        x = 1;
    }
    else if (x < 0)
    {
        printf("Ingresaste un valor menor a 0. \nEntonces se definio como 0 la opcion que elegiste.\n");
        x = 0;
    }
    return x;
}

void imprimeBool(char name, bool x)
{
    if (x == 1)
    {
        printf("%c: verdadero\n\n", name);
    }
    else
    {
        printf("%c: falso\n\n", name);
    }
}

// FIN Funciones definidas para Bools.

// INICIO Funciones definidas para Chars.
char pedirChar(char name)
{
    char n = 'a';
    // lo que hace es recibir un char como parametro, y asi decir que ése es el nombre de la variable que va a almacenar el valor, pero puede serlo, como puede llamarse de otra forma y el mensaje no cambiariía a menos que le pasemos otro char como parámetro.
    printf("Ingrese un valor Char para la variable %c:", name);
    scanf("%c", &n);
    return n;
}

void imprimeChar(char name, char x)
{
    printf("el valor de %c es :%c\n", name, x);
}
// FIN Funciones ya definidas para Chars.