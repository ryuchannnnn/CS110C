#ifndef Dictionary_H
#define Dictionary_H
#include<iostream>
#include "Person.h"
#include<string>
using namespace std;

class Dictionary
{
  private:
    int maxSize = 10;
    Person *contact;
    int numItems;
    int maxItems;
  public:
    Dictionary(); // constructor
    ~Dictionary(); // destructor
    bool add(const Person &P);
    bool remove(const Person &P);
    bool givenMonth(int userMonth);
    bool isEmpty();
    int getPosition(const Person &P);
    int givenName(string searchName);
    void display();
};
#endif