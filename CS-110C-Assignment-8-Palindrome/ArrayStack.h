#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack
{
private:
  static const int size = 50;
	char stack[size];
	int top;
public:
	ArrayStack()
	{
		top = 0;
	}
	bool isEmpty();
	bool push(char item);
	char peek();
	bool pop();
};
#endif