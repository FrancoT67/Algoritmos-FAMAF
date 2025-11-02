{-# LANGUAGE NPlusKPatterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

-- Ej1
-- a) esCero :: Int -> Bool, verifica si un entero es igual a 0
esCero :: Int -> Bool
esCero x = x == 0

{-
Ejemplos de ejecucion:
esCero 2 --> False
esCero 0 --> True
-}
-- b) esPositivo :: Int -> Bool, verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo x = x >= 0

{-
 esPositivo (-2) ---> False
 esPositivo 2 ---> True
-}

-- c)  esVocal :: Char -> Bool, verifica si un caracter es una vocal en minúscula.
esVocal :: Char -> Bool
esVocal x = elem x "aeiou" || elem x "AEIOU"

-- esVocal x | x == "a" = True

{-
Ejemplos de ejecucion:
 esVocal 'a' --> True
 esVocal 'A' --> True
 esVocal 'c' --> False
 esVocal 'C' --> False
-}

-- d)valorAbsoluto :: Int -> Int, devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto x
  | x < 0 = x * (-1)
  | otherwise = x

{-
Ejemplos de ejecucion:

valorAbsoluto 1 --> 1
valorAbsoluto (-1) --> 1
valorAbsoluto (-3) --> 3
-}

-- Ej2
-- a)paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x : xs) = x && paratodo xs

{-
Ejemplos de ejecucion:
paratodo [] --> True
paratodo [True,True,True] --> True
paratodo [True,False,True] --> False
paratodo [True,False,False] --> False
paratodo [False,False,False] --> False
-}

-- b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

{-
Ejemplos de ejecucion:
sumatoria [1,2,3,4,5,6] --> 21
sumatoria [12,3,76,5,6] --> 102
-}

-- c ) productoria :: [Int] -> Int, que calcula el producto de todos los elementos d la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria xs

{-
Ejemplos de ejecucion:
productoria [1,2,3,4,5,6] --> 720
productoria [1,2,5,6] --> 60
-}

-- d ) factorial :: Int -> Int, que toma un número n y calcula n!
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1)

{-
Ejemplos de ejecucion:
factorial 6 --> 720
factorial 3 --> 6
-}

-- e) Utilizá la funci ́on sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de números no vacía y calcula el valor promedio (truncado, usando división entera).

promedio :: [Int] -> Int
promedio [] = 0
promedio x = sumatoria x `div` length x

{-
Ejemplos de ejecucion:
promedio [1,2,3,4,5] --> 3
promedio [1,5,7,9,3] --> 5
-}

-- Ej3. Program ́a la funci ́on pertenece :: Int -> [Int] -> Bool, que verifica si un número se encuentra en una lista.

pertenece :: Int -> [Int] -> Bool
pertenece _ [] = False
pertenece x (y : ys)
  | x == y = True
  | otherwise = pertenece x ys

-- otra forma de hacerlo ⬇
-- pertenece n xs = n `elem` xs

{-
Ejemplos de ejecucion:
pertenece 3 [1,2,3,4,5,6] --> True
pertenece 3 [1,2,4,5,6] --> False
-}

-- Ej4
-- A) paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado T :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado T

paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x : xs) t = t x && paratodo' xs t

{-
Ejemplos de ejecucion:
paratodo' [0,0,0,0,0] esCero --> True
paratodo' [-1,0,0,0,0] esPositivo --> False
-}

-- B) existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado T :: a -> Bool, determina si alg ́un elemento de xs satisface el predicado T.

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x : xs) p = p x || existe' xs p

{-
Ejemplos de Ejecucion:
existe' [0,1,2,3,4,5] esCero --> True
existe' "hola" esVocal --> True
-}

-- C)sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una funci ́on T :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicaci ́on de T a los elementos de xs.

sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] _ = 0
sumatoria' (x : xs) f = f x + sumatoria' xs f

{-
Ejemplos de ejecucion:
sumatoria' [0,1,2,3,4,5] (+2) --> 27
sumatoria' [0,1,2,3,4,5] (+1) --> 21
-}

-- D)productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a] y una funci ́on T :: a -> Int, calcula el producto de los valores que resultan de la aplicaci ́on de T a los elementos de xs.
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] _ = 1
productoria' (x : xs) f = f x * productoria' xs f

{-
Ejemplos de ejecucion:
productoria' [0,1,2] (+1) --> 6
productoria' [0,1,2,3,4,5] (+2) --> 5040
-}

-- Ej5)Defin ́ı nuevamente la funci ́on paratodo, pero esta vez usando la funci ́on paratodo’ (sin recursi ́on ni an ́alisis por casos!).

