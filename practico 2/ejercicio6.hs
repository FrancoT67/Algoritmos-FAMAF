todosMe10 ::  [Int] -> Bool

--Caso en el que sea vacio
todosMe10 []=True
--el x es el primer elemento de la lista xs
todosMe10 (x:xs) | x<10 = todosMe10 xs |x >= 10 = False

                 