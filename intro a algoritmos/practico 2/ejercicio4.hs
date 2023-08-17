--a

sumar1 :: Int -> [Int] -> [Int]

sumar1 n xs | xs == [] =[] |xs /= []  = head xs+n : sumar1 n (tail xs)

--b
duplica :: [Int] -> [Int]

duplica xs | xs == [] =[] |xs /= []  = head xs*2 : duplica (tail xs)

--c
multiplica :: Int -> [Int]-> [Int]

multiplica n xs | xs == [] =[] |xs /= []  = head xs*n : multiplica n (tail xs)

