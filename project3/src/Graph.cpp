#include "Graph.hpp"

Graph::Graph(int vertexNumber, int begin)
    : vertexNumber_(vertexNumber),
      begin_(begin)

{}

void Graph::addNeighbour(int nodeNumber, int neighbourNumber, int pathCost)
{
    adjacency[nodeNumber].emplace_back(std::make_pair(neighbourNumber,pathCost));
}

