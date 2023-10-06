#include <stdio.h>

int main()
{
    /* ********** Tracuccion del 1.h ********** */
    printf("**************** Tracuccion del Ej1.H **************\n\n");
    
    int i=0;
    printf("Ingrese el valor de I: ");
    scanf("%d",&i);
    printf("\n");
    while(i!=0){
        i=i-1;
        printf("el valor de I es %d\n",i);
    }
    printf("\n");
    printf("********** Tracuccion del Ej1.I ********************\n\n");
    /* ********** Tracuccion del 1.I ********** */
    i=0;
    printf("Ingrese el valor de I: ");
    scanf("%d",&i);
    
    while(i!=0){
        i=0;
        printf("el valor de I es %d\n\n",i);
        return 0;
    }
    printf("el valor de I es %d\n\n",i);

    return 0;
}
