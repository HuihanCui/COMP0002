fac :: Int -> Int
fac 0 = 1
fac n = n * fac (n-1)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

fac1 :: IO()
fac1 = do
       putStr "Enter a number which is greater or equal than 0:"
       num <- getLine
       putStr "The factorial of this number is "
       putStrLn (show (fac (read num)))

fib1 :: IO()
fib1 = do
       putStr "Enter a number which is greater or equal than 0:"
       num <- getLine
       putStr "This term of Fibonacci sequence is "
       putStrLn (show (fib (read num)))

showBoard :: [Int] -> IO()
showBoard [] = return()
showBoard list = do
                 putStrLn(take (head list) (repeat '!'))
                 showBoard (tail list)

reduce :: [Int] -> Int -> Int -> [Int]
reduce list num amount = (take (num-1) list) ++ [(list !! (num-1)) - amount] ++ (drop num list)

test :: [Int] -> Bool
test list = (sum list) == 1

game1 :: [Int] -> IO()
game1 list = do
             putStrLn "Player 1, please enter the number of row you want to take from:"
             row <- getLine
             putStrLn "Enter the number of matches you would like to take"
             num <- getLine
             putStrLn "Board starts below: (the first row is 1)"
             showBoard(reduce list (read row) (read num))
             if (test (reduce list (read row) (read num))) then putStrLn "Player 1 is the winner" else (game2 (reduce list (read row) (read num)))

game2 :: [Int] -> IO()
game2 list = do
             putStrLn "Player 2, please enter the number of row you want to take from:"
             row <- getLine
             putStrLn "Enter the number of matches you would like to take"
             num <- getLine
             putStrLn "Board starts below: (the first row is 1)"
             showBoard(reduce list (read row) (read num))
             if (test (reduce list (read row) (read num))) then putStrLn "Player 2 is the winner" else (game1 (reduce list (read row) (read num)))

computer :: [Int] -> Int
computer list | (head list)/= 0 = 0
              | otherwise = 1 + computer (tail list)

gameAuto :: [Int] -> IO()
gameAuto list = do
                putStrLn "Player, please enter the number of row you want to take from:"
                row <- getLine
                putStrLn "Enter the number of matches you would like to take"
                num <- getLine
                putStrLn "Board starts below: (the first row is 1)"
                showBoard(reduce list (read row) (read num))
                if (test (reduce list (read row) (read num))) then putStrLn "Player is the winner" else (gameComp (reduce list (read row) (read num)))

gameComp :: [Int] -> IO()
gameComp list = do
                putStrLn "Board starts below: (the first row is 1)"
                showBoard(reduce list ((computer list)+1) 1)
                if (test (reduce list ((computer list)+1) 1)) then putStrLn "Computer is the winner" else (gameAuto (reduce list ((computer list)+1) 1))