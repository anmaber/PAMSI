#include "ListGraph.hpp"
#include "MatrixGraph.hpp"

#include <fstream>
#include <memory>

class Tester
{
    std::unique_ptr<Graph> g_;
    std::vector<int> size_;
    std::vector<double> density_;
    std::ofstream file_;

public:

    Tester();
    void performTests();
};
