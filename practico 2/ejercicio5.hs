--a
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use null" #-}
todosMenores10 :: [Int] -> Bool

todosMenores10 xs | length xs == 0 = True
                  | head xs < 10 = todosMenores10 (tail xs)
                  | head xs >= 10 = False

--b)
--Opcion 1
hay0 :: [Int] -> Bool

hay0 xs | length xs == 0 = False
        | head xs ==0 = True
        | head xs /=0 = hay0 (tail xs)

--Opcion 2
todosMe10 ::  [Int] -> Bool

--Caso en el que sea vacio
todosMe10 []=True
--el x es el primer elemento de la lista xs
todosMe10 (x:xs) | x<10 = todosMe10 xs |x >= 10 = False



--c)
sumar :: [Int] -> Int

sumar xs | length xs == 0 = 0
         | length xs /= 0 = head xs + sumar (tail xs)