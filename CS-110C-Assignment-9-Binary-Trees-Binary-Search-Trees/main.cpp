// Danny Chan
// CS110C 
// 4/14/21

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>       

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{
   cout << "Test 1: " << endl;
   BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->inorderTraverse(display);

   cout << " " << endl;
   cout << "Now showing random add function in tree2: " << endl; 

   BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();   
   tree2->randomAdd("10");
   tree2->randomAdd("20");
   tree2->randomAdd("30");
   tree2->randomAdd("40");
   tree2->randomAdd("50");
   tree2->randomAdd("60");
   tree2->randomAdd("70");
   tree2->inorderTraverse(display);
   cout << " " << endl;

   cout << "Test 2: " << endl; 
   BinaryTreeInterface<string>* tree3 = new BinaryNodeTree<string>();   
   tree3->add("apple");
   tree3->add("banana");
   tree3->add("orange");
   tree3->add("pear");
   tree3->add("dragonfruit");
   tree3->add("strawberry");
   tree3->inorderTraverse(display);
   cout << " " << endl;
   
   cout << "Now showing random add function in tree4: " << endl;
   BinaryTreeInterface<string>* tree4 = new BinaryNodeTree<string>();   
   tree4->randomAdd("apple");
   tree4->randomAdd("banana");
   tree4->randomAdd("orange");
   tree4->randomAdd("pear");
   tree4->randomAdd("dragonfruit");
   tree4->randomAdd("strawberry");
   tree4->inorderTraverse(display);
   cout << " " << endl;


   return 0;
}  // end main

/*
[dchan89@hills ~]$ ./a.out
Test 1: 
Displaying item - 70
Displaying item - 40
Displaying item - 20
Displaying item - 60
Displaying item - 10
Displaying item - 50
Displaying item - 30
 
Now showing random add function in tree2: 
Displaying item - 50
Displaying item - 30
Displaying item - 60
Displaying item - 40
Displaying item - 10
Displaying item - 20
Displaying item - 70
 
Test 2: 
Displaying item - pear
Displaying item - banana
Displaying item - strawberry
Displaying item - apple
Displaying item - dragonfruit
Displaying item - orange

Now showing random add function in tree4:
Displaying item - strawberry
Displaying item - dragonfruit
Displaying item - apple
Displaying item - orange
Displaying item - banana
Displaying item - pear

*/
