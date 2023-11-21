//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class SortedListHasA.
 @file SortedListHasA.cpp */

#include "SortedListHasA.h"  // Header file
#include "LinkedList.h"
#include <cassert>
#include <cmath>
  
template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
{
   listPtr = new LinkedList<ItemType>();
}  // end default constructor

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sList) 
{
	// First, create our own list
	listPtr = new LinkedList<ItemType>();
	
	// Then add items to it using public methods
	for(int position = 1; position <= sList.getLength(); position++)
	{
		listPtr->insert(position, sList.getEntry(position));
	}  // end for	
}  // end copy constructor

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
   clear();
}  // end destructor

template<class ItemType>
void SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry)
{
   int newPosition = fabs(getPosition(newEntry));
   listPtr->insert(newPosition, newEntry);
}  // end insertSorted

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& anEntry)
{
   bool ableToRemove = false;
   if (!isEmpty())
   {
      int position = getPosition(anEntry);
             
      ableToRemove = position > 0;
      if (ableToRemove)
      {
         ableToRemove = listPtr->remove(position);
      }  // end if
   }  // end if

   return ableToRemove;
}  // end removeSorted

template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& anEntry) const
{
   // this version of getPosition always returns 1.  Fix it so that it implements
   // getPosition() correctly.  
   // It should return either the position of the given 
   // entry, if it occurs in the sorted list, or the position where the entry 
   // would occur, but as a negative integer.  
   /*
   original version:
   int position = 1;
   return position;
   */
   int position = 1;
   if(!isEmpty()) // similar to remove sorted, make sure list is not empty 
   {
     bool findPos = false; // we have not found position yet
     while(!findPos || position > getLength())
     {
       if(anEntry > getEntry(position) && position == getLength()) 
       // this gets implemented when we are at the end of the list, and we output the position where the entry would occur but as a negative integer
       {
         findPos = true;
         position++;
         position *= -1;
       }
       else if(anEntry == getEntry(position)) 
       // if the entry occurs in the sorted list, we end the while loop return its position
       {
         findPos = true;
       }
       else if(anEntry < getEntry(position))  
       // if the entry happens to be before the position, we end the while loop and return it at the position before but with a negative
       {
         findPos = true;
         position *= -1;
       }
       else if(anEntry > getEntry(position))
       // if the entry is after the position, we continue on with the while loop
       {
         position++;
       }
     }
   }
   return position;
}  // end getPosition

//=====================
// List operations:

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position)
{
   return listPtr->remove(position);
}  // end remove

template<class ItemType>
void SortedListHasA<ItemType>::clear()
{
   listPtr->clear();
}  // end clear

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const noexcept(false)
{
   return listPtr->getEntry(position);
}  // end getEntry

template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const
{
   return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const
{
   return listPtr->getLength();
}  // end getLength

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use in this .cpp file.
// (just strings for now, add more types if desired)
template class SortedListHasA<std::string>;
template class SortedListHasA<int>;