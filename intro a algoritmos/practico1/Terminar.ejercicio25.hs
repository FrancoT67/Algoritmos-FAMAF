--25.a segundo3 : (Num, Num, Num) → Num, que dada una terna de enteros devuelve su segundo elemento.
segundo3 a= a!!2

--25.b ordena : (Num, Num) → (Num, Num), que dados dos enteros los ordena de menor a mayor.
ordena a b =
    if a<b
        then (a,b)
    else
        (b,a)

--25.c rangoPrecioParametrizado : Num → (Num, Num) → String que dado un n´umero x, que representa el precio de un producto, y un par (menor, mayor) que represente el rango de precios que uno espera encontrar, retorne “muy barato” si x est´a por debajo del rango, “demasiado caro” si est´a por arriba del rango, “hay que verlo bien” si el precio está en el rango, y “esto no puede ser!” si x es negativo.
rangoPrecioParametrizado x y  | x<0 = "esto no puede ser"
                                  | x<maximum (y) && x>minimum (y) = "hay que verlo bien"
                                  | x>maximum (y) = "es demasiado caro"
                                  | x>0 && x>minimum(y) = "es demasiado barato"


--25.d mayor3 : (Num, Num, Num) → (Bool, Bool, Bool), que dada una una terna de enteros devuelve una terna de valores booleanos que indica si cada uno de los enteros es mayor que 3. Por ejemplo: mayor3.(1, 4, 3) = (False, True, False) y mayor3.(5, 1984, 6) = (True, True, True)


--25.e todosIguales : (Num, Num, Num) → Bool que dada una terna de enteros devuelva True si todos sus elementos son iguales y False en caso contrario. Por ejemplo: todosIguales.(1, 4, 3) = False y todosIguales.(1, 1, 1) = Tru