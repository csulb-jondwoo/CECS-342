-- define qSorting algorithm
qSort :: (Ord a) => [a] -> [a]
qSort [] = []  
qSort (x:xs) =   
    let smallerSorted = qSort [a | a <- xs, a <= x]  
        biggerSorted = qSort [a | a <- xs, a > x]  
    in  smallerSorted ++ [x] ++ biggerSorted

-- create Person data type consisting of name and age
data Person = Person String Int deriving (Show, Eq)
name :: Person -> String
name   (Person n a) = n
age :: Person -> Int
age    (Person n a) = a 

-- Sorting order by name then age
-- instance Ord Person where
--   compare x y =
--     let
--         d = compare (name x) (name y)
--     in
--         if d == EQ then compare (age x) (age y) else d

-- Sorting order by age then name
instance Ord Person where
  compare x y =
    let
        d = compare (age y) (age x)
    in
        if d == EQ then compare (name x) (name y) else d


main =  do
        -- Test 1
        let sortNumbers = qSort [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
        print(sortNumbers)

        -- Test 2
        let sortPersonsByName = qSort [Person "Hal" 20, 
                                 Person "Susann" 31, 
                                 Person "Dwight" 19, 
                                 Person "Kassandra" 21, 
                                 Person "Lawrence" 25, 
                                 Person "Cindy" 22, 
                                 Person "Cory" 27, 
                                 Person "Mac" 19, 
                                 Person "Romana" 27, 
                                 Person "Doretha" 32, 
                                 Person "Danna" 20, 
                                 Person "Zara" 23, 
                                 Person "Rosalyn" 26, 
                                 Person "Risa" 24, 
                                 Person "Benny" 28, 
                                 Person "Juan" 33, 
                                 Person "Natalie" 25]
        print(sortPersonsByName)

        -- Test 3
        -- let sortPersonsByAge = qSort [Person "Hal" 20, 
        --                          Person "Susann" 31, 
        --                          Person "Dwight" 19, 
        --                          Person "Kassandra" 21, 
        --                          Person "Lawrence" 25, 
        --                          Person "Cindy" 22, 
        --                          Person "Cory" 27, 
        --                          Person "Mac" 19, 
        --                          Person "Romana" 27, 
        --                          Person "Doretha" 32, 
        --                          Person "Danna" 20, 
        --                          Person "Zara" 23, 
        --                          Person "Rosalyn" 26, 
        --                          Person "Risa" 24, 
        --                          Person "Benny" 28, 
        --                          Person "Juan" 33, 
        --                          Person "Natalie" 25]
        -- print(sortPersonsByAge)
