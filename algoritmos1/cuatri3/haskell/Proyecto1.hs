{- LABORATORIO 1-}
-- 1. esCero :: Int -> Bool, que verifica si un entero es igual a 0.
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

import Text.Read (Lexeme (Number))

{-# HLINT ignore "Use foldr" #-}
esCero :: Int -> Bool
esCero n = n == 0

-- 2. esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo n = n >= 0

-- 3. esVocal :: Char -> Bool, que verifica si un caracter es una vocal en minuscula.
esVocal :: Char -> Bool
esVocal letra
  | letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' = True
  | letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' = True
  | otherwise = False

-- 4. valorAbsoluto :: Int -> Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto n
  | n < 0 = (-1) * n
  | otherwise = n

{- LABORATORIO 2-}
-- A) paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x : xs) = x && paratodo xs

-- b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

-- c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria xs

-- d) factorial :: Int -> Int, que toma un número n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- e) Utilizá la función sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de números no vacia y calcula el valor promedio (truncado, usando división entera).
promedio :: [Int] -> Int
promedio lista = sumatoria lista `div` length lista

-- p1 = paratodo [True, False, True]

-- p2 = paratodo [True, True]

-- p3 = sumatoria [1, 5, -4]

-- p4 = productoria [2, 4, 1]

{- LABORATORIO 3 : A partir de las expresiones de los ejercicios 4a, 4b y 4d -}

{-
a) Identifica las variables libres de cada expresion y el tipo de cada una.
4A:La variable libre es XS y su tipo es [Number],entonces la expresion es de tipo BOOL.

4B:La variable libre es XS y X, pero XS y X no tienen tipo ya que depende de como se utilice, porque puede tomar tanto valores como NUMBER, STRING,CHAR, BOOL, etc al igual que XS que es un Array pero de diferentes valores, entonces la expresion es de tipo BOOL pero XS y X no tienen tipo alguno.

4D:La variable libre es XS y  no tiene tipo porque la funcion nomas verifica que los elementos de xs sean todos iguales, entonces la expresion es de tipo BOOL pero XS no tiene tipo alguno.
-}

-- b) Defini funciones que tomen como argumento las variables libres identificadas y devuelvan el resultado de la expresion. Atencion: Tene en cuenta que en algunos casos es necesario definir funciones auxiliares.
-- 4A:
todosPositivos :: [Int] -> Bool
todosPositivos [] = True
todosPositivos (x : xs) = x > 0 && todosPositivos xs

-- 4B:
existe :: (Eq a) => [a] -> a -> Bool
existe [] _ = False
existe (x : xs) y = x == y || existe xs y

-- 4D:
iguales :: (Eq a) => [a] -> Bool
iguales [] = True
iguales (x : y : xs) = x == y && iguales (y : xs)

-- c) Evalua las funciones tomando como argumento los valores senalados en 5.

{-
ghci>todosPositivos [-5, -3, 4, 8]
False
ghci>todosPositivos [11, 2, 5, 8]
True
ghci> existe [-5, -3, 4, 8] 5
False
ghci> existe [11, 2, 5, 8] 5
True
ghci> iguales [-5, -3, 4, 8]
False
ghci> iguales [11, 2, 5, 8]
False
-}

{- LABORATORIO 4: A partir de las expresiones en el ejercicio 7 (el 7d no se hace, avisaron por aula virtual) -}

-- a) Identifica las variables libres de cada expresion y el tipo de cada una.
-- 7A: Variable libre es N y su tipo es Number
-- 7B: Variable libre es XS y su tipo es [Number]
-- 7C: Variable libre es YS y XS, y sus tipos son [Number]
-- 7D: Variable libre es N y es de tipo Number
-- b) Definı funciones que tomen como argumento las variables libres identificadas y devuelvan el resultado de la expresion. Atencion: Tene en cuenta que en algunos casos es necesario definir varias funciones.
-- 7A:
factorial' :: Int -> Int
<<<<<<< HEAD
factorial' = factorial
-- 7B:
promedio' :: [Int] -> Int
promedio' xs = promedio xs

--7C:

buscaMaximos::[Int]->Int
buscaMaximos [] = 0
buscaMaximos (x:y:xs) | x>=y=buscaMaximos (x:xs) 
                      | otherwise = buscaMaximos (y:xs)


buscaMinimo::[Int]->Int
buscaMinimo [] = 0
buscaMinimo (x:y:xs) | x<=y=buscaMinimo (x:xs) 
                     | otherwise = buscaMinimo (y:xs)

maximos::[Int] -> [Int] -> Bool
maximos [] _ = True
maximos xs ys =  buscaMaximos xs < buscaMinimo ys


-- 7D:

verifica ::Int -> Int -> Bool
verifica n m | n==m=False 
             | otherwise = True

buscaProducto :: Int -> Int -> Int
buscaProducto prod n | verifica prod n &&  n `mod` prod == 0 = prod 
                     | otherwise = buscaProducto (prod+1) n 

--buscaFactores :: Int -> Bool
--buscaFactores n = buscaProducto 2 n 
=======
factorial' n = factorial n
>>>>>>> 89a5628a35a730c97bdfbb662d5bad12225bab49

--7B:
promedio' :: [Int] -> Int
promedio' xs = promedio xs

--7C:
maximos ::[Int]->Int
maximos [x] = x
maximos (x : xs) = x `max` (maximos xs)

minimos :: [Int] -> Int
minimos [x] = x
minimos (x : xs) =  x `min` (minimos xs)

expresion7C::[Int] -> [Int]-> Bool
expresion7C xs ys = (maximos xs) < (minimos ys)

-- c) Evalua las funciones tomando como argumento los valores señalados en el ejercicio 8.