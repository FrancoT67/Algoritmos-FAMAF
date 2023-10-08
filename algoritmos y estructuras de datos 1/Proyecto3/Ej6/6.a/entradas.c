#include <stdio.h>
// Funciones Originales.
int pedirEntero(char name);
int main(void){
    int m=0;

    m=pedirEntero('m');
    printf("M vale:%d\n",m);
    return 0;
}

int pedirEntero(char name){
    int n=0;
    printf("Ingrese el entero para la variable %c:",name);
    scanf("%d",&n);
    return n;

}
