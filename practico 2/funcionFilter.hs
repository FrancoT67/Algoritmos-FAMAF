pares x  | mod (head x) == 0 = head x : pares(tail x)
         | mod (head x) 2/=0 = pares (tail x) 