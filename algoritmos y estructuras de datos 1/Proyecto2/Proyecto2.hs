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
c) Para escribir musica se utiliza la denominada notacion musical, la cual consta de notas (do,re,mi, ...). Además estas notas pueden presentar algún modificador como sostenido o bemol,definir el tipo NotaBasica cons constructores Do,Re, Mi, Fa, Sol, La y Si.
-}
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si

{-
d) EL sistemade notacion musical anglosajon, tambien conocido como notacion o cifrado americado, relaciona las notas basicas con letras de la A a la G. Este sistema se usa por ejemplo para las tablaturas de guitarra.
Programar usando Pattern Matching la funcion: cifradoAmericano :: NotaBasica -> Char
-}
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'A'
cifradoAmericano Re = 'B'
cifradoAmericano Mi = 'C'
cifradoAmericano Fa = 'D'
cifradoAmericano Sol = 'E'
cifradoAmericano La = 'F'
cifradoAmericano Si = 'G'

{-

-}
