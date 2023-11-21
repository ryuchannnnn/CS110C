// Danny Chan
// CS110C 
// Assignment 0 Getting Started 
/*
This simple class has two member variables and four member functions to set and get the variables.
setName should change member variable name to the parameter n
setArtist should change member variable artist to the parameter a
getName should return member variable name
getArtist should return member variable artist
Implement a complete C++ program which declares this class and implements all four of its member functions.  Then, create a simple main() program which creates an object of the class, asks the user for name and artist, calls the set functions to assign reasonable values for name and artist, and then calls the get functions to output both name and artist to the console.

Hint: to input strings that may contain spaces, use getline instead of cin.
*/


#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

// declare class 
class Song
{
private:
    string name;
    string artist;
public:
    Song();
    void setName(string);
    void setArtist(string);
    string getName();
    string getArtist();
};

// constructor
Song::Song()
{
    name = "none";
    artist = "none";
}

// functions
void Song::setName(string n)
{
    name = n;
}

void Song::setArtist(string a)
{
    artist = a;
}

string Song::getName()
{
    return name;
}

string Song::getArtist()
{
    return artist;
}

int main()
{
    string singerName;
    string artistName;
    Song s;
    cout << "Please enter the name of the song: " << endl;
    getline(cin, singerName);
    s.setName(singerName);
    cout << " " << endl;
    cout << "Please enter the artist's name: " << endl;
    getline(cin, artistName);
    s.setArtist(artistName);
    cout << " " << endl;
    cout << "The name of the song is: " << s.getName() << endl;
    cout << "The name of the artist is: " << s.getArtist() << endl;
}


/*
[dchan89@hills ~]$ g++ CS110CAssignment0.cpp
[dchan89@hills ~]$ ./a.out
Please enter the name of the song:
One Call Away

Please enter the artist's name:
Charlie Puth

The name of the song is: One Call Away
The name of the artist is: Charlie Puth
[dchan89@hills ~]$
*/
