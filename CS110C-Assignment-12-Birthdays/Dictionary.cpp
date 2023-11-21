#include <iostream>
#include "Dictionary.h"
#include "Person.h"
#include <string>
using namespace std;

// constructor
Dictionary::Dictionary()
{
  numItems = 0;
  maxItems = maxSize;
  contact = new Person[maxSize];
}

// destructor
Dictionary::~Dictionary()
{
  delete [] contact;
}

bool Dictionary::add(const Person &P)
{
  int pos = getPosition(P);
  if((pos > 0) && (pos <= numItems +1))
  {
    for(int i = numItems; i >= pos; i--)
    {
      contact[i] = contact[i-1];
    }
    contact[pos-1] = P;
    numItems++;
  }
  return true;
}

bool Dictionary::remove(const Person &P)
{
  int pos = getPosition(P);
  for(int i = pos-1; i < numItems-1; i++)
  {
    contact[i] = contact[i+1];
  }
  numItems--;
  return true;
}

bool Dictionary::givenMonth(int userMonth)
{
  if(userMonth < 1 || userMonth > 12)
  {
    return false;
  }
  for(int i = 0; i < numItems; i++)
  {
    if(contact[i].getMonth() == userMonth)
    {
      cout << "Name is: " << contact[i].getName() << endl;
    }
  }
  return true;
}

bool Dictionary::isEmpty()
{
  if(numItems == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Dictionary::getPosition(const Person &P)
{
  contact[numItems] = P;
  int i = 0;
  while((contact[numItems] > contact[i-1] && (i <= numItems)))
  {
    i++;
  }
  return i;
}


int Dictionary::givenName(string searchName)
{
  int first = 0;
  int mid;
  int last = numItems;
  cout << "The name you entered has their birthday on: " << endl;
  while(first <= last)
  {
    mid = (first+last)/2;
    if(contact[mid].getName() == searchName)
    {
      cout << contact[mid].getMonth() << " " << contact[mid].getDay() << " " << contact[mid].getYear() << endl;
      return mid;
    }
    else if(contact[mid].getName() < searchName)
    {
      first = mid+1;
    }
    else
    {
      last = mid-1;
    }
  }
  return -1;
}

void Dictionary::display()
{
  for(int i = 0; i < numItems; i++)
  {
    cout << contact[i].getName() << "'s birthday is on: ";
    cout << contact[i].getMonth() << " " ;
    cout << contact[i].getDay() << " " ;
    cout << contact[i].getYear();
    cout <<  " " << endl;
  }
}