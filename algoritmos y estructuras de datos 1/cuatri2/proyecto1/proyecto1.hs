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
