// Danny Chan
// CS110C
// 5/13/2021

/*
For this assignment, you will implement Dijkstra’s algorithm in order to determine the cheapest flights from San Francisco to other cities for a fictitious airline, CS Airlines.

Consider the following map of available flights on CS Airlines.  Each vertex has a name and an index, e.g. SFO has index 0, LAX has vertex 1, etc.  Each edge has a weight which is the cost of a ticket between the two cities.

https://lh3.googleusercontent.com/DNIJ1Z3exhE8WDBFf3ZLESb-HZCXlggh1_Al74a__TX0JPB-7tlWlPnIMVIRLWtKY0bRe4uQBe9v5e7bGm4WThN0bkeN_5a5q-4Gj4bP3u77w_rL7C-uZPKF-z_JyXu9ElbHdXmF

We can represent this map as an adjacency matrix:

https://lh5.googleusercontent.com/B-1DKPf6X-SK5W7NoF37Z4mHsbfw0Re49J3e5LatZQUh2vBtCfSyQCMEJZcoZcYTszAbSUZW-eGvWEaajglhAeiRnUYHCjnpenkYwA1kwk9dSUjz_Ew8rwqBndU5z8pBTVG1JiJp

Design and implement a C++ class to represent this graph using an adjacency matrix.  In addition to storing the adjacency matrix, your class should include a method which uses Dijkstra’s algorithm in order to compute and print out the cheapest cost from San Francisco (vertex 0) to each other city.  It may help you debug to print out the weight array, v, and vertex set for each iteration of the algorithm.
*/


#include <iostream>
#include "Graph.h"
using namespace std;

int main() 
{
  Graph airline;
  int matrix[6][6] = 
  {
    {0,120,150,9999,9999,500},
    {120,0,9999,75,9999,350},
    {150,9999,0,9999,250,9999},
    {9999,75,9999,0,150,9999},
    {9999,9999,250,150,0,9999},
    {500,350,9999,9999,9999,0}
  };
  airline.set(matrix);
  airline.dijkstra();
}

/*
[dchan89@hills ~]$ ./a.out
SFO to SFO is: 0
SFO to LAX is: 120
SFO to LAS is: 150
SFO to PHX is: 195
SFO to DEN is: 345
SFO to JFK is: 470
*/