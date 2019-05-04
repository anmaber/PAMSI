#include "MatrixGraph.hpp"

#include <climits>

MatrixGraph::MatrixGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.reserve(vertexNumber);
    for(auto & a : adjacency_)
    {
        a.resize(vertexNumber,INT_MAX);
    }
}

void MatrixGraph::addVertex(int nodeNumber, int neighbourNumber, int pathCost)
{
    adjacency_[nodeNumber][neighbourNumber] = pathCost;
}
