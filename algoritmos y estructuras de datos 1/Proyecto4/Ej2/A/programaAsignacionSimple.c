#include <stdio.h>

//Expansion de libreria Assert.
#include <assert.h>

//Expansion de librerias Propias con Funciones Auxiliares.
#include "../../auxFunctions/entradasInt.h"
#include "../../auxFunctions/imprimeTexto.h"


int main(){

    //Instanciacion de Variables.
    int x=0;
    int y=0;
    int z=0;

    //Solicitud de Datos al Usuario.
    x=pedirEntero('x');
    y=pedirEntero('y');
    z=pedirEntero('z');
    
    int xaux=x; 
    int yaux=y;
    int zaux=z;


    
    printf("Ejecucion de Funcion 1 \n");
    x=xaux+1;
    y=xaux+yaux;
   /*
    {Pre: x = X, y = Y}
    x, y := x + 1, x + y
    {Post: x = X + 1, y = X + Y}
    
    Voy a definir el programa de arriba como funcion1.
    */
    printf("El valor de X=%d.\nEL valor de Y=%d.\n",x,y);
    
    printf("****************** **********************\n");
    printf("Ejecucion de Funcion 2 \n");
    /*
    {Pre: x = X, y = Y, z = Z}
    x, y, z := y, y + x + z, y + x
    {Post: x = Y, y = Y + X + Z, z = Y + X}

    Voy a definir el programa de arriba como funcion2.
    */
    x=yaux;
    y=yaux+xaux+zaux;
    z=yaux+xaux;

    printf("El valor de X=%d.\nEL valor de Y=%d.\nEl valor de Z=%d.",x,y,z);
    
    return 0;
}


