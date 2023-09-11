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
data NotaBasica = Do 
                  | Re 
                  | Mi 
                  | Fa 
                  | Sol 
                  | La 
                  | Si 
                  deriving (Eq, Ord, Show, Bounded)

{-
d) EL sistemade notacion musical anglosajon, tambien conocido como notacion o cifrado americado, relaciona las notas basicas con letras de la A a la G. Este sistema se usa por ejemplo para las tablaturas de guitarra.
Programar usando Pattern Matching la funcion: cifradoAmericano :: NotaBasica -> Char -}
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

-- cifradoAmericano Do = 'A' 
-- cifradoAmericano Re = 'D' 

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
minimoElemento' :: (Bounded a, Ord a ) => [a] -> a
minimoElemento' [] = maxBound
minimoElemento' (x:xs) = min x (minimoElemento' xs)

-- minimoElemento' [3,1,3]::Int = 1
-- minimoElemento' ([1,5,10]::[Int]) = 1
{-
C) Usar la función minimoElemento para determinar la nota más grave de la melodía:
[Fa, La, Sol, Re, Fa]
-}
type Nota = NotaBasica

minimoElemento'' :: [Nota] -> NotaBasica
minimoElemento'' x = minimoElemento x

--minimoElemento'' [Fa, La, Sol, Re, Fa]

{-
4 Sinonimo de tipos, constructores con parámetros
-}

--A) Implementar tipo Deportista
--Sinonimo de Tipo
type Altura = Int 
type NumCamiseta = Int

-- Tipos algebráicos sin parámetros ( aka enumerados)

data Zona = Arco | Defensa | Mediocampo | Delantera deriving(Show)
data TipoReves = DosManos | UnaMano deriving(Show)
data Modalidad = Carretera | Pista | Monte | BMX deriving(Show)
data PiernaHabil = Izquierda | Derecha deriving(Show)
-- Sinónimo
type ManoHabil = PiernaHabil

-- Deportista es un tipo algebráico con constructores parámetricos
data Deportista = Ajedrecista                                     --Constructor sin argumentos
                 | Ciclista Modalidad                           --Constructor con un argumento
                 | Velocista Altura                               --Constructor con un argumento
                 | Tenista TipoReves ManoHabil Altura             --Constructor con tres argumentos
                 | Futbolista Zona NumCamiseta PiernaHabil Altura
                 deriving(Show) -- Constructor con cuatro argumentos 
-- B)¿Cúal es el tipo del constructor Ciclista?
--  El constructor Ciclista es de tipo Modalidad -> Deportista
{-
c) Programá la función contar_velocistas :: [Deportista] -> Int que dada una lista de deportistas xs, devuelve la cantidad de velocistas que hay dentro de xs.
Programar contar_velocistas sin usar igualdad, utilizando pattern matching.
-}
contar_velocistas :: [Deportista] -> Int
contar_velocistas []  = 0
contar_velocistas (x:xs ) =case x of  
    Velocista _ -> 1 + contar_velocistas xs
    _ -> 0+contar_velocistas xs 

--contar_velocistas [(Ciclista Pista),(Velocista 2)] = 1
--contar_velocistas [(Velocista 1),(Velocista 2)] = 2

{-
d) Programá la función contar_futbolistas :: [Deportista] -> Zona -> Int que
dada una lista de deportistas xs, y una zona z, devuelve la cantidad de futbolistas
incluidos en xs que juegan en la zona z. No usar igualdad, sólo pattern matching.
-}

contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] zona = 0
contar_futbolistas (x:xs) zona =case x of  
    Futbolista zona _ _ _ -> 1 + contar_futbolistas xs zona
    _ -> 0+contar_futbolistas xs zona 


-- contar_futbolistas  [(Ciclista Pista),Futbolista Arco 1 Derecha 10] Arco = 1
-- contar_futbolistas  [(Ciclista Pista),Velocista 2] Arco = 0

{- 
e) ¿La función anterior usa filter? Si no es así, reprogramala para usarla.
-}
 
-- controlar verificarFutbolista y contar_futbolistas

verificaFutbolista :: Deportista -> Bool
verificaFutbolista x = x==(Futbolista z _ _ _)

contar_futbolistas' :: [Deportista] -> Zona -> Int
contar_futbolistas' deportista = filter verificarFutbolista deportista  