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
    for(int i=0;i<n_max;i++){
     printf("Ingrese el valor para a[%d]",i);
     scanf("%d",&a[i]);
     }
}

//Defincion del Prototipo imprimir_arreglo.
void imprimir_arreglo(int n_max, int a[]){
    printf("El arreglo ingresado es:[");
    for (int i = 0; i < n_max; i++){
        if(i==(n_max-1)){
         printf("%d]",a[i]);
         }
        printf("%d,",a[i]);
    }
    
}
