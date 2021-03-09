#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Points to my_heap for deallocation purposes
void* heapPtr;

//1. Define struct to represent allocation block
struct Block {
  int block_size;
  struct Block *next_block;
};

// //2. define size of Block
const int OVERHEAD_SIZE = sizeof(struct Block);

// //3. define size of void ptr
const int VOID_PTR_SIZE = sizeof(void *);

// //4. pointer to first free block on free list
struct Block *free_head;

// //5. initializes memory on the heap of given size
void my_initialize_heap(int size) {
  heapPtr = malloc(size); 
  free_head = heapPtr;
  free_head->block_size = size - OVERHEAD_SIZE; //Store the size of data section for this block
  free_head->next_block = NULL;
}

// Allocates minimum required memory size for data
int calculateMinBlockSizeReq(size) {
  int remainder = size % VOID_PTR_SIZE;
  if (remainder) {
    // round up to next closest multiple
    size += VOID_PTR_SIZE - remainder;
    return size;
  } 

  // is multiple
  return size;
}

// //6. allocates block of memory + return pointer of block for req
void* my_malloc(int size) {
	struct Block *new_block; // temp ptr to new block being made from split
	
  // walk the free list checking for a block to fit the alloc request until curr_block is NULL
  while(free_head) {
      // check if the block size is a multiple of void*
      // accounts for each block being minimum of VOID_PTR_SIZE (C.3)
      int allocation_size = calculateMinBlockSizeReq(size);
      if (free_head->block_size >= allocation_size) {
        // has enough size
        // decide whether to split
        // if you split, does excess_mem have more enough for allocation_size and overhead?
        int excess_mem = free_head->block_size - allocation_size - OVERHEAD_SIZE;
        if (excess_mem >= VOID_PTR_SIZE) {
          // split
          // find the byte location of new block and return data
          new_block = (struct Block*)((char*)(free_head + 1) + excess_mem);
          new_block->block_size = allocation_size;
          new_block->next_block = NULL;
          free_head->block_size = excess_mem;

          return ++new_block;
        } else {
          // can not split
          // use current block
          // redirect pointers
          new_block = free_head;
          free_head = free_head->next_block;
          new_block->next_block = NULL;
          new_block->block_size = allocation_size;

          return ++new_block;
        }
      } else {
        // not enough for allocation_size
        free_head = free_head->next_block;
      }
  }
  return 0; //No free block found
};

void my_free(void *data){
  struct Block *free_block = (struct Block*)data - 1;
  free_block->next_block = free_head;
  free_head = free_block;
};

void test() {
  //#1
  printf("Test 1\n");
  printf("Allocating first int...\n");
  int* a1 = my_malloc(sizeof(int));
  printf("Address of first int: %p\n", a1);

  printf("Freeing first int...\n");
  my_free(a1);

  printf("Allocating second int...\n");
  int* a2 = my_malloc(sizeof(int));
  printf("Address of second int: %p\n", a2);
  printf("\n");


  // #2
  printf("Test 2\n");
  printf("Allocating first int...\n");
  int* b1 = my_malloc(sizeof(int));
  printf("Address of first int: %p\n", b1);

  printf("Allocating second int...\n");
  int* b2 = my_malloc(sizeof(int));
  printf("Address of first int: %p\n", b2);

  printf("overhead + void ptr Size: %d\n", OVERHEAD_SIZE + VOID_PTR_SIZE);
  printf("Difference between first int address and second int address %ld\n", (char*)b1 - (char*)b2);
  printf("\n");

  // #3
  printf("Test 3\n");
  printf("Allocating first int...\n");
  int* c1 = my_malloc(sizeof(int));
  printf("Address of first int: %p\n", c1);

  printf("Allocating second int...\n");
  int* c2 = my_malloc(sizeof(int));
  printf("Address of second int: %p\n", c2);

  printf("Allocating third int...\n");
  int* c3 = my_malloc(sizeof(int));
  printf("Address of third int: %p\n", c3);

  printf("Freeing second int...\n");
  my_free(c2);

  printf("Allocating double...\n");
  int* c4 = my_malloc(sizeof(double));
  printf("Address of double: %p\n", c4);

  printf("Address of second int: %p\n", c2);
  printf("\n");

  // #4
  printf("Test 4\n");
  printf("Allocating char...\n");
  int* d1 = my_malloc(sizeof(char));

  printf("Allocating int...\n");
  int* d2 = my_malloc(sizeof(int));

  printf("Address of char: %p\n", d1);
  printf("Address of int: %p\n", d2);
  
  printf("overhead + void ptr Size: %d\n", OVERHEAD_SIZE + VOID_PTR_SIZE);
  printf("Difference between char address and int address %ld\n", (char*)d1 - (char*)d2);
  printf("\n");

  
  // #5
  printf("Test 5\n");
  printf("Allocating for one int value...\n");
  int* e1 = my_malloc(sizeof(int));

  printf("Allocating space for a 100-element int array...\n");
  int* e2 = my_malloc(sizeof(int) * 100);

  printf("Address of 100-element int array: %p\n", e1);
  printf("Address of int:  %p\n", e2);
  
  printf("offset size: %ld \n", 100 * sizeof(int) + OVERHEAD_SIZE);
  printf("Difference between int array address and int address %ld\n", (char*)e1 - (char*)e2);

  printf("Freeing the array...\n");
  my_free(e2);
  printf("Address of int:  %p\n", e2);
  printf("\n"); 
}

void get_sigma() {
  printf("initialize array size: ");
  int size, arr_sum = 0;
  double mean, summation, sigma= 0;
  scanf("%d", &size);

  // allocate user defined array size
  int* arr_ptr = my_malloc(sizeof(int) * size);

  // populate the array with user input
  for (int i = 0; i < size; i++) 
  {
    printf("\nPopulate the list: ");
    scanf("%d", &arr_ptr[i]);
  }
  
  // sum up the total of user input
  for (int i = 0; i < size; i++) 
  {
    arr_sum += arr_ptr[i];
  }

  // calculate mean
  mean = arr_sum / size;
  
  // main formula
  for (int i = 0; i < size; i++) 
  {
    summation += pow(arr_ptr[i] - mean, 2);
  }

  sigma = sqrt(summation / size);
  printf("sigma: %f\n", sigma);
  
}

int main(void) {
  my_initialize_heap(1000);
  test();
  get_sigma();
  
  //Frees the heap memory
  free(heapPtr);
  
  return 0;
}
