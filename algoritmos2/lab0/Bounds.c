#include <stdio.h>
#include <stdbool.h>

struct bound_data
{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length);

int main()
{
    struct bound_data result;
    int a[] = {0, -1, 9, 4};
    result = check_bound(-2, a, 4);
    printf("mayor %d\n", result.is_upperbound); // Imprime 1
    printf("menor %d\n", result.is_lowerbound); // Imprime 0
    printf("existe %d\n", result.exists);       // Imprime 1
    printf("donde %u\n", result.where);         // Imprime 2
    return 0;
}

struct bound_data check_bound(int value, int arr[], unsigned int length)
{
    struct bound_data dataResult;
    dataResult.is_lowerbound = true;
    dataResult.is_upperbound = false;
    dataResult.where = 0;
    unsigned int i = 0;
    while (i < length - 1)
    {
        if (value == arr[i] || value == arr[i + 1])
        {
            dataResult.exists = true;
            dataResult.where = i;
        }
        if (value > arr[i] && value > arr[i + 1])
        {
            dataResult.is_upperbound = true;
            dataResult.is_lowerbound = false;
        }

        i += 1;
    }

    return dataResult;
}
