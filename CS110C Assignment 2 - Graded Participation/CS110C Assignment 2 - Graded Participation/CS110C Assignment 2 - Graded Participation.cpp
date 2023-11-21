//// Danny Chan
// CS 110C
// 2/4/2021
/*
1. Implement the generic Box class discussed in the videos/pdfs. Copying and pasting from the slide is fine.

2. Implement the findBox function discussed in the videos/pdfs. Instead of an array of Boxes containing strings, i.e. Box<string>, however, we want to search an array of Boxes containing ints, i.e. Box<int>.

3. Each box contains an int representing a social security number, and thus cannot be negative. Throw another logic_error exception if the user tries to search for a negative number.

4. Write a main() function to set up a small array of Box<int> elements, and use your findBox function inside of a try-catch block. Test out your catch block by entering invalid inputs, i.e. negative numbers and numbers that aren't in your Box array.

5. Note: to get this to work on hills, you will need to #include <stdexcept>

*/


#include <iostream>
#include <stdexcept>
using namespace std;

// Q1
template <class ItemType>
class Box
{
private:
    ItemType item; // able to hold one of many data type
public:
    void setItem(const ItemType& i)
    {
        item = i;
    }
    ItemType getItem() const
    {
        return item;
    }
};


// Q2
Box <int> findBox(Box<int> boxes[], int size, int target)
{
    int i = 0;
    bool found = false;
    while (!found && (i < size))
    {
        if (target < 0)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        throw logic_error("There is a negative number in here!"); // tells user exception occured
    }
    return boxes[i];
}

int main()
{
    const int numInts = 2;
    Box <int> intBox[numInts];
    Box <int> searchBox;
    Box <string> stringBox;
    intBox[0].setItem(123456789);
    intBox[1].setItem(567431249);
    int userSearch;
    cout << "Enter number to search for: " << endl;
    cin >> userSearch;
    try
    {
        searchBox = findBox(intBox, 9, userSearch);
    }
    catch (logic_error logErr)
    {
        cout << logErr.what() << endl;
        stringBox.setItem("Error");
    }
    cout << stringBox.getItem() << endl;
    cout << " " << endl;
    return 0;
}

/*
[dchan89@hills ~]$ g++ CS110CAssignment2GradedP.cpp
[dchan89@hills ~]$ ./a.out
There is a negative number in here!
Error
*/