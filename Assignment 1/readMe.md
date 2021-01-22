CECS 342-07 Spring 2021
Assignment 1
Homework 1
1. Browse the Haskell website: https://www.haskell.org
2. Read (at least the first two chapters of) “Learn You a Haskell for Great Good!”:
http://learnyouahaskell.com/chapters
Lab Assignment 1
1. Remember the sorting algorithms quick sort (Tony Hoare, 1959) and merge sort (John von
Neumann, 1945).
2. Write each sorting algorithm in C and in Haskell by implementing the following functions:
void qsort2(int *a, int n); // quick sort array a with n elements in place in C
void msort(int *a, int n); // merge sort array a with n elements in place in C
qsort :: Ord a => [a] -> [a] -- quick sort a list in Haskell
msort :: Ord a => [a] -> [a] -- merge sort a list in Haskell
3. Write a brief comment for every line of your code explaining what it does.
4. In a separate text file write a few sentences explaining how and why the C and Haskell
implementations of the same algorithms differ.
5. Write a simple main function (one in C and one in Haskell) to test your sort functions with the
input sequence 4, 65, 2, -31, 0, 99, 2, 83, 287, 1 and print the result to the console.
Deliverable
1. You can work on this assignment in a group of up to 5 students.
2. At the due date you will take a brief quiz to test your understanding of the assignment.
3. During the lab session on the due date each group will do
1. A brief demonstration of the running applications.
2. A presentation explaining the source code.
3. A brief discussion about the differences between C and Haskell.
4. Due date: Tuesday 9 February 2021 at the beginning of lecture.
