#include <stdio.h>

//Expansion de libreria Assert.
#include <assert.h>

//Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"
#include "../../auxFunctions/imprimeTexto.h"

// Declaración de Prototipo.
int verificaMinimo(int a, int b);

int main(){
    // Inicializacion de variables.
    int a=0;
    int b=0;

    // Solicitud de Datos al usuario.
    a=pedirEntero('a');
    b=pedirEntero('b');
    //Verifico que sean distintos, porque no tiene sentido buscar el minimo si ambos son iguales.
    assert(a!=b);


    printf("El valor minimo entre %d y %d es: %d\n",a,b,verificaMinimo(a,b));
    return 0;
}

// Definicion del prototipo.
int verificaMinimo(int a, int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}
