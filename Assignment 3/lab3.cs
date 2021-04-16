using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class people {
  public string name;
  public int age;

  //constructors
  public people(){
    name = "";
    age = 0;
  }
  public people(string name, int age){
    this.name = name;
    this.age = age;
  }
}

class MainClass {
  public static void Main (string[] args) {

    // Test values //
    //For test 1
    double[] numbers = { 645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25 };

    //For test 2
    people[] peeps1 ={
			new people("Hal", 20),
			new people("Susann", 31),
			new people("Dwight", 19),
			new people("Kassandra", 21),
			new people("Lawrence", 25),
			new people("Cindy", 22),
			new people("Cory", 27),
			new people("Mac", 19),
			new people("Romana", 27),
			new people("Doretha", 32),
			new people("Danna", 20),
			new people("Zara", 23),
			new people("Rosalyn", 26),
			new people("Risa", 24),
			new people("Benny", 28),
			new people("Juan", 33),
			new people("Natalie", 25)
		};

    //Test 3
    people[] peeps2 ={
			new people("Hal", 20),
			new people("Susann", 31),
			new people("Dwight", 19),
			new people("Kassandra", 21),
			new people("Lawrence", 25),
			new people("Cindy", 22),
			new people("Cory", 27),
			new people("Mac", 19),
			new people("Romana", 27),
			new people("Doretha", 32),
			new people("Danna", 20),
			new people("Zara", 23),
			new people("Rosalyn", 26),
			new people("Risa", 24),
			new people("Benny", 28),
			new people("Juan", 33),
			new people("Natalie", 25)
		};

    List<people> peeps3 = new List<people>();
    // peeps3.Add(new people("Hal", 20));
    // peeps3.Add(new people("Susann", 31));
		// peeps3.Add(new people("Dwight", 19));
		// peeps3.Add(new people("Kassandra", 21));
		// peeps3.Add(new people("Lawrence", 25));
		// peeps3.Add(new people("Cindy", 22));
		// peeps3.Add(new people("Cory", 27));
		// peeps3.Add(new people("Mac", 19));
		// peeps3.Add(new people("Romana", 27));
		// peeps3.Add(new people("Doretha", 32));
		// peeps3.Add(new people("Danna", 20));
		// peeps3.Add(new people("Zara", 23));
		// peeps3.Add(new people("Rosalyn", 26));
		// peeps3.Add(new people("Risa", 24));
		// peeps3.Add(new people("Benny", 28));
		// peeps3.Add(new people("Juan", 33));
		// peeps3.Add(new people("Natalie", 25));
    
    //Using orderby to sort numbers
    IEnumerable<double> sortNumberAscend =
      from number in numbers
      orderby number
      select number;
       
    Console.WriteLine("Sort numbers by ascending numerical value");
    foreach (double x in sortNumberAscend){
      Console.WriteLine(x);
    }
    Console.WriteLine ("");

    //LINQ Test
    var names1 = from person in peeps1
        orderby person.name
        select person;
    
    var names2 = from person in peeps2
        orderby person.age descending 
        select person;

    // var names3 = from people in peeps3
    //     orderby people.age descending
    //     select people;

    //Making list so can use indexing

    //Sort by lexico
    Console.WriteLine("Sort people alphabetically (lexico.) by name");
    foreach (var person in names1){
      Console.WriteLine("Age: " + (person.age).ToString() + " Name: " + person.name);
    }

    Console.WriteLine("");

    foreach (var person in names2){
      peeps3.Add(person);
    }
    //Test
    // foreach (people x in peeps3){
    //   Console.WriteLine(x.name);
    // }

    //Sort by Age then Lexico with LISTS
    int i = 0;
    while (i < peeps3.Count()-1){
      if (peeps3[i].age == peeps3[i+1].age){
        int x = string.Compare(peeps3[i].name, peeps3[i+1].name);
        if (x > 0){
          var temp = peeps3[i];
          peeps3[i] = peeps3[i+1];
          peeps3[i+1] = temp;
        }
      }
      i++;
    }
    //Sort by Age then Lexico
    Console.WriteLine("Sort people descending by age");
    foreach (people x in peeps3){
      Console.WriteLine("Age: " + x.age + " Name: " + x.name);
    }
  }
}
