#include "ArrayStack.h"

bool ArrayStack::isEmpty()
{
	return (top == 0);
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
	return stack[top - 1];
}

bool ArrayStack::pop()
{
	bool success = false;
	if (top >= 0)
	{
		stack[top] = 0;
		top--;
		success = true;
	}
	return success;
}