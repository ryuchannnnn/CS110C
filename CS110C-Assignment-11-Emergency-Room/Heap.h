#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "Patient.h"
#include <string>
using namespace std;

class Heap
{
  private: 
    Patient waitRoom[10];
    int numPatients = 0;
    int fullRoom = 10;

  public:
    bool add(int num, string N);
    bool remove();
    string peekTop();
    void heapRebuild(int root, Patient waitRoom[], int count);
};
#endif
