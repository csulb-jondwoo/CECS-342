-- Function definiton for qSort
-- Of 'a' being a member of the 'Ord' typeclass, qSort takes in a list with type 'a' elements and returns a list with type 'a' elements
qSort :: (Ord a) => [a] -> [a]
-- our exit condition to our recursive call being if list is empty, return an empty list
qSort [] = []  
-- pattern matching to take out the head of the list (first element of the list)
-- (i.e. 'x' is the first element of the list 'xs')
qSort (x:xs) =   
    -- defining a variable to hold the left half of list relative to the head (values smaller than that of the head)
    -- qSort the list resulting from a list comprehension of values from list 'xs' that are less than or equal to 'x'
    -- get every value less than x, see if it's less than the first element, return a if true?? 
    let smallerSorted = qSort [a | a <- xs, a <= x]  

    -- defining a variable to hold the right half of list relative to the head (values smaller than that of the head)
    -- qSort the list resulting from a list comprehension of values from list 'xs' that are greater than 'x'
        biggerSorted = qSort [a | a <- xs, a > x]  
    
    -- recursive function call.
    -- append smaller values to left and bigger values to right of head
    in  smallerSorted ++ [x] ++ biggerSorted






-- Function definition of merge sort
-- Of 'a' being a member of the 'Ord' typeclass, mSort takes in a list with type 'a' elements and returns a list with type 'a' elements
mSort :: Ord a => [a] -> [a]
-- exit conditions for recursive call
-- if list is empty, return empty list
mSort []  = []
-- if list has only one value, return list with that value
mSort [x] = [x]

-- recursively merge list ys with list zs where ys is the left half and zs is the right half of xs
mSort xs  =
  merge (mSort ys) (mSort zs)
  -- get ys and zs values from partitioning xs
  where (ys, zs) = partition xs

-- funtion definition for merging
-- Of 'a' being a member of the 'Ord' typeclass, merge takes in two lists with type 'a' elements and returns a list with type 'a' elements
merge :: Ord a => [a] -> [a] -> [a]
-- exit conditions for recursive call
-- if merging two empty lists, return with one empty list
merge [] [] = []
-- if merging one list with an empty list, return that list
merge xs [] = xs
-- if merging empty list with one list, return that list
merge [] ys = ys
-- merge the head of list xs with head of list ys
merge (x:xs) (y:ys)
-- guard conditions
  -- if x < y, append the output of merging xs with head of ys (head of right sublist) to x
  | x < y     = x : merge xs (y:ys)
  -- else append output of merging head of xs with ys (head of left sublist) to y
  | otherwise = y : merge (x:xs) ys

-- function definiton for partition
-- Of 'a' being a member of the 'Ord' typeclass, partition takes in a list with type 'a' elements and returns a tuple pair of lists with type 'a' elements
partition :: Ord a => [a] -> ([a], [a])
-- split the list xs at mid, where mid is the length of xs div by 2
partition xs =
  splitAt mid xs
  where mid = length xs `div` 2


-- Main will run the requested functions when run is hit. 
-- Main expects an IO type 
main =  do
        let x =  foldr (const (1+)) 0 [2, 31, 1]
        print x
        --Assigning the result of qSort to variable q 
        let q = qSort [4, 65, 2, -31, 0, 99, 2, 83, 287, 1]
        -- Display q in the console 
        print q
        
        --Assigning the result of the mSort to variable m 
        let m = mSort [4, 65, 2, -31, 0, 99, 2, 83, 287, 1]
        -- Display q in the console 
        print m
