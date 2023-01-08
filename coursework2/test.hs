data Tree a = Null | Leaf a | Node (Tree a) a (Tree a)  deriving (Show, Eq, Ord)

compare' a b = a > b


test a b = compare' a b 

--addNode :: Tree a -> Tree a -> Tree a
addNode Null x = x
addNode (Leaf x) (Leaf y) = if (compare' (Leaf x) (Leaf y)) == True then Node (Leaf y) x Null else Node Null x (Leaf y)
addNode (Node left mid right) new = if (compare' (Leaf mid) new) == True then addNode left new else addNode right new


listtest :: [a] -> Tree a
listtest test = addNode Null (Leaf (head test))














