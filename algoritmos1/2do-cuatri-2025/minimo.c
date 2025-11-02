#include <stdio.h>
#include <assert.h>

int minimo(int a, int b)
{
    int res = b;
    if (a <= b)
    {
        res = a;
    }

    return res;
}
int main()
{
    int num1 = 0;
    int num2 = 0;
    printf("\nIngrese el primer numero:");
    scanf("%d", &num1);
    printf("\nIngrese el segundo numero:");
    scanf("%d", &num2);
    printf("\nEl menor entre %d y %d es: %d", num1, num2, minimo(num1, num2));
    return 0;
}