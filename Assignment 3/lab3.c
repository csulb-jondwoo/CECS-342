#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Student {

    char name[16];
    int age;

};

int checkname; // my makeshift switch 

/* qsort struct comparision function: name,age,float */
int sortpeople(const void* a, const void* b)
{
    if (checkname == 1) {
        struct Student* student1 = (struct Student*)a;
        struct Student* student2 = (struct Student*)b;
        return strcmp(student1->name, student2->name);
    }
    else if (checkname == 0)
    {
        struct Student* age1 = (struct Student*)a;
        struct Student* age2 = (struct Student*)b;
        return age1->age > age2->age ? -1 : age1->age < age2->age;
        //we are doing age in decending order 
        //so if the first age is greater than the 2nd age then return -1
        //if not return the opposite result
    }
    else {

        return (*(const float*)a < *(const float*)b) ? -1 : *(const float*)a > * (const float*)b;

    }
    /* float comparison: returns negative if b > a
    and positive if a > b. */

}

/* Example struct array printing function */
void PrintStructArray(struct Student* array, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" Age: %d \t  Name: %s \n", array[i].age, array[i].name);

    puts("--");
}

// void print_float_array(float array[])
// {
//     // int size = (sizeof(array) / sizeof(array[0]));
//     printf(" \n");
//     for (int i = 0; i < 12; i++) {
//         printf("%s | %.2f", array[i]);

//     }


// }

/* sorting structs using qsort() example */
void createandsort(void)
{
    float floats[] = { 645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25 };

    struct Student structs[] = { {"Hal", 20} ,{"Susann", 31} ,{"Dwight", 19}, {"Kassandra", 21} ,{"Lawrence", 25} ,{"Cindy", 22}, {"Cory", 27},
                                 {"Mac", 19} ,{"Romana", 27}, {"Doretha", 32}, {"Danna", 20} ,{"Zara", 23}, {"Rosalyn", 26} ,{"Risa", 24} ,{"Benny",28},
                                 {"Juan", 33}, {"Natalie", 25} };

    printf("*** Original Float  Array *** ");
    printf("\n");
    size_t structs_len = sizeof(structs) / sizeof(struct Student); // getting the size of the struct array
    size_t floats_len = sizeof(floats) / sizeof(float); // getting the length of the float array
    checkname = 3; // setting the switch to sort floats
    printf("\n");
    for (int i = 0; i < 12; i++)
       printf("%f |", floats[i]);// printing float array
            
    //print_float_array(floats);
    printf("\n");


    qsort(floats, floats_len, sizeof(float), sortpeople);
    printf("\n");
    puts("*** Sorted Float  Array ***");
    printf("\n");
     for (int i = 0; i < 12; i++)
         printf("%f |", floats[i]); 
    printf("\n");
  //  print_float_array(floats);
    printf("\n");
    puts("*** Original Struct Array ***");
    printf("\n");
    /* print original struct array */
    PrintStructArray(structs, structs_len);

    /* sort array using qsort functions */
    checkname = 0; // setting the swtich to swort strings

    puts("*** Struct sorting (decending age) ***");
    printf("\n");
    qsort(structs, structs_len, sizeof(struct Student), sortpeople); 
    // using qsort and passing in the array, length, size of the struct and the method to sort

    /* print sorted struct array */
    PrintStructArray(structs, structs_len);

    puts("*** Struct sorting  ***");

    checkname = 1; // setting the switch to sort ints
    qsort(structs, structs_len, sizeof(struct Student), sortpeople);

    /* print sorted struct array */
    PrintStructArray(structs, structs_len);
}
int main() {
    createandsort();
    return 0;
}
