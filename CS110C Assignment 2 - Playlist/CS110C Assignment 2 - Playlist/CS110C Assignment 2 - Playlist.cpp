// CS110C Assignment 2 - Playlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Array-based List Class for Playlists
// Max Luttrell CS 110C
//
// Danny Chan
// CS110C
// 2/4/21

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE = 2;
    ItemType* list;
    int numItems;
    int maxItems;
public:
    // default constructor and destructor
    List()
    {
        numItems = 0;
        maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE];
    }
    ~List()
    {
        delete[] list;
    }
    // list member functions
    bool isEmpty() const
    {
        return numItems == 0;
    }
    int getLength() const
    {
        return numItems;
    }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear()
    {
        numItems = 0;
    }

    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;

    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};

/*
Also, improve the insert() function.  Currently, if you try to add an item to a full list, insert() returns false and does not add the item.  Improve this so that it dynamically allocates more memory to the list to make room for the new item using the new operator.  You can add another CHUNK_SIZE amount of memory, or any other amount of memory you think makes sense.  Don't forget to deallocate any existing memory, e.g. using delete [].
*/
template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd;
    canAdd = ((pos > 0) && (pos <= numItems + 1));
    if (canAdd)
    {
        if (numItems >= maxItems)
        {
            int moreMem = CHUNK_SIZE * 20;
            ItemType* copyList = new ItemType[moreMem];
            for (int i = 0; i < numItems; i++)
            {
                copyList[i] = list[i];
            }
            copyList[pos - 1] = item;
            delete[] list;
            list = copyList;
        }
        // first, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // position 1.
        for (int i = numItems; i >= pos; i--)
        {
            list[i] = list[i - 1];
        }
        // now put our item at position pos-1
        list[pos - 1] = item;
        numItems++;
    }
    return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if (pos<1 || pos>getLength())
    {
        throw invalid_argument("Error: getEntry() using invalid position");
    }
    else
    {
        return list[pos - 1];
    }
}

// TODO: add implementations for setEntry() and remove() function

/*
void setEntry(int pos, const ItemType& item)
Replace item at position pos in the list with the new parameter item.
Throw the invalid_argument exception if pos < 1 or pos > getLength().
*/
// very similar to getEntry

template <class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
    if (pos<1 || pos>getLength())
    {
        throw invalid_argument("Error: setEntry() using invalid position");
    }
    else
    {
        list[pos - 1] = item;
    }
}

/*bool remove(int pos)
Remove the item at position pos.  You need to update the state of the list, that is, shift items after pos over one to get rid of the gap left by the removed item and update numItems.  If the remove operation is successful, return true.  If it was not successful, for example because pos is out of range, return false.*/
// opposite of insert

template <class ItemType>
bool List<ItemType>::remove(int pos)
{
    if (pos > 0 && pos <= getLength())
    {
        for (int i = pos; i < numItems; i++)
        {
            list[i - 1] = list[i];
        }
        numItems--;
        return true;
    }
    else
    {
        throw invalid_argument("Remove position is invalid");
        return false;
    }
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
    bool inputCheck;
    int trackNumber;
    do
    {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}

int main()
{
    List<string> songs;
    char goAgain = 'y';
    int trackNumber;
    string trackName;

    // Insert some songs into our list
    songs.insert(1, "One More Saturday Night");
    songs.insert(2, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(4, "California Love");
    songs.insert(5, "Test 1");
    songs.insert(6, "Test 2");
    songs.insert(7, "Test 3");
    songs.setEntry(5, "Blue and Grey");
    songs.setEntry(6, "Euphoria");
    songs.setEntry(7, "Spring Day");
    songs.remove(1);
    cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
    while (goAgain != 'n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }
    cout << "Rock on!\n";
    return 0;
}

/*
[dchan89@hills ~]$ g++ CS110CAssignment2Playlist.cpp
[dchan89@hills ~]$ ./a.out
Welcome!  There are 6 tracks.
Please enter the track number you'd like to view: 1
Your track name is Friday I'm in Love
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is Sunday Morning Coming Down
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is Blue and Grey
Go again? (y/n) y
Please enter the track number you'd like to view: 5
Your track name is Euphoria
Go again? (y/n) y
Please enter the track number you'd like to view: 6
Your track name is Spring Day
Go again? (y/n) y
Please enter the track number you'd like to view: 7
Error: getEntry() using invalid position
Your track name is No Track
Go again? (y/n) n
Rock on!
[dchan89@hills ~]$

setEntry() exception throw not demonstrated in sample output. -5

*/