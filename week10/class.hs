import Data.List
import Data.Char
import Data.Char(digitToInt)

evalRPN :: (Num a, Read a) => String -> a
evalRPN str = head (foldl procStack [ ] (words str))

procStack :: (Num a, Read a) => [a] -> String -> [a]
procStack (x : y : ys) "*" = (y*x) : ys
procStack (x : y : ys) "+" = (y+x) : ys
procStack (x : y : ys) "-" = (y-x) : ys
procStack xs numString = read numString : xs

uniform :: [Int] -> Bool
uniform [ ] = True
uniform xs = all (== head xs) (tail xs)