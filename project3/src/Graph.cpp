#include "Graph.hpp"

#include <climits>

Graph::Graph(int vertexNumber, int begin)
    : vertexNumber_(vertexNumber),
      begin_(begin)
{
    distances_.resize(vertexNumber,INT_MAX);
}
