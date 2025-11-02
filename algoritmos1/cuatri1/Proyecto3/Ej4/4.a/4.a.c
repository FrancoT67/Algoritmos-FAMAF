#include <stdio.h>
int main(){

    /*Traduccion del ejercicioo 1.e*/
    int x=0;
    int y=0;
    printf("*********************** Traduccion del ejercicioo 1.E *********************\n\n");
    printf("Ingrese un valor numerico para X:");
    scanf("%d",&x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d",&y);

    if (x>=y)    {
        x=0;
    }else if (x<=y)    {
        x=2;
    }
    printf("El valor de X es %d y el de Y es %d\n\n",x,y);

    
    /*Traduccion del ejercicioo 1.f*/
    x=0;
    y=0;
    printf("*********************** Traduccion del ejercicioo 1.F *********************\n\n");
    printf("Ingrese un valor numerico para X:");
    scanf("%d",&x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d",&y);
    if (x>=y)    {
        x=0;
    }else if (x<=y)    {
        x=2;
    }
    printf("El valor de X es %d y el de Y es %d\n\n",x,y);
    

    return 0;
}
