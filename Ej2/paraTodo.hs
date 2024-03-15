{-# LANGUAGE NPlusKPatterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x : xs) = x && paratodo xs

{-
Ejemplos de ejecucion:
paratodo [] --> True
paratodo [True,True,True] --> True
paratodo [True,False,True] --> False
paratodo [True,False,False] --> False
paratodo [False,False,False] --> False
-}