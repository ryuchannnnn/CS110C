// Danny Chan 
// CS110C
// 3/30/2021

/*
For this assignment, implement the algorithm discussed in the textbook section 13.2.2 which uses a queue and a stack to determine if a string S is a palindrome.
*/

#include <iostream>
#include <string>
#include "ArrayQueue.h"
#include "ArrayStack.h"
using namespace std;

bool isPalindrome(string someString)
{
  ArrayQueue aQ;
  ArrayStack aS;
  int someStringLength = someString.size();
  for (int i = 0; i < someStringLength;i++)
  {
    char nextChar = someString[i];
    aQ.enqueue(nextChar);
    aS.push(nextChar);
  }
  bool palindrome = true;
  while((!aQ.isEmpty()) && palindrome)
  {
    char qFront = aQ.peekFront();
    char sPeek = aS.peek();
    if(qFront == sPeek)
    {
      aQ.dequeue();
      aS.pop();
    }
    else
    {
      palindrome = false;
    }
  }
  return palindrome;
}

int main() 
{
  int len = 33;
  char userInput[len];
  bool confirm;
  cout << "Enter a word: " << endl;
  cin >> userInput;
  confirm = isPalindrome(userInput);
  if(confirm)
  {
    cout << userInput << " is a palindrome." << endl; 
  }
  else
  {
    cout << userInput << " is not a palindrome." << endl;
  }
}