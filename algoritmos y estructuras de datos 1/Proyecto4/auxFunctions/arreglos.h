#include <stdio.h>

//Expansion de la libreria Assert.
#include <assert.h>

//Defincion de Prototipos.
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);


//Definición del Prototipo pedir_arreglo. 
void pedir_arreglo(int n_max, int a[]) {

   
    //Validación de que el valor ingresado sea Positivo.
    if (n_max<=0){
        printf("No se puede crear un arreglo con valores menores a 0");
        assert(n_max>0);
    }

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
