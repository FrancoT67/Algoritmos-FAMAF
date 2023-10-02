#include <stdio.h>

int main(){
    /*Inicializacion de Variables*/
    int x=0;
    int y=0;

   /* Traduccion del ejericio 1.a*/
    printf ("Ingrese un valor numerico para X : \n");
    scanf("%d",&x);
    x=5;
    printf(" el valor de X es: %d\n",x);

    /*Traduccion del ejercicio 1.b*/
    printf ("Ingrese un valor numerico para X : \n");
    scanf("%d",&x);
    printf ("Ingrese un valor numerico para Y : \n");
    scanf("%d",&y);
    x=x+y;
    y=y+y;
    printf(" el valor de X es: %d y el de Y es: %d\n",x,y);

    /*Traduccion del ejercicio 1.c*/
    printf ("Ingrese un valor numerico para X : \n");
    scanf("%d",&x);
    printf ("Ingrese un valor numerico para Y : \n");
    scanf("%d",&y);
    y=y+y;
    x=x+y;
    printf(" el valor de X es: %d y el de Y es: %d\n",x,y);



    return 0;
}
