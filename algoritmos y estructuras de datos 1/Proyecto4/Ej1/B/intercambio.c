#include <stdio.h>

//Expansion de libreria Assert.
#include <assert.h>

//Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"
#include "../../auxFunctions/imprimeTexto.h"

void intercambiar(int a,int b,int c);
int main(){

    // Instanciación de Variables.
    int x=0;
    int y=0;
    int z=0;
    
    // Solicitud de datos al usuario.
    x=pedirEntero('x');
    y=pedirEntero('y');
    z=pedirEntero('z');
    
    //Validacion de que sean diferentes, sino no hay razon para intercambiar sus valores.
    assert((x!=y) && (x!=z) && (y!=z));

    //Muestra de los datos iniciales.
    printf("******************************** Valores  Iniciales *********************************\n\t");
    printf("El valor incial de X es:%d\n\tEl valor incial de Y es:%d\n\tEl valor incial de Z es:%d\n",x,y,z);
    
    //Muestra de los datos luego del Intercambio.
    intercambiar(x,y,z);

    return 0;
}

void intercambiar(int numX, int numY, int numZ){
    //Instanciacion de Variables Auxiliares.
    int auxX=numX;
    int auxY=numY;
    int auxZ=numZ;

    //Intercambio de Valores.
    numZ=auxX;
    numX=auxY;
    numY=auxZ;
    printf("******************************** Valores  Intercambiados *********************************\n\t");
    printf("El valor posterior de X es:%d\n\tEl valor posterior de Y es:%d\n\tEl valor posterior de Z es:%d\n\t",numX,numY,numZ);
}
