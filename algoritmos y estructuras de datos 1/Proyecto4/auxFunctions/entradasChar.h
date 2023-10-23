#include<stdio.h>

char pedirChar();
char pedirChar(){
    char t;
    printf("Ingrese una letra:");
    scanf("%c",&t);
    return t;
}
