#include <iostream>
#include "Graph.h"
using namespace std;

// constructor
Graph::Graph()
{
  Matrix[6][6] = 0;
}

int Graph::vertex()
{
  int min;  
  int v; 
  for(int i = 0; i < 6; i++)
  {
    if((weight[i] <= min) && (!vertexSet[i])) 
    {
      min = weight[i];
      v = i;
    }
  }
  return v;
}

void Graph::airlineCheck(int n)
{
  if(n == 0)
  {
    cout << "SFO";
  }
  else if(n == 1)
  {
    cout <<  "LAX";
  }
  else if(n == 2)
  {
    cout << "LAS";
  }
  else if(n == 3)
  {
    cout << "PHX";
  }
  else if(n == 4)
  {
    cout << "DEN";
  }
 else if(n == 5)
  {
    cout <<  "JFK";
  } 
 else
 {
   cout << "unknown airport";
 }
}

// shortest path from textbook 

/* 
finds the minimum cost paths between an origin vertex 
(vertex 0) and all other vertices in a weighted directed 

step 1: initialization
create a set vertex set that contains only the vertex 0 
n = number of vertices in the graph
for ( v= 0 to n-1)
  weight[v] = matrix [0][v]
  
// steps 2 - n:  
invariant: for v not in vertex set weight[v] is the smalllest weight for all paths from 0 to v that pass through the vertices in vertex set before v
for v in vertex set weight[v] is the smallest weight of all paths from 0 to v (including paths outside vertex) and the shortest path from 0 to v lies entirely in vertex set 
for (steps 2 to n)
  find the smallest weight v such that v is not in vertex set
  add v to vertex set
    check weight[u] for all u not in vertex set
    for(all vertices u not in vertex)
      if (weight[u] > weight[v] + matrix[v][u])
        weight[u] = weight[v] + matrix[v][u]
*/

void Graph::dijkstra()
{
  for(int v = 0; v < 6;v++)
  {
    weight[v] = Matrix[0][v];
  }
  for(int i = 0; i < 6;i++)
  {
    int v = vertex();
    vertexSet[v] = true;
    for(int u = 0; u < 6;u++)
    {
      if((!vertexSet[u]) && (Matrix[u][v] >0) && weight[u] > weight[v] + Matrix[v][u])
      {
        weight[u] = weight[v] + Matrix[v][u];
      }
    }
    cout << "SFO to ";
    airlineCheck(i);
    cout << " is: " << weight[i] << endl;
  }
}

void Graph::set(int M[6][6])
{
  for(int i = 0; i < 6; i++)
  {
    for(int j = 0; j < 6; j++)
    {
      Matrix[i][j] = M[i][j];
    }
  }
}