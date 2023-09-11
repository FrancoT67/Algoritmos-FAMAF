-- 2) Ejercicios:

-- 1. Tipos Enumerados
-- a)Implementá el tipo de Carrera como está definido.
data Carrera = Matematica | Fisica | Computación | Astronomia

{-
b) Definí la sig funcion usando pattern matching : titulo::Carrera-> String que devuelve el nombre completo de la carrera en forma de string.
Ejemplo:
Matematica devuelve "Licenciatura en Matetmática" -}
titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computación = "Licenciatura en Computación"
titulo Astronomia = "Licenciatura en Astronomia"

{-
c) Para escribir musica se utiliza la denominada notacion musical, la cual consta de notas (do,re,mi, ...). Además estas notas pueden presentar algún modificador como sostenido o bemol,definir el tipo NotaBasica cons constructores Do,Re, Mi, Fa, Sol, La y Si. -}
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)

{-
d) EL sistemade notacion musical anglosajon, tambien conocido como notacion o cifrado americado, relaciona las notas basicas con letras de la A a la G. Este sistema se usa por ejemplo para las tablaturas de guitarra.
Programar usando Pattern Matching la funcion: cifradoAmericano :: NotaBasica -> Char -}
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'A'
cifradoAmericano Re = 'B'
cifradoAmericano Mi = 'C'
cifradoAmericano Fa = 'D'
cifradoAmericano Sol = 'E'
cifradoAmericano La = 'F'
cifradoAmericano Si = 'G'

{-
3 . Polimorfismo AD HOC Recordemos la función sumatoria del proyecto anterior:

sumatoria :: [Int] −> Int
sumatoria [] = 0
sumatoria ( x:xs ) = x + sumatoria xs

como solo funciona para los Int, se la abstrae a la forma sumatoria :: [a]->a pero como no tiene los operadors ni propiedades de los numeros, se le agrega Num a=> para definir las propiedades de los numeros al A que estamos usando para la abstracción, entoces la función quedaría: sumatoria : : Num a => [ a ] −> a -}
-- a) Definir usando polimorfismo ad hoc la función minimoElemento que calcula (de manera recursiva) cúal es el menor valor de una lista de tipo [a]. Asegurarse que sólo esté definida para listas no vacías.

minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x : xs) = min x (minimoElemento xs)

{-
minimoElemento [-2,1,-3,-4] = -4
minimoElemento [-1,0,1] = -1
-}

{-
b) Definir la función minimoElemento' de manera tal que el caso base de la recursión sea el de la lista vacía. Para ello revisar la clase Bounded.
Ayuda: Para probar esta función dentro de ghci con listas vacías, indicar el tipo concreto con tipos de la clase Bounded, por ejemplo: ([1,5,10]::[Int]), ([]::[Bool]), etc. -}
minimoElemento' :: (Bounded a, Ord a) => [a] -> a
minimoElemento'[] = maxBound
minimoElemento' (x:xs) = min (minimoElemento' xs)

-- Falla ⬆️⬆️⬆️