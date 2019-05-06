#pragma once

#include <vector>
#include <map>

class Graph
{

protected:

    int vertexNumber_;
    int begin_;
    std::map<int, int> previous_;
    std::vector<int> distances_;


public:

    Graph(int vertexNumber, int begin);
    void print();
    virtual void addVertex(int vertex, int neighbour, int pathCost) = 0;
    virtual void dijkstra() = 0;
    virtual void bellmanFord() = 0;
};
