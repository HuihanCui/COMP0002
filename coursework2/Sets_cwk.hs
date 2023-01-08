module Coursework where

{-
  Your task is to design a datatype that represents the mathematical concept of a (finite) set of elements (of the same type).
  We have provided you with an interface (do not change this!) but you will need to design the datatype and also 
  support the required functions over sets.
  Any functions you write should maintain the following invariant: no duplication of set elements.

  There are lots of different ways to implement a set. The easiest is to use a list
  (as in the example below). Alternatively, one could use an algebraic data type, or 
  wrap a binary search tree.
  Extra marks will be awarded for efficient implementations if appropriate.

  You are NOT allowed to import anything from the standard library or other libraries.
  Your edit of this file should be completely self-contained.

  DO NOT change the type signatures of the functions below: if you do,
  we will not be able to test them and you will get 0% for that part. While sets are unordered collections,
  we have included the Ord constraint on most signatures: this is to make testing easier.

  You may write as many auxiliary functions as you need. Please include everything in this file.
-}

{-
   PART 1.
   You need to define a Set datatype. Below is an example which uses lists internally.
   It is here as a guide, but also to stop ghci complaining when you load the file.
   Free free to change it.
-}

-- you may change this to your own data type
newtype Set a = Set { unSet :: [a] } deriving Show

{-
   PART 2.
   If you do nothing else, at least get the following two functions working. They
   are required for testing purposes.
-}

-- toList {2,1,4,3} => [1,2,3,4]
-- the output must be sorted.
toList :: Ord a => Set a -> [a]
toList set = quicksort (unSet set)

-- sort function for a list
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort [a | a <- xs, a <= x] ++ [x] ++ quicksort [a | a <- xs, a > x]

-- fromList [2,1,1,4,5] => {2,1,4,5}
fromList :: Ord a => [a] -> Set a
fromList list = Set (noRepeat list)

-- remove duplicate elements in a list
noRepeat :: Ord a => [a] -> [a]
noRepeat [] = []
noRepeat list | (last list) `elem` (init list) = noRepeat (init list)
              | otherwise = noRepeat (init list) ++ [(last list)]

{-
   PART 3.
   Your Set should contain the following functions.
   DO NOT CHANGE THE TYPE SIGNATURES.
-}

-- test if two sets have the same elements.
instance (Ord a) => Eq (Set a) where
  s1 == s2 = (length [ x | x <- (unSet s1), x `elem` (unSet s2)] == length (unSet s1)) && (length (unSet s1) == length (unSet s2))


-- the empty set
empty :: Set a
empty = Set []


-- Set with one element
singleton :: a -> Set a
singleton a = Set [a]


-- insert an element of type a into a Set
-- make sure there are no duplicates!
insert :: (Ord a) => a -> Set a -> Set a
insert num set | num `elem` (unSet set) = set
               | otherwise = Set ((unSet set) ++ [num])

-- join two Sets together
-- be careful not to introduce duplicates.
union :: (Ord a) => Set a -> Set a -> Set a
union set1 set2 = Set ([ x | x <- (unSet set1), (x `elem` (unSet set2)) == False] ++ (unSet set2))


-- return the common elements between two Sets
intersection :: (Ord a) => Set a -> Set a -> Set a
intersection set1 set2 = Set [x | x <- (unSet set1), x `elem` (unSet set2)]


-- all the elements in Set A *not* in Set B,
-- {1,2,3,4} `difference` {3,4} => {1,2}
-- {} `difference` {0} => {}
difference :: (Ord a) => Set a -> Set a -> Set a
difference set1 set2 = Set [x | x <- (unSet set1), (x `elem` (unSet set2)) == False]


-- is element *a* in the Set?
member :: (Ord a) => a -> Set a -> Bool
member num set = num `elem` (unSet set)


-- how many elements are there in the Set?
cardinality :: Set a -> Int
cardinality set = length (unSet set)

-- map function for a set
-- the function taken as an argument is applied to each element in a set
setmap :: (Ord b) => (a -> b) -> Set a -> Set b
setmap f set = Set ([f x | x <- (unSet set)])

-- foldr function for a set
setfoldr :: (a -> b -> b) -> Set a -> b -> b
setfoldr f set num = foldr f num (unSet set)


-- powerset of a set
-- powerset {1,2} => { {}, {1}, {2}, {1,2} }
powerSet :: Set a -> Set (Set a)
powerSet set = Set ([Set x | x <- subsetlist (cardinality set) (unSet set)])

-- find all the sublists in a list
subsetlist :: Int -> [a] -> [[a]]
subsetlist 0 list = [[]]
subsetlist 1 list = [[], list]
subsetlist num list =  [x ++ y | x <- [[],[(head list)]], y <- (subsetlist (num-1) (tail list))]


-- cartesian product of two sets
cartesian :: Set a -> Set b -> Set (a, b)
cartesian set1 set2 = Set [(x,y) | x <- (unSet set1), y <- (unSet set2)]


-- partition the set into two sets, with
-- all elements that satisfy the predicate on the left,
-- and the rest on the right
partition :: (a -> Bool) -> Set a -> (Set a, Set a)
partition f set = (Set (filter f (unSet set)), Set (filter condition (unSet set)))
                  where condition x = not (f x)



{-
   On Marking:
   Be careful! This coursework will be marked using QuickCheck, against Haskell's own
   Data.Set implementation. Each function will be tested for multiple properties.
   Even one failing test means 0 marks for that function.

   Marks will be lost for too much similarity to the Data.Set implementation.

   Pass: creating the Set type and implementing toList and fromList is enough for a
   passing mark of 40%.

-}
