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
data NotaBasica = Do| Re| Mi| Fa| Sol| La| Si deriving (Eq, Ord, Show, Bounded, Enum)

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

































{-
Ejercicio 1:
Se va a representar el stock de Productos de un Vivero, usando tipos en Haskell. Los
productos que tenemos en cuenta son: Planta, Semilla, Maceta. La idea es poder
detallar para cada tipo de artículo, las características más importantes. En tal sentido
identificamos las siguientes características de cada uno de los artículos a tener en cuenta:
Planta
● Categoria, que es un tipo enumerado con las siguientes opciones: Bulbosas,
Rosales, Frutales, Trepadoras
● Floracion, que es un tipo enumerado con las siguientes opciones: Primavera,
Verano, Invierno.
● Hoja, que es un sinónimo de String indicando el tipo de hoja.
● Precio, que es un sinónimo de Int indicando el precio

Semilla
● TipoSemilla, que es un tipo enumerado con las siguientes opciones: Flores ,
Hortalizas y Aromaticas
● Hoja, que es un sinónimo de String indicando el tipo de hoja de la planta
● Precio, que es un sinónimo de Int indicando el precio
Maceta
● Material, que es un tipo enumerado con las siguientes opciones: Plastico,
Barro .
● Precio, que es un sinónimo de Int indicando el precio
Para ello:
\* a) Definir el tipo ProductosVivero que consta de los constructores Planta, Semilla
y Maceta, constructores con parámetros descritos arriba (Se deben definir también los
tipos enumerados Categoria, Floracion, TipoSemilla, Material y los
sinónimos de Hoja y de Peso). No se debe usar deriving Eq ni deriving Ord
para ninguno de los tipos. Se puede sin embargo incluir los tipos en la clase Show
\* b) Definir la función cuantasPlantas de la siguiente manera:
cuantasPlantas :: [ProductosVivero] -> Categoria -> Int
que dada una lista de ProductosVivero ls y un valor c de Categoria de Planta,
me devuelve un entero indicando la cantidad de plantas que hay en ls con la categoria c.
\** NOTA: Dejar como comentario dos ejemplo donde hayas probado la función
cuantasPlantas con una lista con al menos 3 ProductosVivero.

\* c) Definir igualdad para el tipo de ProductosVivero: de tal manera que, dos productos de
tipo Planta son iguales sólo si tienen la misma Categoria y la misma Hoja, dos
productos del tipo Semilla son iguales solo si tienen el mismo TipoSemilla, la misma
Hoja y el mismo precio, mientras que dos productos del tipo Maceta son iguales si tiene el
mismo Material y el mismo precio. Como es de suponer las Plantas, Semillas y Macetas
son distintas entre sí.
\** NOTA: Dejar como comentario en el código dos ejemplos en los que probaste la igualdad.
d) Definir la función, hay dos productos iguales de manera consecutiva en una lista de
productos de vivero. La función hayDosIguales, tiene la siguiente definición de tipos:
hayDosIguales :: [ProductosVivero] -> Bool
Dada una lista de ProductosVivero ls, debe devolver True en caso que en la lista ls
existan dos productos que sean iguales de manera consecutiva, y False en caso
contrario.
\** NOTA: Dejar como comentario en el código dos ejemplos en los que probaste la función.
-}

-------------------
------ ejercicio 1
-------------------
data Categoria = Bulbosas | Rosales | Frutales | Trepadoras

data Floracion = Primavera | Verano | Invierno

type Hoja = String

type Precio = Int

data TipoSemilla = Flores | Hortalizas | Aromaticas

data Material = Plastico | Barro

data ProductosVivero = Planta Categoria Floracion Hoja Precio | Semilla TipoSemilla Hoja Precio | Maceta Material Precio

instance Eq ProductosVivero where
  (Planta c1 f1 h1 p1) == (Planta c2 f2 h2 p2) = (mismaCategoria c1 c2) && (h1 == h2)
  (Semilla t1 h1 p1) == (Semilla t2 h2 p2) = (mismoTipo t1 t2) && (h1 == h2) && (p1 == p2)
  (Maceta m1 p1) == (Maceta m2 p2) = (mismoMaterial m1 m2) && (p1 == p2)
  _ == _ = False

-- ejemplos de uso
-- ghci> Planta  Bulbosas Verano "Verde" 2000 == Planta  Bulbosas Verano "Verde" 2000
-- ghci>True
-- ghci> Planta  Bulbosas Verano "Verde" 2000 == Planta  Rosales Verano "Verde" 2000
-- ghci>False
-- ghci> Planta  Bulbosas Verano "Verde" 2000 == Planta  Bulbosas Invierno "Verde" 2000
-- ghci>True
-- ghci> Semilla Flores "Verde" 1000 == Semilla Flores "Verde" 1000
-- ghci>True
-- ghci> Semilla Flores "Verde" 1000 == Semilla Flores "Amarilla" 1000
-- ghci>False
-- ghci>Semilla Flores "Verde" 1000 == Semilla Flores "Verde" 3000
-- ghci>False
-- ghci> Maceta Plastico 3000 == Maceta Plastico 300
-- ghci>False
-- ghci> Maceta Plastico 3000 == Maceta Plastico 3000
-- ghci>True
-- ghci> Maceta Plastico 3000 == Maceta Barro 3000
-- ghci>False

----- b)----- Cuantas Plantas
mismaCategoria :: Categoria -> Categoria -> Bool
mismaCategoria Bulbosas Bulbosas = True
mismaCategoria Rosales Rosales = True
mismaCategoria Frutales Frutales = True
mismaCategoria Trepadoras Trepadoras = True
mismaCategoria _ _ = False

