#include <stdio.h>
#include <stdbool.h>


int B1(int valorX, int valorY){
    int i=0;
    while (valorX>=valorY){
        valorX=valorX-valorY;
        i=i+1;
        printf(" El valor de X es :%d \n El valor de Y es:%d\n en la iteracion n°(I): %d\n",valorX,valorY,i);
    }
    return 0;
    
}
/*int B2(int valorX, int respuesta){
    int i = 2;
    bool respuesta = true;
    while (i<valorX && respuesta){
        bool respuesta = respuesta && ((valorX%i)!=0);
        i=i+1;
        printf(" El valor de X es :%d \n El valor de Y es:%d\n en la iteracion n°(I): %d\n",valorX,respuesta,i);
    }
    return  0;
    
}*/

int main(){

    int x=0;
    int y=0;
    printf("****************** Ejercicio 5.B1) ******************\n\n");
    printf("Ingrese el valor para X:");
    scanf("%d",&x);
    printf("Ingrese el valor para Y: ");
    scanf("%d",&y);
    printf("%d",B1(x,y));
    printf("*****************************************************\n\n");
    
    return 0;
}
