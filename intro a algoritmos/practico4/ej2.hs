-- data es para definir posibilidades para el atributo Color
data Color = Rojo |Azul |Amarillo |Verde

-- deriving es la forma en que se van a poder usar el atributo Color
	deriving (Show,Eq)

data Forma = Circulo |Rombo |Cuadrado | Triangulo  
	deriving (Show,Eq)

-- el type es para definir que atributos va a tener el objeto Figura
type Figura = (Forma, Color, Int)

tam :: Figura -> Int
tam(f,c,t)= t