cuantasPlantas :: [ProductosVivero] -> Categoria -> Int
cuantasPlantas [] c1 = 0
cuantasPlantas ((Planta c f h p) : xs) c1
  | mismaCategoria c c1 = 1 + cuantasPlantas xs c1
  | otherwise = cuantasPlantas xs c1
cuantasPlantas (_ : ds) c1 = cuantasPlantas ds c1

-- ejemplo de uso
-- ghci> cuantasPlantas  [Planta  Bulbosas Verano "Verde" 2000, Semilla Flores "Verde" 1000, Maceta Plastico 3000, Planta  Bulbosas Invierno "Verde" 2000] Bulbosas
-- ghci>2
-- ghci> cuantasPlantas  [Planta  Bulbosas Verano "Verde" 2000, Semilla Flores "Verde" 1000, Maceta Plastico 3000, Planta  Rosales Invierno "Verde" 2000] Bulbosas
-- ghci>1
---- c)---Igualdad
mismoTipo :: TipoSemilla -> TipoSemilla -> Bool
mismoTipo Flores Flores = True
mismoTipo Hortalizas Hortalizas = True
mismoTipo Aromaticas Aromaticas = True
mismoTipo _ _ = False

mismoMaterial :: Material -> Material -> Bool
mismoMaterial Plastico Plastico = True
mismoMaterial Barro Barro = True
mismoMaterial _ _ = False

---- d)---- Dos Iguales
hayDosIguales :: [ProductosVivero] -> Bool
hayDosIguales [] = False
hayDosIguales [p] = False
hayDosIguales (p1 : p2 : xs) = (p1 == p2) || hayDosIguales (p2 : xs)

-- ejemplo de uso
-- ghci> hayDosIguales  [Planta  Bulbosas Verano "Verde" 2000, Semilla Flores "Verde" 1000, Maceta Plastico 3000, Planta  Bulbosas Invierno "Verde" 2000]
-- ghci>False
-- ghci> hayDosIguales [Planta  Bulbosas Verano "Verde" 2000, Planta  Bulbosas Invierno "Verde" 2000, Semilla Flores "Verde" 1000, Maceta Plastico 3000]
-- ghci>True

{-
Ejercicio 2
Queremos hacer en Haskell un programa que va a representar una lista de reproducción
(parecido a las utilizadas en plataformas como Netflix, Disney, etc) para películas. Para ello
\* a) Definir un tipo recursivo MovieList, que permite guardar las películas que se van
reproduciendo por cada perfil creado en la plataforma. El tipo tendrá dos
constructores:
1) Movie, que tiene cinco parámetros con los siguientes tipos:
■ Titulo, que es el nombre de la película y debe ser sinónimo de
String
■ Megusta pensarlo de la siguiente forma, si me encanta tiene un 2, si
me gusta tiene un 1 y si no es para mi, tiene un 0, por lo cual debe ser
sinónimo de Int
■ Estado, que es un tipo enumerado con constructores Reproducido
y SinReproducir
■ Duracion, que es la cantidad de minutos que dura la película y debe
ser un sinónimo de Int
■ MovieList, recursión con el resto de las películas.
2) SinMovie, que es un constructor sin parámetros, similar al de la lista vacía,
para indicar que no hay películas.
\** NOTA: Los tipos nuevos definidos no deben estar en la clase Eq ni Ord
\* b) Programar la función minutosReproducidos

minutosReproducidos :: MovieList -> Megusta -> Duracion
que dada una Lista de Películas mls y un valor para Megusta mg devuelve la suma
de los minutos reproducidos de todas las películas de mls que han sido
reproducidas y que tienen megusta mayor o igual a mg.
\** ** NOTA: Dejar como comentario un ejemplo donde se haya probado
minutosReproducidos con un parámetro de tipo MovieList que tenga al
menos 3 películas.
\* c) Programar la función
estadoDePeli :: Titulo -> MovieList -> Maybe Estado
que dado un título de película t y una lista de películas mls si la película está en
mls con estado e debe devolver Just e y si la película no está debe devolver
Nothing
\** NOTA: Dejar como comentario un ejemplo donde se haya probado la función.

-}

-------------------
------ ejercicio 2
-------------------
type Titulo = String

type Megusta = Int

type Duracion = Int

data Estado = Reproducido | SinReproducir deriving (Show)

data MovieList = Movie Titulo Megusta Estado Duracion MovieList | SinMovie deriving (Show)

----- b)
minutosReproducidos :: MovieList -> Megusta -> Duracion
minutosReproducidos SinMovie mg = 0
minutosReproducidos (Movie _ _ SinReproducir _ mls) mg = minutosReproducidos mls mg
minutosReproducidos (Movie _ mg1 Reproducido d mls) mg
  | mg1 >= mg = d + minutosReproducidos mls mg
  | otherwise = minutosReproducidos mls mg

----- c)
estadoDePeli :: Titulo -> MovieList -> Maybe Estado
estadoDePeli _ SinMovie = Nothing
estadoDePeli t (Movie ti _ e _ mls)
  | t == ti = Just e
  | otherwise = estadoDePeli t mls

-- Main> minutosReproducidos (Movie "Ironman" 1 Reproducido 120 (Movie "Avenger" 2 Reproducido 140 (Movie "Spiderman" 0 SinReproducir 110 SinMovie))) 1
-- 260
-- Main> estadoDePeli "Avenger" (Movie "Ironman" 1 Reproducido 120 (Movie "Avenger" 2 Reproducido 140 (Movie "Spiderman" 0 SinReproducir 110 SinMovie)))
-- Just Reproducido
-- Main> estadoDePeli "Spiderman" (Movie "Ironman" 1 Reproducido 120 (Movie "Avenger" 2 Reproducido 140 (Movie "Spiderman" 0 SinReproducir 110 SinMovie)))
-- Just SinReproducir