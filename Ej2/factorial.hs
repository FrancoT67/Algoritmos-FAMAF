{-# LANGUAGE NPlusKPatterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x - 1)

{-
Ejemplos de ejecucion:
factorial 6 --> 720
factorial 3 --> 6
-}