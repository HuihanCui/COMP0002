data Shape = Circle Float | Rect Float Float deriving Show

square :: Float -> Shape
square n = Rect n n

area :: Shape -> Float
area (Circle r) = pi * r^2 
area (Rect x y) = x * y

data Guess a = Naa | Is a deriving Show

safeDiv :: Int -> Int -> Guess Int
safeDiv _ 0 = Naa
safeDiv m n = Is (m `div` n)

data Student = First | Second | Third | Fourth deriving (Show, Eq, Ord)

data Expr = Val Int 
 | Add Expr Expr 
 | Mul Expr Expr deriving Show

size :: Expr -> Int 
size (Val n) = 1
size (Add x y) = size x + size y
size (Mul x y) = size x + size y

eval :: Expr -> Int 
eval (Val n) = n
eval (Add x y) = eval x + eval y
eval (Mul x y) = eval x * eval y

data Q a = Q [a] deriving (Eq, Show)
empty :: Q a -- an empty queue
add :: a -> Q a -> Q a -- add element at back
remove :: Q a -> Q a -- remove element from front
front :: Q a -> a -- inspect front element
isEmpty :: Q a -> Bool 

empty = Q [ ]
add x (Q xs) = Q (xs ++ [x])
remove (Q (x : xs)) = Q xs
front (Q (x : xs)) = x
isEmpty (Q xs) = null xs
