-- Ejercicios

-- 1
-- a) esCero :: Int -> Bool, que verifica si un entero es igual a 0.
esCero :: Int -> Bool
esCero x = (x == 0)

-- esCero 10 = False
-- esCero 0 = True

-- b) esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo x = (x > 0)

-- esPositivo 10 = True
-- esPositivo -10 = False

-- c) esVocal :: Char -> Bool, que verifica si un caracter es una vocal en minúscula.
esVocal :: Char -> Bool
esVocal y = y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u'

-- esVocal 'a' = True
-- esVocal 'z' = False

-- d) valorAbsoluto :: Int -> Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto n | n >= 0 = n | n < 0 = n * (-1)

-- valorAbsoluto (-5) = 5
-- valorAbsoluto 5 = 5

-- 2 Programá las siguientes funciones usando recursión o composición:
-- a) paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x : xs)
  | x == True = paraTodo xs
  | x /= True = False

-- paraTodo [True,True,True,True]= True
-- paraTodo [True,True,False,True]= False

-- b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

-- sumatoria [1,2,3,4,5,6] = 21
-- sumatoria [1,2,3,4,5,6,7] = 28

-- c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria (xs)

-- productoria [1,2,3,4,5] = 120
-- productoria [4,5] = 20

-- d) factorial :: Int -> Int, que toma un número n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1)

-- factorial 5 = 120
-- factorial 3 = 6

-- e) Utilizá la función sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de números no vacia y calcula el valor promedio (truncado, usando división entera).
promedio :: [Int] -> Int
promedio [] = 0
promedio x = div (sumatoria x) (length x)

-- promedio [1,2,3,4,5,6] = 3
-- promedio [4,6] = 5

-- 3) Programá la función pertenece :: Int -> [Int] -> Bool, que verifica si un número se encuentra en una lista.
pertenece :: Int -> [Int] -> Bool
pertenece x [] = False
pertenece x (y : ys)
  | x == y = True
  | x /= y = pertenece x ys

-- pertenece 3 [1,2,3,4] = True
-- pertenece 5 [1,2,3,4] = False

-- 4)Programá las siguientes funciones que implementan los cuantificadores generales. Notá que el segundo parámetro de cada función, es otra función!

-- a) paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado t :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado t.
paratodo' :: Eq a => [a] -> (a -> Bool) -> Bool
paratodo' [] funcion = True
paratodo' (x : xs) funcion
  | funcion x = paratodo' xs funcion
  | otherwise = False

-- paratodo' [0] esCero = True
-- paratodo' ['a'] esVocal = True

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] funcion = False
existe' (x : xs) funcion
  | funcion x = True
  | otherwise = existe' xs funcion

-- existe' ['b','a'] esVocal == True
-- existe' ['b','c'] esVocal == False
-- existe' [1,2,0] esCero == True
-- existe' [1,2,3] esCero == False

-- c) sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una función t :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicación de t a los elementos de xs.
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] funcion = 0
sumatoria' (x : xs) t = t x + sumatoria' xs t

--  sumatoria' [1,2,3] factorial = 9
--  sumatoria' [1,2,3] valorAbsoluto = 6