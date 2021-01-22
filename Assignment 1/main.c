#include <stdio.h>

// helper function to swap pointer values
void swap(int* p1, int* p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

/* 
Function used to correctly position the pivot element in the array, 
making left half of the array less than the pivot and the right half greater than the pivot 
*/
int* partition(int* low, int* high)
{
  // pivot = value at last idx
  int pivot = *high;

  // i points to same address as low (i.e. same idx)
  int* i = low;

  // j points to same addreess as high (i.e. same idx)
  int* j = high;

  // repeat until i crosses j
  while (i < j)
  {
    /* 
    incr i until it hits the first element that is greater than the value of the pivot or until i is at end of array

    NOTE  - not a do-while because first element CAN be greater than the pivot
    */
    while (*i <= pivot && i < high)
    {
      i++;
    }

    /* 
    decr j until it hits the first element that is less than the value of the pivot
    
    NOTE - do-while because we don't need to check our pivot against our pivot. we want to check starting from first value left of pivot 
    (since the pivot is the last element of the array)
    */
    do
    {
      j--;
    } while (*j > pivot);

    // only swap if i has not crossed j
    if (i < j)
    {
      // at this point, swap the values at address i and address j
      swap(i, j);
    }
  }

  // at this point, i has crossed j so swap value at high with value at i to correctly position the pivot
  swap(high, i);
  
  return i;
}

/* 
  Quicksort function definition 

  NOTE - When passing in an array (such as test_array), the pointer points to the first element of the array,
  which is why we are able to access the first element's address directly with an int pointer.
*/
void qsort2(int* arr, int size)
{
  /* 
  compare address of first value with address of the last value
  (effectively comparing first idx and last idx)
  */
  if (arr < &arr[size - 1])
  {
    // assign pointer to point to address of the correctly positioned element
    int* p_idx = partition(&arr[0], &arr[size - 1]);

    // get size of left array by subtracting p_idx address to the address of the first element
    int left_array_size = p_idx - &arr[0];

    // get size of right array by subtracting address of last element with address of p_idx
    int right_array_size = &arr[size - 1] - p_idx;
   
    // sort left array
    qsort2(&arr[0], left_array_size);

    // sort right array
    qsort2(&arr[left_array_size + 1], right_array_size);
  }
}


// void mSort(int *a, int n)
// {
//   int chunk = 1; //Tracks how many sorted elements are group together
  
// }

// Function to format the printing of an array
void printArray(int* arr, char* sort_type)
{
  printf("%s sorted array\n", sort_type);
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }
}


// Main function to initiate the program
int main(void) {
  // initialize test array
  int test_array[] = {4, 65, 2, -31, 0, 99, 2, 83, 287, 1};

  /* 
  Function call to quick sort, passing in the array and size of array.

  NOTE - The trick to writing out this specific qs algorithm was to treat addresses of pointer values as indices.
  Knowing that an index of an element in an array represents where the location of that value is in memory, 
  we can apply regular value and index searches using pointers and addresses instead.
  */
  qsort2(test_array, 10);

  // function call to print the sorted array
  printArray(test_array, "quick");
}
