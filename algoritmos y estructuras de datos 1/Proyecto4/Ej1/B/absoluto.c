#include <stdio.h>

//Expansion de libreria Assert.
#include <assert.h>

//Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"
#include "../../auxFunctions/imprimeTexto.h"

// Declaración de Prototipo.
int absolutoNumero(int a);
int main(){
    int num=0;
    num=pedirEntero('n');

    // // No encontré la necesidad de aplicar un assert en este programa.

    imprimeEntero('n',absolutoNumero(num));
    return 0;
}

int absolutoNumero(int a){
    if(a>=0){
        assert(a>=0);
        return a;
    }else{
        assert(a<0);
        return(a*(-1));
    }
}
