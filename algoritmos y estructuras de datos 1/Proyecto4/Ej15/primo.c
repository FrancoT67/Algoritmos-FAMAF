#include <stdio.h>

int es_primo(int num)
{
    if (num <= 1)
    {
        return 0; // No es primo
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // No es primo
        }
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
        printf("Ingrese un umero positivo para encontrar el n-esimo primo: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Error: El número debe ser no negativo. Por favor, ingrese un nuevo valor.\n");
        }
    } while (n < 0);

    int resultado = nesimo_primo(n);
    printf("El %d-esimo primo es: %d\n", n, resultado);
    return 0;
}
