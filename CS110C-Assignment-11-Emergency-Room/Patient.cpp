#include <iostream>
#include "Patient.h"
#include <string>
using namespace std;

void Patient::setName(string firstN)
{
  name = firstN;
}

void Patient::setPriority(int prio)
{
  priority = prio;
}

int Patient::getPriority()
{
  return priority;
}

string Patient::getName()
{
  return name;
}

bool Patient::operator < (Patient &P)
{
  return priority < P.priority;
}

bool Patient::operator > (Patient &P)
{
  return P.priority < priority; 
}