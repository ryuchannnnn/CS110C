// Danny Chan
// CS110C 
// 1/26/2021

/*
Implement a recursive reverseString in C++ function like the one in the pdf's videos, but with a twist.  You are no longer allowed to print out the last character in s.  You are, however, allowed to print out the first character in s, i.e. s[0].

First, make one change to the function so that it prints out the first character in s, s[0] and then calls ReverseString on s minus the last character.  Notice that it doesn't work anymore!  It no longer reverses the string.  Look at what it does and think about why.

What further changes can you make to the function to fix it?  In other words, write a recursive function that reverses the string, but you aren't allowed to print out the last character in s.  You are allowed print out the first character in s.  Useful string functions:

s.size() - returns length of string s

s.substr(pos,len) - returns the substring of s of length len starting at postion pos (zero is first position)

*/


#include <iostream>
using namespace std;

void reverseString(string s)
{
    int length = s.size();
    if (length > 0)
    {
        reverseString(s.substr(1, length - 1));
        cout << s[0];
    }
}

int main()
{
    reverseString("cat");
    return 0;
}
