#include "ListGraph.hpp"

#include <queue>
#include <algorithm>

ListGraph::ListGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.reserve(vertexNumber);
}

void ListGraph::addVertex(int vertex, int neighbour, int pathCost)
{
    adjacency_[vertex].push_back(std::make_pair(neighbour,pathCost));
}


using Pair = std::pair<int,int>;
using PairVector = std::vector<Pair>;


void ListGraph::dijkstra()
{
    std::priority_queue<Pair, PairVector,std::greater<Pair>> costVertexPq;

    costVertexPq.push(std::make_pair(0, begin_));
    distances_[begin_] = 0;

    while(!costVertexPq.empty())
    {
        int smallestCost = costVertexPq.top().second;
        costVertexPq.pop();

        for(const auto& neighbour : adjacency_[smallestCost])
        {
            int vertex = neighbour.first;
            int cost = neighbour.second;

            if (distances_[vertex] > distances_[smallestCost] + cost)
            {
                distances_[vertex] = distances_[smallestCost] + cost;
                costVertexPq.push(std::make_pair(distances_[vertex], vertex));
                previous_[vertex] = smallestCost;
            }
        }

    }
}

void ListGraph::bellmanFord()
{
    distances_[begin_] = 0;

    for (int i = 1; i < vertexNumber_; ++i)
    {
        for (int j = 0; j < vertexNumber_; ++j)
        {
            for (const auto& n : adjacency_[j])
            {
                if (distances_[n.first] > n.second + distances_[j])
                {
                    distances_[n.first] = n.second + distances_[j];
                    previous_[n.first] = j;
                }
            }
        }
    }
}

