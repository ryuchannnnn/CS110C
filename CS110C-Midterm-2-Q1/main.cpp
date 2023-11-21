// Danny Chan
// CS110C
// 4/26/21

/*
Write a C++ function shortName which returns the number of nodes containing short names in a link-based binary tree containing strings at each node.  A short name is defined as a string with 3 or fewer characters.  Hint: use the length() function to determine the length of a string.  For example, if string s contains "Bob", s.length() will return 3.

You must use the BinaryNode class below for each node in the tree.  You cannot assume any other classes or functions are available.

class BinaryNode
{
public:
  string item;
  BinaryNode *leftChildPtr;
  BinaryNode *rightChildPtr;
};

You can assume that your function is called with parameter nodePtr pointing to a valid binary tree with one or more nodes.
// nodePtr: pointer to the root of tree we need to search
int shortName(BinaryNode* nodePtr)
*/

#include <iostream>
using namespace std;

class BinaryNode
{
public:
  string item;
  BinaryNode *leftChildPtr;
  BinaryNode *rightChildPtr;
};

int shortName(BinaryNode* nodePtr) // takes in a nodePtr only
{
  if(nodePtr == nullptr)
  {
    return 0; // if empty and base case 
  }
  if(nodePtr->item.length()<=3) 
  {
    return 1; // add 1 to final answer
  }
  else
  {
    return shortName(nodePtr->leftChildPtr) + shortName(nodePtr->rightChildPtr); 
    // recursion to go to the left side of tree and points to the item  and right side of tree and points to the item
  }
}