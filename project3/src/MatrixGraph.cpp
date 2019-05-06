#include "MatrixGraph.hpp"
#include <iostream>
#include <climits>

MatrixGraph::MatrixGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.resize(vertexNumber);
    for(auto & a : adjacency_)
    {
        a.resize(vertexNumber,INT_MAX);
    }
}

void MatrixGraph::addVertex(int nodeNumber, int neighbourNumber, int pathCost)
{
    adjacency_[nodeNumber][neighbourNumber] = pathCost;
}

void MatrixGraph::dijkstra()
{
    std::vector<bool> processed(vertexNumber_, false);
    distances_[begin_] = 0;

    for(int i = 0; i < vertexNumber_ -1; ++i)
    {
        int min = INT_MAX;
        int minIndex;

        for(int j = 0; j < vertexNumber_; ++j)
        {
            if(!processed[j] && distances_[j] <= min)
            {
                min = distances_[j];
                minIndex = j;
            }
        }

        processed[minIndex] = true;

        for(int k = 0; k < vertexNumber_; ++k)
        {
            if(!processed[k] && adjacency_[minIndex][k] != INT_MAX && distances_[minIndex] != INT_MAX
                    && distances_[minIndex] + adjacency_[minIndex][k] < distances_[k])
            {
                distances_[k] = distances_[minIndex] + adjacency_[minIndex][k];
                previous_[k] = minIndex;
            }
        }
    }
}



void MatrixGraph::bellmanFord()
{
    distances_[begin_] = 0;

    for(int i = 0; i < vertexNumber_ - 1; ++i)
    {
        for(int j = 0; j < vertexNumber_; ++j)
        {
            for(int k = 0; k < vertexNumber_; ++k)
            {
                if(adjacency_[j][k] != INT_MAX && distances_[k] > adjacency_[j][k] + distances_[j])
                {
                    distances_[k] = adjacency_[j][k] + distances_[j];
                    previous_[k] = j;
                }
            }
        }
    }

}
