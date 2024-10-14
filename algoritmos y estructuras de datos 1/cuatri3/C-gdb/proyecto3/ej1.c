// Como compilar en C: Para compilar un archivo .c escribir en la terminal:
// $> gcc -Wall -Wextra -std=c99 miarchivo.c -o miprograma
// Para ejecutar escribir:
// $> ./miprograma
// Para compilar para gdb, agregar el flag -g al momento de compilar .c escribir en la terminal:
// $> gcc -Wall -Wextra -std=c99 -g miarchivo.c -o miprograma

#include <stdio.h>

int main()
{
    int x;
    int y;
    int z;
    printf("Ingresar un valor para X:");
    scanf("%d", &x);
    printf("\nIngresar un valor para Y:");
    scanf("%d", &y);

    printf("*********  *********\n");
    printf("x+y+1: %d\n", x + y + 1);

    printf("*********  *********\n");
    printf("Ingresar un valor para Z: ");
    scanf("%d", &z);
    printf("\nz * z + y * 45 - 15 * x: %d\n", z * z + y * 45 - 15 * x);

    printf("*********  *********\n");
    printf("y - 2 == (x * 3 + 1) mod 5: %d\n", x + y + 1);

    printf("*********  *********\n");
    printf("y / 2 * x: %d\n", z / 2 * x);

    printf("*********  *********\n");
    printf("y < x * z(1=True y 0=False): %d\n", y < x * z);

    return 0;
}
