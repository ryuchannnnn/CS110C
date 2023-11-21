// Danny Chan
// CS110C 
// 3/8/2021
#include <iostream>
using namespace std;

/*
Consider the circular linked list data structure.  It is similar to the standard linked list data structure we studied, except that the last node's next pointer points back to the first node instead of being nullptr.

Write a C++ function countList that returns how many elements there are in a circular list.  For example, for the list pictured above, your function should return 3.  It must take one parameter: a pointer the first node in the list head.  You may assume that the parameter passed in points to a valid circular list with at least 2 elements.  You may use the Node class defined below for your nodes, or define your own.

class Node {

  public:

    int data;

    Node* next;

};

Your function must have the following signature:

int countList(Node* head)
*/


class Node
{
public:
    int data;
    Node* next;
};

int countList(Node* head)
{
    int counter = 0;
    Node* loopToHead = head;
    if (head != NULL) // if this is a circular, the last node pointer must point back to the first node and the last element cannot have null
    {
        while (loopToHead != head) // while loop before loopToHead points back to head
        {
            loopToHead = loopToHead->next;
            counter++; // counter to count how many times we are in the while loop before loopToHead points back to head
        }
    }
    return counter;
}


int main()
{
    Node* head;
    cout << countList(head);
}