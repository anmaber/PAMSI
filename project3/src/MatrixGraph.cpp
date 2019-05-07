#include "MatrixGraph.hpp"

#include <iostream>
#include <climits>
#include <queue>

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

using Pair = std::pair<int,int>;
using PairVector = std::vector<Pair>;

void MatrixGraph::dijkstra()
{
    std::priority_queue<Pair, PairVector,std::greater<Pair>> costVertexPq;

    costVertexPq.push(std::make_pair(0, begin_));
    distances_[begin_] = 0;

    while(!costVertexPq.empty())
    {
        int smallestCost = costVertexPq.top().second;
        costVertexPq.pop();

        for(int i = 0; i < vertexNumber_; ++i)
        {
            if(adjacency_[smallestCost][i] == INT_MAX) continue;
            int vertex = i;
            int cost = adjacency_[smallestCost][i];

            if (distances_[vertex] > distances_[smallestCost] + cost)
            {
                distances_[vertex] = distances_[smallestCost] + cost;
                costVertexPq.push(std::make_pair(distances_[vertex], vertex));
                previous_[vertex] = smallestCost;
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
