{-# LANGUAGE NPlusKPatterns #-}

esPositivo :: Int -> Bool
esPositivo x = x >= 0

{-
 esPositivo (-2) ---> False
 esPositivo 2 ---> True
-}