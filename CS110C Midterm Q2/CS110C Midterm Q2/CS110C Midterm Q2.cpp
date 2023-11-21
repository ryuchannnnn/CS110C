// Danny Chan
// CS110C
// 3/8/21

#include <iostream>
using namespace std;

/*
Write a recursive C++ function that computes and returns the sum of all the positive integers in an integer array of length size.  For example, if the array contains {2, -4, 7, 3, -15} your function should return 12.  You may assume the array passed in and its size are valid, and that the array has at least one element.  No points given for a solution which isn’t recursive. Your function must have the following signature:

int sum(int array[], int size)

*/

int sum(int array[], int size)
{
    int total = 0;
    int index = size - 1; // going backwards 
    while (size > 0 && array[index] < 0)
        // if we get a negative number and can stil traverse down the array, we go down another index
    {
        index--;
    }
    if (index == 0 && array[index] > 0)
        // if we are at the beginning of the array and the number inside the index is positive, we add it to total and end the recursive function
    {
        total += array[index];
        return total;
    }
    else if (index == 0 && array[index] < 0)
        // if we are at the beginning of the array and the number inside the index is negative, we just return the total we got from recursion
    {
        return total;
    }
    else
    {
        total += array[index] + sum(array, index);
        //we add the index to total and use index to traverse down the array from end to beginning
    }
    return total;
}

int main()
{
    int array[] = { 2,-4,7,3,-15 };
    cout << sum(array, 5);
}
