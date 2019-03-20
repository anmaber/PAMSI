#include "priorityQueue.hpp"

int main()
{
    /***    MY PRIORITY QUEUE ***/
    try{
        PriorityQueue<int> queue;
        queue.enqueue(1,2);
        queue.enqueue(1,2);
        queue.enqueue(3,4);
        queue.enqueue(3,4);
        queue.enqueue(2,3);
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





    return 0;
}
