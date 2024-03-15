{-# LANGUAGE NPlusKPatterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria xs

{-
Ejemplos de ejecucion:
productoria [1,2,3,4,5,6] --> 720
productoria [1,2,5,6] --> 60

-}
