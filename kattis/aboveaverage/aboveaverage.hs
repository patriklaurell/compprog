import Data.List
import Text.Printf

avg x = realToFrac (sum x) / genericLength x
aboveavg x = map ((<) (avg x)) x
toFloats = map (read::String->Float)
formatout :: Float -> String
formatout f = (printf "%.3f" f) ++ "%"

solve = map (formatout . ((*) 100) . avg . map fromEnum . aboveavg . tail . toFloats . words)

main = interact(unlines . solve . tail . lines)
