#include <stdio.h>

int main(){
    int x=0;
    int y=0;
    int z=0;
    int m=0;
    printf("********************************************\n\n");
    printf("Ingrese un valor numerico para X:");
    scanf("%d",&x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d",&y);
    printf("Ingrese un valor numerico para Z:");
    scanf("%d",&z);
    printf("Ingrese un valor numerico para M:");
    scanf("%d",&m);
    if(x<y){
        m=x;
    }else{
        m=y;
    }

    if(m<z){
        m=m;
        z=z;
    }else{
        z=m;
    }

    printf("los estados de X es %d, el de Y es %d, el de Z es %d y el de M es %d.\n\n ",x,y,z,m);
    printf("El valor final de M es: %d\n\n ",m);
    printf("********************************************\n\n");

    return 0;
}