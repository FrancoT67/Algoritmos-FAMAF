 ```
# Proyecto 1

## Introducción

Este proyecto contiene los ejercicios del Proyecto 1 de Algoritmos y Estructuras de Datos I de FAMAF.

## Ejercicios

### 1. Funciones básicas

**a)** `esCero :: Int -> Bool`

Esta función verifica si un entero es igual a 0.

```haskell
esCero :: Int -> Bool
esCero x = (x == 0)
```

**b)** `esPositivo :: Int -> Bool`

Esta función verifica si un entero es estrictamente mayor a 0.

```haskell
esPositivo :: Int -> Bool
esPositivo x = (x > 0)
```

**c)** `esVocal :: Char -> Bool`

Esta función verifica si un caracter es una vocal en minúscula.

```haskell
esVocal :: Char -> Bool
esVocal y = y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u'
```

**d)** `valorAbsoluto :: Int -> Int`

Esta función devuelve el valor absoluto de un entero ingresado.

```haskell
valorAbsoluto :: Int -> Int
valorAbsoluto n | n >= 0 = n | n < 0 = n * (-1)
```

### 2. Funciones recursivas

**a)** `paratodo :: [Bool] -> Bool`

Esta función verifica que todos los elementos de una lista sean True.

```haskell
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x : xs)
  | x == True = paraTodo xs
  | x /= True = False
```

**b)** `sumatoria :: [Int] -> Int`

Esta función calcula la suma de todos los elementos de una lista de enteros.

```haskell
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs
```

**c)** `productoria :: [Int] -> Int`

Esta función calcula el producto de todos los elementos de la lista de enteros.

```haskell
productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria (xs)
```

