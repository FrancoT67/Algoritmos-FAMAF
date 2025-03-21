#include <stdio.h>

/**
 * Ejemplo de ejecucion:
 *  .\primoC.exe
    Ingrese un numero positivo para encontrar el n-esimo primo: 10
    El 10-esimo primo es: 29
 *  .\primoC.exe
    Ingrese un numero positivo para encontrar el n-esimo primo: -5
    Error: El numero debe ser positivo. Por favor, ingrese un nuevo valor.
    Ingrese un numero positivo para encontrar el n-esimo primo: 5
    El 5-esimo primo es: 11

*/
int es_primo(int num)
{
    if (num <= 1)
    {
        return 0; // No es primo
    }
    int i = 2;
    while (i * i <= num)
    {
        if (num % i == 0)
        {
            return 0; // No es primo
        }
        i++;
    }
    return 1; // Es primo
}

int nesimo_primo(int N)
{
    int contador = 0;
    int numero = 2;
    while (contador < N)
    {
        if (es_primo(numero))
        {
            contador++;
        }
        numero++;
    }
    return numero - 1;
}

int main()
{
    int n = 0;
    do
    {
        printf("Ingrese un numero positivo para encontrar el n-esimo primo: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("Error: El numero debe ser positivo. Por favor, ingrese un nuevo valor.\n");
        }
    } while (n <= 0);

    int resultado = nesimo_primo(n);
    printf("El %d-esimo primo es: %d\n", n, resultado);
    return 0;
}
