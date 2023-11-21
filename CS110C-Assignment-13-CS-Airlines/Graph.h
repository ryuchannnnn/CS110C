#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph
{
  private:
    int Matrix[6][6]; // 6 x 6 matrix
    int weight[6];    
    bool vertexSet[6];
  
  public:
    // constructor
    Graph();
    int vertex();
    void airlineCheck(int x);
    void dijkstra();
    void set(int M[6][6]);
};
#endif