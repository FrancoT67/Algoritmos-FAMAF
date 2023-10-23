#include <stdio.h>

//Expansion de libreria Assert.
#include <assert.h>

//Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"
#include "../../auxFunctions/imprimeTexto.h"

//Prototipos de Funciones.
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);

int main(){
    //Instanciación de Variables.
    int n_max=0;
    int a[n]

    //Solicitud del tamaño del 
    printf("Ingrese un valor numérico positivo para el tamaño del arreglo:");
    scanf("%d",&maxArreglo);
    assert(maxArreglo>0);
    pedir_arreglo(maxArreglo,a);

    return 0;
}

//Defincion del Prototipo pedir_arreglo.
void pedir_arreglo(int n_max, int a[]){
    if (n_max<=0){
        imprimeTexto("No se puede crear un arreglo de tamaño cero o  negativo");
        assert(n_max>0);
    }
    int a[n_max];
}

//Defincion del Prototipo imprimir_arreglo.
void imprimir_arreglo(int n_max, int a[]){
    for (int i = 0; i < n_max; i++)
    {
        printf("El valor del arreglo en la posición %d es : %d\n",i,a[i]);
    }
    
}
