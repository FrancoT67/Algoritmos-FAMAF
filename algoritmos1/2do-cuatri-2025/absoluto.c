#include <stdio.h>
#include <assert.h>

int absoluto(int a)
{
    int res = a;
    if (a < 0)
    {
        res = -a;
    }

    return res;
}
int main()
{
    int num1 = 0;

    printf("\nIngrese el numero:");
    scanf("%d", &num1);
    printf("\nEl valor absoluto de %d es: %d", num1, absoluto(num1));
    return 0;
}