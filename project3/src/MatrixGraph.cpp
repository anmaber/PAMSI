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

void MatrixGraph::addVertex(int vertex, int neighbourNumber, int pathCost)
{
    adjacency_[vertex][neighbourNumber] = pathCost;
    adjacency_[neighbourNumber][vertex] = pathCost;

}

using Edge = std::pair<int,int>;
using EdgeVector = std::vector<Edge>;

void MatrixGraph::dijkstra()
{
    std::priority_queue<Edge, EdgeVector,std::greater<Edge>> costVertexPq;

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
                if(distances_[j] != INT_MAX && adjacency_[j][k] != INT_MAX && distances_[k] > adjacency_[j][k] + distances_[j])
                {
                    distances_[k] = adjacency_[j][k] + distances_[j];
                    previous_[k] = j;
                }
            }
        }
    }

}

void MatrixGraph::initializeAdjacency()
{
    if(!adjacency_.empty()) adjacency_.clear();

    adjacency_.resize(vertexNumber_);
    for(auto & a : adjacency_)
    {
        a.resize(vertexNumber_,INT_MAX);
    }
}

void MatrixGraph::randomizeEdges(std::vector<Edge> &possibleEdges, int edgesNumber)
{
    for (int i = 0; i < edgesNumber; ++i)
    {
        int cost = std::rand() % 50 +1;
        int edgeIndex = std::rand() % possibleEdges.size();
        Edge e = possibleEdges[edgeIndex];
        auto toRemove = possibleEdges.begin()+edgeIndex;
        possibleEdges.erase(toRemove);
        adjacency_[e.first][e.second] = cost;
        adjacency_[e.second][e.first] = cost;
    }
}
