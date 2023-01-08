squares :: [Int] -> [Int]
squares ns = [x * x | x <- ns]

sums :: [Int] -> Int
sums ns = sum (squares ns)

greater :: [Int] -> Bool
greater ns = foldr (&&) True (map (>0) ns)

min' :: (Ord a) => (Int -> a) -> Int -> a
min' f n = foldr min (f 0) [(f x) | x <- [0..n]]

equal :: (Eq a) => (Int -> a) -> Int -> Bool
equal f n = length (filter (== (f 0)) [(f x) | x <- [0..n]]) == n+1

greater2 :: (Int -> Int) -> Int -> [Bool]
greater2 f n = map (>0) [(f x) | x <- [0..n]]

increasing :: (Ord a) => (Int -> a) -> Int -> Bool
increasing f 0 = True
increasing f n = ((f n) > (f (n-1))) && increasing f (n-1)

twice :: (a -> a) -> a -> a
twice f x = f (f x)

iter :: Int -> (a -> a) -> a -> a
iter 0 f x = x
iter n f x = iter (n-1) f (f x)

exponential :: (Num a) => Int -> a
exponential 0 = 1
exponential n =  iter (n-1) double 2
            where double x = x * 2

data Rhtype = Pos | Neg deriving (Show, Eq)
data ABOtype = A | B | AB | O deriving (Show, Eq)
data Bloodtype = Type ABOtype Rhtype deriving (Show, Eq)

showRh :: Bloodtype -> Rhtype
showRh (Type _ x) = x

showABO :: Bloodtype -> ABOtype
showABO (Type x _) = x

showBloodtype :: Bloodtype -> Bloodtype
showBloodtype x = x

canDonateTo :: Bloodtype -> Bloodtype -> Bool
canDonateTo (Type x _) (Type y _) | (x == O) || ((x == AB) && (y == AB)) || ((x == A) && ((y == A) || (y == AB))) || ((x == B) && ((y == B) || (y == AB)))= True
                                  | otherwise = False

data Answer = Yes | No | Unknown deriving Show

wonky :: Answer -> Answer
wonky Yes = No
wonky No = Unknown
wonky Unknown = Yes

data Shape = Ellipse Float Float | Rect Float Float deriving Show

area :: Shape -> Float
area (Ellipse a b) = pi * a * b
area (Rect x y) = x * y

circle :: Float -> Float -> Shape
circle a b = Ellipse a b