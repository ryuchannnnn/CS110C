#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient
{
  private:
    int priority;
    string name;

  public:
    bool operator <(Patient &P);
    bool operator >(Patient &P);
    int getPriority();
    string getName();
    void setPriority(int prio);
    void setName(string firstN);
};
#endif