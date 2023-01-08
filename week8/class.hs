foldr111 :: (a -> a -> a) -> [a] -> a
foldr111 f [x] = x
foldr111 f (x:xs) = f x (foldr111 f xs)