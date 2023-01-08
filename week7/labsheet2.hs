import Data.Char
import Data.List

inRange :: Int -> Int -> [Int] -> [Int]
inRange x y list | null list = []
                 | head list >= x && head list <= y = head list: inRange x y (tail list)
                 | otherwise = inRange x y (tail list)

countPositives :: [Int] -> Int
countPositives list | null list = 0
                    | head list > 0 = 1 + countPositives (tail list)
                    | otherwise = countPositives (tail list)

capitalised :: String -> String
capitalised str | null str = ""
                | length str == 1 = toUpper (str!!0) : ""
                | otherwise =  capitalised (init str) ++ [toLower (last str)]

allLower :: String -> String
allLower str | null str = ""
             | otherwise = toLower(head str) : allLower (tail str)

title :: [String] -> [String]
title strlist | null strlist = []
              | length strlist == 1 = capitalised (strlist !! 0 ) : []
              | length (last strlist) < 4 = title (init strlist) ++ [allLower (last strlist)]
              | otherwise = title (init strlist) ++ [capitalised (last strlist)]

isort :: Ord a => [a] -> [a]
isort list | null list = []
           | length list == 1 = list
           | otherwise = insert (head list) (isort(tail list))

merge :: Ord a => [a] -> [a] -> [a]
merge list1 list2 | null list1 = list2
                  | null list2 = list1
                  | (head list1) < (head list2) = (head list1) : merge (tail list1) list2
                  | (head list1) > (head list2) = (head list2) : merge list1 (tail list2)

rotor :: Int -> String -> String
rotor x str | x < 0 || x >= (length str) = "Error"
            | otherwise = drop x str ++ take x str

makeKey :: Int -> [(Char, Char)]
makeKey x = zip "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (rotor x "ABCDEFGHIJKLMNOPQRSTUVWXYZ")

lookUp :: Char -> [(Char, Char)] -> Char
lookUp char charlist | null charlist = char
                     | char == (fst(head charlist)) = snd(head charlist)
                     | otherwise = lookUp char (tail charlist)

encipher :: Int -> Char -> Char
encipher x char = lookUp char (makeKey x)

normalise :: String -> String
normalise str | null str = ""
              | (head str) `elem` ['A'..'Z'] = (head str) : normalise (tail str)
              | (head str) `elem` ['a'..'z'] = toUpper(head str) : normalise (tail str)
              | (head str) `elem` ['0'..'9'] = (head str) : normalise (tail str)
              | otherwise = normalise(tail str)

encipherStr :: Int -> String -> String
encipherStr x str | null str = ""
                  | otherwise = encipher x (head(normalise str)): encipherStr x (tail(normalise str))

decipherStr :: String -> [String]
decipherStr str = [encipherStr x str| x<-[0..25]]