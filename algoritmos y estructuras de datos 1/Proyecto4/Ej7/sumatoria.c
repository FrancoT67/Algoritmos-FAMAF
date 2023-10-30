#include <stdio.h>

//Expansion de la libreria Assert.
#include <assert.h>
#include "../auxFunctions/arreglos.h"


//Defincion de Prototipos.
int sumatoria(int tam, int a[]);

int main() {

    //Inicializacion de Varibles.
    int tamañoArreglo;

    //Solicitud de valores al Usuario.
    printf("Ingrese un número positivo para el tamaño del arreglo: ");
    scanf("%d", &tamañoArreglo);

    // Creamos un arreglo de tamaño tamañoArreglo.
    int a[tamañoArreglo]; 
    
    // Llamamos a la función para pedir el arreglo al usuario.
    pedir_arreglo(tamañoArreglo, a);
    
    // Imprimimos el resultado de la suma de los valores del arreglo.
    printf("el resultado de la suma del arreglo ingresado es: %d",sumatoria(tamañoArreglo, a));
    
    return 0;
}

//Definción del Prototipo Sumatoria.
int sumatoria(int tam, int a[]){
    int resultadoSuma=0;
    for (int i = 0; i < tam; i++)
    {
        resultadoSuma+=a[i];
    }
    return resultadoSuma;
}
