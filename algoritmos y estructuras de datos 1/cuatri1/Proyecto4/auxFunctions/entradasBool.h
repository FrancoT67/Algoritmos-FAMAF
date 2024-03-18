#include <stdio.h>

// Inclusion de Biblioteca necesaria para el tipo Bool.
#include <stdbool.h>

/* Prototipos */
bool pedirBooleano(char name);
void imprimeBool(char name,bool x);

/* Definición de Pedir Booleano */
bool pedirBooleano(char name)
{
    int x=0;
    printf("Ingrese 1 para True o 0 para False para agregar en la variable %c:\n",name);
    scanf("%d", &x);
    if (x>1){
        printf("Ingresaste un valor mayor a 1. \nEntonces se definio como 1 la opcion que elegiste.\n");
        x=1;
    }else if(x<0){
        printf("Ingresaste un valor menor a 0. \nEntonces se definio como 0 la opcion que elegiste.\n");
        x=0;

    }
    return x;
}

/* Definición de Imprime Booleano */
void imprimeBool(char name, bool x){
    if(x==1){
        printf("%c: verdadero\n\n",name);
    }else{
        printf("%c: falso\n\n",name);

    }
}