#pragma once

#include "Graph.hpp"

using AdjacencyList = std::vector<std::vector<std::pair<int,int>>>;

class ListGraph : public Graph
{

    AdjacencyList adjacency_;

public:

    ListGraph(int vertexNumber, int begin);
    void addVertex(int vertex, int neighbour, int pathCost);
    void dijkstra();
    void bellmanFord();

};
