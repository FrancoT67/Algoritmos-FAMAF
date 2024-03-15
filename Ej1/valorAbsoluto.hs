{-# LANGUAGE NPlusKPatterns #-}

valorAbsoluto :: Int -> Int
valorAbsoluto x
  | x < 0 = x * (-1)
  | otherwise = x

{-
Ejemplos de ejecucion:

valorAbsoluto 1 --> 1
valorAbsoluto (-1) --> 1
valorAbsoluto (-3) --> 3
-}