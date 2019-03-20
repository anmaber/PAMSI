#include "queue.hpp"
#include <queue>

int main()
{
    /***MY QUEUE ***/
    try{
        Queue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        std::cout<<"queue:"<<std::endl;
        queue.display();
        std::cout<<"dequeueing: " << queue.dequeue()<<std::endl;
        std::cout<<"after dequeue: ";
        queue.display();
        std::cout<<"dequeueing: " << queue.dequeue()<<std::endl;
        std::cout<<"after dequeue: ";
        queue.display();
        std::cout<<"dequeueing: " << queue.dequeue()<<std::endl;
        std::cout<<"after dequeue: ";
        queue.display();

        /*
        std::cout<<"dequeueing: " << queue.dequeue()<<std::endl;
        std::cout<<"after dequeue: ";
        queue.display();
        */

    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /*** STL QUEUE ***/
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.pop();



    return 0;
}
