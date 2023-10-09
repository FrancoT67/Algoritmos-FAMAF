#include <stdio.h>
#include <stdbool.h>

/*
Encontrar los valores para las variables para que las siguientes expresiones tengan el resultado indicado.

(x → 0, y → 0, z →0, b → 0, w→0 )
-----------------------------------------
| Expresion                      | Valor |
-----------------------------------------
| x%4 == 0                       | True  |
| x +y == 0 &&  y - x == (-1) *z | True  |      
| not b && w                     | False |
----------------------------------------- 
*/

/* Funcion auxiliar*/
// La función recibe como parametro una expresion de condicion y verifica si el resultado de su comprobación es 1 (True ) o 0 (False).
char* comprobacion(int expresion){
    if(expresion == 1){
        return "True";
    }
    return "False";
}

int main(){
    
    /*Instanciacion de Variables*/
    int x=0;
    int y=0;
    int z=0;
    int b=0;
    int w=0;
    
    /*Expresiones Solicictadas*/
    printf("Resultado de %d (Módulo)4 == 0 es %s\n",x,comprobacion((x%4==0)));
    printf("Resultado de %d + %d == 0 && %d - %d == (-1) * %d es : %s\n",x,y,y,x,z,comprobacion((x+y == 0 && y -x == (-1) * z)));
    printf("Resultado de not %d && %d es: %s\n",b,w,comprobacion((!b && w)));


    return 0;
}
