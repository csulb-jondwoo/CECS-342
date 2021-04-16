#include <iostream>
#include <string.h>

class people
{
public:
    std::string name;
    int age;

    //Constructors
    people() { name = ""; age = 0; }
    people(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    //Returns person with name in lexicographical presedence 
    bool operator<(const people& p)
    {
        int val = this->name.compare(p.name);
        if (val < 0)
            return 1;
        return 0;
    }


    //Returns person with greater age
    bool operator>(const people& p)
    {
        //if the age are the same return by name order
        if (this->age == p.age)
        {
            return (*this < p);
        }

        //Return person with greater age
        if (this->age > p.age)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //compares two people and returns 1 if they are the same, and 0 if not
    int operator==(const people& p)
    {
        if (this->age == p.age && (this->name.compare(p.name)) == 0)
        {
            return 1;
        }
        return 0;
    }
};

//use for descending
//gets the max of two values
template <class T>
T Max(T a, T b) { return ((a > b) ? a : b); }

//use for ascending
//Gets the minimum of two values
template <class T>
T Min(T a, T b) { return ((a < b) ? a : b); }

//Swaps two values
template <class T>
void swap(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//Selection sort
//Sorts array given an array of type T, size of array, and a bool which determines ordering array
  //in ascending order or descending order
  //true = ascending, false = descending
//Types must implement for <, >, and == operators
template <class T>
void mySort(T* arr, int size, bool isAscending)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int selectedI = i; //index of the selected value for swapping
        for (int j = i + 1; j < size; ++j)
        {
            T returned;

            //Get the min or max of the group
            if (isAscending)
            {
                returned = Min(arr[selectedI], arr[j]);
            }
            else
            {
                returned = Max(arr[selectedI], arr[j]);
            }

            //set new min or max
            if (returned == arr[j])
            {
                selectedI = j;
            }
        }

        //Swap the values
        if (i != selectedI) { swap(&arr[selectedI], &arr[i]); }
    }
}


int main()
{
    // Test values //
    //For test 1
    float numbers[] = { 645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25 };

    //For test 2
    people peeps1[] = { people("Hal", 20), people("Susann", 31), people("Dwight", 19), people("Kassandra", 21), 
        people("Lawrence", 25), people("Cindy", 22), people("Cory", 27), people("Mac", 19), people("Romana", 27), 
        people("Doretha", 32), people("Danna", 20), people("Zara", 23), people("Rosalyn", 26), people("Risa", 24), 
        people("Benny", 28), people("Juan", 33), people("Natalie", 25) };

    //For test 3
    people peeps2[] = { people("Hal", 20), people("Susann", 31), people("Dwight", 19), people("Kassandra", 21),
        people("Lawrence", 25), people("Cindy", 22), people("Cory", 27), people("Mac", 19), people("Romana", 27),
        people("Doretha", 32), people("Danna", 20), people("Zara", 23), people("Rosalyn", 26), people("Risa", 24),
        people("Benny", 28), people("Juan", 33), people("Natalie", 25) };

    // Sorts //
    //Sort 1: numbers ascending by numerical value
    mySort(numbers, 12, true);
    std::cout << "Sort numbers ascending by numerical value" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << numbers[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Sort 2: people alphabetically (lexicographically) by name
    mySort(peeps1, 17, true);
    std::cout << "Sort people alphabetically (lexicographically) by name" << std::endl;
    for (int i = 0; i < 17; i++)
    {
        std::cout << "Age: " << peeps1[i].age << " Name: " << peeps1[i].name << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Sort 3: people descending by age, where people of the same age should be sorted alphabetically
    mySort(peeps2, 17, false);
    std::cout << "Sort people descending by age, then alphabetically (lexicographically) by name if age is same" << std::endl;
    for (int i = 0; i < 17; i++)
    {
        std::cout << "Age: " << peeps2[i].age << " Name: " << peeps2[i].name << std::endl;
    }
    
}
