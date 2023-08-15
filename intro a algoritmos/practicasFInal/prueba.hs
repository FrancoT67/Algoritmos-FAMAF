{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use odd" #-}
{-# HLINT ignore "Use even" #-}
{-# HLINT ignore "Use map" #-}

-- primerosPares :: [Int] -> [Int]
-- ejemplo : primerosPares [2,8,3,4] = [2,8]

primerosPares :: [Int] -> [Int]
primerosPares [] = []
primerosPares (x : xs)
  | mod x 2 == 0 = x : primerosPares xs
  | mod x 2 /= 0 = []

-- output [2,8,3]

-- hacer un programa en haskell que devuelva los primeros numeros pares de una lista?

-- esMayor 3 [3,4] =  [False, True]
esMayor :: Int -> [Int] -> [Bool]
esMayor n [] = []
-- pega el resultado de la evaluacion de x(el primer elemento de la lista) > n(el número que se recibe como limite de evaluación).
-- con ésto mantengo el tipo de lista y se va concatenando un elemento tipo bool a una lista de tipo Int hasta  cambiar completamente su tipado a tipo Bool.
esMayor n (x : xs) = (x > n) : esMayor n xs
