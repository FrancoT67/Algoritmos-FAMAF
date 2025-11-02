/**
 * Ejercicio 4
La famosa blockchain Cardano vio la luz por el año 2017, iniciando con un protocolo bien
simple muy similar al de otra (esta de verdad) famosa blockchain: Bitcoin. Eventualmente
Cardano fue evolucionando, donde cada vez que se produce una evolución importante se
dice que la blockchain cambia de era. Por ejemplo, tenemos las eras Byron, Shelley,
Alonzo, Babbage.
Nuestra tarea será traducir determinado tipo de dato de la era Alonzo a la era Babbage. En
particular queremos traducir una componente central de Cardano el tipo output.
- Un output en Alonzo es básicamente un arreglo de int que solo puede tener
tamaño 2 o 3.
- Un output en Babbage, es una estructura más definida con 4 campos, uno de los
cuales puede no estar presente.(esto lo indica present)
En lo que respecta a nosotros podemos asumir que ambas versiones contienen la misma
información, solo que organizada de manera distinta. Puntualmente los tipos serán:
Para Alonzo, podremos simplemente declarar un arreglo de enteros de tamaño 2 o 3
(cualquier otro tamaño no tendrá sentido). Es decir, no hace falta un nuevo tipo y
podemos hacer simplemente: int a_output[2]; o int a_output[3];
Para Babbage, en cambio, tendremos los siguientes tipos nuevos
typedef struct {
int addr;
int value;
int datum;
bool present;
} babbage_output;
Por ejemplo, asumiendo tenemos declarada una variable babbage_output b_out; los
siguientes outputs son el mismo pero en versiones distintas:

 * La traducción de un Alonzo output a un Babbage output se deber realizar con la función
alonzo_to_babbage, cuyo prototipo será:
babbage_output alonzo_to_babbage(int tam, int a_output[])
La función alonzo_to_babbage() tomará un tamaño y un arreglo de enteros, cuya
precondición será que tam solo puede tener dos valores posibles: 2 o 3, para asegurar esto
deberemos usar la sentencia assert. El resultado de llamar a la función devolverá un
babbage_output.
En la función main se debe llamar a la función alonzo_to_babbage para al menos dos
alonzo outputs distintos e imprimir por pantalla el resultado de la traducción. Por simplicidad
esta permitido especificar en la misma función main ambos alonzo outputs cuando los
declaramos, es decir: int a_output[2] = {4242,10};
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    int datum;
    bool present;
} maybe_datum;

typedef struct
{
    int addr;
    int value;
    maybe_datum datum;
} babbage_output;

babbage_output alonzo_to_babbage(int tam, int a_output[])
{
    babbage_output b_out;
    maybe_datum nothing;

    assert(tam == 2 || tam == 3);

    nothing.datum = 0;
    nothing.present = false;

    b_out.addr = a_output[0];
    b_out.value = a_output[1];
    b_out.datum = nothing;

    if (tam == 3)
    {
        b_out.datum.datum = a_output[2];
        b_out.datum.present = true;
    }

    return b_out;
}

void print_babbage_output(babbage_output b_out)
{

    printf("Address: %d\n", b_out.addr);
    printf("Value: %d\n", b_out.value);
    if (b_out.datum.present)
    {
        printf("Datum: %d\n", b_out.datum.datum);
    }
}

int main(void)
{
    int a_output1[2] = {4242, 10};
    int a_output2[3] = {4243, 100, 5555};
    babbage_output b_out;

    b_out = alonzo_to_babbage(2, a_output1);
    print_babbage_output(b_out);

    b_out = alonzo_to_babbage(3, a_output2);
    print_babbage_output(b_out);

    return 0;
}