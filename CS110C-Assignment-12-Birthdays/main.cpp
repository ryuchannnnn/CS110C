// Danny Chan
// CS110C
// 5/5/2021

/*
For this assignment, you will implement a dictionary to track the name and birthday of your friends and relatives.  Your should support the following operations:

add an entry
remove an entry
search the dictionary for the birthday for a given name
display the name and birthday of every entry in the dictionary
display everyone in the dictionary who was born in a given month

The search key is the name, and you may assume that the names are unique.

Design and implement a C++ class to represent a Person, which contains a name and a birthday at minimum.  It is up to you how to store the birthday.  Additionally, design and implement a C++ class to represent an ADT Dictionary of Person objects.  Do not use an existing library class for the dictionary, you must fully implement your own.

Searching for a person in your dictionary must be an average-case O(log n) operation; adding and removing can be O(n); and the "list everyone who was born in a given month" operation can be an O(n) operation.  With these requirements in mind, it is up to you which type of dictionary to use. 
*/

#include <iostream>
#include "Dictionary.h"
#include "Person.h"
#include <string>
using namespace std;

int main() 
{
  Dictionary D;
  int userInput;
  int bdayMonth;
  int bday;
  int bdayYear;
  string bdayName;

  cout << "1. add an entry: " << endl;
  cout << "2. remove an entry: " << endl;
  cout << "3. search the dictionary for the birthday for a given name: " << endl;
  cout << "4. display the name and birthday of every entry in the dictionary: " << endl;
  cout << "5. display everyone in the dictionary who was born in a given month: " << endl;
  cout << "6. exit" << endl; 
  do
  {
    cout << "Enter an option: " << endl;
    cin >> userInput;
    if(userInput == 1)
    {
      cout << "Enter name: " << endl;
      cin >> bdayName;
      cout << "Enter month: " << endl;
      cin >> bdayMonth;
      cout << "Enter day: " << endl;
      cin >> bday;
      cout << "Enter year: " << endl;
      cin >> bdayYear;
      D.add(Person(bdayName, bdayMonth, bday, bdayYear));
      cout << " " << endl;
    }
    else if(userInput == 2)
    {
      cout << "Enter name to remove: " << endl;
      cin >> bdayName;
      cout << "Enter month to remove: " << endl;
      cin >> bdayMonth;
      cout << "Enter day to remove: " << endl;
      cin >> bday;
      cout << "Enter year to remove: " << endl;
      cin >> bdayYear;
      D.remove(Person(bdayName, bdayMonth, bday, bdayYear));
      cout << " " << endl;
    }
    else if(userInput == 3)
    {
      cout << "Enter name of who you would like to find: " << endl;
      cin >> bdayName;
      D.givenName(bdayName);
      cout << " " << endl;
    }
    else if(userInput == 4)
    {
      cout << "Displaying all entries: " << endl; 
      D.display();
      cout << " " << endl;
    }
    else if(userInput == 5)
    {
      cout << "Enter month of who you would like to find: " << endl;
      cin >> bdayMonth;
      D.givenMonth(bdayMonth);
    }
    else if(userInput == 6)
    {
      cout << "Exiting..." << endl;
    }
  }while(userInput != 6);
}

/*
[dchan89@hills ~]$ ./a.out
1. add an entry: 
2. remove an entry: 
3. search the dictionary for the birthday for a given name: 
4. display the name and birthday of every entry in the dictionary: 
5. display everyone in the dictionary who was born in a given month: 
6. exit
Enter an option: 
1
Enter name: 
Barbara
Enter month: 
3
Enter day: 
22
Enter year: 
1992
 
Enter an option: 
1
Enter name: 
Lenox
Enter month: 
9
Enter day: 
14
Enter year: 
1994
 
Enter an option: 
1
Enter name: 
Roz
Enter month: 
1
Enter day: 
17
Enter year: 
1997
 
Enter an option: 
1
Enter name: 
Silvia
Enter month: 
2
Enter day: 
4
Enter year: 
1998
 
Enter an option: 
2
Enter name to remove: 
Roz  
Enter month to remove: 
1
Enter day to remove: 
17
Enter year to remove: 
1997
 
Enter an option: 
4
Displaying all entries: 
Barbara's birthday is on: 3 22 1992 
Lenox's birthday is on: 9 14 1994 
Silvia's birthday is on: 2 4 1998 
 
Enter an option: 
3
Enter name of who you would like to find: 
Lenox
The name you entered has their birthday on: 
9 14 1994
 
Enter an option: 
5
Enter month of who you would like to find: 
2
Name is: Silvia
Enter an option: 
6
Exiting...
*/