paraTodo'' :: [Bool] -> Bool
paraTodo'' xs = paratodo' xs id

{-
Ejemplos de ejecucion:
paratodo'' [True,True] --> True
 paratodo'' [True,False] --> False

-}

-- Ej6)Utilizando las funciones del ejercicio 4, program ́a las siguientes funciones por composici ́on,sin usar recursi ́on ni an ́alisis por casos
-- A) todosPares :: [Int] -> Bool verifica que todos los n ́umeros de una lista sean pares.
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

{-
Ejemplos de ejecucion:
todosPares [2,2,2,2,2,3] --> False
todosPares [2,4,6,8,0] --> True
-}
-- B)hayMultiplo :: Int -> [Int] -> Bool verifica si existe alg ́un n ́umero dentro del segundo par ́ametro que sea m ́ultiplo del primer par ́ametro.
multiplo :: Int -> Int -> Bool
multiplo n z = mod z n == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (multiplo n)

{-
Ejemplos de ejecucion:
hayMultiplo 2 [1,4,5] --> True
hayMultiplo 1 [1,4,5] --> True
hayMultiplo 3 [1,4,5] --> False
-}

-- C) sumaCuadrados :: Int -> Int, dado un n ́umero no negativo n, calcula la suma de los primeros n cuadrados, es decir 〈∑i : 0 ≤i < n : i2〉

sumaCuadrados :: Int -> Int
sumaCuadrados x = sumatoria' [0 .. (x - 1)] (^ 2)

{-
Ejemplos de ejecucion:
sumaCuadrados 4 --> 14
sumaCuadrados 5 --> 30
-}

-- D)Programar la fuci ́on existeDivisor::Int-> [Int] -> Bool, que dado en entero n y una lista ls , devuelve True si y solo si, existe alg ́un elemento en ls que divida a n.
divide :: Int -> Int -> Bool
divide n m = mod n m == 0

existeDivisor :: Int -> [Int] -> Bool
existeDivisor n ls = existe' ls (divide n)

{-
Ejemplos de ejecucion:
existeDivisor 3 [6,4] --> False
existeDivisor 3 [3,4] --> True

-}

-- E) Utilizando la funci ́on del apartado anterior, defin ́ı la funci ́on esPrimo:: Int -> Bool, que dado un entero n, devuelve True si y solo si n es primo
esPrimo :: Int -> Bool
esPrimo n = not (existeDivisor n [2 .. (n - 1)]) && n /= 1 && n /= 0

{-
Ejemplos de ejecucion:
esPrimo 1 --> False
esPrimo 2 --> True
esPrimo 3 --> True
esPrimo 4 --> False
esPrimo 1 --> True
esPrimo 1 --> False
-}
-- f ) ¿Se te ocurre cómo redefinir factorial (ej. 2d) para evitar usar recursión?
factorial' :: Int -> Int
factorial' n = productoria [1 .. n]

{-
factorial' 4 = 24
factorial' 5 = 120
-}

-- g) Programar la función multiplicaPrimos :: [Int] -> Int que calcula el producto de todos los números primos de una lista.
primos :: Int -> Int
primos x | esPrimo x = x | not (esPrimo x) = 1

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos m = productoria' m primos

{-
multiplicaPrimos [1,2,3,4,5] = 30
multiplicaPrimos [1,2,3,4,5,6,7,8,9,10] = 210
-}

-- h) Programar la función esFib :: Int -> Bool, que dado un entero n, devuelve True si y sólo si n está en la sucesión de Fibonacci.
-- Ayuda: Realizar una función auxiliar fib :: Int -> Int que dado un n devuelva el n-ésimo elemento de la sucesión.

fib :: Int -> Int
fib n
  | n < 0 = 0
  | n >= 0 && n <= 2 = n
  | otherwise = fib (n - 1) + fib (n - 2)

verifica :: Int -> [Int]
verifica 0 = [0, 1]
verifica n = verifica (n - 1) ++ [fib n]

esFib :: Int -> Bool
esFib n = existe' (verifica n) (== n)

{-
verifica 10 =[89,55,34,21,13,5,3,2,1]
esFib 11= False
esFib 8= True
-}

-- i) Utilizando la función del apartado anterior, definí la función todosFib :: [Int] -> Bool, que dada una lista xs de enteros, devuelva si todos los elementos de la lista pertenecen (o no) a la sucesión de Fibonacci.

todosFib :: [Int] -> Bool
todosFib [] = True
todosFib (x : xs) = esFib x && todosFib xs

