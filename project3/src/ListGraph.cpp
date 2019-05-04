#include "ListGraph.hpp"

#include <queue>
#include <iostream>
#include <climits>
#include <map>
#include <algorithm>

Graph::Graph(int vertexNumber, int begin)
    : vertexNumber_(vertexNumber),
      begin_(begin)

{
    adjacency_.reserve(vertexNumber);
}

void Graph::addNeighbour(int nodeNumber, int neighbourNumber, int pathCost)
{
    adjacency_[nodeNumber].push_back(std::make_pair(neighbourNumber,pathCost));
    adjacency_[neighbourNumber].push_back(std::make_pair(nodeNumber, pathCost));
}


using Pair = std::pair<int,int>;
using PairVector = std::vector<Pair>;


void Graph::dijkstra()
{
    std::priority_queue<Pair, PairVector,std::greater<Pair>> costVertexPq;
    std::vector<int> distances(vertexNumber_,INT_MAX);
    std::map<int, int> previous;

    costVertexPq.push(std::make_pair(0, begin_));
    distances[begin_] = 0;

    while(!costVertexPq.empty())
    {
        int smallestCost = costVertexPq.top().second;
        costVertexPq.pop();

        for(const auto& neighbour : adjacency_[smallestCost])
        {
            int vertex = neighbour.first;
            int cost = neighbour.second;

            if (distances[vertex] > distances[smallestCost] + cost)
            {
                distances[vertex] = distances[smallestCost] + cost;
                costVertexPq.push(std::make_pair(distances[vertex], vertex));
                previous[vertex] = smallestCost;
            }
        }

    }

    std::cout<<"Vertex Distance from Source\n";
    for (int i = 0; i < vertexNumber_; ++i)
        std::cout<<i<<"--->"<<distances[i]<<"\n";

    for(auto n: previous)
    {
        std::cout<<n.first<<"<--\t";
        int index = n.first;
        while(index>0)
        {
            std::cout<<previous[index]<<"\t";
            index = previous[index];
        }
        std::cout<<std::endl;
    }
}
