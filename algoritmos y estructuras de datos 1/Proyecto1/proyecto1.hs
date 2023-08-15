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
esVocal y = (y == 'a') || (y == 'e') || (y == 'i') || (y == 'o') || (y == 'u')

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

-- 2C)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria (xs)

-- productoria [1,2,3,4,5] = 120

-- 2D)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1)

-- factorial 5 = 120

-- 2E)
promedio :: [Int] -> Int
promedio [] = 0
promedio x = div (sumatoria x) (length x)

-- promedio [1,2,3,4,5,6] = 3
-- promedio [4,6] = 5
