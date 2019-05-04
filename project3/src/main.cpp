#include "ListGraph.hpp"

int main()
{
    ListGraph g(9,0);


    g.addNeighbour(0,1,4);
    g.addNeighbour(0,7,8);
    g.addNeighbour(1,2,8);
    g.addNeighbour(1,7,11);
    g.addNeighbour(2,3,7);
    g.addNeighbour(2,8,2);
    g.addNeighbour(2,5,4);
    g.addNeighbour(3,4,9);
    g.addNeighbour(3,5,14);
    g.addNeighbour(4,5,10);
    g.addNeighbour(5,6,2);
    g.addNeighbour(6,7,1);
    g.addNeighbour(6,8,6);
    g.addNeighbour(7,8,7);

    g.dijkstra();

    ListGraph g2(9,0);


    g2.addNeighbour(0,1,4);
    g2.addNeighbour(0,7,8);
    g2.addNeighbour(1,2,8);
    g2.addNeighbour(1,7,11);
    g2.addNeighbour(2,3,7);
    g2.addNeighbour(2,8,2);
    g2.addNeighbour(2,5,4);
    g2.addNeighbour(3,4,9);
    g2.addNeighbour(3,5,14);
    g2.addNeighbour(4,5,10);
    g2.addNeighbour(5,6,2);
    g2.addNeighbour(6,7,1);
    g2.addNeighbour(6,8,6);
    g2.addNeighbour(7,8,7);

    g2.bellmanFord();

    return 0;
}
