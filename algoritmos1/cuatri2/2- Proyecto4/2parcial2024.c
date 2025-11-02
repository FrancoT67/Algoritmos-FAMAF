/**
 * a)
void llenar_con_temperaturas(float a[], int tam);
que dado un arreglo a[] de tamaño tam, pide al usuario ingresar los valores (float) del
arreglo. Cada valor representa una temperatura en grados Celsius.
 * 
*/
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5



void imprimeBool(char* name, bool x)
{
    if (x == 1)
    {
        printf("%s: verdadero\n\n", name);
    }
    else
    {
        printf("%s: falso\n\n", name);
    }
}


void llenar_con_temperaturas(float a[], int tam);
bool hay_mas_de_2_altas(float a[], int tam);

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


int main()
{
  float arreglo[N];
  assert(N>0);
  bool respuesta;
  llenar_con_temperaturas(arreglo,N);
  printf("El arreglo ingresado en Grados Celsius es:");
  imprimir_arregloFloat(N,arreglo);
  respuesta=hay_mas_de_2_altas(arreglo,N);
  imprimeBool("Existen mayores a 30.0 y menores a 45.0:",respuesta);

  return 0;
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

bool hay_mas_de_2_altas(float a[], int tam){
int i=0;
int contador=0;
while (i<tam){
  if (a[i]>=30.0 && a[i]<=45.0){
    contador=contador+1;
  }
  i=i+1;
  if (contador>=3)
  {
    return true;
  }
  
}
  return false;
}


/**
 * /2parcialC
Ingrese los Grados en Celsius para la posicion 0:28.5
Ingrese los Grados en Celsius para la posicion 1:32.0
Ingrese los Grados en Celsius para la posicion 2:29.5
Ingrese los Grados en Celsius para la posicion 3:35.2
Ingrese los Grados en Celsius para la posicion 4:40.0
El arreglo ingresado en Grados Celsius es:[28.500000,32.000000,29.500000,35.200001,40.000000]
Existen mayores a 30.0 y menores a 45.0:: verdadero
 * 
*/