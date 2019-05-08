#include "ListGraph.hpp"

#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

ListGraph::ListGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.resize(vertexNumber);

}

void ListGraph::addVertex(int vertex, int neighbour, int pathCost)
{
    adjacency_[vertex].emplace_back(std::make_pair(neighbour,pathCost));
    adjacency_[neighbour].emplace_back(std::make_pair(vertex,pathCost));

}


using Edge = std::pair<int,int>;
using EdgeVector = std::vector<Edge>;


void ListGraph::dijkstra()
{
    std::priority_queue<Edge, EdgeVector,std::greater<Edge>> costVertexPq;

    costVertexPq.push(std::make_pair(0, begin_));
    distances_[begin_] = 0;

    while(!costVertexPq.empty())
    {
        int smallestCost = costVertexPq.top().second;
        costVertexPq.pop();

        if(!adjacency_[smallestCost].empty())
        {
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
}

void ListGraph::bellmanFord()
{
    distances_[begin_] = 0;

    for (int i = 0; i < vertexNumber_-1; ++i)
    {
        for (int j = 0; j < vertexNumber_; ++j)
        {
            if(!adjacency_[j].empty())
            {
                for (auto& n : adjacency_[j])
                {

                    if (distances_[n.first] > n.second + distances_[j] && distances_[j]!=INT_MAX)
                    {
                        distances_[n.first] = n.second + distances_[j];
                        previous_[n.first] = j;
                    }
                }
            }
        }
    }
}


void ListGraph::initializeAdjacency()
{
    if(!adjacency_.empty()) adjacency_.clear();

    adjacency_.resize(vertexNumber_);
    //std::cout<<__FUNCTION__<<std::endl;
}

void ListGraph::randomizeEdges(std::vector<Edge>& possibleEdges, int edgesNumber)
{
    for (int i = 0; i < edgesNumber; ++i)
    {
        //std::cout<<i <<"ok"<<std::endl;
        int cost = std::rand() % 50 +1;
        int edgeIndex = std::rand() % possibleEdges.size();
        //std::cout<<possibleEdges.size()<<std::endl;
       // std::cout<<edgeIndex<<std::endl;


        Edge e = possibleEdges.at(edgeIndex);
       // std::cout<<"ok";
        auto toRemove = possibleEdges.begin()+edgeIndex;
        possibleEdges.erase(toRemove);
        adjacency_[e.first].emplace_back(std::make_pair(e.second,cost));
        adjacency_[e.second].emplace_back(std::make_pair(e.first,cost));
    }


}
