
type Precio = Int

data TipoLadrillo = Ceramico | Hormigon | Tradicional deriving( Show)
data UsoLadrillo = Pared | Techo deriving( Show)

type Largo = Float
data MaterialViga = Hierro | Madera deriving( Show)

data MarcaCemento = Minetti | LomaNegra deriving( Show)

data MaterialesConstruccion = Ladrillo TipoLadrillo UsoLadrillo Precio | Vigueta Largo MaterialViga Precio | Cemento MarcaCemento Precio  deriving( Show)

ladrillosDeMenorPrecio :: [MaterialesConstruccion] -> Int -> [MaterialesConstruccion]
ladrillosDeMenorPrecio [] _ = []
ladrillosDeMenorPrecio (Ladrillo tipoLad usoLad precio:lm) n | precio<=n = Ladrillo tipoLad usoLad precio:ladrillosDeMenorPrecio lm n
                                                             | otherwise = ladrillosDeMenorPrecio lm n
ladrillosDeMenorPrecio (_:lm) n = ladrillosDeMenorPrecio lm n

lista=[Cemento Minetti 10,Ladrillo Ceramico Pared 4,Ladrillo Hormigon Techo 5]


--funcion auxiliar para validar el tipo de los ladrillos
mismoTipo :: TipoLadrillo -> TipoLadrillo -> Bool
mismoTipo Ceramico Ceramico = True
mismoTipo Hormigon Hormigon = True
mismoTipo Tradicional Tradicional = True
mismoTipo _ _ = False

--funcion auxiliar para validar el material de las Viguetas
mismoMaterial :: MaterialViga -> MaterialViga -> Bool
mismoMaterial Hierro Hierro = True
mismoMaterial Madera Madera = True
mismoMaterial _ _ = False

--funcion auxiliar para validar la marca del Cemento
mismaMarca :: MarcaCemento -> MarcaCemento -> Bool
mismaMarca Minetti Minetti = True
mismaMarca LomaNegra LomaNegra = True
mismaMarca _ _ = False


--Agrega la clase Eq al tipo MaterialesConstruccion sin usar deriving
instance Eq MaterialesConstruccion 
--con where especificamos "Guardas" de comparacion
  where 
    -- Definimos una estructura generalizada que tiene el constructor ladrillo, lo comparamos con otro igual y luego llamamos a nuestras funciones auxiliares.
    (Ladrillo tipoLad usoLad precio) == (Ladrillo tipoLad1 usoLad1 precio1) = mismoTipo tipoLad tipoLad1 && precio==precio1

    -- Definimos una estructura generalizada que tiene el constructor vigueta, lo comparamos con otro igual y luego llamamos a nuestras funciones auxiliares.
    (Vigueta largoVig materialVig precio) == (Vigueta largoVig1 materialVig1 precio1) = mismoMaterial materialVig materialVig1 && precio==precio1

    -- Definimos una estructura generalizada que tiene el constructor cemento, lo comparamos con otro igual y luego llamamos a nuestras funciones auxiliares.
    (Cemento marcaCemento precio) == (Cemento marcaCemento1 precio1) = mismaMarca marcaCemento marcaCemento1 && precio==precio1

    -- si viene algo distinto a los constructores que definimos en el tipo MaterialesCosntruccion, devolvemos un false.
    _==_ = False