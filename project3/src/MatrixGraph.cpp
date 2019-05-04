#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.reserve(vertexNumber);
    for(auto & a : adjacency_)
    {
        a.reserve(vertexNumber);
    }
}
