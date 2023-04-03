apellidos :: [(String, String, Int)] -> [String]

apellidos []=[]
apellidos ((x,y,z):xs) = y:apellidos xs   