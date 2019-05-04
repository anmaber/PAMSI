#include "Graph.hpp"

#include <climits>
#include <iostream>

Graph::Graph(int vertexNumber, int begin)
    : vertexNumber_(vertexNumber),
      begin_(begin)
{
    distances_.resize(vertexNumber,INT_MAX);
}

void Graph::print()
{
    std::cout<<"Vertex Distance from Source\n";
    for (int i = 0; i < vertexNumber_; ++i)
        std::cout<<i<<"--->"<<distances_[i]<<"\n";

    for(auto n: previous_)
    {
        std::cout<<n.first<<"<--\t";
        int index = n.first;
        while(index>0)
        {
            std::cout<<previous_[index]<<"\t";
            index = previous_[index];
        }
        std::cout<<std::endl;
    }
}
