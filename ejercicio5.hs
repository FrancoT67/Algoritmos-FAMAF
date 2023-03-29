--a
todosMenores10 :: [Int] -> Bool

todosMenores10 xs | length xs == 0 = True 
                  | (head xs) < 10 = todosMenores10 (tail xs) 
                  | (head xs) >= 10 = False   

hay0 :: [Int] -> Bool

hay0 xs | length xs == 0 = False 
	    | (head xs) ==0 = True 
        | (head xs) /=0 = hay0 (tail xs)   

sumar :: [Int] -> Int

sumar xs | length xs == 0 = 0
	   | length xs /= 0 = head(xs)+ sumar (tail xs)