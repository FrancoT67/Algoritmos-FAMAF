--length

longitud :: [a] -> Integer
longitud [] = 0 
longitud (x:xs) = 1 + longitud xs 

-- !! = tomar
tomar :: [a] -> Int -> a
tomar [] n= error "sin elementos" 
tomar (x:xs) n | n==0 = x | n/= 0 = tomar xs (n-1) 

-- take 

tAke :: [a] -> Int -> [a]

tAke [] n= error "sin elementos" 
tAke (x:xs) n =  x:tAke xs (n-1) 

-- drop 
soltar :: [a] -> Int -> [a]

soltar (x:xs) n | n == 0 = x:xs | n>0 = soltar xs (n-1)

-- ++
concatenar :: [a] -> [a] -> [a] 
concatenar [] [] = []
concatenar [] ys = ys
concatenar xs [] = xs

concatenar (x:xs) ys = x:concatenar xs ys