{-
todosFib [8,5,3,2,1] = True
todosFib [8,5,4,2,1] = False
-}

-- 7. Indagá en Hoogle sobre las funciones map y filter. También podes consultar su tipo en ghci con el comando :t
-- ¿Qué hacen estas funciones?
{-
La función map lo que hace es aplicar una función a cada elemento de una lista y retornar una lista con los resultados obtenidos de haber aplicado dicha función.
-}
-- ¿A qué equivale la expresión map succ [1, -4, 6, 2, -8], dde succ n = n+1?
{-
La expresión equivale a sumarle 1 a cada elemento de la lista [1, -4, 6, 2, -8].
-}
-- ¿Y la expresión filter esPositivo [1, -4, 6, 2, -8]?
{-
La expresion equivale a eliminar todos los elementos que son menores que 0
-}

-- 8. Programá una función que dada una lista de números xs, devuelve la lista que resulta de duplicar cada valor de xs.

-- a) Definila usando recursión.
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x : xs) = (x * 2) : duplica xs

{-
duplica [1, -4, 6, 2, -8] = [2,-8,12,4,-16]
duplica [2, -5, 7, 3, -9] = [4,-10,14,6,-18]
-}

-- b) Definila utilizando la función map.
duplica' :: [Int] -> [Int]
duplica' n = map (* 2) n

{-
duplica' [1, -4, 6, 2, -8] = [2,-8,12,4,-16]
duplica' [2, -5, 7, 3, -9] = [4,-10,14,6,-18]
-}

-- 9. Programá una función que dada una lista de números xs, calcula una lista que tiene como elementos aquellos números de xs que son primos.

-- a) Definila usando recursión.
soloPrimos :: [Int] -> [Int]
soloPrimos [] = []
soloPrimos (x : xs)
  | esPrimo x = x : soloPrimos xs
  | not (esPrimo x) = soloPrimos xs

{-
soloPrimos [1,2,3,4,5,6,7,8,9] = [1,2,3,5,7]
soloPrimos [2,5,7,8,21] = [2,5,7]
-}
-- b) Definila utilizando la función filter.
soloPrimos' :: [Int] -> [Int]
soloPrimos' n = filter esPrimo n

{-
soloPrimos' [1,2,3,4,5,6,7,8,9] = [1,2,3,5,7]
soloPrimos' [2,5,7,8,21] = [2,5,7]
-}

-- c) Revisá tu definición del ejercicio 6g. ¿Cómo podes mejorarla?

-- Se la puede mejorar usando la función creada en el ej 9a, ésta sería :
productoria'' :: [Int] -> Int
productoria'' n = productoria (soloPrimos' n)

{-
productoria'' [1,2,3,4,5,6,7,8,9] = 210
productoria'' [7,8,9] = 7
-}

-- 10. La función primIgualesA toma un valor y una lista, y calcula el tramo inicial más largo de la lista cuyos elementos son iguales a ese valor.

-- a) Programá primIgualesA por recursión.
primIgualesA :: (Eq a) => a -> [a] -> [a]
primIgualesA n [] = []
primIgualesA n (x : xs)
  | n == x = x : primIgualesA n xs
  | x /= n = []

{-
primIgualesA 3 [3,4,3,4]= [3]
primIgualesA 3 [4,3,3,4]= []
primIgualesA 'a' "aaaAAA" = "aaa"
primIgualesA 'a' "baaAAA" = ""
-}

-- b) Programá nuevamente la función utilizando takeWhile.
primIgualesA' :: (Eq a) => a -> [a] -> [a]
primIgualesA' n xs = takeWhile (== n) xs

{-
primIgualesA' 3 [3,4,3,4]= [3]
primIgualesA' 3 [4,3,3,4]= []
primIgualesA' 'a' "aaaAAA" = "aaa"
primIgualesA' 'a' "baaAAA" = ""
-}

-- 11. La función primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos elementos son todos iguales entre sí.

-- a) Programá primIguales por recursión.
primIguales :: (Eq a) => [a] -> [a]
primIguales [] = []
primIguales (x : y : xs) | x == y = [x] ++ [y] ++ primIguales xs | x /= y = [x]

{-
primIguales "aDaDa" = "a"
primIguales "aaaDa" = "aaa"
-}

-- b) Usá cualquier versión de primIgualesA para programar primIguales. Está permitido dividir en casos, pero no usar recursión.
primIguales' :: (Eq a) => [a] -> [a]
primIguales' (x : xs) = primIgualesA' x (x : xs)

{-
primIguales' "aDaDa" = "a"
primIguales' "aaaDa" = "aaa"
-}
