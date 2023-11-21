#include <iostream>
#include "ArrayQueue.h"
using namespace std;

bool ArrayQueue::isEmpty()
{
  return count == 0;
}

bool ArrayQueue::enqueue(char item)
{
  bool result = false;
  if(count < maxSize)
  {
    back = (back + 1) % maxSize;
    queue[back] = item;
    count++;
    result = true;
  }
  return result;
}

bool ArrayQueue::dequeue()
{
  bool result = false;
  if(!isEmpty())
  {
    front = (front + 1) % maxSize;
    count--;
    result = true;
  }
  return result;
}
char ArrayQueue::peekFront()
{
  if(isEmpty())
  {
    cout << "empty" << endl;
  }
  else
  {
    return queue[front];
  }
}