{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use camelCase" #-}
{-# HLINT ignore "Use foldr" #-}
{-# HLINT ignore "Eta reduce" #-}
{-# HLINT ignore "Use newtype instead of data" #-}

-- 2) Ejercicios:
-- 1. Tipos Enumerados
-- a)Implementá el tipo de Carrera como está definido.

data Carrera = Matematica | Fisica | Computación | Astronomia

-- b) Definí la sig funcion usando pattern matching : titulo::Carrera-> String que devuelve el nombre completo de la carrera en forma de string.
-- Ejemplo:
-- Matematica devuelve "Licenciatura en Matetmática"
titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computación = "Licenciatura en Computación"
titulo Astronomia = "Licenciatura en Astronomia"

-- c) Para escribir musica se utiliza la denominada notacion musical, la cual consta de notas (do,re,mi, ...). Además estas notas pueden presentar algún modificador como sostenido o bemol,definir el tipo NotaBasica cons constructores Do,Re, Mi, Fa, Sol, La y Si.
data NotaBasica
  = Do
  | Re
  | Mi
  | Fa
  | Sol
  | La
  | Si
  deriving (Eq, Ord, Show, Bounded, Enum)

-- d) EL sistemade notacion musical anglosajon, tambien conocido como notacion o cifrado americado, relaciona las notas basicas con letras de la A a la G. Este sistema se usa por ejemplo para las tablaturas de guitarra.
-- Programar usando Pattern Matching la funcion: cifradoAmericano :: NotaBasica -> Char
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

-- 3 . Polimorfismo AD HOC Recordemos la función sumatoria del proyecto anterior:

-- sumatoria :: [Int] −> Int
-- sumatoria [] = 0
-- sumatoria ( x:xs ) = x + sumatoria xs

-- como solo funciona para los Int, se la abstrae a la forma sumatoria :: [a]->a pero como no tiene los operadors ni propiedades de los numeros, se le agrega Num a=> para definir las propiedades de los numeros al que estamos usando para la abstracción, entoces la función quedaría: sumatoria : : Num a => [ a ] −> a.
-- a) Definir usando polimorfismo ad hoc la función minimoElemento que calcula (de manera recursiva) cúal es el menor valor de una lista de tipo [a]. Asegurarse que sólo esté definida para listas no vacías.

minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x : xs) = min x (minimoElemento xs)

-- minimoElemento [-2,1,-3,-4] = -4
-- minimoElemento [-1,0,1] = -1
-- b) Definir la función minimoElemento' de manera tal que el caso base de la recursión sea el de la lista vacía. Para ello revisar la clase Bounded.
-- Ayuda: Para probar esta función dentro de ghci con listas vacías, indicar el tipo concreto con tipos de la clase Bounded, por ejemplo: ([1,5,10]::[Int]), ([]::[Bool]), etc.

minimoElemento' :: (Bounded a, Ord a) => [a] -> a
minimoElemento' [] = maxBound
minimoElemento' (x : xs) = min x (minimoElemento' xs)

-- minimoElemento' [3,1,3]::Int = 1
-- minimoElemento' ([1,5,10]::[Int]) = 1

-- C) Usar la función minimoElemento para determinar la nota más grave de la melodía:
-- [Fa, La, Sol, Re, Fa]

minimoElemento'' :: [NotaBasica] -> NotaBasica
minimoElemento'' x = minimoElemento x

-- minimoElemento'' [Fa, La, Sol, Re, Fa] = Re

-- 4 Sinonimo de tipos, constructores con parámetros

-- A) Implementar tipo Deportista

type Altura = Int -- Sinonimo de Tipo

type NumCamiseta = Int -- Sinonimo de Tipo

data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Show, Eq) -- Tipos algebráicos sin parámetros ( aka enumerados)

data TipoReves = DosManos | UnaMano deriving (Show) -- Tipos algebráicos sin parámetros ( aka enumerados)

data Modalidad = Carretera | Pista | Monte | BMX deriving (Show) -- Tipos algebráicos sin parámetros ( aka enumerados)

data PiernaHabil = Izquierda | Derecha deriving (Show) -- Tipos algebráicos sin parámetros ( aka enumerados)

type ManoHabil = PiernaHabil -- Sinónimo

-- Deportista es un tipo algebráico con constructores parámetricos
data Deportista
  = Ajedrecista -- Constructor sin argumentos
  | Ciclista Modalidad -- Constructor con un argumento
  | Velocista Altura -- Constructor con un argumento
  | Tenista TipoReves ManoHabil Altura -- Constructor con tres argumentos
  | Futbolista Zona NumCamiseta PiernaHabil Altura
  deriving (Show) -- Constructor con cuatro argumentos

-- B)¿Cúal es el tipo del constructor Ciclista?
--  El constructor Ciclista es de tipo Modalidad -> Deportista

-- c) Programá la función contar_velocistas :: [Deportista] -> Int que dada una lista de deportistas xs, devuelve la cantidad de velocistas que hay dentro de xs.
-- Programar contar_velocistas sin usar igualdad, utilizando pattern matching.

contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas (x : xs) = case x of
  Velocista _ -> 1 + contar_velocistas xs
  _ -> 0 + contar_velocistas xs

-- contar_velocistas [(Ciclista Pista),(Velocista 2)] = 1
-- contar_velocistas [(Velocista 1),(Velocista 2)] = 2

-- d) Programá la función contar_futbolistas :: [Deportista] -> Zona -> Int que dada una lista de deportistas xs, y una zona z, devuelve la cantidad de futbolistas incluidos en xs que juegan en la zona z. No usar igualdad, sólo pattern matching.

contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] zona = 0
contar_futbolistas (x : xs) zona = case x of
  Futbolista zona _ _ _ -> 1 + contar_futbolistas xs zona
  _ -> 0 + contar_futbolistas xs zona

-- contar_futbolistas  [(Ciclista Pista),Futbolista Arco 1 Derecha 10] Arco = 1
-- contar_futbolistas  [(Ciclista Pista),Velocista 2] Arco = 0

-- e) ¿La función anterior usa filter? Si no es así, reprogramala para usarla.

verificarFutbolista :: Zona -> Deportista -> Bool
verificarFutbolista z (Futbolista zona _ _ _) = zona == z
verificarFutbolista _ _ = False

contar_futbolistas' :: [Deportista] -> Zona -> Int
contar_futbolistas' xs zona = length (filter (verificarFutbolista zona) xs)

-- contar_futbolistas' [Ajedrecista ] Mediocampo = 0
-- contar_futbolistas' [Futbolista Mediocampo 10 Derecha 185] Defensa = 1

-- 5. Definición de clases.

-- a) Implementá la función sonidoNatural como está definida arriba.
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

-- b) Definir el tipo enumerado Alteracion que consta de los constructores Bemol, Natural y Sostenido.
data Alteracion = Bemol | Natural | Sostenido deriving (Show, Enum, Eq, Ord)

-- c) Definir el tipo algebraico NotaMusical que debe tener un solo constructor que llamaremos Nota el cual toma dos parámetros.El primer parámetro es de tipo NotaBasica y el segundo de  tipo Alteracion. De esta manera cuando se quiera representar una nota alterada se puede usar como segundo parámetro del constructor un Bemol o Sostenido y si se quiere representar una nota sin alteraciones se usa Natural como segundo parámetro.

data NotaMusical = Nota (NotaBasica, Alteracion) deriving (Eq, Show, Ord)

-- d) Definí la funcíon sonidoCromatico :: NotaMusical -> Int que devuelve el sonido de una nota, incrementando en uno su valor si tiene la alteracion Sostenido, decrementando en uno si tiene la alteración Bemol y dejando su valor intacto si la alteracion es Natural.

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota (x, alt)) = case (x, alt) of
  (_, Bemol) -> sonidoNatural x - 1
  (_, Sostenido) -> sonidoNatural x + 1
  (_, Natural) -> sonidoNatural x

-- sonidoCromatico (Nota (Re, Bemol)) = 1
-- sonidoCromatico (Nota (Re, Sostenido)) = 3
-- sonidoCromatico (Nota (Re, Natural)) = 2

--    otra opcion que pensé
-- sonidoCromatico (Nota (x, Sostenido)) = sonidoNatural x + 1
-- sonidoCromatico (Nota (x, Bemol)) = sonidoNatural x - 1
-- sonidoCromatico (Nota (x, Natural)) = sonidoNatural x

-- e) Incluí el tipo NotaMusical a la clase Eq de manera tal que dos notas que tengan el mismo valor de sonidoCromatico se consideren iguales.
-- sonidoCromatico (Nota (Re,Sostenido )) == sonidoCromatico (Nota(Mi,Bemol))= True

-- f) Incluí el tipo NotaMusical a la clase Ord definiendo el operador <=. Se debe definir que una nota es menor o igual a otra si y sólo si el valor de sonidoCromatico para la primera es menor o igual al valor de sonidoCromatico para la segunda.
-- sonidoCromatico (Nota (Re,Sostenido )) <= sonidoCromatico (Nota(Mi,Bemol)) == True
-- sonidoCromatico (Nota (Re,Sostenido )) >= sonidoCromatico (Nota(Mi,Sostenido)) == False

-- 6. Tipos enumerados con polimorfismo
-- a) Definir la funcion primerElemento que devuelve el primer elemento de una lista no vacía, o Nothing si la lista es vacía.
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento x = Just (head x)

-- primerElemento [-10 .. 10] = Just(-10)
-- primerElemento [] = Nothing

-- 7. Tipos recursivos
data Cola = VaciaC | Encolada Deportista Cola

-- a)Programá las siguientes funciones:
-- 1) atender::Cola -> Maybe Cola, que elimina a la persona que esta en la primer posicion de una cola, por haber sido atendida. Si la cola está vacía, entonces devuleve Nothing.
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing

-- atender (x : xs) = atender xs