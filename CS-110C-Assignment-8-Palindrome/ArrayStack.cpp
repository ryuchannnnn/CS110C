#include <iostream>
#include "ArrayStack.h"
using namespace std;

bool ArrayStack::isEmpty()
{
	return top < 0;
}

bool ArrayStack::push(char item)
{
	bool pushed = false;
	if (top < size)
	{
    top++;
		stack[top] = item;
		pushed = true;
	}
	return pushed;
}

char ArrayStack::peek()
{
  if(isEmpty())
  {
    cout << "empty" << endl;
  }
  else
  {
    return stack[top];
  }
}

bool ArrayStack::pop()
{
	bool success = false;
	if (!isEmpty())
	{
		top--;
		success = true;
	}
	return success;
}