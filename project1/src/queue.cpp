#include "queue.hpp"

int main()
{
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();
    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();


    return 0;
}
