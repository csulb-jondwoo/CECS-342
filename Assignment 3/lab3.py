class Person:
    def __init__ (self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return str(self.name) + " " + str(self.age)

def main():
    peopleToSort = [
      Person("Hal", 20), 
      Person("Susann", 31),
      Person("Dwight", 19),
      Person("Kassandra", 21), 
      Person("Lawrence", 25),
      Person("Cindy", 22), 
      Person("Cory", 27), 
      Person("Mac", 19),
      Person("Romana", 27), 
      Person("Doretha", 32),
      Person("Danna", 20), 
      Person("Zara", 23), 
      Person("Rosalyn", 26), 
      Person("Risa", 24), 
      Person("Benny", 28),
      Person("Juan", 33), 
      Person ("Natalie", 25)
      ]

    # Sorting numbers in ascending order 
    numbersToSort = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25] #array
    print("NUMBERS TO SORT:")
    for i in numbersToSort:
      print(i)
    print("\n")

    print("NUMBERS AFTER SORTING:")
    numbersToSort.sort()
    for i in numbersToSort:
      print(i)
    print("\n")

    # Sorting People
    print("PEOPLE TO SORT:")
    for i in peopleToSort:
      print(i)
    print("\n")

    # https://stackoverflow.com/a/13669265
    print("PEOPLE AFTER SORTING BY NAME:")
    peopleToSort.sort(key=lambda Person: Person.name)
    for i in peopleToSort:
      print(i)
    print("\n")

    # https://stackoverflow.com/a/403426
    print("PEOPLE AFTER SORTING BY AGE:")
    peopleToSort.sort(key=lambda Person: Person.age, reverse=True)
    for i in peopleToSort:
      print(i)
    print("\n")


if __name__ == "__main__":
    main()
