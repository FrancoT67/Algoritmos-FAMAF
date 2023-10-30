#include <stdio.h>

//Expansion de la libreria Assert.
#include <assert.h>

//Expansion de la Libreria para los tipos Booleanos.
#include <stdbool.h>

//Expansión de libreria personal con Funciones Auxiliares.
#include "../auxFunctions/arreglos.h"

//Definición de Prototipos.
bool todos_pares(int tam, int a[]);
bool existe_multiplo(int m, int tam, int a[]);
void menu(int opcion,int tamañoArreglo,int a[]);
int main(){
    //Inicializacion de Varibles.
    int tamañoArreglo=0;
    //int multiplo=0;
    int opcion=0;

    //Solicitud de valores al Usuario.
    printf("Ingrese un número positivo para el tamaño del arreglo: ");
    scanf("%d", &tamañoArreglo);

    // Creamos un arreglo de tamaño tamañoArreglo.
    int a[tamañoArreglo]; 
    
    // Llamamos a la función para pedir el arreglo al usuario.
    pedir_arreglo(tamañoArreglo, a);

    //Llamamos a ala funcion Menu, donde corre la interfaz para el usuario.
    menu(opcion,tamañoArreglo,a);
    
    return 0;
}


//Defincion del prototipo todos_pares.
bool todos_pares(int tam, int a[]){
    for (int i = 0; i < tam; i++){
        if (a[i]%2!=0){

            return false;
        }
    }
    
    return true;
}

//Definicion del prototipo existe_multiplo.
bool existe_multiplo(int m, int tam, int a[]){

    for (int i = 0; i < tam; i++){
        if (a[i]%m==0){
            return true;
        }
    }
    
    return false;
}

//Definicion del Prototipo menu.
void menu(int opcion, int tamañoArreglo,int a[]){
    int multiplo=0;
    while (opcion !=3){

        printf("Ingrese el número de la opcion que desea: \n\t1-Verificar si todos son pares.\n\t2-Verificar si existe un multiplo.\n\t3-Salir.\n\t");
        scanf("%d",&opcion);

        //Condicional para usar todos_pares.
        if (opcion==1){

            if (todos_pares(tamañoArreglo,a)){
                printf("\n\tTodos  pares!!\n\n");
            }else{
                printf("\n\tExiste al menos uno que no es par.\n\n");
            }
        }
        
        //Condicional para usar existe_multiplo.
        if (opcion==2){

            printf("Ingrese el valor del multiplo a buscar:");
            scanf("%d",&multiplo);
            if (existe_multiplo(multiplo,tamañoArreglo,a)){
                printf("\n\tExiste uno que es Multiplo de %d.\n\n",multiplo);
            }else{
                printf("\n\tNo existe alguno que sea Multiplo de %d.\n\n",multiplo);
            }
    
        }
        //Condicional para salir del bucle.
        if (opcion==3){
            printf("Gracias por usar el programa!!");
            break;
        }
        if(opcion<1 || opcion>3)
        {
            printf("\n\nOpcion Incorrecta\n\n Las opciones son: \n1-Verificar si todos son pares.\n\t2-Verificar si existe un multiplo.\n\t3-Salir.\n\t");   
        }
    }
}
