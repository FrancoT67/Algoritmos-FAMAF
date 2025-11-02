#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data
{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length)
{
    struct bound_data res;
    res.is_lowerbound = true;
    res.is_upperbound = false;
    res.where = 0;
    unsigned int i = 0;
    while (i < length - 1)
    {
        if (value == arr[i] || value == arr[i + 1])
        {
            res.exists = true;
            res.where = i;
        }
        if (value > arr[i] && value > arr[i + 1])
        {
            res.is_upperbound = true;
            res.is_lowerbound = false;
        }

        i += 1;
    }
    return res;
}

void llenarArray(unsigned int length, int arr[])
{
    unsigned int i = 0;
    int value = 0;
    while (i < length)
    {
        printf("Ingrese un valor para la posicion %d: ", i);
        scanf("%d", &value);
        arr[i] = value;
        value = 0;
        printf("\n");
        i += 1;
    }
}

void mostrarArray(unsigned int length, int arr[])
{
    printf("[");
    unsigned int i = 0;
    while (i < (length - 1))
    {
        printf("%d,", arr[i]);
        i = i + 1;
    }
    printf("%d]\n", arr[length - 1]);
}

int main(void)
{
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    // int value = 9;
    int value1 = 0;
    printf("Ingrese un valor para buscar:");
    scanf("%d", &value1);
    llenarArray(ARRAY_SIZE, a);
    mostrarArray(ARRAY_SIZE, a);
    struct bound_data result = check_bound(value1, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    if (result.exists == true)
    {

        printf("Upper: %d \n", result.is_upperbound); // Imprime 1
        printf("Lower: %d \n", result.is_lowerbound); // Imprime 0
        printf("Exist: %u \n", result.exists);        // Imprime 1
        printf("Where: %u \n", result.where);         // Imprime 2
    }
    else
    {

        printf("Upper: %d \n", result.is_upperbound); // Imprime 1
        printf("Lower: %d \n", result.is_lowerbound); // Imprime 0
        printf("Exist: %u \n", result.exists);        // Imprime 1
    }

    return EXIT_SUCCESS;
}
