#include <iostream>
#include <string>
#include "Heap.h"
#include "Patient.h"
using namespace std;

// insert newData into the heap
// first, add it to the bottom of the tree, then trickle it up
// return true if successful, false if not

bool Heap::add(int prio, string firstN)
{
  int newData;
  int parentData;
  bool inPlace = false; 
  if(numPatients == fullRoom)
  {
    return false; 
  }
  // trickle new item up to the right spot of the tree
  waitRoom[numPatients].setName(firstN);
  waitRoom[numPatients].setPriority(prio);
  newData = numPatients;
  while(newData > 0 && !inPlace)
  {
    parentData = (newData - 1)/2;
    if(waitRoom[newData] < waitRoom[parentData])
    {
      inPlace = true;
    }
    else
    {
      swap(waitRoom[newData], waitRoom[parentData]);
      newData = parentData;
    }
  } 
  numPatients++;
  return true;
}

bool Heap::remove()
{
  if(numPatients == 0)
  {
    return false;
  }
  else
  {
    waitRoom[0] = waitRoom[numPatients - 1];
    heapRebuild(0, waitRoom , numPatients);
    return true;
  }
}

// return top of heap
string Heap::peekTop()
{
  return waitRoom[0].getName();
}

// convert a semiheap rooted into a heap
// recursively trickle item at rootIndex down to its proper position by swapping it with its larger child, if the child is larger than the item
// if the item is a leaf, nothing needs to be done

void Heap::heapRebuild(int root, Patient waitRoom[], int numPatients)
{
  int largerChildIndex;
  int rightChildIndex;
  if(root < numPatients/2)
  {
    largerChildIndex = 2 * root + 1 ;
    if(((root == numPatients / 2 - 1 ) && (numPatients % 2 == 1 )) || ( root < numPatients / 2 - 1))
    {
      rightChildIndex = 2 * root + 2 ;
      if(waitRoom[rightChildIndex] > waitRoom[largerChildIndex])
      {
        largerChildIndex = rightChildIndex;
      }
    }
    if(waitRoom[root] < waitRoom[largerChildIndex])
    {
      swap(waitRoom[root], waitRoom[largerChildIndex]);
      heapRebuild(largerChildIndex, waitRoom, numPatients);
    }
  }
}
