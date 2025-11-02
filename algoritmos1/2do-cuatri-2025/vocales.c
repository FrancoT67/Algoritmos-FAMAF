#include <stdio.h>
#include <stdbool.h>
#define N 10

bool es_vocal(char letra)
{
    char vocales[N] = "aeiouAEIOU";
    bool res = false;
    int i = 0;

    while (i < N && !res)
    {
        if (letra == vocales[i])
        {
            res = true;
        }
        i += 1;
    }
    return res;
}
char pedir_char()
{
    char res;
    printf("Ingrese una letra:");
    scanf("%c", &res);
    return res;
}
int main()
{
    char letra_ingresada;
    bool resultado;
    letra_ingresada = pedir_char();
    resultado = es_vocal(letra_ingresada);
    if (resultado)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}