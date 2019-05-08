#include "Tester.hpp"
#include <iostream>
#include <chrono>

Tester::Tester()
{
    //g_ = std::make_unique<ListGraph>();
    g_ = std::make_unique<MatrixGraph>();

    size_.emplace_back(10);
    size_.emplace_back(50);
    size_.emplace_back(100);
    size_.emplace_back(500);

    density_.emplace_back(0.25);
    density_.emplace_back(0.5);
    density_.emplace_back(0.75);
    density_.emplace_back(1);

    //file_.open("listDijkstra.csv", std::ios::out);
    //file_.open("matrixDijkstra.csv", std::ios::out);
    //file_.open("listBellmanFord.csv", std::ios::out);
     file_.open("matrixBellmanFord.csv", std::ios::out);


}

void Tester::performTests()
{
    file_ << "size; density; time \n";
    for(auto d : density_)
    {
        for(auto s : size_)
        {
            g_->GenerateRandom(s,d);
            auto start = std::chrono::high_resolution_clock::now();
            //g_->dijkstra();
            g_->bellmanFord();
            auto end = std::chrono::high_resolution_clock::now();

            auto duration =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

             file_ << s<< ";" << d << ";" << duration.count() << std::endl;
        }
    }
}
