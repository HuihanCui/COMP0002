import Data.Char
import Data.List

mult :: (Num a) => [a] -> a
mult list = foldr (*) 1 list

posList :: [Int] -> [Int]
posList list = filter (>0) list

trueList :: [Bool] -> Bool
trueList list = foldr (&&) True list

evenList :: [Int] -> Bool
evenList list = foldr (&&) True (map even list)

maxList :: (Ord a) => [a] -> a 
maxList list = foldr max (head list) list

inRange :: Int -> Int -> [Int] -> [Int]
inRange start end list = filter f list
                         where f x = (x >= start) && (x <= end)

countPositives :: [Int] -> Int
countPositives list = length (filter (>0) list)

myLength :: [a] -> Int
myLength list = foldr (+) 0 (map p list)
                where p x = 1

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f list = foldr (:) [] ((f (head list)) : (myMap f (tail list)))

myLength' :: [a] -> Int
myLength' list = foldr (+) 0 [1 | x <- list] 