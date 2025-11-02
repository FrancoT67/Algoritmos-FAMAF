#include <stdio.h>
#include <assert.h>
#define N 5

typedef float decimal;
typedef struct
{
  int cuantas_bajas;
  int cuantas_medias;
  int cuantas_altas;
} s_temperaturas;

s_temperaturas totales(float a[], int tam);

void imprimir_arregloFloat(int n_max, float a[])
{

  printf("[");
  int i = 0;
  while (i < (n_max - 1))
  {
    printf("%f,", a[i]);
    i = i + 1;
  }
  printf("%f]\n", a[n_max - 1]);
}

void llenar_con_temperaturas(float a[], int tam)
{

  int i = 0;
  float valor = 0;
  while (i < tam)
  {
    printf("Ingrese los Grados en Celsius para la posicion %d:", i);
    scanf("%f", &valor);
    a[i] = valor;
    valor = 0;
    i = i + 1;
  }
}

int main()
{
  float arreglo[N];
  assert(N > 0);
  llenar_con_temperaturas(arreglo, N);
  printf("El arreglo ingresado en Grados Celsius es:");
  imprimir_arregloFloat(N, arreglo);
  printf("Existen:\n\t temperaturas bajas:%d\n\t Temperaturas medias:%d\n\t Temperaturas Altas:%d \n", totales(arreglo, N).cuantas_bajas, totales(arreglo, N).cuantas_medias, totales(arreglo, N).cuantas_altas);
  return 0;
}

s_temperaturas totales(float a[], int tam)
{
  s_temperaturas respuestas;
  int i = 0;
  int menores = 0;
  int medias = 0;
  int altas = 0;
  while (i < tam)
  {
    if (a[i] < 15.0)
    {
      menores = menores + 1;
    }
    if (a[i] >= 15.0 && a[i] <= 30.0)
    {
      medias = medias + 1;
    }
    if (a[i] > 30.0)
    {
      altas = altas + 1;
    }
    i = i + 1;
  }
  respuestas.cuantas_altas = altas;
  respuestas.cuantas_medias = medias;
  respuestas.cuantas_bajas = menores;
  return respuestas;
}

/**
 * Ingrese los Grados en Celsius para la posicion 0:0
Ingrese los Grados en Celsius para la posicion 1:-1.5
Ingrese los Grados en Celsius para la posicion 2:15
Ingrese los Grados en Celsius para la posicion 3:30
Ingrese los Grados en Celsius para la posicion 4:38
El arreglo ingresado en Grados Celsius es:[0.000000,-1.500000,15.000000,30.000000,38.000000]
Existen:
         temperaturas bajas:2
         Temperaturas medias:2
         Temperaturas Altas:1
 *
*/