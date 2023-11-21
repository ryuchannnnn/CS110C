// Danny Chan
// CS110C 
// 3/19/2021

/*
For this assignment, implement a simple stack calculator which can compute an infix expression.  It should take in a string containing an infix expression, compute the result, and print it out.  It should handle operators +, -, *, / and parenthesis.

Your program must have two main steps -- first convert the infix expression to postfix, and then compute the result using the algorithms discussed in videos/pdfs and textbook.  These algorithms require that you use a stack.  You must implement your own stack, you may not use a library that implements a stack.  No credit will be given if you don't implement your own stack.

To keep things simple, you may make the following assumptions:

there are no spaces or other whitespace in the string
all the operands are single digits
the result of every operation is a single digit.  For example, 2+3 is allowed because the result is 5.  5*3 is not allowed because the result is 15, which is two digits.   5+3+4 is not allowed because even though the first operation is 8, a single digit, the result of the second operation is 12, two digits.  5+3-4 is allowed because the result of the first operation is 8, and the result of the second operation is 4
any string entered contains a valid, syntactically correct infix expression.  If there are parenthesis in the expression, they are balanced.

Conversion between int and char
The expression contains both char and int data, because each operator is a char and each operand is a digit.  The easiest way to handle this is to implement a stack which supports char data.  Since we know all our operands are single digits, we can simply push the character representing the digit onto the stack.  Note this character will be the ASCII value of the character, not the integer value!  As an example, the character '7' is ASCII value 55, '8' is 56, etc.  If you need the actual integer value of the character, in this case 7, there is a convenient way to determine it.  You can subtract the ASCII value of zero, '0' from the character.  For example, the following code will store 7 in i:

*/

#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int main()
{
    ArrayStack a;
    const int maxChars = 33;
    char infix[maxChars];
    char operator2;
    char operator1;
    char leftP = '(';
    char rightP = ')';
    int ascii1;
    int ascii2;
    int operand1 = 0;
    int operand2 = 0;
    int answer = 0;
    string postFixExp;
    cout << "Please enter an infix expression to convert to postfix: " << endl;
    cin >> infix;
    for (int i = 0; i < maxChars; i++)
    {
        // if we have an operand, append it to postfixExp
        if (isdigit(infix[i]))
        {
          postFixExp += infix[i];
        }
        // if we have a '(' push it on the stack
        else if (infix[i] == leftP)
        {
          a.push('(');
        }
        // if you encounter an operator (+,-,*,/)
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
          // if stack is empty, push the operator onto the stack
          if(a.isEmpty())
          {

          }
          else
          // else peek at the stack, if it is an operator greater or equal precedence, pop it from the stack and append it to postfixexp. keep peeking/popping until you encounter a "(" or an operator of lower precedence, or the stack becomes empty, then push the operator onto the stack 
          {
            
          }
        // if you encounter a ")", pop operators off the stack and append them to postfixExp until you encouter the "(" and pop off the "("
        else if (infix[i] == rightP)
        {
            while (a.pop() != leftP)
            {
                a.pop();
            }
        }
        // if you encounter the end of the string, pop off the remaining stack operators and append them to postfixExp
        else 
        {
            while (!a.isEmpty())
            {
                postFixExp += a.pop();
            }
        }
    }
    cout << "postfixExp is: " << postFixExp << endl;
    if (answer < 10)
    {
        cout << "Your answer was: " << answer << endl;
    }
    else
    {
        cout << "This calculator can only calculate up to 10." << endl;
    }
}