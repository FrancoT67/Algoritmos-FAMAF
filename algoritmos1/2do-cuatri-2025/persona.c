#include <stdio.h>
#include <stdbool.h>

typedef struct _persona
{
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

float peso_promedio(int longitud, persona_t arr[]);
persona_t persona_de_mayor_edad(int longitud, persona_t arr[]);
persona_t persona_de_menor_altura(int longitud, persona_t arr[]);

int main()
{
    persona_t p1 = {.nombre = "Paola", .edad = 21, .altura = 1.85, .peso = 75};
    persona_t p2 = {.nombre = "Luis", .edad = 54, .altura = 1.75, .peso = 69};
    persona_t p3 = {.nombre = "Julio", .edad = 40, .altura = 1.70, .peso = 80};
    unsigned int longitud = 3;
    persona_t arr[] = {p1, p2, p3};
    printf("El peso promedio es %f\n", peso_promedio(longitud, arr));
    persona_t p = persona_de_mayor_edad(longitud, arr);
    printf("El nombre de la persona con mayor edad es %s\n", p.nombre);
    p = persona_de_menor_altura(longitud, arr);
    printf("El nombre de la persona con menor altura es %s\n", p.nombre);
    return 0;
}

float peso_promedio(int longitud, persona_t arr[])
{
    float res = 0;
    int i = 0;
    while (i < longitud)
    {
        res = res + arr[i].peso;
        i++;
    }
    res = res / longitud;

    return res;
}

persona_t persona_de_mayor_edad(int longitud, persona_t arr[])
{
    persona_t res = arr[0];
    int i = 0;
    while (i < longitud)
    {
        if (res.edad < arr[i].edad)
        {
            res = arr[i];
        }
        i++;
    }

    return res;
}

persona_t persona_de_menor_altura(int longitud, persona_t arr[])
{
    persona_t res = arr[0];
    int i = 0;
    while (i < longitud)
    {
        if (res.altura >= arr[i].altura)
        {
            res = arr[i];
        }
        i++;
    }

    return res;
}
