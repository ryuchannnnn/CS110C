// Danny Chan
// CS 110C 
// 1/26/2021
/*
In the videos/pdfs, you have seen a recursive solution for the fibonacci sequence and also an iterative solution.  In this exercise you will examine the runtime efficiency of both.

Enter the recursive solution from the videos/pdfs in a program.  Add a simple main() function which calls rabbit() with a value the user supplies.  Try running the program with small values like 5 and 6 and make sure the results are correct.

Now, try the program with a larger value, like 45.   Notice approximately how long it takes for the program to run.

Now, do steps 1 and 2 with the iterative solution.  Notice approximately how long it takes for the program to run.

In your reply to this discussion, post your main function, and indicate approximately how long it took your program to run for the recursive approach and also for the iterative approach for the larger value 45.

*/


#include <iostream>
using namespace std;

// Rabbit function from lecture
int rabbit(int a)
{
    if ((a == 1) || (a == 2))
    {
        return 1;
    }
    else
    {
        return rabbit(a - 1) + rabbit(a - 2);
    }
}


int rabbitIterative(int b)
{
    int current = 1, next = 1, previous = 1;
    for (int i = 3; i <= b; i++)
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
    int userInt;
    cout << "Enter an integer for fibonacci sequence: " << endl;
    cin >> userInt;
    cout << rabbit(userInt); // cout << rabbit(45); approx 16.71 seconds 
    cout << " " << endl;
    cout << rabbitIterative(userInt); // cout << rabbitIterative(45); approx 2.17 seconds 
}
