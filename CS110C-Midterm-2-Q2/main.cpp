// Danny Chan
// CS110C
// 4/26/21

/*
Write a pseudocode function which modifies a stack containing integers so that every element in the stack is doubled.  For example:

aStack before function: aStack after function:

top-> 3                         top-> 6                         

      2                               4                         

      1                               2                         
The stack implements the functions discussed in class and the textbook (and only these functions):

+isEmpty(): boolean

+push(newEntry: integer): boolean                  

+pop(): boolean

+peek(): integer

 

Hint: use temporary stack(s).  

// doubles every element in aStack, which is passed in by reference

doubleStack(aStack: Stack)
*/

doubleStack(aStack: Stack)
{
 // aStack is already passed by reference
 tempStack = a new empty stack
 while(!aStack.isEmpty())
 {
  newChar = aStack.peek()
  newChar = newChar * 2
  tempStack.push(newChar)
  aStack.pop()
 }
 while(!tempStack.isEmpty())
 {
  pushBack = tempStack.peek()
  aStack.push(pushBack)
  tempStack.pop()
 }
}

#include <iostream>
using namespace std;

int main() 
{

}