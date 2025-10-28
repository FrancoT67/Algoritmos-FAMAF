--1.
-- a) definir y agregar Show

data TipoYerba = ConPalo | SinPalo | Compuesta
  deriving (Show)

data Paquete = PaqueteNormal TipoYerba Cantidad | PaquetePremium TipoYerba Cantidad Origen deriving (Show)

data Origen = Organica | Agroecologica deriving (Show)

type Cantidad = Int

-- b) implementar funciones

es_yerba_con_palo :: Paquete -> Bool
es_yerba_con_palo (PaqueteNormal ConPalo _) = True
es_yerba_con_palo (PaquetePremium ConPalo _ _) = True
es_yerba_con_palo _ = False

{-
ghci> es_yerba_con_palo (PaqueteNormal SinPalo 3)
False
ghci> es_yerba_con_palo (PaquetePremium  SinPalo 3 Organica )
False
ghci> es_yerba_con_palo (PaquetePremium  CoPalo 3 Organica )
Compuesta  ConPalo
ghci> es_yerba_con_palo (PaquetePremium  ConPalo 3 Organica )
True
ghci>
-}

agregar_paquete :: Paquete -> [Paquete] -> [Paquete]
agregar_paquete p [] = [p]
agregar_paquete p ps = p : ps

{-
ghci> agregar_paquete (PaqueteNormal ConPalo 3) []
[PaqueteNormal ConPalo 3]
ghci> agregar_paquete (PaqueteNormal ConPalo 3) [PaquetePremium ConPalo 8 Organica]
[PaqueteNormal ConPalo 3,PaquetePremium ConPalo 8 Organica]
ghci> agregar_paquete (PaquetePremium Compuesta  8 Organica )[PaqueteNormal ConPalo 3,PaquetePremium SinPalo 5 Organica]
[PaquetePremium Compuesta 8 Organica,PaqueteNormal ConPalo 3,PaquetePremium SinPalo 5 Organica]
ghci>
-}

-- funcion auxiliar para comparar tiposYerba
mismoTipoYerba :: TipoYerba -> TipoYerba -> Bool
mismoTipoYerba ConPalo ConPalo = True
mismoTipoYerba SinPalo SinPalo = True
mismoTipoYerba Compuesta Compuesta = True
mismoTipoYerba _ _ = False

-- funcion auxiliar para extraer kilos
kilos_de :: Paquete -> TipoYerba -> Int
kilos_de (PaqueteNormal tipo cant) tipoY
  | (mismoTipoYerba tipo tipoY) = cant
  | otherwise = 0
kilos_de (PaquetePremium tipo cant orig) tipoY
  | (mismoTipoYerba tipo tipoY) = cant
  | otherwise = 0

cuantos_kilos :: [Paquete] -> TipoYerba -> Int
cuantos_kilos [] _ = 0
cuantos_kilos (p : ps) tipo = kilos_de p tipo + cuantos_kilos ps tipo
{-
ghci> cuantos_kilos [PaqueteNormal ConPalo 3,PaquetePremium SinPalo 5 Organica] SinPalo
5
ghci> cuantos_kilos [PaqueteNormal SinPalo 3,PaquetePremium SinPalo 5 Organica] SinPalo
8
ghci>                                                                                                                                 
-}

--2.
--a) definir tipos
data StockPaquetes = NoHayPaquetes | AgregarPaquete Paquete StockPaquetes deriving Show



hay_organica_de_5kg :: StockPaquetes -> Bool
hay_organica_de_5kg NoHayPaquetes = False
hay_organica_de_5kg (AgregarPaquete (PaquetePremium _ 5 Organica) s) = True
hay_organica_de_5kg (AgregarPaquete _ s) = hay_organica_de_5kg s
          
{-
ghci> hay_organica_de_5kg (AgregarPaquete (PaqueteNormal ConPalo 3) (AgregarPaquete (PaqueteNormal SinPalo 7) NoHayPaquetes))
False
ghci> hay_organica_de_5kg (AgregarPaquete (PaqueteNormal ConPalo 3) (AgregarPaquete (PaqueteNormal SinPalo 7) (AgregarPaquete (PaquetePremium ConPalo 5 Organica ) NoHayPaquetes)))
True
ghci> hay_organica_de_5kg (AgregarPaquete (PaqueteNormal ConPalo 3) (AgregarPaquete (PaqueteNormal SinPalo 7) (AgregarPaquete (PaquetePremium ConPalo 4 Organica ) NoHayPaquetes)))
False
ghci> hay_organica_de_5kg (AgregarPaquete (PaqueteNormal ConPalo 3) (AgregarPaquete (PaqueteNormal SinPalo 7) (AgregarPaquete (PaquetePremium ConPalo 5 Agr ) NoHayPaquetes)))
AgregarPaquete  Agroecologica
ghci> hay_organica_de_5kg (AgregarPaquete (PaqueteNormal ConPalo 3) (AgregarPaquete (PaqueteNormal SinPalo 7) (AgregarPaquete (PaquetePremium ConPalo 5 Agroecologica  ) NoHayPaquetes)))
False
ghci>
-}


--3. para b+

vender_cantidad::[Paquete]->TipoYerba->Int->Maybe[Paquete]
vender_cantidad [] tipoY cant = Nothing
vender_cantidad (p:ps) tipoY cant = 















