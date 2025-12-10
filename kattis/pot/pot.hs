readLines = (tail . lines)

mapTuple f (a,b) = (f a, f b)
splitPow x = (uncurry (^)) (mapTuple (read::String->Int) (init x, [last x]))
solve x = sum (map splitPow x)

main = interact(show . solve . readLines)
