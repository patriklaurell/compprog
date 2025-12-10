import Data.List

toInt = map (read::String->Int)
unique = reverse . nub . reverse
solve = length . unique . (map ((flip mod) 42)) . toInt

main = interact(show . solve . lines)
