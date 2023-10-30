#include <stdio.h>

//Expansion de Libreria Personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

//Definicion de Prototipos.
void intercambiar(int tam, int a[], int i, int j);

int main()
{
    //Instanciacion de Variables.
    int pos1=0;
    int pos2=0;
    int tamañoArreglo=0;

    //Solicitud del tamaño del Arreglo al Usuario.
    printf("Ingrese un valor entero positivo para el tamaño del arreglo.");
    scanf("%d",&tamañoArreglo);

    //Creamos el arreglo de tamano tamañoArreglo.
    int a[tamañoArreglo];
    
    //Solcitamos los valores para el Arreglo.
    pedir_arreglo(tamañoArreglo,a);

    //Mostramos el arreglo ingresado.
    imprimir_arreglo(tamañoArreglo,a);

    //Llamada a la funcion para Intercambiar los valores.
    intercambiar(tamañoArreglo,a,pos1,pos2);

    return 0;
}

void intercambiar(int tam, int a[], int i, int j)
{
}
