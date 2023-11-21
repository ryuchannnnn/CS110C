#ifndef Person_H
#define Person_H 

#include <iostream>
#include <string>
using namespace std;

class Person
{
  private:
    string name;
    int month;
    int day;
    int year;
  
  public:
    Person(); // default constructor
    Person(string n, int m, int d, int y); // constructor
    // getters
    string getName();
    int getMonth();
    int getDay();
    int getYear();
    // setters
    string setName(string n);
    int setMonth(int m);
    int setDay(int d);
    int setYear(int y);
    // operator overload
    bool operator <(const Person &P);
    bool operator >(const Person &P);
};
#endif