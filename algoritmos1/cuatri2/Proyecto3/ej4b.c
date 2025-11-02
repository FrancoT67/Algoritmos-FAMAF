#include <stdio.h>

/*
σ0 :(x → 5 , y → 4, z → 8, m → 0)
    var x,y,z,m:Int;
    if (x < y) → m := x
    (x ≥ y)    → m := y
    fi
σ1 :(x → 5 , y → 4, z → 8, m → 4)
    if (m < z) → skip
    (m ≥ z)    → m := z
    fi
σ2 :(x → 5 , y → 4, z → 8, m → 4)
*/

int main()
{

    /*Inicializacion de Variables*/
    int x = 0;
    int y = 0;
    int z = 0;
    int m = 0;

    /* Ingreso de valores a las variables */
    printf("********************************************\n\n");
    printf("Ingrese un valor numerico para X:");
    scanf("%d", &x);
    printf("Ingrese un valor numerico para Y:");
    scanf("%d", &y);
    printf("Ingrese un valor numerico para Z:");
    scanf("%d", &z);
    printf("Ingrese un valor numerico para M:");
    scanf("%d", &m);

    /*Comprobación de Valores de X e Y.*/
    if (x < y)
    {
        m = x;
    }
    else
    {
        m = y;
    }

    if (m < z)
    {
        m = m;
        z = z;
    }
    else
    {
        z = m;
    }

    /* Visualizacion de los estados finales de las variables.*/
    printf("los estados de X es %d, el de Y es %d, el de Z es %d y el de M es %d.\n\n ", x, y, z, m);
    printf("El valor final de M es: %d\n\n ", m);
    printf("********************************************\n\n");

    return 0;
}