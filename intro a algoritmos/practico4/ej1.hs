-- data es para definir posibilidades para el atributo Color
data Color = Rojo |Azul |Amarillo |Verde

-- deriving es la forma en que se van a poder usar el atributo Color
	deriving (Show,Eq)

data Forma = Circulo |Rombo |Cuadrado | Triangulo  
	deriving (Show,Eq)

-- el type es para definir que atributos va a tener el objeto Figura
type Figura = (Forma, Color, Int)



--funcion correspondiente a Rojo
rojo :: Figura -> Bool
rojo (f,c,i) = (c == Rojo)

--funcion correspondiente a Azul
azul :: Figura -> Bool
azul (f,c,i) = (c == Azul)

--funcion correspondiente a Amarillo
amarillo :: Figura -> Bool
amarillo (f,c,i) = (c == Amarillo)

--funcion correspondiente a Verde
verde :: Figura -> Bool
verde (f,c,i) = (c == Verde)

--funcion correspondiente a Circulo
circulo :: Figura -> Bool
circulo (f,c,i) = (f == Circulo)

--funcion correspondiente a Rombo
rombo :: Figura -> Bool
rombo (f,c,i) = (f == Rombo)

--funcion correspondiente a Cuadrado
cuadrado :: Figura -> Bool
cuadrado (f,c,i) = (f == Cuadrado)

--funcion correspondiente a Triangulo
triangulo :: Figura -> Bool
triangulo (f,c,i) = (f == Triangulo)
