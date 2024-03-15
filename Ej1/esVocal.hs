{-# LANGUAGE NPlusKPatterns #-}

esVocal :: Char -> Bool
esVocal x = elem x "aeiou" || elem x "AEIOU"

{-
Ejemplos de ejecucion:
 esVocal 'a' --> True
 esVocal 'A'--> True
 esVocal 'c'--> False
 esVocal 'C'--> False
-}