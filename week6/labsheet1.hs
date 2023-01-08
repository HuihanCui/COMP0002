import Data.Char

square :: Int -> Int
square x = x * x

pyth :: Int -> Int -> Int
pyth x y = square x + square y

isTriple :: Int -> Int -> Int -> Bool
isTriple x y z = pyth x y == square z

isTripleAny :: Int -> Int -> Int -> Bool
isTripleAny x y z = pyth x y == square z || pyth y z == square x || pyth x z == square y

isTripleMore :: Int -> Int -> Int -> Bool
isTripleMore x y z = isTriple x y z || isTriple y z x || isTriple x z y

halfEvens :: [Int] -> [Int]
halfEvens list = [if x `mod` 2 ==0 then x `div` 2 else x | x<- list]

inRange :: Int -> Int -> [Int] -> [Int]
inRange start end list = [x |x<-list, x `elem` [start .. end]]

countPositives :: [Int] -> Int
countPositives list = sum[1 | x<-list, x>0]

capitalize :: String -> String
capitalize str = toUpper (str!!0) : tail[toLower x | x<-str]

allLower :: String -> String
allLower str = [toLower x | x<-str]

title :: [String] -> [String]
title strlist =  if length strlist == 0 then ["None"] else capitalize (strlist !! 0) : tail[if length str < 4 then allLower str else capitalize str | str <- strlist ]