#include "priorityQueue.hpp"

int main()
{
    PriorityQueue<int> queue;
    queue.enqueue(1,2);
    queue.enqueue(1,2);
    queue.enqueue(3,4);
    queue.enqueue(3,4);
    queue.enqueue(2,3);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();




    return 0;
}
