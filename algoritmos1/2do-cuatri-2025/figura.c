#include <stdio.h>
#include <stdbool.h>
typedef enum _forma
{
    TRIANGULO,
    CUADRADO,
    CIRCULO
} forma_t;

typedef enum _color
{
    ROJO,
    AZUL,
    VERDE,
    AMARILLO
} color_t;

typedef struct _figura
{
    forma_t forma;
    color_t color;
    int tamano;
} figura_t;

/* a) Definir las funciones es_roja, es_verde, es_azul, es_amarilla, es_triangulo, es_cuadrado,
es_circulo, que devuelva bool si la figura es de la caracter ́ıstica correspondiente. */
bool es_roja(figura_t f);
bool es_azul(figura_t f);
bool es_verde(figura_t f);
bool es_amarillo(figura_t f);

bool es_triangulo(figura_t f);
bool es_circulo(figura_t f);
bool es_cuadrado(figura_t f);

/*definir la funcion tam que devuelve el tamaño de la figura*/
int tam(figura_t f);

/**definir la funcion todas_rojas, que toma un entero n y un arreglo de figuras de tamaño n y devuelve verdadero si son todas rojas, y falso en caso contrario */

bool todas_rojas(int longitud, figura_t arr[]);

/*Derivar e implementar la funci ́on triangulos_amarillos, que toma un entero n y un arreglo de figuras de
tama ̃no n y devuelve verdadero si son todos los triangulos son amarillos, y falso en caso contrario.*/
bool triangulos_amarillos(int longitud, figura_t arr[]);

/** f) Derivar e implementar la funci ́on suma_tam, que toma un entero n y un arreglo de figuras de tama ̃no n y
devuelve la suma de los tama ̃nos de cada figura. */

int suma_tam(int longuitud, figura_t arr[]);

