#include "Graph.hpp"

#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


Graph::Graph(int vertexNumber, int begin)
    : vertexNumber_(vertexNumber),
      begin_(begin)
{
    distances_.resize(vertexNumber,INT_MAX);
    previous_.resize(vertexNumber);
}

void Graph::print()
{
    std::cout<<"Vertex Distance from Source\n";
    for (int i = 0; i < vertexNumber_; ++i)
        std::cout<<i<<"--->"<<distances_[i]<<"\n";

    for(auto i = 0u; i < previous_.size(); ++i)
    {
        std::cout<<i<<"<--\t";
        int index = i;
        while(index != begin_ && index!=INT_MAX)
        {
            std::cout<<previous_[index]<<"\t";
            index = previous_[index];
        }
        std::cout<<std::endl;
    }

}

std::string Graph::getDistanceAndPreviousOnes(int vertex)
{
    std::stringstream ss;
    ss << vertex << " | \t" << distances_[vertex] << " | \t";
    while(vertex != begin_)
    {
        ss<<previous_[vertex]<<"\t";
        vertex = previous_[vertex];
    }
    ss << "\n";

    return ss.str();
}

void Graph::saveToFile(const std::string &fileName)
{
    std::ofstream file;
    file.open(fileName);
    file << "Vertex \t minimal distnce \t previous ones \n";

    for(int i = 0; i < vertexNumber_; ++i)
    {
        file << getDistanceAndPreviousOnes(i);
    }
    file.close();
}

void Graph::GenerateRandom(int size, double density)
{
    vertexNumber_ = size;

    srand( time( NULL ) );
    begin_ = std::rand() % vertexNumber_;
    int edgesNumber = static_cast<int>(density * vertexNumber_*(vertexNumber_ - 1) / 2);

    std::vector<Edge> possibleEdges;
    for (int i = 0; i < vertexNumber_; ++i)
    {
        for (int j = i + 1; j < vertexNumber_; ++j)
        {
            possibleEdges.emplace_back(std::make_pair(i,j));
        }
    }

    if(!previous_.empty()) previous_.clear();
    previous_.reserve(vertexNumber_);

    if(!distances_.empty()) distances_.clear();
    distances_.resize(vertexNumber_,INT_MAX);

    initializeAdjacency();
    randomizeEdges(possibleEdges,edgesNumber);
}
