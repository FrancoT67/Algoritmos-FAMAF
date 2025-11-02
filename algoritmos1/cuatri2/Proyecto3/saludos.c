#include <stdio.h>

/* Intenciacion de Prototipos. */
void imprimeHola(void);
void imprimeChau(void);

int main()
{
    imprimeHola();
    imprimeChau();
    return 0;
}

/* Definicion de los prototipos. */
void imprimeHola(void)
{
    printf("Hola\n");
    printf("Hola\n");
}

void imprimeChau(void)
{
    printf("Chau\n");
    printf("Chau\n");
}
