#include <stdio.h>

//Expansion de la libreria Assert.
#include <assert.h>

//Defincion de Prototipos.
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);


int main() {

    //Inicializacion de Varibles.
    int n_max;

    //Solicitud de valores al Usuario.
    printf("Ingrese un número positivo para el tamaño del arreglo: ");
    scanf("%d", &n_max);

    //Validación de que el valor ingresado sea Positivo.
    if (n_max<=0){
        printf("No se puede crear un arreglo con valores menores a 0");
        assert(n_max>0);
    }
    
    // Creamos un arreglo de tamaño n_max
    int a[n_max]; 
    
    // Llamamos a la función para pedir el arreglo al usuario
    pedir_arreglo(n_max, a);
    
    // Llamamos a la función para imprimir el arreglo
    imprimir_arreglo(n_max, a);
    
    return 0;
}

//Definición del Prototipo pedir_arreglo. 
void pedir_arreglo(int n_max, int a[]) {
    for (int i = 0; i < n_max; ++i) {
        printf("Ingrese un valor para a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

//Definición del Prototipo imprimir_arreglo. 
void imprimir_arreglo(int n_max, int a[]) {
    printf("El arreglo ingresado es: [");
    for (int i = 0; i < n_max; ++i) {
        if (i==n_max-1){
            printf("%d] ", a[i]);
        }else{
            printf("%d, ", a[i]); 
        }
    }   
}