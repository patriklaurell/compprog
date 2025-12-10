import Data.List

toInt = map (read::String->Int)
mod42 = (flip mod) 42
unique = reverse . nub . reverse
solve = length . unique . (map mod42) . toInt

main = interact(show . solve . lines)
