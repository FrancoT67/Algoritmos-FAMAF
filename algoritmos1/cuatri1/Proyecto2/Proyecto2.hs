-- 2) Ejercicios:
-- 1. Tipos Enumerados
-- a)Implementá el tipo de Carrera como está definido.
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}
{-# HLINT ignore "Eta reduce" #-}
{-# HLINT ignore "Use camelCase" #-}
{-# HLINT ignore "Use newtype instead of data" #-}

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

minimoElemento :: (Ord a) => [a] -> a
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

data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Show) -- Tipos algebráicos sin parámetros ( aka enumerados)

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
contar_velocistas (Velocista _ : xs) = 1 + contar_velocistas xs
contar_velocistas (_ : xs) = contar_velocistas xs

-- contar_velocistas [(Ciclista Pista),(Velocista 2)] = 1
-- contar_velocistas [(Velocista 1),(Velocista 2)] = 2

-- d) Programá la función contar_futbolistas :: [Deportista] -> Zona -> Int que dada una lista de deportistas xs, y una zona z, devuelve la cantidad de futbolistas incluidos en xs que juegan en la zona z. No usar igualdad, sólo pattern matching.

contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] zona = 0
contar_futbolistas ((Futbolista Arco _ _ _) : xs) Arco = 1 + contar_futbolistas xs Arco
contar_futbolistas ((Futbolista Defensa _ _ _) : xs) Defensa = 1 + contar_futbolistas xs Defensa
contar_futbolistas ((Futbolista Mediocampo _ _ _) : xs) Mediocampo = 1 + contar_futbolistas xs Mediocampo
contar_futbolistas ((Futbolista Delantera _ _ _) : xs) Delantera = 1 + contar_futbolistas xs Delantera
contar_futbolistas (_ : xs) zona = contar_futbolistas xs zona

-- contar_futbolistas (x : xs) zona = case x of
--   Futbolista zona _ _ _ -> 1 + contar_futbolistas xs zona
--   _ -> 0 + contar_futbolistas xs zona

-- contar_futbolistas  [(Ciclista Pista),Futbolista Arco 1 Derecha 10] Arco = 1
-- contar_futbolistas  [(Ciclista Pista),Velocista 2] Arco = 0

-- e) ¿La función anterior usa filter? Si no es así, reprogramala para usarla.

verificarFutbolista :: Zona -> Deportista -> Bool
verificarFutbolista z (Futbolista Arco _ _ _) = True
verificarFutbolista z (Futbolista Defensa _ _ _) = True
verificarFutbolista z (Futbolista Mediocampo _ _ _) = True
verificarFutbolista z (Futbolista Delantera _ _ _) = True
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
sonidoCromatico (Nota (nota, alt)) = case (nota, alt) of
  (_, Bemol) -> sonidoNatural nota - 1
  (_, Sostenido) -> sonidoNatural nota + 1
  (_, Natural) -> sonidoNatural nota

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
data Cola = VaciaC | Encolada Deportista Cola deriving (Show)

-- A)Programá las siguientes funciones:
-- 1) atender::Cola -> Maybe Cola, que elimina a la persona que esta en la primer posicion de una cola, por haber sido atendida. Si la cola está vacía, entonces devuleve Nothing.
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada deportista cola) = Just cola

p = Encolada (Futbolista Arco 10 Derecha 100) (Encolada (Ciclista Pista) (Encolada Ajedrecista (Encolada Ajedrecista VaciaC)))

p' = Encolada Ajedrecista (Encolada (Ciclista Pista) (Encolada (Futbolista Arco 10 Derecha 100) (Encolada Ajedrecista VaciaC)))

-- atender p = Just (Encolada (Ciclista Pista) (Encolada Ajedrecista VaciaC))

-- 2) encolar :: Deportista -> Cola -> Cola, que agrega una persona a una colade deportistas, en la última posición
encolar :: Deportista -> Cola -> Cola
encolar deporAgregar VaciaC = VaciaC
encolar deporAgregar (Encolada depor cola) = Encolada deporAgregar (Encolada depor cola)

--  encolar (Ciclista BMX) p = Encolada (Ciclista BMX) (Encolada Ajedrecista (Encolada (Ciclista Pista) (Encolada Ajedrecista VaciaC)))
--  encolar (Ciclista BMX) VaciaC = VaciaC

-- 3)busca :: Cola -> Zona -> Maybe Deportista, que devuelve el/la primera futbolista dentro de la cola que juega en la zona que se corresponde con el segundo parámetro. Si no hay futbolistas jugando en esa zona devuelve Nothing.

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC zona = Nothing
busca (Encolada dpt cola) zona = case dpt of
  Futbolista zona _ _ _ -> Just dpt
  _ -> busca cola zona

