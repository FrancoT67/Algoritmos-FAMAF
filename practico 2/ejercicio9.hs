--maximo

maximo :: [Int] -> Int

maximo []=0
--maximo (x:y:xs) | x<y = maximo(y:x:xs) | y>x = y 
maximo (x:y:xs) | x<y = y | x>y = x 