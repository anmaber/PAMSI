#pragma once

#include <vector>

using AdjacencyList = std::vector<std::vector<std::pair<int,int>>>;

class Graph{

    int vertexNumber_;
    int begin_;
    AdjacencyList adjacency_;

public:

    Graph(int vertexNumber, int begin);
    void addNeighbour(int nodeNumber, int neighbourNumber, int pathCost);
    void dijkstra();

};
