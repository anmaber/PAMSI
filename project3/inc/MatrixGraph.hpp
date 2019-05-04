#pragma once

#include "Graph.hpp"

using Matrix = std::vector<std::vector<int>>;
class MatrixGraph : public Graph
{
    Matrix adjacency_;

public:

    MatrixGraph(int vertexNumber, int begin);
    void addVertex(int nodeNumber, int neighbourNumber, int pathCost);
    void dijkstra();
    void bellmanFord();
};
