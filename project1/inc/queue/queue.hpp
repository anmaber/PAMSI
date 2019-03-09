#pragma once

#include "queueNode.hpp"

template<class Type>
class Queue{

    QueueNode<Type>* top;
    QueueNode<Type>* bottom;

  public:
    Queue();
    ~Queue();
    void enqueue(const Type& newElement);
};

template<class Type>
Queue<Type>::Queue()
    : top(nullptr),
      bottom(nullptr)
{}

template<class Type>
Queue<Type>::~Queue()
{
 while(top)
 {
     QueueNode<Type>* next = top->next;
     delete top;
     top=next;
 }
}

template<class Type>
void Queue<Type>::enqueue(const Type &newElement)
{
    QueueNode<Type>* node = new QueueNode<Type>(newElement);
    if(!top)
    {
        top = node;
        bottom = node;
    }
    else
    {
        bottom->next = node;
        bottom = node;
    }

}

