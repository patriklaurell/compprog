import Data.List
import Data.List.Split

removeEmpty x =  filter (not . null) x
combs (x:xs) = (if length xs > 1 then (combs xs) else [])++[x++y | y <- xs]++[y++x | y <- xs]
unique = reverse . nub . reverse

solve = sort . unique . combs . removeEmpty . splitOneOf " \n"

main = interact(unlines . solve)
