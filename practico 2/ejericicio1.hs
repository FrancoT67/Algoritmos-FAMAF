--A)
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Eta reduce" #-}
{-# HLINT ignore "Use list literal" #-}
longitud a= length a

--B)

mostrar a b= a!! b

--C)

agregarVacio a= a :[]

--D)
primeros a b=take a (b)

--E)
ultimos a b=drop a (b)

--F)
cabeza a b= head(a:b)
--G)
concatListas  a  b c= (a ++ b) ++ c

--H)
primerosListasConcat   a b c d e=take a ((b ++ c) ++d)

