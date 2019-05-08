#pragma once

#include "Graph.hpp"

using Matrix = std::vector<std::vector<int>>;
class MatrixGraph : public Graph
{
    Matrix adjacency_;
    void initializeAdjacency();
    void randomizeEdges(std::vector<Edge>& possibleEdges, int edgesNumber);

public:

    MatrixGraph(int vertexNumber, int begin);
    MatrixGraph() = default;
    void addVertex(int nodeNumber, int neighbourNumber, int pathCost);
    void dijkstra();
    void bellmanFord();
};
