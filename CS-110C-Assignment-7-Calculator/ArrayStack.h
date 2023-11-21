#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

int const size = 33;

class ArrayStack
{
private:
	char* stack;
	int length;
	int top;
public:
	ArrayStack()
	{
		stack = new char[size];
		top = 0;
	}
	~ArrayStack()
	{
		delete[] stack;
	}
	bool isEmpty();
	bool push(char item);
	char peek();
	bool pop();
};

#endif