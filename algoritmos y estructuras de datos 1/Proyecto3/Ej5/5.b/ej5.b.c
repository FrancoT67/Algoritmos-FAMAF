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
int B2(int valorX,int valorI,int res){
    if(res < 0 || res >1 ){
        printf("valor Incorrecto, se definira a Res como 1(True).\n");
        
    }
    valorI = 2;
    res = 1;
    while (valorI<valorX && res){
        res = res && ((valorX%valorI)!= 0);
        if(res ==1){
            printf(" El valor de X es :%d \n El valor de boolExpresion es: True\n El valor de I es: %d\n *** En la iteracion n°(I): %d ***\n",valorX,valorI,(valorI-1));
            valorI=valorI+1;
            continue;

        }else{
            printf(" El valor de X es :%d \n El valor de boolExpresion es: False\n El valor de I es: %d\n *** En la iteracion n°(I): %d ***\n",valorX,valorI,(valorI-1));
            valorI=valorI+1;
        }
    }
    return 0;
}

int main(){

    //Instanciación de Variables.
    int x=0;
    int y=0;
    int i=0;
    int boolExpresion=1;
    
    //Peticion de datos y Llamado a la funcion B1.
    printf("****************** Ejercicio 5.B1) ******************\n\n");
    printf("Ingrese el valor para X:");
    scanf("%d",&x);
    printf("Ingrese el valor para Y: ");
    scanf("%d",&y);
    printf("%d\n\n",B1(x,y));
    
    //Peticion de datos y Llamado a la funcion B2.
    printf("****************** Ejercicio 5.B2) ******************\n\n");
    x=0;
    printf("Ingrese el valor para X: ");
    scanf("%d",&x);
    printf("Ingrese 1(True) o 0(False): ");
    scanf("%d",&boolExpresion);
    printf("%d\n",B2(x,i,boolExpresion));

    // Instansiacion de Variables y llamado a la funcion B1 con valores predefinidos.
    printf("****************** Ejercicio 5.B3) ******************\n\n");
    x=0;
    y=0;
    printf("Programa 1 con X=%d, Y=%d %d\n\n",10,9,B1(10,9));
    printf("Programa 1 con X=%d, Y=%d %d\n\n",9,8,B1(9,8));
    printf("Programa 1 con X=%d, Y=%d %d\n\n",8,7,B1(8,7));
    //La funcion B1 lo que hace es buscar los multiplos del número x  
    printf("***************** Fin Programa 1 *******************\n\n");
    
    x=0;
    y=0;
    printf("Programa 2 con X=%d, y Res en True.\n\n",B2(10,0,0));
    printf("Programa 2 con X=%d, y Res en False.\n\n",B2(9,2,1));
    printf("Programa 2 con X=%d, y Res en True.\n\n",B2(8,3,1));
    //La funcion B2 lo que hace es verificar si el número ingresado es Impar.
    printf("***************** Fin Programa 2 *******************\n\n");
    
    return 0;
}
