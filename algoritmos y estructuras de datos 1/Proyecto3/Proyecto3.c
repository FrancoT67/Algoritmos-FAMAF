#include <stdio.h>
#include <stdbool.h>
/* 3. Ejercicios*/

/* 1. Entrada/Salida*/
int sumaXmasYmas1(int a,int b){
    return a+b+1;
}
int sumayRestaDeProducto(int a,int b,int c){
    return c*c+b*45-15*a;
}
int comparacionRestaConModuloDeDivision(int a,int b){
    return (b-2 == (a*3+1)%5);
}
int divisionDeYporElDobleDeX(int a,int b){
    return (b/2*a);
}
int comparacionYconXporZ(int a,int b,int c){
    return b<a*c; 
}
/* 2. Debugging con GDB*/

/*
(x => 1, y => algo , z => algo , b =>algo , w => )
*/
char* verificarMultiplo4(int a){
    if ((a%4 == 0) == 1){
        return "True";
    }
    return "False";
}
char* verificarSumaConProducto(int x, int y, int z){
    if(( x + y == 0 ) && ( x - y == (-1) * z )){
        return "True";
    }
    return "False";
}

char* verificarNotConW(int b, int w){
    if(b==0 && w==0){
        return "False";
    }
    return "True";
}
int main(void)
{
    int x=0, y=0, z=0;
    /*Ingreso de valores a las variables*/
    printf("Ingrese el valor de x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y:\n");
    scanf("%d", &y);
    printf("Ingrese el valor de z:\n");
    scanf("%d", &z);
    /* Ejercicio 1*/
    printf("-----------------------||---------------\n\n");
    printf("Estados de x:%d, y:%d , z:%d \n\n",x,y,z);
    printf("-----------------------||---------------\n\n");
    printf("Resultados del ejercicio 3.1 \n\n");
    printf("-----------------------||---------------\n\n");
    printf("El resultado de x + y + 1 es: %d\n\n",sumaXmasYmas1(x,y));
    printf("El resultado de z * z + y * 45 - 15 * x es: %d \n\n",sumayRestaDeProducto(x,y,z));
    printf("El resultado de y - 2 == (x * 3 + 1) (modulo) 5 es: %d \n\n",comparacionRestaConModuloDeDivision(x,y));
    printf("El resultado de y / 2 * x es: %d \n\n",divisionDeYporElDobleDeX(x,y));
    printf("El resultado de y < x * z es: %d \n\n",comparacionYconXporZ(x,y,z));
    printf("-----------------------||---------------\n\n");
    printf("Resultados del ejericio 3.2 \n\n");
    printf("-----------------------||---------------\n\n");
    printf("El estado de x es: %d,\n\nEl valor de X con modulo 4 es %s\n\n",x,verificarMultiplo4(x));
    printf("El estado de x es: %d, el Estado de y:%d, el Estado de z es:%d \n\nEl valor de x + y == 0 && y - x == (-1)*z es:  %s\n\n",x,y,z,verificarSumaConProducto(x,y,z));
    printf("El estado de x es: %d,\n\nEl valor de not b && w es:  %s\n\n",x,verificarNotConW(x,(y||z)));
    
    
    
    return 0;
}
