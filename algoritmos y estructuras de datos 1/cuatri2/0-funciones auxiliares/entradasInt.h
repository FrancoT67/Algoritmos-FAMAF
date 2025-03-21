#include <stdio.h>
int pedirEntero(char name);
void imprimeEntero(char name, int x);

// Funciones ya definidas.
int pedirEntero(char name)
{
    int n = 0;
    // lo que hace es recibir un char como parametro, y asi decir que ése es el nombre de la variable que va a almacenar el valor, pero puede serlo, como puede llamarse de otra forma y el mensaje no cambiariía a menos que le pasemos otro char como parámetro.
    printf("Ingrese un entero para la variable %c:", name);
    scanf("%d", &n);
    return n;
}

void imprimeEntero(char name, int x)
{
    printf("el valor de %c es :%d\n", name, x);
}
