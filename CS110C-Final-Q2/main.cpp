#include <iostream>
using namespace std;

/*
Write a C++ function odds which returns the number of odd integers in a node-based binary search tree containing positive integers.  For example, for the binary search tree below your function should return 5, because it contains 5 odd integers (1, 3, 5, 7, 9). 

https://lh4.googleusercontent.com/lzsLBEYqop9fGjJmoer2YzsP3QIS5wLb45ilQe1xQXzYkv45QAHfgdrITPaaxZYgLXV8PgaFUoLVdgHegoFTUToWU8Y1o4cSMfnsnCaEDy5iuitNL8mA6wkmVBnngYA3pCfS7Gyo

Assume each node in your tree is implemented using the class BinaryNode, which implements the following binary node functions discussed in the videos and textbook (and only the following functions).

+getItem(): integer

+isLeaf(): boolean

+getLeftChildPtr(): BinaryNode*                  

+getRightChildPtr(): BinaryNode*                  

// nodePtr: pointer to the root node of tree to check

int odds(BinaryNode* nodePtr)
*/

// Danny Chan
// CS110C
// 5/24/2021
// Final Q2

int odds(BinaryNode* nodePtr)
{
  int numOddInts = 0; // our counter for the total of odd integers
  if(!nodePtr->isLeaf()) // we keep running this code because of recursion and as long as we are NOT at a leaf
  {
    numOddInts += odds(nodePtr->getLeftChildPtr()); // this will get the total of the left side of the tree
    if(nodePtr->getItem() %2 == 1) // if we get a remainder of 1
    {
      numOddInts++; // increment counter by 1 
    }
    numOddInts += odds(nodePtr->getRightChildPtr()); 
    // this will get the total of the right side of our tree 
    // and numOddInts will already have the total from the left side
  }
  return numOddInts; // output the amount of odd integers in the tree
}

int main() 
{

}