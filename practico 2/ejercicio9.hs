--9.a) maximo
maximo :: [Int] -> Int
maximo []=error "no hay maximo en una lista vacia"
maximo (x:y:xs) | x<y = maximo xs | x>y = x

--9.b) sumaPares
-- ej sumaPares [ (1,2) (7,8) (11,0) ] = 29

sumaPares :: [(Int,Int)] -> Int

sumaPares []=0
sumaPares ((x,y):xs) = x+y + sumaPares xs

--9.c) todos0y1
-- ej1 todos0y1 [1,0,1,2,0,1] = False
-- ej2 todos0y1 [1,0,1,0,0,1] = True

todos0y1 :: [Int] -> Bool

todos0y1 [] = True
todos0y1 (x:xs) | ((x==0) || (x==1)) && todos0y1 xs = True 
                | (x/=0) || (x/=1) = False

-- 9.d) quitar0s
--Ej quitar0s [2,0,3,4] = [2,3,4]

quitar0S ::  [Int] -> [Int]

quitar0S [] = []

quitar0S (x:xs) | x==0 = quitar0S xs
                | x /= 0 = x:quitar0S xs

-- //remover un elemento de una lista en haskell?