-- busca p Arco = Just (Futbolista Arco 10 Derecha 100)
-- busca p' Arco = Just (Futbolista Arco 10 Derecha 100)

-- B)¿A qué otro tipo se parece cola? Se parece al tipo [a] xq de forma implicita esta generado una lista de Deportistas

-- 8. Tipos recursivos y polimórficos

-- a) ¿Cómo se debe instanciar el tipo ListaAsoc para representar la información almacenada en una guia telefónica?

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving (Show)

type Guia = ListaAsoc String Int

-- b) Programar las sig Funciones:
-- 1) la_long :: ListaAsoc a b -> Int que devuelve la cantidad de datos en una lista
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo x y lista) = 1 + la_long lista

--  la_long (Nodo 'a' 1 (Nodo 'b' 2 Vacia)) = 2
--  la_long (Nodo (Ajedrecista) 1 (Nodo (Ciclista BMX) 2 Vacia)) = 2

-- 2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b, que devuelve la concatenacion de dos listas de asociaciones
nodoEjemplo1 = Nodo Ajedrecista 2 (Nodo (Ciclista Pista) 2 Vacia)

nodoEjemplo2 = Nodo (Futbolista Arco 10 Izquierda 100) 1 (Nodo (Ciclista BMX) 2 Vacia)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat x Vacia = x
la_concat Vacia x = x
la_concat (Nodo dato1 dato2 lista) (Nodo dato1' dato2' lista') = Nodo dato1 dato2 (la_concat lista (Nodo dato1' dato2' lista'))

-- la_concat  nodoEjemplo3 nodoEjemplo3 = Nodo 'a' 1 (Nodo 'b' 3 (Nodo 'c' 4 (Nodo 'a' 1 (Nodo 'b' 3 (Nodo 'c' 4 Vacia)))))
-- la_concat  nodoEjemplo1 nodoEjemplo1 = Nodo Ajedrecista 2 (Nodo (Ciclista Pista) 2 (Nodo Ajedrecista 2 (Nodo (Ciclista Pista) 2 Vacia)))

-- 3) la_agregar :: Eq a=> ListaAsoc a b -> a -> b -> ListaAsoc a b, que agrega un nodo a la lista de asociaciones si la clave no está en la lista, o actualiza el valor si la clave ya se encontraba.
nodoEjemplo3 = Nodo 'a' 1 (Nodo 'b' 3 (Nodo 'c' 4 Vacia))

la_agregar :: (Eq a) => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia dato1 dato2 = Nodo dato1 dato2 Vacia
la_agregar (Nodo dato1 dato2 lista) dato3 dato4
  | dato1 == dato3 = Nodo dato1 dato4 lista
  | dato1 /= dato3 = Nodo dato1 dato2 (la_agregar lista dato3 dato4)

-- la_agregar nodoEjemplo3 'r' 4 = Nodo 'a' 1 (Nodo 'b' 3 (Nodo 'c' 4 (Nodo 'r' 4 Vacia)))
-- la_agregar nodoEjemplo3 'b' 4 = Nodo 'a' 1 (Nodo 'b' 4 (Nodo 'c' 4 Vacia))

-- 4) la_pares :: ListaAsoc a b -> [(a, b)] que transforma una lista de asociaciones en una lista de pares clave-dato.
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo x z Vacia) = [(x, z)]
la_pares (Nodo x z c) = (x, z) : la_pares c

-- la_pares nodoEjemplo3 = [('a',1),('b',3),('c',4)]
-- la_pares nodoEjemplo1 = [(Ajedrecista,2),(Ciclista Pista,2)]
-- la_pares Vacia = []

-- 5) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b que dada una lista y una clave devuelve el dato asociado, si es que existe. En caso contrario devuelve Nothing.
la_busca :: (Eq a) => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo x z c) d | x == d = Just z | otherwise = la_busca c d

-- la_busca nodoEjemplo3 'e' = Nothing
-- la_busca nodoEjemplo3 'c' = Just 4

-- 6) la_borrar :: Eq a=> a -> ListaAsoc a b -> ListaAsoc a b que dada una clave a elimina la entrada en la lista.
la_borrar :: (Eq a) => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar buscaDato (Nodo dato1 dato2 lista) | buscaDato == dato1 = lista | otherwise = Nodo dato1 dato2 (la_borrar buscaDato lista)

-- la_borrar 'c' nodoEjemplo3 = Nodo 'a' 1 (Nodo 'b' 3 Vacia)
-- la_borrar 'z' nodoEjemplo3 = Nodo 'a' 1 (Nodo 'b' 3 (Nodo 'c' 4 Vacia))