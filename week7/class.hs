double :: Int -> Int
double x = ((\x->x*2) x)*2

double2 :: Int -> Int
double2 x = (\x -> x*2) (x*2)

f :: Int -> Int
f x = x + (\x->(x+1)*(x+1)) x

get :: [Int] -> [Int]
get list | null list = []
         | list!!0 <5 = list!!0 : get ((\(x:xs) -> xs) list)
         | otherwise = get ((\(x:xs) -> xs) list)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x-1) + fib (x-2)

sum1 :: [Int] -> Int
sum1 list | null list = 0
         | length list == 1 = head(list)
         | otherwise = head list + sum1 (tail list)

insert1 :: Int -> [Int] -> [Int]
insert1 x list | null list = [x]
               | (head list)<x = (head list) : insert1 x (tail list)
               | otherwise = [x] ++ list