int main()
{
    figura_t f1 = {.forma = TRIANGULO, .color = ROJO, .tamano = 5};
    figura_t f2 = {.forma = CIRCULO, .color = ROJO, .tamano = 1};
    figura_t f3 = {.forma = TRIANGULO, .color = ROJO, .tamano = 4};
    int longitud = 3;
    figura_t arr[] = {f1, f2, f3};
    /**ejemplo de arreglo 2 */
    figura_t t1 = {.forma = CUADRADO, .color = AZUL, .tamano = 15};
    figura_t t2 = {.forma = CIRCULO, .color = ROJO, .tamano = 8};
    figura_t t3 = {.forma = TRIANGULO, .color = AMARILLO, .tamano = 49};
    longitud = 3;
    figura_t arr2[] = {t1, t2, t3};

    /* COMPLETAR */
    /**rojos */
    if (todas_rojas(longitud, arr))
    {
        printf("\nson todas rojas");
    }
    else
    {
        printf("\nno son todas rojas");
    }
    if (todas_rojas(longitud, arr2))
    {
        printf("\nson todas rojas");
    }
    else
    {
        printf("\nno son todas rojas");
    }

    /**Triangulos amarillos */
    if (triangulos_amarillos(longitud, arr))
    {
        printf("\nson todas triangulos amarillos");
    }
    else
    {
        printf("\nno son todas triangulos amarillos");
    }
    if (triangulos_amarillos(longitud, arr2))
    {
        printf("\nson todas triangulos amarillos");
    }
    else
    {
        printf("\nno son todas triangulos amarillos");
    }

    /**es_roja() */
    printf("\nes roja F:%d (1-True, 0-False)", es_roja(f1));
    printf("\nes roja F:%d (1-True, 0-False)", es_roja(f2));
    printf("\nes roja F:%d (1-True, 0-False)", es_roja(f3));

    printf("\nes roja T:%d (1-True, 0-False)", es_roja(t1));
    printf("\nes roja T:%d (1-True, 0-False)", es_roja(t2));
    printf("\nes roja T:%d (1-True, 0-False)", es_roja(t3));

    /**es_verde() */
    printf("\nes verde F:%d (1-True, 0-False)", es_verde(f1));
    printf("\nes verde F:%d (1-True, 0-False)", es_verde(f2));
    printf("\nes verde F:%d (1-True, 0-False)", es_verde(f3));

    printf("\nes verde T:%d (1-True, 0-False)", es_verde(t1));
    printf("\nes verde T:%d (1-True, 0-False)", es_verde(t2));
    printf("\nes verde T:%d (1-True, 0-False)", es_verde(t3));

    /**es_azul() */
    printf("\nes azul F:%d (1-True, 0-False)", es_azul(f1));
    printf("\nes azul F:%d (1-True, 0-False)", es_azul(f2));
    printf("\nes azul F:%d (1-True, 0-False)", es_azul(f3));

    printf("\nes azul T:%d (1-True, 0-False)", es_azul(t1));
    printf("\nes azul T:%d (1-True, 0-False)", es_azul(t2));
    printf("\nes azul T:%d (1-True, 0-False)", es_azul(t3));

    /**es_amarillo() */
    printf("\nes amarillo F:%d (1-True, 0-False)", es_amarillo(f1));
    printf("\nes amarillo F:%d (1-True, 0-False)", es_amarillo(f2));
    printf("\nes amarillo F:%d (1-True, 0-False)", es_amarillo(f3));

    printf("\nes amarillo T:%d (1-True, 0-False)", es_amarillo(t1));
    printf("\nes amarillo T:%d (1-True, 0-False)", es_amarillo(t2));
    printf("\nes amarillo T:%d (1-True, 0-False)", es_amarillo(t3));

    /**es_triangulo() */
    printf("\nes triangulo F:%d (1-True, 0-False)", es_triangulo(f1));
    printf("\nes triangulo F:%d (1-True, 0-False)", es_triangulo(f2));
    printf("\nes triangulo F:%d (1-True, 0-False)", es_triangulo(f3));

    printf("\nes triangulo T:%d (1-True, 0-False)", es_triangulo(t1));
    printf("\nes triangulo T:%d (1-True, 0-False)", es_triangulo(t2));
    printf("\nes triangulo T:%d (1-True, 0-False)", es_triangulo(t3));

    /**es_cuadrado() */
    printf("\nes cuadrado F:%d (1-True, 0-False)", es_cuadrado(f1));
    printf("\nes cuadrado F:%d (1-True, 0-False)", es_cuadrado(f2));
    printf("\nes cuadrado F:%d (1-True, 0-False)", es_cuadrado(f3));

    printf("\nes cuadrado T:%d (1-True, 0-False)", es_cuadrado(t1));
    printf("\nes cuadrado T:%d (1-True, 0-False)", es_cuadrado(t2));
    printf("\nes cuadrado T:%d (1-True, 0-False)", es_cuadrado(t3));

    /**es_circulo() */
    printf("\nes circulo F:%d (1-True, 0-False)", es_circulo(f1));
    printf("\nes circulo F:%d (1-True, 0-False)", es_circulo(f2));
    printf("\nes circulo F:%d (1-True, 0-False)", es_circulo(f3));

    printf("\nes circulo T:%d (1-True, 0-False)", es_circulo(t1));
    printf("\nes circulo T:%d (1-True, 0-False)", es_circulo(t2));
    printf("\nes circulo T:%d (1-True, 0-False)", es_circulo(t3));

    /**tam() */
    printf("\nel tamano de F1 es:%d", tam(f1));
    printf("\nel tamano de F2 es:%d", tam(f2));
    printf("\nel tamano de F3 es:%d", tam(f3));

    printf("\nel tamano de T1 es:%d", tam(t1));
    printf("\nel tamano de T2 es:%d", tam(t2));
    printf("\nel tamano de T3 es:%d", tam(t3));

    /**todas_rojas() */
    printf("\nson rojas arr:%d (1-True, 0-False)", todas_rojas(longitud, arr));
    printf("\nson rojas arr2:%d (1-True, 0-False)", todas_rojas(longitud, arr2));

    /**triangulos_amarillos() */
    printf("\nson triangulos amarillos arr:%d (1-True, 0-False)", triangulos_amarillos(longitud, arr));
    printf("\nson triangulos amarillos arr2:%d (1-True, 0-False)", triangulos_amarillos(longitud, arr2));

    /**suma_tam() */
    printf("\nla suma de tamanos del arreglo es(arr1):%d", suma_tam(longitud, arr));
    printf("\nla suma de tamanos del arreglo es(arr2):%d", suma_tam(longitud, arr2));

    return 0;
}
/**COLORES */
bool es_roja(figura_t f)
{
    bool res;
    res = f.color == ROJO;
    return res;
}
bool es_azul(figura_t f)
{
    bool res;
    res = f.color == AZUL;
    return res;
}
bool es_verde(figura_t f)
{
    bool res;
    res = f.color == VERDE;
    return res;
}
bool es_amarillo(figura_t f)
{
    bool res;
    res = f.color == AMARILLO;
    return res;
}

/**FORMAS */

bool es_circulo(figura_t f)
{
    bool res;
    res = f.forma == CIRCULO;
    return res;
}
bool es_triangulo(figura_t f)
{
    bool res;
    res = f.forma == TRIANGULO;
    return res;
}
bool es_cuadrado(figura_t f)
{
    bool res;
    res = f.forma == CUADRADO;
    return res;
}
/**tamaño */
int tam(figura_t f)
{
    int res = 0;
    res = f.tamano;
    return res;
}
/**todas rojas */
bool todas_rojas(int longitud, figura_t arr[])
{
    bool res = true;
    int n = 0;
    while (n < longitud)
    {
        res = res && arr[n].color == ROJO;
        n++;
    }
    return res;
}
/** triangulos amarillos */
bool triangulos_amarillos(int longitud, figura_t arr[])
{
    bool res = true;
    int i = 0;
    while (i < longitud)
    {
        res = res && arr[i].color == AMARILLO && arr[i].forma == TRIANGULO;
        i++;
    }

    return res;
}

int suma_tam(int longuitud, figura_t arr[])
{
    int res = 0;
    int i = 0;
    while (i < longuitud)
    {
        res = res + arr[i].tamano;
        i++;
    }
    return res;
}
