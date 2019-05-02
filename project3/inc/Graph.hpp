#pragma once

#include <vector>

using AdjacencyList = std::vector<std::vector<std::pair<int,int>>>;

class Graph{

    int vertexNumber;
    AdjacencyList adjacency;

public:

    void addNeighbour(int nodeNumber, int neighbourNumber, int pathCost);

};
