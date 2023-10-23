#include <stdio.h>

// Expansion de libreria Assert.
#include <assert.h>
// Expansion de libreria Bools.
#include <stdbool.h>

// Expansion de librerias Propias con Funciones Auxiliares.
#include "../auxFunctions/entradasInt.h"
#include "../auxFunctions/entradasBool.h"
#include "../auxFunctions/entradasChar.h"

// Definicion del Protipo de mi Funcion para verificar si es vocal o no.
bool es_vocal(char letra);

int main(){

    //Instanciacion de Variables.
    int resultado = 0;
    char vocal;

    //Solicitud de ingreso de letra.
    vocal=pedirChar();

    //Asigno el valor retornado por la verificación.
    resultado = es_vocal(vocal);
    
    //Immprime verdadero o falso dependiendo de la verificacion junto a la letra ingresada.
    imprimeBool(vocal, resultado);

    return 0;
}

//Definicion del Pototipo para la verificacion.
bool es_vocal(char letra)
{

    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++)
    {
        if (letra == vocales[i])
        {
            return true;
        }
    }
    
    return false;

}
