repartir :: [String] -> [String] -> [(String, String)] 

repartir [] []= []
repartir [] xs= []
repartir ys []= []
repartir (x:xs) (y:ys) = (x,y) : repartir xs ys