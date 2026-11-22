
keepOdd :: [Int] -> [Int]
keepOdd xs = map snd (filter (\(i, x) -> odd i) (zip [1..] xs))

keepEven :: [Int] -> [Int]
keepEven xs = map snd (filter (\(i, x) -> even i) (zip [1..] xs))

skipThird :: [Int] -> [Int]
skipThird xs = map snd (filter (\(i, x) -> i `mod` 3 /= 0) (zip [1..] xs))

solve :: [[Int] -> [Int]] -> [Int] -> Int
solve _ [x] = x
solve (move:moves) xs = solve moves (move xs)

main :: IO ()
main = do
    n <- readLn :: IO Int
    print (solve (cycle [keepOdd, keepEven, skipThird]) [1..n])
