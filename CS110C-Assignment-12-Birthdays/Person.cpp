#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
Person::Person()
{
  month = 0;
  day = 0;
  year = 0;
}

// constructor
Person::Person(string n, int m, int d, int y)
{
  name = n;
  month = m;
  day = d;
  year = y;
}

// getters
string Person::getName()
{
  return name;
}

int Person::getMonth()
{
  return month;
}

int Person::getDay()
{
  return day;
}

int Person::getYear()
{
  return year;
}

// setters
string Person::setName(string n)
{
  name = n;
}

int Person::setMonth(int m)
{
  month = m;
}

int Person::setDay(int d)
{
  day = d;
}

int Person::setYear(int y)
{
  year = y;
}

// operator overload
bool Person:: operator <(const Person &P)
{
  return name < P.name;
}

bool Person::operator >(const Person &P)
{
  return name > P.name;
}