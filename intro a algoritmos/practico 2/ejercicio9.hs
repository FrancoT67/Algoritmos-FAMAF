
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

todos0y1 [] = False
todos0y1 (x:xs) | (x == 0 || x == 1 ) && todos0y1 xs = True
                | (x/=0) || (x/=1) = False

-- 9.d) quitar0s
--Ej quitar0s [2,0,3,4] = [2,3,4]

quitar0s ::  [Int] -> [Int]

quitar0s [] = []

quitar0s (x:xs) | x == 0 = quitar0s xs
                | x /= 0 = x:quitar0s xs


-- 9.e) ultimo 
-- Ej ultimo [1,2,5] = 5
ultimo :: [a] -> a

ultimo [] = error "Lista Vacia"

ultimo (x:xs) | null xs = x
              | not (null xs) = ultimo xs



-- 9.f) repetir
--Ej repetir 3 6 = [6,6,6]
repetir :: Int -> Int -> [Int]

repetir n k | n > 0 = k:repetir (n-1) k
            | n<=0 = []

-- 9.g) concat 
-- Ej concat [[1,4],[],[2]] = [1,4,2]

conCat :: [[a]] -> [a]

conCat [[]] = []
conCat (x:xs) | not(null xs) = x++conCat xs
              | null xs = x 

-- 9.h) rev 
-- Ej rev [1,2,3] = [3,2,1,]

rev :: [a] -> [a]
rev [] = []
rev (x:xs) = rev xs ++ [x]
