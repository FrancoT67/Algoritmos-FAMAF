-- Ejercicios

-- 1A)
esCero :: Int -> Bool
esCero x = (x == 0)

-- esCero 10 = False
-- esCero 0 = True

-- 1B)
esPositivo :: Int -> Bool
esPositivo x = (x > 0)

-- esPositivo 10 = True
-- esPositivo -10 = False

-- 1C)
esVocal :: Char -> Bool
esVocal y = y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u'

-- esVocal 'a' = True
-- esVocal 'z' = False

-- 1D)
valorAbsoluto :: Int -> Int
valorAbsoluto n | n >= 0 = n | n < 0 = n * (-1)

-- valorAbsoluto (-5) = 5
-- valorAbsoluto 5 = 5

-- 2A)
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x : xs) | x == True = paraTodo xs | x /= True = False

-- paraTodo [True,True,True,True]= True
-- paraTodo [True,True,False,True]= False

-- 2B)
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

-- sumatoria [1,2,3,4,5,6] = 21
-- sumatoria [1,2,3,4,5,6,7] = 28

-- 2C)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria (xs)

-- productoria [1,2,3,4,5] = 120
-- productoria [4,5] = 20

-- 2D)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1)

-- factorial 5 = 120
-- factorial 3 = 6

-- 2E)
promedio :: [Int] -> Int
promedio [] = 0
promedio x = div (sumatoria x) (length x)

-- promedio [1,2,3,4,5,6] = 3
-- promedio [4,6] = 5

-- 3)
pertenece :: Int -> [Int] -> Bool
pertenece x [] = False
pertenece x (y : ys) | x == y = True | x /= y = pertenece x ys

-- pertenece 3 [1,2,3,4] = True
-- pertenece 5 [1,2,3,4] = False

-- 4)
paratodo' :: Eq a => [a] -> (a -> Bool) -> Bool
paratodo' [] f = False
paratodo' (x : xs) f
  | ((f x && paratodo' xs f) == True || xs == []) = True
  | (f x && paratodo' xs f) /= True = False

-- paratodo' [0] esCero = True
-- paratodo' ['a'] esVocal = True
