#include <stdio.h>

// Inclision de Biblioteca necesaria para el tipo Bool.
#include <stdbool.h>

int main()
{
    // Declaracion e inicializacion del valor booleano a true.
    bool variable = true;
    int x = 0;

    printf("Ingrese true o false:");
    scanf("%d", &x);
    variable = x;
    printf("%d", variable);

    return 0;
}
