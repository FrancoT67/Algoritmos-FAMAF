#include <stdio.h>
#include "./entradasInt.h"
/*
    Se define antes del main para indicar al compilador que existe una función llamada pedirEntero que será utilizada más adelante en el código.
    Esta técnica se llama declaración anticipada o prototipo de función, para que el compilador sepa qué tipo de datos devuelve la función y qué tipo de argumentos espera antes de que la función sea realmente definida más adelante en el código.
 */

/* Prototipo de las funciones a definir.*/
int pedirEntero(char name);
void imprimeEntero(char name, int x);

int main(void)
{
    /*Inicializacion de Variables*/
    int pideEntero = 0;
    char texto = 't';

    /* Ingreso de valores a las variables */
    printf("Ingrese una letra: ");
    scanf("%c", &texto);

    /* Llamado a las funciones. */
    pideEntero = pedirEntero(texto);
    imprimeEntero(texto, pideEntero);
    return 0;
}

/* Defincion de los Prototipos */
int pedirEntero(char name)
{
    int n = 0;
    printf("Ingrese el entero para la variable %c:", name); // lo que hace es recibir un char como parametro, y asi decir que ése es el nombre de la variable que va a almacenar el valor, pero puede serlo, como puede llamarse de otra forma y el mensaje no cambiariía a menos que le pasemos otro char como parámetro.
    scanf("%d", &n);
    return n;
}

void imprimeEntero(char name, int x)
{
    printf("el valor de %c es :%d\n", name, x);
}
