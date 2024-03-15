{-# LANGUAGE NPlusKPatterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

{-
Ejemplos de ejecucion:
sumatoria [1,2,3,4,5,6] --> 21
sumatoria [12,3,76,5,6] --> 102
-}