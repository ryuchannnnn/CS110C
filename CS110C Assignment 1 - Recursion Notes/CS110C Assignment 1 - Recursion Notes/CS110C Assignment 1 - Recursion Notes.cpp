#include <iostream>
using namespace std;

// Recursion factorial
// precondition is n == 0 
// postcondition is n is unchanged
// return: factorial of n


int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

// Recursion reverse string
// recursively outputs a reverse of string s
// precondition: s is a string 
// postcondition: s isnt changed

void reverseString(string s)
{
    int length = s.size();
    if (length > 0)
    {
        // write the last character 
        cout << s[length - 1];
        // call reverseString on the s minus the last character 
        reverseString(s.substr(0, length - 1));
    }
}

void reverseString2(string s)
{
    int length = s.size();
    if (length > 0)
    {
        // call reverseString 2 on s minus the FIRST character
        reverseString2(s.substr(1, length - 1));
        // write the FIRST character
        cout << s[0];
    }
}

// reverseString2 is different from reverseString because 
/*
1. reverseString2 calls recursive call first then cout

2. In reverseString2, we print out the FIRST character, not the last character
*/

// Recursion with Arrays

// recursively write an array of ints backward
// pre: an array is a valid array of ints;
// first pos, last pos are zero-indexed first and lat indices in array to write backwards
// post: anArray us output backwards from firstPos and lastPos

void writeArrayBackward(int anArray[], int firstPos, int lastPos)
{
    if (firstPos <= lastPos)
    {
        cout << anArray[lastPos] << endl;
        writeArrayBackward(anArray, firstPos, lastPos - 1);
    }
}

// Recursion with Fibonacci

// pre: n is an int greater than 0 
// post: returns the fibonacci number: 

int rabbit(int f)
{
    if ((f == 1) || (f == 2))
    {
        return 1;
    }
    else
    {
        return rabbit(f - 1) + rabbit(f - 2);
    }
}

// the above function isnt wrong, however it is very inefficient (2 base cases and the recursive calls twice)

// the function below is an iterative solution with the previous function as a guideline

// pre: n is an interger greater than zero
// post: returns the fiboncaci number using an interative approach

int rabbitIterative(int r)
{
    int current = 1, next = 1, previous = 1;
    for (int i = 3; i <= r; i++)
    {
        // first, put rabbit(i) into next
        next = current + previous;
        // now, set up previous and current for next
        previous = current;
        current = next;
    }
    return next;
}

int main()
{
    cout << "This is recursion factorial: " << endl;
    cout << fact(3) << endl;
    cout << " " << endl;

    cout << "This is reverse string, where the last character gets outputted first, then it continues to reverse it." << endl;
    reverseString("cat");
    cout << " " << endl;
    cout << " " << endl;

    cout << "This is also a reverse string, but the recursions happens first until it reaches the last character." << endl; cout << "Then goes backward and outputs it in reverse. " << endl;
    reverseString2("cat");
    cout << " " << endl;
    cout << " " << endl;

    cout << "This is recursion with arrays: " << endl;
    int arr[] = { 2, 4, 6, 8 };
    writeArrayBackward(arr, 0, 3);
    cout << " " << endl;
    cout << " " << endl;

    cout << "This is for recursion with fibonacci sequence: " << endl;
    cout << rabbit(5);
    cout << " " << endl;
    cout << " " << endl;

    cout << "This is an iterative solution with recursion with fibonacci sequence: " << endl;
    cout << rabbitIterative(5);
    cout << " " << endl;

    return 0;
}