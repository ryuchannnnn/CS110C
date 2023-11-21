// Danny Chan
// CS110C
// 1/28/2021

/*
Write the following functions in C++.  They must be recursive.

1.  Chapter 2, exercise 9: Write a recursive C++ function that writes the digits of a positive decimal integer in reverse order.  Hint: 2015 % 10 == 5, 2015 / 10 == 201.  Example: if given the integer 2015, your function should output 5102.

2.  Rewrite both of the functions writeBackward and writeBackward2 in section 2.3.1 of the text (page 61 in both the 6th and 7th edition) as C++ functions.  You may use either C-strings (char *)  or C++ string objects for the string.  Make sure you include all of the cout statements in these functions which indicate function entry, function exit, and about to write a character.  Make sure you carefully trace the functions and understand why the cout statements appear where they do when you run the program.

3.  Chapter 2, exercise 4: Given two integers, start and end, where end is greater than start, write a recursive C++ function that returns the sum of the integers from start through end, inclusive.  For example, if start is 3 and end is 6, the function should return 18, because 3+4+5+6 = 18.
*/


#include <iostream>
using namespace std;

// Q1

int reversePosInt(int posInt)
{
    if (posInt < 10)
    {
        cout << posInt << endl; // base case because if the number entered is from 1-9 there is no reversing 
    }
    else
    {
        cout << (posInt % 10); // printing last number because it is the remainder
        reversePosInt(posInt / 10); // slicing off the number in the last position
    }
    return posInt;
}

// Q2

void writeBackward(string s)
{
    cout << "Enter writeBackward with string: " << s << endl;
    int lengthS = s.size();
    if (lengthS == 0)
    {
        // do nothing base case 
    }
    else
    {
        cout << "About to write last character in string: " << s << endl;
        // write the last character of s
        cout << "Last character is: " << s[lengthS - 1] << endl;
        writeBackward(s.substr(0, lengthS - 1));
    }
    cout << "Leave writeBackward with string: " << s << endl;
}

void writeBackward2(string s2)
{
    cout << "Enter writeBackward2 with string: " << s2 << endl;
    int lengthS2 = s2.size();
    if (lengthS2 == 0)
    {
        // do nothing base case
    }
    else
    {
        writeBackward2(s2.substr(1, lengthS2));
        cout << "About to write furst character of string: " << s2 << endl;
        cout << s2[0] << endl;
    }
    cout << "Leave writeBackward2 with string: " << s2 << endl;
}

// Q3
int recursiveSum(int smallNum, int bigNum)
{
    int total;
    if (smallNum > bigNum)
    {
        return 0;
    }
    else
    {
        total = smallNum + recursiveSum(smallNum + 1, bigNum); // keeps adding until smallNum is bigger than bigNum
    }
    return total;
}


int main()
{
    int userNum;
    cout << "Starting Q1..." << endl;
    cout << "Enter a number to be reversed: " << endl;
    cin >> userNum;
    reversePosInt(userNum);
    cout << " " << endl;

    cout << "Starting Q2..." << endl;
    cout << " " << endl;
    writeBackward("cat");
    cout << " " << endl;

    writeBackward2("cat");
    cout << " " << endl;

    int start, end;
    cout << "Starting Q3..." << endl;
    cout << "Enter a number: " << endl;
    cin >> start;
    cout << "Enter a number higher than " << start << ": " << endl;
    cin >> end;
    cout << "The sum of numbers between " << start << " and " << end << " is: " << recursiveSum(start, end);
    return 0;
}

/*
[dchan89@hills ~]$ g++ CS110CAssignment1.cpp
[dchan89@hills ~]$ ./a.out
Starting Q1...
Enter a number to be reversed:
2015
5102

Starting Q2...

Enter writeBackward with string: cat
About to write last character in string: cat
Last character is: t
Enter writeBackward with string: ca
About to write last character in string: ca
Last character is: a
Enter writeBackward with string: c
About to write last character in string: c
Last character is: c
Enter writeBackward with string:
Leave writeBackward with string:
Leave writeBackward with string: c
Leave writeBackward with string: ca
Leave writeBackward with string: cat

Enter writeBackward2 with string: cat
Enter writeBackward2 with string: at
Enter writeBackward2 with string: t
Enter writeBackward2 with string:
Leave writeBackward2 with string:
About to write furst character of string: t
t
Leave writeBackward2 with string: t
About to write furst character of string: at
a
Leave writeBackward2 with string: at
About to write furst character of string: cat
c
Leave writeBackward2 with string: cat

Starting Q3...
Enter a number:
3
Enter a number higher than 3:
6
The sum of numbers between 3 and 6 is: 18[dchan89@hills ~]$
*/