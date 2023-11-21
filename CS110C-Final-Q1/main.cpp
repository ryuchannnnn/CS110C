#include <iostream>
using namespace std;


/*
Write a pseudocode function which takes two parameters: heap1 and heap2, and returns an integer.  The function should return the 3rd largest number contained in both heaps.  Both heap1 and heap2 are maxheaps containing integers, and both heaps have at least 3 elements. 

For example, if heap1 contains 10, 7, 6, 4, 1 and heap2 contains 8, 4, 3 your function should return 7.  If heap1 contains 10, 7, 4 and heap2 contains 5, 4, 3 your function should return 5.  It is acceptable if heap1 and heap2 are changed during the function call. 

Assume you have a class Heap implemented which implements the following heap functions discussed in the videos and textbook (and only the following functions).

+isEmpty(): boolean

+getNumberOfNodes(): integer

+add(newEntry: ItemType): boolean                  

+peek(): ItemType

+remove(): boolean

bronze(heap1: Heap, heap2: Heap): integer
*/

// Danny Chan
// CS110C
// 5/24/2021
// Final Q1

bronze(heap1: Heap, heap2: Heap): integer
{
  // heaps are already passed in 
  thirdLargestNum: integer 
  if(heap1.getNumberofNodes() + heap2.getNumberofNodes() >= 6) 
  // since there are 2 heaps(each have at least 3 ints), there must be at least 6 nodes
  {
    for(i starting at 0, i <= 2, increment i by 1)
    {
      bigNum1:integer
      bigNum2:integer
      bigNum1 = heap1.peek() // since this is a max heap, our root is the largest value
      bigNum2 = heap2.peek() // since this is a max heap, our root is the largest value
      if(i == 2) // we have iterated our i counter 3 times (0,1,2) because arrays start at 0
      {
        if(bigNum1 < bigNum2)
        {
          thirdLargestNumber = bigNum2
          return thirdLargestNumber
          // after going through the loop twice, if the number in heap 2 is bigger than our number than heap 1, we have found our third largest number
        }
        else if(bigNum2 < bigNum1)
        {
          thirdLargestNumber = bigNum1
          return bigNum1
          // after going through the loop twice, if the number in heap 1 is bigger than our number than heap 2, we have found our third largest number
        }
        else if(bigNum2 == bigNum1) // if the number happens to be the same, we can return either bigNum1 or bigNum2 (choosing bigNum1 in this case)
        {
          thirdLargestNumber = bigNum1
          return bigNum1
        }
      }
      if(bigNum1 < bigNum2)
      {
        heap2.remove() // if the root of heap 2 is bigger than heap 1, we delete the root from heap2
      }
      else if(bigNum2 < bigNum1)
      {
        heap1.remove() // if the root of heap 1 is bigger than heap 2, we delete the root from heap1
      }
      else if(bigNum2 == bigNum1) 
      {
        heap1.remove() // if the number happens to be the same, we can remove either bigNum1 or bigNum2 (choosing bigNum1 in this case)
      }
    }
  }
}

int main() 
{

}